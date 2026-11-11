/* app_right: host side of the MAKCU box.
 *
 * Wires up the UART1 link and mirrors frame_forward (0x4200F6C4): every incoming
 * frame gets exactly one reply frame on the same port.  The reply bytes follow
 * the decompiled helpers:
 *
 *   oversized (payload > MAKCU_LINK_MAX_FIELD)     5A <cmd> 01 00 FF   (no dispatch)
 *   0xA0  frame_ep0_dir (0x4200FAC0)               5A A0 01 00 <dir>  dir = *d88 ? 0x00 : 0xFF
 *   0xA1  payload < 8                              5A A1 01 00 FF
 *         payload >= 8          FUN_4200FC74       (needs the USB host URB path - TODO)
 *   0x1A  snapshot (0x4200F854)  no device          5A 1A 01 00 FF
 *   0xA3  frame_a3_flag (0x4200FAE0)               5A A3 01 00 00   (also sets the re-attach flag)
 *   0xA4  config (0x4200FE44)    no device          5A A4 01 00 FF
 *  0xB1  no handler                                5A B1 00 00     (header only)
 *   other default error (0x420248E4)                5A <cmd> 01 00 FF
 *
 * The host-side state the original reads is kept in `g_host`: `ready` is
 * DAT_42000d28+4 (a device is attached), `session` is *DAT_42000d2c, `ep0_dir`
 * is *DAT_42000d88.  With no USB host stack yet they stay 0, which is exactly the
 * "nothing attached" state of a freshly booted right chip - so the replies below
 * match the original's behaviour on an empty bench, and each branch is a marked
 * TODO for when makcu_hidhost lands.
 */
#include <stddef.h>
#include <string.h>

#include "driver/uart.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "nvs_flash.h"

#include "makcu_link.h"
#include "esp_log.h"
#include <stdarg.h>
#include <stdio.h>
#include "makcu_right_frames.h"
#include "makcu_hidhost.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#define LINK_UART      UART_NUM_1
/* Wiring of the inter-chip link, from the two factory images (see
 * components/makcu_link/include/makcu_link_bridge.h): this side is
 * FUN_4200F644 -> uart_set_pin(1, 1, 2, ...) at 5 Mbaud, i.e. crossed with the
 * left chip's TX=2 / RX=1. */
#define LINK_BAUD      5000000
#define LINK_TX        1
#define LINK_RX        2
#define LINK_RX_BUF    1024
#define LINK_TX_BUF    4096   /* ~6.5 ms of headroom at 5 Mbaud */

static const char *TAG = "makcu-right";

static makcu_link_parser_t s_parser;
static makcu_frame_t       s_frame;

/* Host-side state of the original (see makcu_right_frames.h for the mapping):
 *   ready    DAT_42000d28+4   a device is attached
 *   session  *DAT_42000d2c
 *   ep0_dir  *DAT_42000d88
 *   reattach *DAT_42000d48    set by 0xA3
 * With no host stack yet every field stays 0, which is the freshly booted state
 * of the original right chip. */
static makcu_right_state_t g_host;

/* ---------------------------------------------------------------- tx frames */
/* The reply bytes live in components/makcu_right (portable C) so the left chip's
 * `mx.rf` bench command exercises the very same code - this board cannot be
 * flashed with the right-chip firmware, and that would otherwise leave frame
 * replies verified only by review. */
static uint8_t s_tx[MAKCU_LINK_HEADER + MAKCU_LINK_MAX_FIELD];
static bool    s_last_attached;

/* ---------------------------- log forwarding (bench: no console on this chip)
 * This chip has no usable console (USB-Serial-JTAG shares the PHY with the host
 * stack), so its ESP_LOG output was invisible and every investigation had to
 * guess from counters.  Forward it to the left chip as 0x1F frames; the left
 * prints them on COM3 prefixed with [R]. */
static volatile bool s_log_ready;

/* Right-chip logs go into a RAM ring and are drained by the link task between
 * frames.  Writing the link UART straight from the log hook interleaves with the
 * 1 kHz report stream and both get corrupted. */
#define LOGRING_N   8
#define LOGRING_LEN 160
static char     s_logring[LOGRING_N][LOGRING_LEN];
static volatile uint8_t s_logring_head, s_logring_tail;

