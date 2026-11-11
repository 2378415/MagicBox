/* USB HID device for the MAKCU rebuild (device side).
 *
 * Bring-up path for ESP32-S3 with the managed `espressif/tinyusb` component:
 *   1. initialise the internal USB PHY for the OTG controller (the component
 *      ships no board layer, so we do the same thing its BSP does);
 *   2. tusb_init();
 *   3. run tud_task() from a dedicated task;
 *   4. forward every makcu mouse report through tud_hid_report().
 *
 * Note: USB-Serial-JTAG and USB-OTG share D+/D- on the ESP32-S3, so a build
 * with this component must keep the serial console on UART0 (see
 * MB_CONTROL_USB_JTAG in app_main.c).
 */
#include "tusb.h"

#include "esp_private/usb_phy.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "makcu_hiddev.h"

#include <string.h>
#include "makcu_clone.h"        /* report-ID convention of the cloned descriptor */

static const char *TAG = "makcu-hid";
static usb_phy_handle_t s_phy;
static bool s_mounted;
static bool s_init_ok;
static SemaphoreHandle_t s_hid_lock;
static void (*s_pump_hook)(void);

void makcu_hiddev_set_pump_hook(void (*fn)(void))
{
    s_pump_hook = fn;
}

/* Raw-injection bookkeeping (mx.hv): a report can be dropped because the host is
 * not configured, because the endpoint is still busy, or by the stack itself. */
static uint32_t s_raw_attempts;
static uint32_t s_raw_sent;
static uint32_t s_raw_not_ready;
static uint32_t s_raw_wake;          /* reports that had to wake the bus first */
static uint32_t s_send_no_mount;     /* hid_send() refused: host not configured */
static uint32_t s_send_ok;           /* reports the stack accepted */
static uint32_t s_send_busy;         /* endpoint was not ready */
static uint32_t s_send_false;        /* tud_hid_report() returned false */

/* Report queue + drain task.  A 1 kHz mouse delivers ~1000 0xA2 frames per
 * second; pushing them straight into the endpoint from the link task floods it
 * (TinyUSB leaves the IN endpoint claimed when a transfer is refused, and then
 * almost every later report fails - measured: 12 of 1573).  The original right
 * chip uses queue + drain as well, so the rebuild does the same: enqueue here,
 * let km_hid_tx send at most one report per HID interval. */
#define TX_QUEUE_DEPTH  32
#define TX_REPORT_MAX   16

static uint8_t           s_txq_data[TX_QUEUE_DEPTH][TX_REPORT_MAX];
static uint8_t           s_txq_len[TX_QUEUE_DEPTH];
static volatile unsigned s_txq_head;
static volatile unsigned s_txq_tail;
static SemaphoreHandle_t s_txq_lock;
static TaskHandle_t      s_tx_task;
static volatile uint32_t s_txq_enqueued;
static volatile uint32_t s_txq_sent;
static volatile uint32_t s_txq_dropped;
static volatile uint32_t s_ready_fail;
static volatile uint32_t s_complete_count;
static volatile uint32_t s_ep_sent, s_ep_failed;

/* Report queue.  tud_hid_n_report() fails whenever the previous transfer has not
 * completed yet; dropping that report loses relative displacement, which the user
 * perceives as "the cursor is slower than the real mouse" (measured: only ~35% of
 * reports got through when injected back to back).  Queue them instead and drain
 * from tud_hid_report_complete_cb().  Reports are NEVER merged - 1 kHz timing
 * matters more than throughput. */
#define REP_QD    32   /* absorbs the boot/re-enumerate burst (was 16) */
#define REP_QLEN  8
static uint8_t  s_rep_q[REP_QD][REP_QLEN];
static uint8_t  s_rep_len[REP_QD];
static volatile uint8_t s_rep_head, s_rep_tail;
static volatile uint32_t s_rep_queued, s_rep_dropped_q, s_rep_drained;

void makcu_hiddev_report_verbatim_ep(uint8_t ep, const uint8_t *data, uint16_t len);

/* 按键报告插队槽（2026-11-11）。
 *
 * 背景：注入队列满时旧实现"丢最旧"，而瞄准时引擎 1 kHz 灌满 32 深度的队列，
 * 按键报告一旦排在队尾或撞上溢出就被丢掉 / 被推迟几十毫秒 —— 主机侧表现就是
 * "鼠标移动过程中按键被冲掉"。
 *
 * 处理：任何按键字节与上一次不同的报告都不进 FIFO，而是放进这个单槽并抢先发送
 * （rep_drain_one 优先发它）。若槽里还有一条没发出去的按键报告，就先把它落到 FIFO，
 * 保证"按下 → 松开"两条都不会丢。 */
