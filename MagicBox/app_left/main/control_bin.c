/* Binary fast path on the UART0 control port - see control_bin.h. */
#include "control_bin.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <string.h>

#include "esp_timer.h"

#include "makcu_mouse.h"
#include "makcu_mouse_hooks.h"
#include "makcu_sumv.h"
#include "btn_evt.h"
#include "btn_trace.h"
#include "makcu_hiddev.h"

#define CB_MAGIC 0x5A

static cb_write_fn s_writer;
static cb_idle_fn  s_tx_idle;      /* 2026-11-13：控制口 TX 是否空闲（决定事件能否直发） */
static TaskHandle_t s_wake_task;   /* 2026-11-14：事件发送任务（收到通知立即发，不等 tick） */

/* --- parser state ---------------------------------------------------------- */
enum {
    ST_IDLE = 0,
    ST_CMD,
    ST_SEQ,
    ST_LEN0,
    ST_LEN1,
    ST_PAYLOAD,
    ST_CRC,
};

static uint8_t  s_state;
static uint8_t  s_cmd;
static uint8_t  s_seq;
static uint16_t s_len;
static uint16_t s_got;
static uint8_t  s_payload[CB_MAX_PAYLOAD];

/* --- diagnostics (QUERY 0) ------------------------------------------------- */
static uint32_t s_pkts;       /* frames whose CRC checked out */
static uint32_t s_crc_err;
static uint32_t s_len_err;
static uint32_t s_gaps;       /* seq jumps seen on accepted frames */
static uint8_t  s_last_seq;
static bool     s_have_seq;
static uint32_t s_plans;      /* MOTION_PLAN frames accepted */
static uint32_t s_button_cmds;    /* 2026-11-12 取证：收到的 0x32 BUTTON 帧数 */
static uint8_t  s_inj_btn;        /* 2026-11-13：最近一次注入按住的位置（主持位窗口按位用） */

/* --- last plan timing (QUERY 2) -------------------------------------------- */
static int16_t  s_p_dx, s_p_dy;
static uint16_t s_p_dur;
static uint32_t s_p_recv_us;
static uint32_t s_p_submit_us;

static uint8_t crc8(const uint8_t *p, size_t n)
{
    uint8_t crc = 0;
    for (size_t i = 0; i < n; i++) {
        crc ^= p[i];
        for (int b = 0; b < 8; b++) {
            crc = (uint8_t)((crc & 0x80) ? ((crc << 1) ^ 0x07) : (crc << 1));
        }
    }
    return crc;
}

static void put_u32(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)(v & 0xFF);
    p[1] = (uint8_t)((v >> 8) & 0xFF);
    p[2] = (uint8_t)((v >> 16) & 0xFF);
    p[3] = (uint8_t)((v >> 24) & 0xFF);
}
static void build_frame(uint8_t cmd, uint8_t seq, const uint8_t *payload, uint16_t len)
{
    if (s_writer == NULL || len > CB_MAX_PAYLOAD) {
        return;
    }
    uint8_t frame[5 + CB_MAX_PAYLOAD + 1];
    frame[0] = CB_MAGIC;
    frame[1] = cmd;
    frame[2] = seq;
    frame[3] = (uint8_t)(len & 0xFF);
    frame[4] = (uint8_t)(len >> 8);
    if (len != 0) {
        memcpy(&frame[5], payload, len);
    }
    frame[5 + len] = crc8(&frame[1], (size_t)len + 4u);
    s_writer(frame, (size_t)len + 6u);
}

static void build_reply(uint8_t cmd, uint8_t seq, const uint8_t *payload, uint16_t len)
{
    build_frame((uint8_t)(cmd | CB_REPLY_FLAG), seq, payload, len);
}

/* 0xE1：设备主动推的按键事件（异步段，seq 为事件序号低字节）
 *
 * 2026-11-13（P1-6）：**不在热路径写串口**。
 * 以前这里直接 build_frame → s_writer → uart_write_bytes()；这条链跑在 km_link 任务里，
 * 控制口 TX 环（1 KB）一满就会阻塞，把 1 kHz 报告顶进 FIFO，再被出队戳印抹掉按键边沿
 * ——"订阅后偶发吞键"的另一半原因。现在只入队（8 深，满了丢事件并计数），
 * 由控制口任务在空闲时调 cb_evt_pump() 真正发送。事件自带 t_us，晚发不影响解码。 */