static int log_forward(const char *fmt, va_list ap)
{
    if (!s_log_ready) {
        return 0;
    }
    const uint8_t next = (uint8_t)((s_logring_head + 1) % LOGRING_N);
    if (next == s_logring_tail) {
        return 0;                       /* ring full: drop, never block */
    }
    char *dst = s_logring[s_logring_head];
    int n = vsnprintf(dst, LOGRING_LEN, fmt, ap);
    if (n <= 0) {
        return n;
    }
    if (n >= LOGRING_LEN) {
        n = LOGRING_LEN - 1;
    }
    while (n > 0 && (dst[n - 1] == '\n' || dst[n - 1] == '\r')) {
        n--;
    }
    dst[n] = 0;
    s_logring_head = next;
    return n;
}

/* Called from link_task: send at most one buffered log line. */
static void log_flush_one(void)
{
    if (s_logring_tail == s_logring_head) {
        return;
    }
    const char *line = s_logring[s_logring_tail];
    const size_t len = strlen(line);
    if (len > 0 && len <= MAKCU_LINK_MAX_FIELD) {
        const size_t total = makcu_link_build(s_tx, sizeof(s_tx), 0x1F,
                                              (const uint8_t *)line, (uint16_t)len);
        if (total != 0u) {
            uart_write_bytes(LINK_UART, s_tx, total);
        }
    }
    s_logring_tail = (uint8_t)((s_logring_tail + 1) % LOGRING_N);
}

static SemaphoreHandle_t s_tx_lock;

/* Forward one HID report to the left chip as 0xA2 <ep> <report...>.
 * The factory gates this on the A3 flag (raised by 0xA3, cleared on detach), so
 * we do the same: g_host.reattach is set by the 0xA3 handler. */
static void report_sink(uint8_t ep, const uint8_t *data, uint8_t len)
{
    if (len == 0u || len > MAKCU_LINK_MAX_FIELD - 4u) {
        return;
    }
    const int64_t t0 = esp_timer_get_time();
    /* 0xA2 payload layout expected by the left chip (see
     * makcu_link_bridge.c: avail = f->len - 4, report copied from payload[4]):
     *   [0]=ep  [1]=session  [2]=report_len  [3]=flag  [4..]=report bytes  */
    uint8_t payload[MAKCU_LINK_MAX_FIELD];
    payload[0] = ep;
    payload[1] = makcu_hidhost_session();
    payload[2] = len;
    payload[3] = 0u;
    memcpy(&payload[4], data, len);
    const size_t n = makcu_link_build(s_tx, sizeof(s_tx), 0xA2, payload, (uint16_t)(len + 4u));
    if (n == 0u) {
        return;
    }
    if (s_tx_lock != NULL) {
        xSemaphoreTake(s_tx_lock, portMAX_DELAY);
    }
    uart_write_bytes(LINK_UART, s_tx, n);
    if (s_tx_lock != NULL) {
        xSemaphoreGive(s_tx_lock);
    }
    /* Instrumentation: how long the per-report forward costs on this chip. */
    makcu_hidhost_sink_latency_add((uint32_t)(esp_timer_get_time() - t0));
}

/* 0x21: report the sink-duration histogram (p50/p99/max/samples, all u16 LE). */
static void handle_latency_query(void)
{
    uint16_t p50 = 0, p99 = 0, mx = 0;
    uint32_t n = 0;
    makcu_hidhost_sink_latency(&p50, &p99, &mx, &n);
    uint8_t payload[8];
    payload[0] = (uint8_t)(p50 & 0xFF);
    payload[1] = (uint8_t)(p50 >> 8);
    payload[2] = (uint8_t)(p99 & 0xFF);
    payload[3] = (uint8_t)(p99 >> 8);
    payload[4] = (uint8_t)(mx & 0xFF);
    payload[5] = (uint8_t)(mx >> 8);
    payload[6] = (uint8_t)(n > 0xFFFFu ? 0xFFu : (n & 0xFF));
    payload[7] = 0;
    const size_t total = makcu_link_build(s_tx, sizeof(s_tx), 0x21, payload, 8);
    if (total != 0u) {
        if (s_tx_lock != NULL) { xSemaphoreTake(s_tx_lock, portMAX_DELAY); }
        uart_write_bytes(LINK_UART, s_tx, total);
        if (s_tx_lock != NULL) { xSemaphoreGive(s_tx_lock); }
    }
}

/* --------------------------------------------------------------- dispatch */
/* Bench-only frame 0x1C: report what the USB host core currently sees.
 *   reply 5A 1C 0A 00 <attached> <addr> <vid:u16> <pid:u16> <itf> <in0> <out0> <in1> <out1>
 * Keeps the host state observable without a console (the right chip's USB is the
 * OTG host, so there is no CDC log channel). */