/* 按键专用队列（URG_MAX 深）。按键报告**永不进入**运动 FIFO，
 * 于是队列逻辑与运动完全解耦：按键按到达顺序逐条发送，旧的绝不因为新按键到达而丢。
 * 深度 32 = 32 ms 的按键积压，而人手不可能在 32 ms 内产生 32 次不同的按键变化；
 * 真满了只计数（btn_overflow），不覆盖任何已排队的报告。 */
#define URG_MAX 32
static uint8_t           s_urg_q[URG_MAX][REP_QLEN];
static uint16_t          s_urg_lenq[URG_MAX];
static volatile uint8_t  s_urg_head;
static uint32_t          s_urg_ts[URG_MAX];   /* 每条入队时刻（µs） */
static bool              s_urg_eng[URG_MAX];   /* true = 引擎注入（可合并）；false = 真实鼠标（直发） */
static volatile bool     s_push_from_engine;   /* 当前 rep_push 的来源标记 */
static volatile uint32_t s_btn_merged;        /* P2：5 ms 内同值重复被合并的次数 */
static volatile uint32_t s_btn_cancel;        /* P2：5 ms 内反向成对被抵消的次数 */
#define BTN_COALESCE_US 5000u
static volatile uint8_t  s_urg_tail;
static volatile uint8_t  s_urg_n;
static volatile uint8_t  s_last_btn;
static volatile uint32_t s_urg_sent;

static volatile uint32_t s_btn_in;            /* 入队次数 */
static volatile uint32_t s_btn_sent;          /* 上总线次数 */
static volatile uint32_t s_btn_wait_max_us;   /* 入队 → 上总线的最大延迟 */
static volatile uint32_t s_btn_overflow;      /* 队列满而没接下的次数（正常应恒为 0） */
static volatile uint32_t s_urg_stamp_us;      /* 最老一条入队时刻 */

/* S2：按键审计改为在"真正上线"处统计——只有这里看得见透传与注入两条路径。 */
static volatile uint32_t s_wire_btn_chg;   /* 上线报告中按键字节发生变化的次数 */
static uint8_t           s_wire_btn_last;  /* 上一条上线报告的按键字节 */
static volatile uint32_t s_btn_stamped;   /* A：出队时被改写按键字节的报告数 */
static volatile uint32_t s_btn_dedup;      /* S3：1 ms 内同值重复被合并的次数 */
static volatile uint32_t s_btn_flood;      /* S3：1 s 内按键字节变化 > 50 次 的次数 */
static uint32_t          s_flood_win_start_us;
static uint16_t          s_flood_win_count;
/* S4：最近 8 条上线报告的按键字节（环形） */
static uint8_t           s_btn_hist[8];
static volatile uint8_t  s_btn_hist_n;
static volatile uint8_t  s_btn_hist_pos;

static void wire_btn_track(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) {
        return;
    }
    const uint8_t b = (uint8_t)(data[0] & 0x1Fu);
    if (b != s_wire_btn_last) {
        s_wire_btn_last = b;
        s_wire_btn_chg++;
        s_btn_hist[s_btn_hist_pos] = b;
        s_btn_hist_pos = (uint8_t)((s_btn_hist_pos + 1) % 8u);
        if (s_btn_hist_n < 8u) {
            s_btn_hist_n++;
        }
        const uint32_t now = (uint32_t)esp_timer_get_time();
        if (now - s_flood_win_start_us > 1000000u) {
            s_flood_win_start_us = now;
            s_flood_win_count = 0;
        }
        if (++s_flood_win_count > 50u) {
            s_btn_flood++;
            s_flood_win_count = 0;
        }
    }
}

void makcu_hiddev_btn_wire(uint16_t *chg, uint16_t *flood, uint16_t *merged, uint16_t *cancel)
{
    if (chg != NULL) { *chg = (uint16_t)s_wire_btn_chg; }
    if (flood != NULL) { *flood = (uint16_t)s_btn_flood; }
    if (merged != NULL) { *merged = (uint16_t)s_btn_merged; }
    if (cancel != NULL) { *cancel = (uint16_t)s_btn_cancel; }
}

uint16_t makcu_hiddev_btn_stamped(void)
{
    return (uint16_t)s_btn_stamped;
}

void makcu_hiddev_btn_history(uint8_t *out, uint8_t max)
{
    if (out == NULL || max < 8) {
        return;
    }
    for (uint8_t i = 0; i < 8; i++) {
        out[i] = 0;
    }
    const uint8_t n = s_btn_hist_n;
    for (uint8_t i = 0; i < n; i++) {
        /* 最新一条放在最后 */
        const uint8_t idx = (uint8_t)((s_btn_hist_pos + 8u - n + i) % 8u);
        out[i] = s_btn_hist[idx];
    }
}

