/* Inter-chip link (UART1) bridge - see include/makcu_link_bridge.h. */
#include "makcu_link_bridge.h"

#include "makcu_link.h"

#include "driver/uart.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include <string.h>

#define LINK_UART      UART_NUM_1
#define LINK_BAUD      MAKCU_LINK_BAUD   /* 5 Mbaud, from the factory image (see the header) */
#define LINK_TX_BUF    1024
#define LINK_RX_BUF    4096

static const char *TAG = "makcu-link";

static makcu_link_parser_t s_parser;
static makcu_link_stats_t  s_stats;
static uint8_t             s_chunk[MAKCU_LINK_EP_COUNT][MAKCU_LINK_EP_CHUNK];
static size_t              s_chunk_len[MAKCU_LINK_EP_COUNT];
static bool                s_ready;

/* 0xA0 tunnel handshake state (the original keeps this as one flag: DAT_4200122c). */
static bool     s_ep0_pending;

/* 0xA2 filter: the first frame adopts the session id, everything after it has to
 * match (the original compares against DAT_42001208).  0 = not adopted yet. */
static uint8_t  s_session;

/* Bench switches: pin the session id (mx.ss) and keep 0xA2 out of the HID path
 * (mx.hk 0) so regression cases stay deterministic while a real mouse is
 * streaming reports into the link. */
static bool     s_session_forced;
static uint8_t  s_session_forced_val;
static bool     s_sink_enabled = true;
static bool     s_heartbeat = true;   /* mx.hb: off silences the 2 s re-arm */

/* Report sink + bench observation of the last injected payload. */
/* Last frame seen on the wire, raw: the only way to see what the right chip
 * actually sends (mx.lr). */
static uint8_t  s_last_rx_cmd;
static uint16_t s_last_rx_len;
static uint8_t  s_last_rx[MAKCU_LINK_INJECT_MAX];

bool makcu_link_set_heartbeat(bool on)
{
    const bool prev = s_heartbeat;
    s_heartbeat = on;
    return prev;
}

void makcu_link_force_session(uint8_t session, bool force)
{
    s_session_forced = force;
    s_session_forced_val = session;
    if (!force) {
        s_session = 0;                 /* back to first-frame adoption */
    }
}

bool makcu_link_enable_sink(bool on)
{
    const bool prev = s_sink_enabled;
    s_sink_enabled = on;
    return prev;
}

/* Send one frame and wait for the reply that carries the same command byte.
 * Used by the auto-clone path to drive the 0xA1 EP0 tunnel synchronously. */
/* A pending makcu_link_request() gets its reply copied here by cmd match.
 * The old code waited on s_last_rx_cmd, which the 1 kHz 0xA2 report stream
 * overwrites constantly - that race is why vendor OUT acks only landed
 * occasionally (measured 1/17) while a quiet bench was 5/5. */
static uint8_t           s_req_cmd;
static volatile bool     s_req_got;
static volatile size_t   s_req_len;
static uint8_t           s_req_buf[MAKCU_LINK_MAX_FIELD];

/* One synchronous request at a time.  The state above is a single slot, and three
 * tasks drive it: km_uart0 (mx.ln / mx.lat / mx.ac probes), km_outq (0xA5 vendor
 * downlink) and km_heal (clone verification after a replug).  Overlapping calls
 * used to overwrite each other's s_req_cmd and both timed out even though the
 * right chip had answered - the "ack race" that only showed up while HECATE was
 * writing config during a replug. */
static SemaphoreHandle_t s_req_lock;

int makcu_link_request(uint8_t cmd, const uint8_t *payload, uint16_t len,
                       uint8_t *out, size_t cap, uint32_t timeout_ms)
{
    if (!s_ready) {
        return -1;
    }
    if (s_req_lock != NULL) {
        xSemaphoreTake(s_req_lock, portMAX_DELAY);
    }
    s_req_got = false;
    s_req_len = 0;
    s_req_cmd = cmd;
    (void)makcu_link_send(cmd, payload, len);

    const TickType_t deadline = xTaskGetTickCount() + pdMS_TO_TICKS(timeout_ms);
    int result = -1;
    while (xTaskGetTickCount() < deadline) {
        if (s_req_got) {
            size_t n = s_req_len;
            if (n > cap) {
                n = cap;
            }
            if (out != NULL && n != 0) {
                memcpy(out, s_req_buf, n);
            }
            result = (int)n;
            break;
        }
        vTaskDelay(1);
    }
    s_req_cmd = 0;
    if (s_req_lock != NULL) {
        xSemaphoreGive(s_req_lock);
    }
    return result;
}