static size_t host_info_frame(const makcu_frame_t *f, uint8_t *out, size_t cap)
{
    (void)f;
    makcu_hidhost_info_t info;
    makcu_hidhost_info(&info);

    /* 36 bytes: 12 header-ish fields + 4 x u16 counters（兼容老左片）+ 4 x u32 精确计数。
     * u16 那四个满 65535 就饱和（实测两次读都 +0），所以后面追加 u32 版本；
     * 左片按回包长度 rn 判断能不能用（旧左片只读前 20 B，不受影响）。 */
    uint8_t payload[36];
    payload[0] = info.attached ? 1u : 0u;
    payload[1] = info.dev_addr;
    payload[2] = (uint8_t)(info.vid & 0xFFu);
    payload[3] = (uint8_t)(info.vid >> 8);
    payload[4] = (uint8_t)(info.pid & 0xFFu);
    payload[5] = (uint8_t)(info.pid >> 8);
    payload[6] = info.itf_count;
    payload[7] = info.itf_count > 0 ? info.itf[0].in_addr : 0u;
    payload[8] = info.itf_count > 0 ? info.itf[0].out_addr : 0u;
    payload[9] = info.itf_count > 1 ? info.itf[1].in_addr : 0u;
    payload[10] = info.itf_count > 1 ? info.itf[1].out_addr : 0u;

    uint16_t ok = 0, fail = 0, done = 0, fwd = 0;
    makcu_hidhost_stats(&ok, &fail, &done, &fwd);
    payload[11] = g_host.reattach;      /* A3 gate state                  */
    /* 16-bit counters from here on (they used to saturate at 255) */
    payload[12] = (uint8_t)(ok & 0xFF);      payload[13] = (uint8_t)(ok >> 8);
    payload[14] = (uint8_t)(fail & 0xFF);    payload[15] = (uint8_t)(fail >> 8);
    payload[16] = (uint8_t)(done & 0xFF);    payload[17] = (uint8_t)(done >> 8);
    payload[18] = (uint8_t)(fwd & 0xFF);     payload[19] = (uint8_t)(fwd >> 8);

    /* 追加 u32 精确计数（ok/fail/done/fwd 各 4 B，小端） */
    uint32_t ok32 = 0, fail32 = 0, done32 = 0, fwd32 = 0;
    makcu_hidhost_stats32(&ok32, &fail32, &done32, &fwd32);
    const uint32_t exact[4] = { ok32, fail32, done32, fwd32 };
    for (int i = 0; i < 4; i++) {
        payload[20 + i * 4 + 0] = (uint8_t)(exact[i] & 0xFF);
        payload[20 + i * 4 + 1] = (uint8_t)((exact[i] >> 8) & 0xFF);
        payload[20 + i * 4 + 2] = (uint8_t)((exact[i] >> 16) & 0xFF);
        payload[20 + i * 4 + 3] = (uint8_t)((exact[i] >> 24) & 0xFF);
    }
    return makcu_link_build(out, cap, 0x1C, payload, 36);
}

/* 0xA1 = EP0 tunnel: payload is the 8-byte USB setup packet.  The left chip's
 * auto-clone reads the descriptors through this (bmRequestType 0x81 for report
 * descriptors).  Reply: 5A A1 <len> <data...>, or 5A A1 01 00 FF on failure. */
static void handle_ep0_tunnel(const makcu_frame_t *f)
{
    static uint8_t ctl_buf[256];
    if (f->len < 8u) {
        static const uint8_t err[5] = { 0x5A, 0xA1, 0x01, 0x00, 0xFF };
        uart_write_bytes(LINK_UART, err, sizeof(err));
        return;
    }

    const int n = makcu_hidhost_control(f->payload, ctl_buf, sizeof(ctl_buf), 100);
    if (n < 0) {
        static const uint8_t err[5] = { 0x5A, 0xA1, 0x01, 0x00, 0xFF };
        uart_write_bytes(LINK_UART, err, sizeof(err));
        return;
    }
    const size_t total = makcu_link_build(s_tx, sizeof(s_tx), 0xA1, ctl_buf, (uint16_t)n);
    if (total != 0u) {
        if (s_tx_lock != NULL) {
            xSemaphoreTake(s_tx_lock, portMAX_DELAY);
        }
        uart_write_bytes(LINK_UART, s_tx, total);
        if (s_tx_lock != NULL) {
            xSemaphoreGive(s_tx_lock);
        }
    }
}

/* 0xA5 = OUT submit: payload <ep><len:u16 LE><data...>.
 * Reply 5A A5 03 00 <rc> <ep> <len>.  This is the vendor channel path the
 * HECATE Connect app uses to write mouse configuration. */