/* 最近一条真正上了总线的报告（0x42 LAST_HID 诊断用：确认按键字节与轴字节各是多少）。 */
static uint8_t           s_last_rep[16];
static volatile uint8_t  s_last_rep_len;
static volatile uint8_t  s_last_rep_rid;
static volatile uint32_t s_last_rep_seq;

void makcu_hiddev_last_report(uint8_t *out, uint8_t max)
{
    if (out == NULL || max < 10) {
        return;
    }
    const uint8_t n = (s_last_rep_len > 8u) ? 8u : s_last_rep_len;
    out[0] = s_last_rep_rid;
    out[1] = n;
    for (uint8_t i = 0; i < 8; i++) {
        out[2 + i] = (i < n) ? s_last_rep[i] : 0;
    }
}

void makcu_hiddev_button_stats(uint16_t *in, uint16_t *sent, uint16_t *wait_max_us,
                               uint16_t *over)
{
    if (in != NULL) { *in = (uint16_t)s_btn_in; }
    if (sent != NULL) { *sent = (uint16_t)s_btn_sent; }
    if (wait_max_us != NULL) { *wait_max_us = (uint16_t)s_btn_wait_max_us; }
    if (over != NULL) { *over = (uint16_t)s_btn_overflow; }
}

/* 入队一条按键报告。满了只计数、不丢旧的、不覆盖（新报告被拒，界面能看出 overflow>0）。 */
static void urg_push(const uint8_t *data, uint16_t len, bool engine)
{
    if (s_urg_n >= URG_MAX) {
        s_btn_overflow++;
        return;
    }
    /* P2：5 ms 合并窗口——**只对引擎注入生效**。
     * 真实鼠标的点击必须原样直发：以前这段不分来源，导致不布防时物理点击也被延迟/吞掉
     * （体感"多发或少发"）。 */
    const uint32_t now_us = (uint32_t)esp_timer_get_time();
    if (engine && s_urg_n > 0) {
        const uint8_t prev = (uint8_t)((s_urg_head + URG_MAX - 1u) % URG_MAX);
        const uint8_t prev_val = (uint8_t)(s_urg_q[prev][0] & 0x1Fu);
        const uint8_t new_val = (uint8_t)(data[0] & 0x1Fu);
        if (!s_urg_eng[prev]) {
            /* 上一条是真实鼠标的报告：不合并，各自直发 */
        } else if (prev_val == new_val && (now_us - s_urg_ts[prev]) < BTN_COALESCE_US) {
            s_btn_merged++;
            return;
        } else if (s_urg_n == 1 && prev_val != new_val
                && (now_us - s_urg_ts[prev]) < BTN_COALESCE_US
                && new_val == s_wire_btn_last) {
            /* 注入的按下还没发出去，5 ms 内又被注入了反值 → 两条都作废 */
            s_urg_head = prev;
            s_urg_n--;
            s_btn_cancel++;
            return;
        }
    }
    if (s_urg_n == 0) {
        s_urg_stamp_us = now_us;
    }
    memcpy(s_urg_q[s_urg_head], data, len);
    s_urg_lenq[s_urg_head] = len;
    s_urg_ts[s_urg_head] = now_us;
    s_urg_eng[s_urg_head] = engine;
    s_urg_head = (uint8_t)((s_urg_head + 1) % URG_MAX);
    s_urg_n++;
    s_btn_in++;
}

static void rep_push_fifo(const uint8_t *data, uint16_t len)
{
    const uint8_t next = (uint8_t)((s_rep_head + 1) % REP_QD);
    if (next == s_rep_tail) {          /* full: drop the oldest to stay current */
        s_rep_tail = (uint8_t)((s_rep_tail + 1) % REP_QD);
        s_rep_dropped_q++;
    }
    memcpy(s_rep_q[s_rep_head], data, len);
    s_rep_len[s_rep_head] = (uint8_t)len;
    s_rep_head = next;
    s_rep_queued++;
}

static void rep_push(const uint8_t *data, uint16_t len)
{
    if (len == 0 && data == NULL) {
        return;
    }
    if (len > REP_QLEN) {
        len = REP_QLEN;
    }
    const uint8_t btn = (uint8_t)(data[0] & 0x1Fu);
    if (btn != s_last_btn) {
        s_last_btn = btn;
        urg_push(data, len, s_push_from_engine);   /* 只进按键队列，绝不进运动 FIFO */
        return;
    }
    rep_push_fifo(data, len);
}