size_t makcu_link_last_frame(uint8_t *cmd, uint8_t *out, size_t cap)
{
    if (cmd != NULL) {
        *cmd = s_last_rx_cmd;
    }
    if (out == NULL) {
        return 0;
    }
    size_t n = s_last_rx_len;
    if (n > cap) {
        n = cap;
    }
    memcpy(out, s_last_rx, n);
    return n;
}

static makcu_link_custom_hook_t s_custom_hook;

void makcu_link_set_custom_hook(makcu_link_custom_hook_t fn)
{
    s_custom_hook = fn;
}

static makcu_link_report_fn s_report_sink;
static uint8_t  s_last_injected[MAKCU_LINK_INJECT_MAX];
static size_t   s_last_injected_len;

makcu_link_stats_t makcu_link_stats(void)
{
    return s_stats;
}

bool makcu_link_ep0_pending(void)
{
    return s_ep0_pending;
}

uint8_t makcu_link_session(void)
{
    return s_session_forced ? s_session_forced_val : s_session;
}

void makcu_link_reset_session(void)
{
    if (!s_session_forced) {
        s_session = 0;              /* next report re-adopts */
    }
}

void makcu_link_set_report_sink(makcu_link_report_fn fn)
{
    s_report_sink = fn;
}

size_t makcu_link_last_injected(uint8_t *out, size_t cap)
{
    if (out == NULL) {
        return 0;
    }
    size_t n = s_last_injected_len;
    if (n > cap) {
        n = cap;
    }
    memcpy(out, s_last_injected, n);
    return n;
}

size_t makcu_link_chunk(int endpoint, uint8_t *out, size_t cap)
{
    if (endpoint < 0 || endpoint >= MAKCU_LINK_EP_COUNT || out == NULL) {
        return 0;
    }
    size_t n = s_chunk_len[endpoint];
    if (n > cap) {
        n = cap;
    }
    memcpy(out, s_chunk[endpoint], n);
    return n;
}

void makcu_link_reset_chunks(void)
{
    memset(s_chunk_len, 0, sizeof(s_chunk_len));
}

size_t makcu_link_send(uint8_t cmd, const uint8_t *payload, uint16_t len)
{
    if (!s_ready) {
        return 0;
    }
    uint8_t frame[MAKCU_LINK_HEADER + MAKCU_LINK_MAX_FIELD];
    const size_t total = makcu_link_build(frame, sizeof(frame), cmd, payload, len);
    if (total == 0) {
        return 0;
    }
    return (size_t)uart_write_bytes(LINK_UART, frame, total);
}

/* Parse a synthetic frame locally: a private parser, no UART involved, so a live
 * mouse streaming real 0xA2 frames into the wire parser cannot corrupt it. */
static makcu_link_parser_t s_probe_parser;

static void handle_frame(const makcu_frame_t *f);

size_t makcu_link_probe_frame(uint8_t cmd, const uint8_t *payload, uint16_t len)
{
    uint8_t wire[4 + MAKCU_LINK_INJECT_MAX];
    if (len > MAKCU_LINK_INJECT_MAX) {
        len = MAKCU_LINK_INJECT_MAX;
    }
    wire[0] = 0x5A;
    wire[1] = cmd;
    wire[2] = (uint8_t)(len & 0xFF);
    wire[3] = (uint8_t)(len >> 8);
    if (len != 0 && payload != NULL) {
        memcpy(&wire[4], payload, len);
    }
    makcu_link_parser_reset(&s_probe_parser);
    makcu_frame_t frame;
    for (uint16_t i = 0; i < (uint16_t)(4 + len); i++) {
        if (makcu_link_parser_feed(&s_probe_parser, wire[i], &frame)) {
            handle_frame(&frame);
        }
    }
    return (size_t)(4 + len);
}