static void handle_out_submit(const makcu_frame_t *f)
{
    if (f->len < 4u) {
        return;
    }
    const uint8_t  ep  = f->payload[0];
    const uint16_t len = (uint16_t)(f->payload[1] | ((uint16_t)f->payload[2] << 8));
    if (len == 0u || (size_t)len + 3u > f->len) {
        return;
    }
    const int rc = makcu_hidhost_out_async(ep, &f->payload[3], len);

    uint8_t payload[3];
    payload[0] = (uint8_t)(rc == 0 ? 0 : 1);
    payload[1] = ep;
    payload[2] = (uint8_t)(len & 0xFFu);
    const size_t total = makcu_link_build(s_tx, sizeof(s_tx), 0xA5, payload, 3);
    if (total != 0u) {
        if (s_tx_lock != NULL) {
            xSemaphoreTake(s_tx_lock, portMAX_DELAY);
        }
        uart_write_bytes(LINK_UART, s_tx, total);
        if (s_tx_lock != NULL) {
            xSemaphoreGive(s_tx_lock);
        }
    }
}

/* 0x1B: the device descriptor as read by the ESP-IDF host stack at enumeration.
 * These never traverse the 0xA1 control tunnel, so the 1 kHz report stream cannot
 * corrupt them (that corruption made the cloned VID/PID drift). */
static void handle_raw_device(void)
{
    uint8_t dev[18];
    if (makcu_hidhost_live_device(dev) != 18) {
        static const uint8_t err[5] = { 0x5A, 0x1B, 0x01, 0x00, 0xFF };
        uart_write_bytes(LINK_UART, err, sizeof(err));
        return;
    }
    const size_t n = makcu_link_build(s_tx, sizeof(s_tx), 0x1B, dev, 18);
    if (n != 0u) {
        uart_write_bytes(LINK_UART, s_tx, n);
    }
}

/* 0x1D: configuration descriptor, fragment request <offset:u16><len:u8>.
 * Reply <total:u16><offset:u16><data...> so the left chip can detect a short
 * read and re-request. */
static void handle_raw_config(const makcu_frame_t *f)
{
    uint8_t total_buf[MAKCU_HIDHOST_RAW_CONFIG_MAX];
    uint16_t total = 0;
    const int got = makcu_hidhost_raw_config(total_buf, sizeof(total_buf), &total);
    if (got <= 0 || total == 0) {
        static const uint8_t err[5] = { 0x5A, 0x1D, 0x01, 0x00, 0xFF };
        uart_write_bytes(LINK_UART, err, sizeof(err));
        return;
    }

    const uint16_t off = (f->len >= 2u) ? (uint16_t)(f->payload[0] | (f->payload[1] << 8)) : 0u;
    uint16_t want = (f->len >= 3u) ? f->payload[2] : 64u;
    if (want == 0u) {
        want = 64u;
    }
    if (off >= total) {
        static const uint8_t err[5] = { 0x5A, 0x1D, 0x01, 0x00, 0xFF };
        uart_write_bytes(LINK_UART, err, sizeof(err));
        return;
    }
    if ((uint32_t)off + want > total) {
        want = (uint16_t)(total - off);
    }
    if (want > MAKCU_LINK_MAX_FIELD - 4u) {
        want = MAKCU_LINK_MAX_FIELD - 4u;
    }

    uint8_t payload[MAKCU_LINK_MAX_FIELD];
    payload[0] = (uint8_t)(total & 0xFF);
    payload[1] = (uint8_t)(total >> 8);
    payload[2] = (uint8_t)(off & 0xFF);
    payload[3] = (uint8_t)(off >> 8);
    memcpy(&payload[4], &total_buf[off], want);
    const size_t n = makcu_link_build(s_tx, sizeof(s_tx), 0x1D, payload, (uint16_t)(want + 4u));
    if (n != 0u) {
        uart_write_bytes(LINK_UART, s_tx, n);
    }
}

/* Tell the left chip when the device appears/disappears so it can re-enumerate
 * its own USB device.  Without this the host-side HID stack sticks in a state
 * where it never delivers input again (the classic "unplug/replug once and the
 * mouse stops" bug - the factory firmware has it too) until the left cable is
 * physically replugged. */