/* Called from the completion callback: send the next queued report, if any. */
static void rep_drain_one(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    const uint8_t rid = (c != NULL && c->valid) ? c->ifs[0].report_id : 0u;
    if (s_urg_n > 0) {
        /* P2：先等 5 ms 合并窗口；队列 ≥2 时立即发最旧一条，避免堆叠。 */
        const uint32_t waited0 = (uint32_t)esp_timer_get_time() - s_urg_ts[s_urg_tail];
        if (s_urg_eng[s_urg_tail] && s_urg_n < 2 && waited0 < BTN_COALESCE_US) {
            return;   /* 只对注入的按键等 5 ms 窗口；真实鼠标立即发 */
        }
        /* 按键报告优先：下一条就发它。 */
        if (tud_hid_n_report(0, rid, s_urg_q[s_urg_tail], s_urg_lenq[s_urg_tail])) {
            const uint32_t waited = (uint32_t)esp_timer_get_time() - s_urg_ts[s_urg_tail];
            if (waited > s_btn_wait_max_us) {
                s_btn_wait_max_us = waited;
            }
            wire_btn_track(s_urg_q[s_urg_tail], s_urg_lenq[s_urg_tail]);
            memcpy(s_last_rep, s_urg_q[s_urg_tail], s_urg_lenq[s_urg_tail] > 16u
                    ? 16u : s_urg_lenq[s_urg_tail]);
            s_last_rep_len = (uint8_t)s_urg_lenq[s_urg_tail];
            s_last_rep_rid = rid;
            s_last_rep_seq++;
            s_urg_tail = (uint8_t)((s_urg_tail + 1) % URG_MAX);
            s_urg_n--;
            s_urg_sent++;
            s_btn_sent++;
            s_rep_drained++;
            s_ep_sent++;
            if (s_urg_n > 0) {
                s_urg_stamp_us = s_urg_ts[s_urg_tail];
            }
        }
        return;
    }
    if (s_rep_tail == s_rep_head) {
        return;
    }
    const uint8_t idx = s_rep_tail;
    /* 方案 A（2026-11-11）：**按键字节以最新上线状态为准**。
     *
     * FIFO 里存的是"入队那一刻"的整条报告（含 byte0 按键字节）。按键变化的报告走
     * 插队槽先发出去，于是队列里还压着若干"按下之前"的报告（byte0=0）——它们随后
     * 被原样发出，PC 就会看到 按下 → 松开 → 按下，一次物理点击变成两次（游戏里
     * 表现为"瞄准开了又取消"、按键抖动）。
     *
     * 修法：出队时把 byte0 的低 5 位（按键位）改写为**最近一次真正上线**的按键字节
     * `s_wire_btn_last`，高位保持原样。位移 dx/dy/wheel 一个字节都不动，位置总量守恒。
     */
    uint8_t out_buf[REP_QLEN];
    uint8_t out_len = s_rep_len[idx];
    memcpy(out_buf, s_rep_q[idx], out_len);
    if (out_len >= 1u) {
        out_buf[0] = (uint8_t)((out_buf[0] & (uint8_t)~0x1Fu) | (s_wire_btn_last & 0x1Fu));
    }
    if (tud_hid_n_report(0, rid, out_buf, out_len)) {
        if (out_buf[0] != s_rep_q[idx][0]) {
            s_btn_stamped++;          /* 统计：有多少条出队报告被"改了按键字节" */
        }
        wire_btn_track(out_buf, out_len);
        memcpy(s_last_rep, out_buf, out_len > 16u ? 16u : out_len);
        s_last_rep_len = out_len;
        s_last_rep_rid = rid;
        s_last_rep_seq++;
        s_rep_tail = (uint8_t)((s_rep_tail + 1) % REP_QD);
        s_rep_drained++;
        s_ep_sent++;
    }
}   /* transfers the HOST actually took */

static void usb_phy_setup(void)
{
    usb_phy_config_t cfg = {
        .controller = USB_PHY_CTRL_OTG,
        .target = USB_PHY_TARGET_INT,
        .otg_mode = USB_OTG_MODE_DEVICE,
        .otg_speed = USB_PHY_SPEED_FULL,
    };
    ESP_ERROR_CHECK(usb_new_phy(&cfg, &s_phy));
}

static bool hid_send(uint8_t report_id, const uint8_t *data, uint16_t len)
{
    if (!s_mounted) {
        s_send_no_mount++;
        return false;
    }
    if (s_hid_lock == NULL) {
        if (!tud_hid_ready()) {
            s_send_busy++;
            return false;
        }
        const bool ok0 = tud_hid_report(report_id, data, len);
        if (ok0) { s_send_ok++; } else { s_send_false++; }
        return ok0;
    }
    xSemaphoreTake(s_hid_lock, portMAX_DELAY);
    if (!tud_hid_ready()) {
        xSemaphoreGive(s_hid_lock);
        s_send_busy++;
        return false;
    }
    const bool ok = tud_hid_report(report_id, data, len);
    xSemaphoreGive(s_hid_lock);
    if (ok) { s_send_ok++; } else { s_send_false++; }
    return ok;
}