/* 2026-11-13：深度 8 → 32 → 64。
 * 控制任务每 1 tick（10 ms）才泵一次：8 深只扛 800 事件/秒（实测 1000 边沿/秒时 evdrop=268），
 * 32 深扛 1000 已通过，64 深把上限推到 ~6400 事件/秒，覆盖 2 kHz 极端台架。 */
#define CB_EVT_QD 64
typedef struct {
    uint16_t seq;
    uint32_t t_us;
    uint8_t  mask;
    uint8_t  edge;
} cb_evt_item_t;

static cb_evt_item_t     s_evtq[CB_EVT_QD];
static volatile uint8_t  s_evq_head;
static volatile uint8_t  s_evq_tail;
static volatile uint32_t s_evq_drop;
static volatile uint32_t s_evq_sent;   /* 2026-11-13：真正写进串口的事件帧数（对账用） */
/* 2026-11-13：事件延迟（边沿时刻 → 写进串口），µs。用 esp_timer 同一时钟，口径可信。 */
static volatile uint32_t s_evlat_last;
static volatile uint32_t s_evlat_max;
static volatile uint32_t s_evlat_sum;
static volatile uint32_t s_evlat_n;

static void evt_push_frame(uint16_t seq, uint32_t t_us, uint8_t mask, uint8_t edge)
{
    /* 2026-11-13：**安全快路径**。
     * 控制口 TX 全空（没有任何回包/事件在排队）时，直接在热路径把这 11 字节写进环形缓冲：
     * `uart_write_bytes` 只做一次拷贝、不会阻塞。事件延迟从"等下一次 tick（平均 6 ms、
     * 最差 10~35 ms）"降到 ~0.2 ms；TX 忙时仍入队由控制任务泵（慢但绝不阻塞报告路径）。 */
    if (s_evq_head == s_evq_tail && s_tx_idle != NULL && s_tx_idle()) {
        uint8_t pl[8];
        put_u32(&pl[0], t_us);
        pl[4] = (uint8_t)(seq & 0xFF);
        pl[5] = (uint8_t)(seq >> 8);
        pl[6] = mask;
        pl[7] = edge;
        build_frame(CB_EVT_PUSH, (uint8_t)(seq & 0xFF), pl, 8);
        s_evq_sent++;
        s_evlat_last = (uint32_t)(esp_timer_get_time() - (int64_t)t_us);
        s_evlat_sum += s_evlat_last;
        s_evlat_n++;
        if (s_evlat_last > s_evlat_max) { s_evlat_max = s_evlat_last; }
        return;
    }
    const uint8_t next = (uint8_t)((s_evq_head + 1u) % CB_EVT_QD);
    if (next == s_evq_tail) {
        s_evq_drop++;              /* 队列满：丢事件（可选遥测）比拖慢点击更划算 */
        return;
    }
    s_evtq[s_evq_head].seq = seq;
    s_evtq[s_evq_head].t_us = t_us;
    s_evtq[s_evq_head].mask = mask;
    s_evtq[s_evq_head].edge = edge;
    s_evq_head = next;
    if (s_wake_task != NULL) {
        /* task notification：被唤醒的任务优先级更高，会**立即抢占**，不受 10 ms tick 限制。 */
        (void)xTaskNotifyGive(s_wake_task);
    }
}

bool cb_evt_pending(void)
{
    return s_evq_head != s_evq_tail;
}

uint32_t cb_evt_dropped(void)
{
    return s_evq_drop;
}

uint32_t cb_evt_sent(void)
{
    return s_evq_sent;
}

/* 2026-11-13：事件延迟（边沿时刻 → 写进串口），µs。 */
void cb_set_wake_task(TaskHandle_t task)
{
    s_wake_task = task;
}

void cb_evt_latency(uint32_t *last_us, uint32_t *avg_us, uint32_t *max_us)
{
    if (last_us != NULL) { *last_us = s_evlat_last; }
    if (max_us != NULL)  { *max_us  = s_evlat_max; }
    if (avg_us != NULL)  { *avg_us  = (s_evlat_n != 0u) ? (s_evlat_sum / s_evlat_n) : 0u; }
}