size_t makcu_link_send_loopback(uint8_t cmd, const uint8_t *payload, uint16_t len)
{
    if (!s_ready) {
        return 0;
    }
    /* The loopback bit routes TXD into RXD inside the peripheral, so it has to
     * stay set until the TX FIFO has actually shifted the frame out - clearing
     * it right after uart_write_bytes() loses the frame. */
    uart_set_loop_back(LINK_UART, true);
    const size_t sent = makcu_link_send(cmd, payload, len);
    uart_wait_tx_done(LINK_UART, pdMS_TO_TICKS(50));
    vTaskDelay(pdMS_TO_TICKS(20));
    /* ...but it MUST be cleared again: with loopback left on, the right chip's
     * reports never reach this chip, which looks exactly like "the report path
     * died" (measured: after a plain `mx.lfx` the ds counter froze for good).
     * 20 ms is far more than the 0.2 ms the frame needs at 5 Mbaud, so the
     * frame is already in the RX ring by now. */
    uart_set_loop_back(LINK_UART, false);
    return sent;
}

size_t makcu_link_loopback_selftest(const uint8_t *payload, uint16_t len)
{
    return makcu_link_send_loopback(MAKCU_LINK_HID, payload, len);
}

void makcu_link_set_loopback(bool on)
{
    if (s_ready) {
        uart_set_loop_back(LINK_UART, on);
    }
}

/* ------------------------------------------------------------- dispatch */
/* 0xA0: the original's tunnel handshake (reversed 0x42013734).
 *   len == 1 && payload[0] == 0x00 -> open a session (set the pending flag)
 *   payload[0] == 0xFF or len == 0 -> close it if one is open
 * Everything else is ignored, exactly like the original. */
static void handle_ep0(const makcu_frame_t *f)
{
    s_stats.ep0_requests++;
    const uint8_t dir = (f->len > 0) ? f->payload[0] : 0xFF;

    if (f->len == 1 && dir == 0x00) {
        s_stats.ep0_in++;
        s_ep0_pending = true;
        s_stats.ep0_starts++;
        return;
    }
    if (dir != 0xFF && f->len != 0) {
        return;                                  /* other direction: ignored */
    }
    s_stats.ep0_out++;
    if (s_ep0_pending) {
        s_ep0_pending = false;
        s_stats.ep0_ends++;
    }
}

/* 0xA2: report pass-through.  payload = [ep, id, len, 0, data...]. */
static void handle_hid(const makcu_frame_t *f)
{
    s_stats.hid_chunks++;
    if (f->len < 5) {
        s_stats.reports_dropped++;
        return;
    }
    const int ep = f->payload[0];
    const uint8_t session = f->payload[1];
    const uint8_t report_len = f->payload[2];

#if defined(MB_DEBUG_OPCODE)
    /* Reassembly exists only for the mx.dc bench probe.  It used to run on every
     * report, i.e. an extra memcpy at 1 kHz for nothing - gate it to bench builds. */
    if (ep >= 0 && ep < MAKCU_LINK_EP_COUNT) {
        const size_t room = MAKCU_LINK_EP_CHUNK - s_chunk_len[ep];
        size_t n = report_len;
        const size_t avail = (size_t)f->len - 4;      /* payload[4..] */
        if (n > avail) {
            n = avail;
        }
        if (n > room) {
            n = room;
        }
        if (n > 0) {
            memcpy(&s_chunk[ep][s_chunk_len[ep]], &f->payload[4], n);
            s_chunk_len[ep] += n;
        }
    }
#endif

    if (s_session_forced) {
        /* Pinned session (mx.ss): it replaces adoption entirely, otherwise the
         * auto comparison below would reject the very id we pinned. */
        if (session != s_session_forced_val) {
            s_stats.reports_dropped++;
            return;
        }
    } else {
        if (s_session == 0) {
            s_session = session;                  /* adopt the first session */
        }
        if (session != s_session) {
            s_stats.reports_dropped++;
            return;
        }
    }
    if (report_len == 0) {
        s_stats.reports_dropped++;
        return;
    }

    size_t n = report_len;
    const size_t avail = (size_t)f->len - 4;
    if (n > avail) {
        n = avail;
    }
    if (n == 0) {
        s_stats.reports_dropped++;
        return;
    }
    if (n > sizeof(s_last_injected)) {
        n = sizeof(s_last_injected);
    }
    memcpy(s_last_injected, &f->payload[4], n);
    s_last_injected_len = n;
    s_stats.reports_injected++;
    if (s_sink_enabled && s_report_sink != NULL) {
        s_report_sink(f->payload[0], s_last_injected, (uint16_t)n);
    }
}