/* ---- report layout of the served (cloned) device ---------------------------
 * The served descriptor decides how many bytes one input report has, and the
 * host silently drops a shorter one.  Measured 2026-11-10: `.km.move(200,0)`
 * returned, the HID layer accepted it (mx.hs grew) and the cursor did not move a
 * single pixel, while `mx.lfx` — the verbatim path that sends the mouse's own 7
 * bytes — moved it 314 px for the same 200 counts.  The G3M PRO descriptor is
 * 93 bytes describing buttons(5)+pad(3), X16, Y16, wheel, pan = 7 bytes, but this
 * layer used to emit 4.  So derive the size from the descriptor instead of
 * assuming it. */
static uint8_t report_bytes_from_desc(const uint8_t *d, uint16_t len)
{
    uint32_t bits = 0;
    int size = 0;
    int count = 0;
    uint16_t i = 0;

    while (i < len) {
        const uint8_t b = d[i];
        const uint8_t bsize = (uint8_t)(b & 0x03);
        const uint8_t btype = (uint8_t)((b >> 2) & 0x03);
        const uint8_t btag  = (uint8_t)(b >> 4);
        if (bsize == 3) {                       /* long item: skip */
            i = (uint16_t)(i + 5);
            continue;
        }
        uint32_t val = 0;
        for (uint8_t k = 0; k < bsize; k++) {
            if ((uint16_t)(i + 1u + k) < len) {
                val |= (uint32_t)d[i + 1u + k] << (8u * k);
            }
        }
        i = (uint16_t)(i + 1u + bsize);
        if (btype == 1) {                       /* global */
            if (btag == 0x7) {
                size = (int)val;                /* Report Size */
            } else if (btag == 0x9) {
                count = (int)val;               /* Report Count (also global!) */
            }
        } else if (btype == 2) {                /* local: usage/label, not needed */
            continue;
        } else if (btype == 0 && btag == 0x8) { /* main: Input */
            bits += (uint32_t)size * (uint32_t)count;
        }
    }
    return (uint8_t)((bits + 7u) / 8u);
}

/* Bytes per input report of the mouse interface we serve (0 = unknown).
 * Bench probe `mx.rb` reads this back, because "hs grew but the cursor did not
 * move" is otherwise indistinguishable from a wrong report size. */
uint8_t makcu_hiddev_report_bytes(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c == NULL || !c->valid) {
        return 0;
    }
    const uint8_t *d = NULL;
    uint16_t len = 0;
    if (c->if_count > 0 && c->ifs[0].valid && c->ifs[0].report_len > 0) {
        d = c->ifs[0].report;
        len = c->ifs[0].report_len;
    } else if (c->report_len > 0) {
        d = c->report;
        len = c->report_len;
    }
    if (d == NULL || len == 0) {
        return 0;
    }
    const uint8_t n = report_bytes_from_desc(d, len);
    return (n > 0 && n <= 16) ? n : 0;
}