static void notify_left_presence(uint8_t present)
{
    uint8_t payload[1] = { present };
    const size_t n = makcu_link_build(s_tx, sizeof(s_tx), 0x1E, payload, 1);
    if (n != 0u) {
        if (s_tx_lock != NULL) { xSemaphoreTake(s_tx_lock, portMAX_DELAY); }
        uart_write_bytes(LINK_UART, s_tx, n);
        if (s_tx_lock != NULL) { xSemaphoreGive(s_tx_lock); }
    }
}

static void forward(const makcu_frame_t *f)
{
    if (f->cmd == 0xA5 && f->len >= 4u) {
        handle_out_submit(f);
        return;
    }
    if (f->cmd == 0xA1 && f->len >= 8u) {
        handle_ep0_tunnel(f);
        return;
    }
    if (f->cmd == 0x21) {
        handle_latency_query();
        return;
    }
    if (f->cmd == 0x1B) {
        handle_raw_device();
        return;
    }
    if (f->cmd == 0x1D) {
        handle_raw_config(f);
        return;
    }
    if (f->cmd == 0x1C) {
        const size_t n = host_info_frame(f, s_tx, sizeof(s_tx));
        if (n != 0) {
            uart_write_bytes(LINK_UART, s_tx, n);
        }
        return;
    }

    /* The factory reads these three bytes straight out of its host state; we
     * pull them from the USB host core before every reply. */
    const bool attached = makcu_hidhost_attached();
    if (attached != s_last_attached) {
        s_last_attached = attached;
        notify_left_presence(attached ? 1u : 0u);
    }
    g_host.ready   = attached ? 1u : 0u;
    g_host.session = makcu_hidhost_session();
    /* 0xA0 answers with `ep0_dir ? 00 : FF`; the left chip's auto-clone treats
     * 00 as "device present, EP0 usable" and gives up on FF.  Track attachment
     * here, otherwise the tunnel is never even attempted. */
    g_host.ep0_dir = attached ? 1u : 0u;

    const size_t n = makcu_right_reply(f->cmd, f->payload, f->len,
                                       &g_host, s_tx, sizeof(s_tx));
    if (n != 0) {
        if (s_tx_lock != NULL) {
            xSemaphoreTake(s_tx_lock, portMAX_DELAY);
        }
        uart_write_bytes(LINK_UART, s_tx, n);
        if (s_tx_lock != NULL) {
            xSemaphoreGive(s_tx_lock);
        }
    }
}

static void link_task(void *arg)
{
    (void)arg;
    /* Block reads: byte-wise reads meant ~15k syscalls and wake-ups per second at
     * 1 kHz, all of it overhead on the report path. */
    uint8_t buf[128];
    makcu_link_parser_reset(&s_parser);

    for (;;) {
        const int got = uart_read_bytes(LINK_UART, buf, sizeof(buf), pdMS_TO_TICKS(20));
        if (got <= 0) {
            log_flush_one();          /* idle: drain at most one buffered log line */
            continue;
        }
        for (int i = 0; i < got; i++) {
            if (makcu_link_parser_feed(&s_parser, buf[i], &s_frame)) {
                forward(&s_frame);
            }
        }
        log_flush_one();              /* per block, not per byte (P1-7) */
    }
}

void app_main(void)
{
    /* USB host first: the left chip starts cloning a second or two after boot,
     * so the host stack must be up before anything slow (NVS, logging) runs. */
    const esp_err_t host_err = makcu_hidhost_start();
    if (host_err != ESP_OK) {
        ESP_LOGE(TAG, "usb host start failed: %s", esp_err_to_name(host_err));
    }

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    const uart_config_t cfg = {
        .baud_rate = LINK_BAUD,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    ESP_ERROR_CHECK(uart_driver_install(LINK_UART, LINK_RX_BUF, LINK_TX_BUF, 0, NULL, 0));
    ESP_ERROR_CHECK(uart_param_config(LINK_UART, &cfg));
    ESP_ERROR_CHECK(uart_set_pin(LINK_UART, LINK_TX, LINK_RX,
                                 UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));

    memset(&g_host, 0, sizeof(g_host));
    s_tx_lock = xSemaphoreCreateMutex();
    makcu_hidhost_set_sink(report_sink);
    xTaskCreate(link_task, "km_uart1", 4096, NULL, 8, NULL);   /* below the USB tasks */

    /* Only now is the link UART usable, so right-chip logs can be relayed to the
     * left chip (which prints them as "[R] ..." on COM3).  This chip has no
     * console of its own: USB-Serial-JTAG shares the PHY with the host stack. */
    s_log_ready = true;
    esp_log_set_vprintf(log_forward);

    ESP_LOGI(TAG, "link port up at %d baud (logs relayed to the left chip)", LINK_BAUD);
}