static void handle_frame(const makcu_frame_t *f)
{
    s_stats.frames++;
    s_last_rx_cmd = f->cmd;
    s_last_rx_len = (f->len > sizeof(s_last_rx)) ? (uint16_t)sizeof(s_last_rx) : f->len;
    if (s_last_rx_len != 0) {
        memcpy(s_last_rx, f->payload, s_last_rx_len);
    }

    /* Satisfy a pending makcu_link_request() by command match, before the
     * report stream can overwrite the last-frame slot. */
    if (s_req_cmd != 0 && f->cmd == s_req_cmd && !s_req_got) {
        s_req_len = (f->len > sizeof(s_req_buf)) ? sizeof(s_req_buf) : f->len;
        if (s_req_len != 0) {
            memcpy(s_req_buf, f->payload, s_req_len);
        }
        s_req_got = true;
    }

    switch (f->cmd) {
    case MAKCU_LINK_EP0:
        handle_ep0(f);
        break;
    case MAKCU_LINK_HID:
        handle_hid(f);
        break;
    case MAKCU_LINK_A3:
        s_stats.a3_frames++;
        break;
    default:
        if (s_custom_hook != NULL && s_custom_hook(f->cmd, f->payload, f->len)) {
            break;
        }
        s_stats.unknown++;
        break;
    }
}

/* The right chip only forwards 0xA2 reports while *DAT_42000d48 is set, and that
 * flag is written by frame_a3_flag (0x4200FAE0) when the LEFT chip sends 0xA3.
 * Without this announcement the link carries nothing but our own probes. */
static TickType_t s_last_arm;

static void arm_right_chip(void)
{
    const uint8_t zero = 0;
    (void)makcu_link_send(MAKCU_LINK_A3, &zero, 1);
    s_last_arm = xTaskGetTickCount();
}

static void link_task(void *arg)
{
    (void)arg;
    /* Read a block per syscall instead of one byte at a time: at 1 kHz the link
     * carries ~15 kB/s, so byte-wise reads cost ~15k uart_read_bytes() calls and
     * task wake-ups per second - a big share of the CPU spent on overhead. */
    uint8_t buf[128];
    makcu_frame_t frame;
    for (;;) {
        const int got = uart_read_bytes(LINK_UART, buf, sizeof(buf), pdMS_TO_TICKS(20));
        if (got <= 0) {
            /* Re-arm every 2 s: the flag is cleared when the right chip loses its
             * USB device, so a one-shot announcement is not enough. */
            if (s_heartbeat &&
                (xTaskGetTickCount() - s_last_arm) > pdMS_TO_TICKS(2000)) {
                arm_right_chip();
            }
            continue;
        }
        s_stats.rx_bytes += (uint32_t)got;       /* raw evidence: anything on the wire? */
        for (int i = 0; i < got; i++) {
            if (makcu_link_parser_feed(&s_parser, buf[i], &frame)) {
                handle_frame(&frame);
            }
        }
    }
}

void makcu_link_bridge_init(void)
{
    if (s_ready) {
        return;
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
    /* The pins are board wiring, not a programming error: if they are rejected
     * (or the board revision routes the link elsewhere) the bridge must still
     * come up so the console stays usable. */
    const esp_err_t pin_err = uart_set_pin(LINK_UART, MAKCU_LINK_TX, MAKCU_LINK_RX,
                                           UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    if (pin_err != ESP_OK) {
        ESP_LOGW(TAG, "uart_set_pin(tx=%d rx=%d) failed: %s", MAKCU_LINK_TX, MAKCU_LINK_RX,
                 esp_err_to_name(pin_err));
    }
    makcu_link_parser_reset(&s_parser);
    memset(s_chunk_len, 0, sizeof(s_chunk_len));
    s_ep0_pending = false;
    s_session = 0;
    s_last_injected_len = 0;
    if (s_req_lock == NULL) {
        /* Priority inheritance: the console task (prio 10) must not be starved by
         * a lower-priority holder, and the holder must not be preempted into a
         * timeout by whoever it is blocking. */
        s_req_lock = xSemaphoreCreateMutex();
        if (s_req_lock == NULL) {
            ESP_LOGW(TAG, "request lock alloc failed: synchronous requests stay unsynchronised");
        }
    }
    s_ready = true;
    arm_right_chip();                            /* announce before the task starts */
    xTaskCreate(link_task, "km_link", 4096, NULL, 9, NULL);
    ESP_LOGI(TAG, "UART1 bridge up (tx=%d rx=%d)", MAKCU_LINK_TX, MAKCU_LINK_RX);
}