void makcu_hiddev_report(const makcu_report_t *r)
{
    if (r == NULL) {
        return;
    }
    if (tud_suspended()) {
        tud_remote_wakeup();               /* host stopped polling: ask it to resume */
        s_raw_wake++;
        return;
    }
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
        /* Clone active: encode with the cloned descriptor's own layout, and add
         * no Report ID prefix unless the descriptor declares one. */
        const uint8_t want = makcu_hiddev_report_bytes();
        const uint8_t ep_in = (c->if_count > 0 && c->ifs[0].valid && c->ifs[0].ep_in)
                            ? c->ifs[0].ep_in : 0x81u;
        uint8_t rep[16] = { 0 };
        if (want >= 7) {
            /* 16-bit axes: buttons, X16 LE, Y16 LE, wheel, pan (G3M PRO) */
            const uint16_t x = (uint16_t)(int16_t)r->dx;
            const uint16_t y = (uint16_t)(int16_t)r->dy;
            rep[0] = (uint8_t)(r->buttons & 0x1F);
            rep[1] = (uint8_t)(x & 0xFF);
            rep[2] = (uint8_t)(x >> 8);
            rep[3] = (uint8_t)(y & 0xFF);
            rep[4] = (uint8_t)(y >> 8);
            rep[5] = (uint8_t)r->wheel;
            rep[6] = 0;                    /* AC pan */
            /* Same sender as the pass-through path: that is the code path that
             * demonstrably drives the host cursor, and it queues when the endpoint
             * is busy instead of dropping the motion outright. */
            makcu_hiddev_report_verbatim_ep(ep_in, rep, 7);
            return;
        }
        if (want == 5) {
            /* 12-bit packed axes: buttons, x[7:0], x[11:8]|y[3:0]<<4, y[11:4], wheel */
            const int32_t x12 = (int32_t)r->dx & 0x0FFF;
            const int32_t y12 = (int32_t)r->dy & 0x0FFF;
            rep[0] = (uint8_t)(r->buttons & 0x07);
            rep[1] = (uint8_t)(x12 & 0xFF);
            rep[2] = (uint8_t)(((x12 >> 8) & 0x0F) | ((y12 & 0x0F) << 4));
            rep[3] = (uint8_t)((y12 >> 4) & 0xFF);
            rep[4] = (uint8_t)r->wheel;
            makcu_hiddev_report_verbatim_ep(ep_in, rep, 5);
            return;
        }
        const uint8_t report[4] = { (uint8_t)(r->buttons & 7), (uint8_t)r->dx,
                                    (uint8_t)r->dy, (uint8_t)r->wheel };
        makcu_hiddev_report_verbatim_ep(ep_in, report, sizeof(report));
        return;
    }
    /* Built-in descriptor: ID 2 is the mouse interface and it expects the 5-byte
     * hid_mouse_report_t (buttons, x, y, vertical, horizontal). */
    const uint8_t report[5] = { (uint8_t)(r->buttons & 7), (uint8_t)r->dx,
                                (uint8_t)r->dy, (uint8_t)r->wheel, 0 };
    hid_send(2, report, sizeof(report));
}

/* Accumulator used by the direct raw path (kept for probes and for builds where
 * the mouse layer is not wired in). */
static int32_t s_acc_dx;
static int32_t s_acc_dy;
static int32_t s_acc_wheel;
static uint8_t s_acc_buttons;

static int32_t clamp_i8(int32_t v)
{
    if (v > 127) { return 127; }
    if (v < -128) { return -128; }
    return v;
}

static void flush_accumulated(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    for (int guard = 0; guard < 4; guard++) {
        if (!tud_hid_ready()) {
            s_ready_fail++;
            return;
        }
        if (s_acc_dx == 0 && s_acc_dy == 0 && s_acc_wheel == 0) {
            return;
        }
        const int8_t dx = (int8_t)clamp_i8(s_acc_dx);
        const int8_t dy = (int8_t)clamp_i8(s_acc_dy);
        const int8_t dw = (int8_t)clamp_i8(s_acc_wheel);
        uint8_t report[5] = { s_acc_buttons, (uint8_t)dx, (uint8_t)dy, (uint8_t)dw, 0 };
        const uint8_t rid = (c != NULL && c->valid) ? c->report_id : 2;
        if (hid_send(rid, report, 5)) {
            s_txq_sent++;
            s_acc_dx -= dx;
            s_acc_dy -= dy;
            s_acc_wheel -= dw;
        } else {
            return;
        }
    }
}

/* Forward a report to the interface that owns this endpoint: a composite mouse
 * has two HID interfaces (mouse on 0x81, keyboard/vendor on 0x82), and each has
 * its own Report ID convention. */
void makcu_hiddev_report_verbatim_ep(uint8_t ep, const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) {
        return;
    }
    s_raw_attempts++;

    const makcu_clone_t *c = makcu_clone_get();
    uint8_t inst = 0;
    uint8_t rid = (c != NULL && c->valid) ? c->report_id : 1;
    if (c != NULL && c->valid) {
        for (uint8_t i = 0; i < c->if_count && i < MAKCU_CLONE_IF_MAX; i++) {
            if (c->ifs[i].valid && c->ifs[i].ep_in == ep) {
                inst = i;
                /* The mouse interface must carry the report id the served report
                 * descriptor declares - without it the host silently drops every
                 * report (the bytes arrive, the cursor never moves).  Fall back to
                 * the clone-wide id when the per-interface scan found none.
                 * The vendor channel's 64-byte reports go out raw: a prepended id
                 * would make them 65 bytes on a 64-byte MPS endpoint. */
                if (i == 0) {
                    /* Use exactly what the per-interface scan found: this is the
                     * configuration that was verified to move the cursor. */
                    rid = c->ifs[i].report_id;
                } else {
                    rid = 0u;
                }
                break;
            }
        }
    }

    if (tud_suspended()) {
        tud_remote_wakeup();
        s_raw_wake++;
        /* Keep the movement: queue it, the completion callback will drain once the
         * host resumes polling. */
        if (inst == 0) {
            rep_push(data, len);
        }
        return;
    }
    if (!tud_hid_n_ready(inst)) {
        s_raw_not_ready++;
        /* This is the common case at 1 kHz - the endpoint is still busy with the
         * previous report.  Queue instead of returning, otherwise the report (and
         * with it that slice of relative movement) is lost for good. */
        if (inst == 0) {
            rep_push(data, len);
        }
        return;
    }
    if (len > CFG_TUD_HID_EP_BUFSIZE) {
        len = CFG_TUD_HID_EP_BUFSIZE;
    }
    if (tud_hid_n_report(inst, rid, data, len)) {
        s_raw_sent++;
        s_ep_sent++;
    } else if (inst == 0) {
        /* Endpoint busy: queue it (mouse reports only; never merge). */
        rep_push(data, len);
    } else {
        s_ep_failed++;
    }
}