/* 由控制口任务周期调用（非热路径）：把排队的事件帧真正发出去。 */
void cb_evt_pump(void)
{
    while (s_evq_head != s_evq_tail) {
        const cb_evt_item_t *it = &s_evtq[s_evq_tail];
        /* 记录在线格式（与 btn_evt_t 内存布局一致，EVT_READ 原样拷出）：
         *   +0 t_us u32 | +4 seq u16 | +6 mask u8 | +7 edge u8 */
        uint8_t pl[8];
        put_u32(&pl[0], it->t_us);
        pl[4] = (uint8_t)(it->seq & 0xFF);
        pl[5] = (uint8_t)(it->seq >> 8);
        pl[6] = it->mask;
        pl[7] = it->edge;
        build_frame(CB_EVT_PUSH, (uint8_t)(it->seq & 0xFF), pl, 8);
        {
            const uint32_t now = (uint32_t)esp_timer_get_time();
            const uint32_t lat = now - it->t_us;   /* 边沿 → 入串口 */
            s_evlat_last = lat;
            s_evlat_sum += lat;
            s_evlat_n++;
            if (lat > s_evlat_max) { s_evlat_max = lat; }
        }
        s_evq_sent++;
        s_evq_tail = (uint8_t)((s_evq_tail + 1u) % CB_EVT_QD);
    }
}