void makcu_hiddev_report_verbatim(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) {
        return;
    }
    s_raw_attempts++;
    if (tud_suspended()) {
        tud_remote_wakeup();
        s_raw_wake++;
        return;
    }
    if (!tud_hid_ready()) {
        s_raw_not_ready++;
        return;
    }
    if (len > CFG_TUD_HID_EP_BUFSIZE) {
        len = CFG_TUD_HID_EP_BUFSIZE;
    }
    const makcu_clone_t *c = makcu_clone_get();
    const uint8_t rid = (c != NULL && c->valid) ? c->report_id : 1;
    if (hid_send(rid, data, len)) {
        s_raw_sent++;
    }
}

void makcu_hiddev_report_raw(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len < 3) {
        return;
    }
    s_raw_attempts++;
    s_txq_enqueued++;                     /* keep the probe names stable */
    s_acc_buttons = data[0];
    s_acc_dx += (int32_t)(int8_t)data[1];
    s_acc_dy += (int32_t)(int8_t)data[2];
    if (len >= 4) {
        s_acc_wheel += (int32_t)(int8_t)data[3];
    }
    if (tud_suspended()) {
        tud_remote_wakeup();
        s_raw_wake++;
    }
    flush_accumulated();
}

static void hid_drain_one(void)
{
    if (s_txq_lock == NULL || s_txq_head == s_txq_tail) {
        return;
    }
    if (!tud_hid_ready()) {
        s_ready_fail++;
        return;
    }
    uint8_t buf[TX_REPORT_MAX];
    uint8_t n;
    xSemaphoreTake(s_txq_lock, portMAX_DELAY);
    n = s_txq_len[s_txq_tail];
    memcpy(buf, s_txq_data[s_txq_tail], n);
    s_txq_tail = (s_txq_tail + 1) % TX_QUEUE_DEPTH;
    xSemaphoreGive(s_txq_lock);

    const makcu_clone_t *c = makcu_clone_get();
    const uint8_t rid = (c != NULL && c->valid) ? c->report_id : 1;
    if (hid_send(rid, buf, n)) {
        s_txq_sent++;
    }
}

static void hid_tx_task_unused(void *arg)
{
    (void)arg;
    for (;;) {
        /* Plain polling: one report per 2 ms (about 500 Hz).  A notify-driven
         * inner loop starved the idle task and tripped the task watchdog, and
         * pushing faster than the endpoint drains just makes TinyUSB drop the
         * claim (measured 12 of 1573 accepted). */
        vTaskDelay(pdMS_TO_TICKS(2));
        if (s_txq_head == s_txq_tail) {
            continue;
        }
        if (!tud_hid_ready()) {
            continue;
        }
        uint8_t buf[TX_REPORT_MAX];
        uint8_t n;
        xSemaphoreTake(s_txq_lock, portMAX_DELAY);
        n = s_txq_len[s_txq_tail];
        memcpy(buf, s_txq_data[s_txq_tail], n);
        s_txq_tail = (s_txq_tail + 1) % TX_QUEUE_DEPTH;
        xSemaphoreGive(s_txq_lock);

        const makcu_clone_t *c = makcu_clone_get();
        const uint8_t rid = (c != NULL && c->valid) ? c->report_id : 1;
        if (hid_send(rid, buf, n)) {
            s_txq_sent++;
        } else {
            s_raw_not_ready++;
        }
    }
}

void makcu_hiddev_link_state(uint32_t *ready_fail, bool *ready,
                             bool *suspended, bool *mounted)
{
    if (ready_fail != NULL) { *ready_fail = s_ready_fail; }
    if (ready != NULL) { *ready = tud_hid_ready(); }
    if (suspended != NULL) { *suspended = tud_suspended(); }
    if (mounted != NULL) { *mounted = s_mounted; }
}

void makcu_hiddev_complete_count(uint32_t *done)
{
    if (done != NULL) { *done = s_complete_count; }
}

void makcu_hiddev_send_stats(uint32_t *ok, uint32_t *busy,
                             uint32_t *failed, uint32_t *no_mount, bool *mounted)
{
    if (ok != NULL) { *ok = s_send_ok; }
    if (busy != NULL) { *busy = s_send_busy; }
    if (failed != NULL) { *failed = s_send_false; }
    if (no_mount != NULL) { *no_mount = s_send_no_mount; }
    if (mounted != NULL) { *mounted = s_mounted; }
}

void makcu_hiddev_raw_stats(uint32_t *attempts, uint32_t *sent,
                            uint32_t *not_ready, uint32_t *wake,
                            uint32_t *no_mount, bool *mounted)
{
    if (attempts != NULL) { *attempts = s_txq_enqueued; }
    if (sent != NULL) { *sent = s_txq_sent; }
    if (not_ready != NULL) { *not_ready = (uint32_t)(s_acc_dx + s_acc_dy + s_acc_wheel); }
    if (wake != NULL) { *wake = s_raw_wake; }
    if (no_mount != NULL) { *no_mount = s_send_no_mount; }
    if (mounted != NULL) { *mounted = s_mounted; }
}

void makcu_hiddev_kbd_report(const uint8_t *report8)
{
    if (report8 == NULL) {
        return;
    }
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
        /* A cloned mouse descriptor has no keyboard collection; sending ID 2
         * would be an out-of-range report for the host. */
        return;
    }
    hid_send(2, report8, 8);                         /* report ID 2 = keyboard */
}

void makcu_hiddev_rebind(void)
{
    /* Descriptors are only read while enumerating, so drop the bus and come back
     * after the store has been updated. */
    tud_disconnect();
    vTaskDelay(pdMS_TO_TICKS(30));
    tud_connect();
}

bool makcu_hiddev_init_ok(void)
{
    return s_init_ok;
}

bool makcu_hiddev_mounted(void)
{
    return s_mounted;
}

static void hid_task(void *arg)
{
    (void)arg;
    for (;;) {
        tud_task();
    }
}

void makcu_hiddev_init(void)
{
    if (s_phy == NULL) {
        usb_phy_setup();
    }
    if (s_hid_lock == NULL) {
        s_hid_lock = xSemaphoreCreateMutex();
    }
    if (s_txq_lock == NULL) {
        s_txq_lock = xSemaphoreCreateMutex();
    }
    if (!tusb_init()) {
        ESP_LOGE(TAG, "tusb_init failed");
        return;
    }
    s_init_ok = true;
    xTaskCreate(hid_task, "km_hid", 4096, NULL, 11, NULL);
    /* TODO(run-20): report queue + paced drain.  The naive version tripped the
     * task watchdog, so injection stays direct for now (see verification/report). */
    ESP_LOGI(TAG, "HID device up (%04x:%04x)", 0x303A, 0x4004);
}

/* ------------------------------------------------------------ TinyUSB cb */
void tud_mount_cb(void)
{
    s_mounted = true;
    ESP_LOGI(TAG, "mounted");
}

void tud_umount_cb(void)
{
    s_mounted = false;
    ESP_LOGI(TAG, "unmounted");
}

void tud_suspend_cb(bool remote_wakeup_en)
{
    (void)remote_wakeup_en;
    s_mounted = false;
}

void tud_resume_cb(void)
{
    s_mounted = true;
}

uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id,
                               hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
    (void)instance;
    (void)report_id;
    (void)report_type;
    (void)buffer;
    (void)reqlen;
    return 0;
}

/* The only race-free moment to queue another report: TinyUSB just finished the
 * previous transfer, so the endpoint is free and its claim is released. */
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report, uint16_t len)
{
    (void)instance;
    (void)report;
    (void)len;
    s_complete_count++;
    if (instance == 0) {
        rep_drain_one();
    }
    if (s_pump_hook != NULL) {
        s_pump_hook();
    }
}

static makcu_hiddev_out_hook_t s_out_hook;

void makcu_hiddev_set_out_hook(makcu_hiddev_out_hook_t hook)
{
    s_out_hook = hook;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id,
                           hid_report_type_t report_type,
                           uint8_t const *buffer, uint16_t bufsize)
{
    (void)report_type;
    if (s_out_hook != NULL && buffer != NULL && bufsize > 0) {
        s_out_hook(instance, report_id, buffer, bufsize);
    }
}

/* Per-endpoint (dual-interface) send counters for the stress bench. */
void makcu_hiddev_ep_stats(uint32_t *sent, uint32_t *failed)
{
    if (sent != NULL)   { *sent = s_ep_sent; }
    if (failed != NULL) { *failed = s_ep_failed + s_rep_dropped_q; }
}