static void handle_frame(void)
{
    s_pkts++;
    if (s_have_seq) {
        const uint8_t expect = (uint8_t)(s_last_seq + 1u);
        if (s_seq != expect && s_seq != s_last_seq) {
            s_gaps++;
        }
    }
    s_last_seq = s_seq;
    s_have_seq = true;

    switch (s_cmd) {
    case CB_CMD_MOTION_PLAN: {
        /* dx i16, dy i16, dur_ms u16, mode u8, flags u8 */
        if (s_len < 8) {
            s_len_err++;
            return;
        }
        const int16_t dx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        const int16_t dy = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        const uint16_t dur = (uint16_t)(s_payload[4] | (s_payload[5] << 8));
        const uint8_t mode = s_payload[6];
        const uint8_t flags = s_payload[7];
        const uint32_t t0 = (uint32_t)esp_timer_get_time();
        if (makcu_mouse_move_hook != NULL) {
            (void)makcu_mouse_move_hook(NULL, dx, dy, (mode == 1u) ? 1u : 2u);
        }
        const uint32_t t1 = (uint32_t)esp_timer_get_time();
        s_plans++;
        s_p_dx = dx;
        s_p_dy = dy;
        s_p_dur = dur;
        s_p_recv_us = t0;
        s_p_submit_us = t1 - t0;
        (void)flags;      /* tremor / bow flags are consumed by the planner (P3) */
        return;
    }
    case CB_CMD_BUTTON:
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        s_button_cmds++;
        /* 2026-11-13（P1-1）：主持位窗口**只覆盖被注入按住的位**。
         * 以前是整字节 + 200 ms：注入期间所有真实报告（含物理点击）的按键位都被替换成
         * s_wire_btn_last，实测「订阅 + 0x32 注入并发」10 组物理点击丢 18 个边沿
         * （wire_chg 22/40）。现在窗口仍是 200 ms（覆盖一次连点/扳机周期），但按位生效；
         * 注入松开时 mask=0，直接关窗。 */
        {
            const uint8_t ib = (uint8_t)(s_payload[0] & 0x1F);
            s_inj_btn = ib;
            makcu_hiddev_btn_hold_bits(ib, 200);
        }
        /* 强制立即上线（不看 2 ms 让路窗口）：显式注入不是物理抖动候选，
         * 走 emit_now 时若窗口开着，末条"松开"可能等不到下一次运动 flush。 */
        makcu_mouse_emit_event(s_payload[0]);
        return;
    case CB_CMD_WHEEL:
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        if (makcu_wheel_hook != NULL) {
            (void)makcu_wheel_hook(NULL, (int8_t)s_payload[0]);
        }
        return;
    case CB_CMD_QUERY: {
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        uint8_t rp[26];
        switch (s_payload[0]) {
        case 0: {                       /* counters */
            put_u32(&rp[0], s_pkts);
            put_u32(&rp[4], s_crc_err);
            put_u32(&rp[8], s_len_err);
            put_u32(&rp[12], s_gaps);
            rp[16] = s_last_seq;
            rp[17] = 1;                 /* protocol version */
            build_reply(s_cmd, s_seq, rp, 18);
            return;
        }
        case 1: {                       /* caps + clock */
            rp[0] = 1;                  /* protocol version */
            rp[1] = CB_MAX_PAYLOAD;
            rp[2] = 0;                  /* plan engine: 0 = chunked/Bezier (P3 -> 1) */
            rp[3] = 0;
            put_u32(&rp[4], (uint32_t)esp_timer_get_time());
            build_reply(s_cmd, s_seq, rp, 12);
            return;
        }
        case 2: {                       /* last plan */
            rp[0] = (uint8_t)(s_p_dx & 0xFF);
            rp[1] = (uint8_t)((uint16_t)s_p_dx >> 8);
            rp[2] = (uint8_t)(s_p_dy & 0xFF);
            rp[3] = (uint8_t)((uint16_t)s_p_dy >> 8);
            rp[4] = (uint8_t)(s_p_dur & 0xFF);
            rp[5] = (uint8_t)(s_p_dur >> 8);
            put_u32(&rp[6], s_p_recv_us);
            put_u32(&rp[10], s_p_submit_us);
            put_u32(&rp[14], s_plans);
            build_reply(s_cmd, s_seq, rp, 18);
            return;
        }
        default:
            s_len_err++;
            return;
        }
    }
    case CB_CMD_SUMV: {
        /* dx i16, dy i16, speed u16, mode u8, seed u8 [, dur_ms u16]
         * dur_ms 只在 mode bit0（固定时长）时生效。fire-and-forget。 */
        if (s_len < 8) {
            s_len_err++;
            return;
        }
        makcu_sumv_req_t req;
        req.dx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        req.dy = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        req.speed = (uint16_t)(s_payload[4] | (s_payload[5] << 8));
        req.mode = s_payload[6];
        req.seed = s_payload[7];
        req.dur_ms = (s_len >= 10) ? (uint16_t)(s_payload[8] | (s_payload[9] << 8)) : 0;
        (void)makcu_sumv_start(&req);
        s_plans++;
        return;
    }
    case CB_CMD_AIM: {
        /* dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]
         * 无回包（fire-and-forget）；结果码用 AIM_STATE 读。 */
        if (s_len < 6) {
            s_len_err++;
            return;
        }
        const int16_t adx = (int16_t)(s_payload[0] | (s_payload[1] << 8));
        const int16_t ady = (int16_t)(s_payload[2] | (s_payload[3] << 8));
        const uint8_t ms = s_payload[4];
        const uint8_t flags = s_payload[5];
        const uint8_t dead = (s_len >= 7) ? s_payload[6] : 0;
        (void)makcu_sumv_aim(adx, ady, ms, flags, dead);
        s_plans++;
        return;
    }
    case CB_CMD_HID_STAT: {
        uint16_t bin = 0, bsent = 0, bwait = 0, bdrop = 0;
        makcu_hiddev_button_stats(&bin, &bsent, &bwait, &bdrop);
        uint16_t wire_chg = 0, wire_flood = 0, btn_merged = 0, btn_cancel = 0;
        makcu_hiddev_btn_wire(&wire_chg, &wire_flood, &btn_merged, &btn_cancel);
        uint8_t rp[16];
        rp[0] = (uint8_t)(bin & 0xFF);        rp[1] = (uint8_t)(bin >> 8);
        rp[2] = (uint8_t)(bsent & 0xFF);      rp[3] = (uint8_t)(bsent >> 8);
        rp[4] = (uint8_t)(bwait & 0xFF);      rp[5] = (uint8_t)(bwait >> 8);
        rp[6] = (uint8_t)(bdrop & 0xFF);      rp[7] = (uint8_t)(bdrop >> 8);
        /* S3：追加 flood（1 s 内按键字节变化 > 50 次的窗口数）；老客户端按长度忽略 */
        rp[8] = (uint8_t)(wire_flood & 0xFF);
        rp[9] = (uint8_t)(wire_flood >> 8);
        rp[10] = (uint8_t)(btn_merged & 0xFF);
        rp[11] = (uint8_t)(btn_merged >> 8);
        rp[12] = (uint8_t)(btn_cancel & 0xFF);
        rp[13] = (uint8_t)(btn_cancel >> 8);
        /* 2026-11-12：追加 wire_chg —— 上线报告里按键字节真正发生变化的次数。
         * `btn_in/btn_sent` 只统计"进过队列"的按键报告（端点忙时才会入队），
         * 端点空闲时报告是直发的，所以判断"丢没丢"必须看 wire_chg。 */
        rp[14] = (uint8_t)(wire_chg & 0xFF);
        rp[15] = (uint8_t)(wire_chg >> 8);
        build_reply(s_cmd, s_seq, rp, 16);
        return;
    }
    case CB_CMD_AIM_STATE: {
        uint8_t rp[12];
        (void)makcu_sumv_aim_state(rp, sizeof(rp));
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_SUMV_STOP:
        makcu_sumv_stop();
        return;
    case CB_CMD_SUMV_STATE: {
        makcu_sumv_stats_t st;
        makcu_sumv_stats(&st);
        uint8_t rp[32];
        rp[0] = st.active ? 1u : 0u;
        put_u32(&rp[1], st.samples);
        put_u32(&rp[5], st.aborted);
        put_u32(&rp[9], st.rounds);
        put_u32(&rp[13], st.mute_dropped);
        put_u32(&rp[17], st.btn_forwarded);
        put_u32(&rp[21], st.speed_eff);
        put_u32(&rp[25], st.remain_ms);
        build_reply(s_cmd, s_seq, rp, 29);
        return;
    }
    case CB_CMD_BTN_CNT: {
        extern uint32_t btn_diag_counts(uint8_t which);
        uint8_t rp[62];
        put_u32(&rp[0], btn_diag_counts(0));
        put_u32(&rp[4], btn_diag_counts(1));
        put_u32(&rp[8], btn_diag_counts(2));
        put_u32(&rp[12], btn_diag_counts(3));
        /* 追加最近一帧原始报告的前 8 字节（看真实布局：byte0 到底是不是按键） */
        extern void btn_diag_last_frame(uint8_t *out);
        extern uint8_t btn_diag_last_ep(void);
        extern uint8_t btn_diag_last_len(void);
        rp[16] = btn_diag_last_ep();
        rp[17] = btn_diag_last_len();
        btn_diag_last_frame(&rp[18]);
        /* 2026-11-12 追加：定位"帧到了但没产生按键变化"的两种来源 */
        put_u32(&rp[26], btn_diag_counts(4));   /* btn_same：与上一帧同值（重复帧） */
        put_u32(&rp[30], btn_diag_counts(5));   /* fwd_reports：真正转发的报告数 */
        put_u32(&rp[34], btn_diag_counts(6));   /* rx_ovf：控制口接收溢出（吞命令） */
        put_u32(&rp[38], btn_diag_counts(7));   /* lf_drop：mx.lf 环回重试仍失败 */
        /* 2026-11-12 取证：按键变化按发送路径拆分 */
        put_u32(&rp[42], btn_diag_counts(12));  /* direct_chg：直发引入的变化 */
        put_u32(&rp[46], btn_diag_counts(13));  /* queued_chg：队列引入的变化 */
        put_u32(&rp[50], s_button_cmds);        /* 0x32 BUTTON 帧计数（传输侧取证） */
        build_reply(s_cmd, s_seq, rp, 54);
        return;
    }
    case CB_CMD_BTN_LOG: {
        /* 请求：since u16（序号）；回包：total u16, count u8, count × 8B 记录 */
        uint16_t since = 0;
        if (s_len >= 2) {
            since = (uint16_t)(s_payload[0] | (s_payload[1] << 8));
        }
        btn_trace_entry_t entries[5];
        uint16_t total = 0;
        uint16_t n = btn_trace_read(since, entries, 5, &total);
        uint8_t rp[2 + 1 + 5 * 8];
        rp[0] = (uint8_t)(total & 0xFF);
        rp[1] = (uint8_t)(total >> 8);
        rp[2] = (uint8_t)n;
        uint8_t *p = &rp[3];
        for (uint16_t i = 0; i < n; i++) {
            p[0] = (uint8_t)(entries[i].t_us & 0xFF);
            p[1] = (uint8_t)((entries[i].t_us >> 8) & 0xFF);
            p[2] = (uint8_t)((entries[i].t_us >> 16) & 0xFF);
            p[3] = (uint8_t)((entries[i].t_us >> 24) & 0xFF);
            p[4] = entries[i].raw;
            p[5] = entries[i].fwd;
            p[6] = entries[i].src;
            p[7] = 0;
            p += 8;
        }
        build_reply(s_cmd, s_seq, rp, (uint16_t)(3 + n * 8));
        return;
    }
    case CB_CMD_LAST_HID: {
        /* 20 B：rid,len,8B 报告 | 8B 上线按键字节历史 | stamped(u16)
         * `stamped` = 方案 A 生效后"出队时被改写按键字节"的报告数（≈按下瞬间的队列深度）。 */
        uint8_t rp[20] = {0};
        makcu_hiddev_last_report(rp, 10);
        makcu_hiddev_btn_history(&rp[10], 8);
        const uint16_t stamped = makcu_hiddev_btn_stamped();
        rp[18] = (uint8_t)(stamped & 0xFF);
        rp[19] = (uint8_t)(stamped >> 8);
        build_reply(s_cmd, s_seq, rp, 20);
        return;
    }
    case CB_CMD_AIM_RESET: {
        makcu_sumv_aim_clear_stats();
        return;                       /* fire-and-forget */
    }
    case CB_CMD_EVT_RESET: {
        btn_evt_reset_stats();
        return;
    }
    case CB_CMD_BTN_AUDIT: {
        /* 按键回环审计：12 B
         *   [0..3]  in_chg  —— set_buttons 真正改变字节的次数（= 注入的按键变化数）
         *   [4..7]  out_chg —— 实际发出去的报告里按键字节变化的次数
         *   [8..11] extra   —— 变了但没有变化请求挂着（凭空多发）
         * 正常终态：in_chg == out_chg、extra == 0。 */
        uint32_t in_chg = 0, out_chg = 0, extra = 0;
        makcu_mouse_btn_audit(&in_chg, &out_chg, &extra);
        uint8_t rp[12];
        put_u32(&rp[0], in_chg);
        put_u32(&rp[4], out_chg);
        put_u32(&rp[8], extra);
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_EVT_CTL: {
        /* enable u8, mask u8, push u8 [, consume u8]
         * 默认 **穿透**：订阅只产生事件，按键照常给 PC；
         * 第 4 字节 = 1 才是"吃掉"（PC 看不到这次点击）。为兼容老客户端，
         * 长度不足 4 时按穿透处理。 */
        if (s_len < 3) {
            s_len_err++;
            return;
        }
        btn_evt_ctl(s_payload[0] != 0, s_payload[1], s_payload[2] != 0,
                    (s_len >= 4) && (s_payload[3] != 0));
        return;
    }
    case CB_CMD_EVT_READ: {
        /* count u8 → 回 [count][n x 8B 事件]，单帧最多 7 条（payload 上限 64） */
        if (s_len < 1) {
            s_len_err++;
            return;
        }
        uint8_t want = s_payload[0];
        if (want > 7) {
            want = 7;
        }
        uint8_t buf[1 + 7 * 8];
        const uint8_t n = btn_evt_read(&buf[1], want);
        buf[0] = n;
        build_reply(s_cmd, s_seq, buf, (uint16_t)(1u + (uint16_t)n * 8u));
        return;
    }
    case CB_CMD_EVT_STAT: {
        btn_evt_stat_t st;
        btn_evt_stat(&st);
        uint8_t rp[12];
        rp[0] = (uint8_t)(st.head_seq & 0xFF);
        rp[1] = (uint8_t)(st.head_seq >> 8);
        rp[2] = st.count;
        put_u32(&rp[3], st.overflow);
        rp[7] = st.mask;
        rp[8] = st.pending;
        rp[9] = st.cur;
        rp[10] = st.last_fwd;
        rp[11] = (uint8_t)((st.enabled ? 1u : 0u) | (st.push ? 2u : 0u) |
                           (st.auto_released ? 4u : 0u) | (st.consume ? 8u : 0u));
        btn_evt_heartbeat();
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    case CB_CMD_PING: {
        if (s_len < 4) {
            s_len_err++;
            return;
        }
        btn_evt_heartbeat();                     /* PING 也算客户端存活 */
        uint8_t rp[12];
        memcpy(&rp[0], s_payload, 4);            /* echo the counter */
        put_u32(&rp[4], (uint32_t)esp_timer_get_time());
        rp[8] = (uint8_t)(s_plans & 0xFF);
        rp[9] = (uint8_t)((s_plans >> 8) & 0xFF);
        rp[10] = s_last_seq;
        rp[11] = 0;
        build_reply(s_cmd, s_seq, rp, 12);
        return;
    }
    default:
        return;                          /* unknown command: silently ignored */
    }
}

void cb_reset(cb_write_fn writer, cb_idle_fn tx_idle)
{
    s_writer = writer;
    s_tx_idle = tx_idle;
    btn_evt_set_push_fn(evt_push_frame);
    s_state = ST_IDLE;
    s_cmd = s_seq = 0;
    s_len = s_got = 0;
    s_pkts = s_crc_err = s_len_err = s_gaps = s_plans = 0;
    s_last_seq = 0;
    s_have_seq = false;
    s_p_dx = s_p_dy = 0;
    s_p_dur = 0;
    s_p_recv_us = s_p_submit_us = 0;
}

void cb_stats(uint32_t *pkts, uint32_t *crc_err, uint32_t *len_err,
              uint32_t *gaps, uint8_t *last_seq, uint32_t *plans)
{
    if (pkts)     { *pkts = s_pkts; }
    if (crc_err)  { *crc_err = s_crc_err; }
    if (len_err)  { *len_err = s_len_err; }
    if (gaps)     { *gaps = s_gaps; }
    if (last_seq) { *last_seq = s_last_seq; }
    if (plans)    { *plans = s_plans; }
}

bool cb_feed(uint8_t byte, bool at_line_start)
{
    switch (s_state) {
    case ST_IDLE:
        if (byte != CB_MAGIC || !at_line_start) {
            return false;                /* not ours: leave it to the text parser */
        }
        s_state = ST_CMD;
        return true;
    case ST_CMD:
        s_cmd = byte;
        s_state = ST_SEQ;
        return true;
    case ST_SEQ:
        s_seq = byte;
        s_state = ST_LEN0;
        return true;
    case ST_LEN0:
        s_len = byte;
        s_state = ST_LEN1;
        return true;
    case ST_LEN1:
        s_len = (uint16_t)(s_len | ((uint16_t)byte << 8));
        s_got = 0;
        if (s_len > CB_MAX_PAYLOAD) {
            s_len_err++;
            s_state = ST_IDLE;           /* drop the frame, resync on next 0x5A */
            return true;
        }
        s_state = (s_len == 0) ? ST_CRC : ST_PAYLOAD;
        return true;
    case ST_PAYLOAD:
        s_payload[s_got++] = byte;
        if (s_got >= s_len) {
            s_state = ST_CRC;
        }
        return true;
    case ST_CRC: {
        uint8_t buf[4 + CB_MAX_PAYLOAD];
        buf[0] = s_cmd;
        buf[1] = s_seq;
        buf[2] = (uint8_t)(s_len & 0xFF);
        buf[3] = (uint8_t)(s_len >> 8);
        if (s_len != 0) {
            memcpy(&buf[4], s_payload, s_len);
        }
        const uint8_t want = crc8(buf, (size_t)s_len + 4u);
        s_state = ST_IDLE;
        if (want != byte) {
            s_crc_err++;                 /* fire-and-forget: drop, never complain */
            return true;
        }
        handle_frame();
        return true;
    }
    default:
        s_state = ST_IDLE;
        return true;
    }
}
