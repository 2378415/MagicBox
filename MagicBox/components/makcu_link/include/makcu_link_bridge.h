/* Inter-chip link (UART1) bridge: driver, task, frame dispatch.
 *
 * Frame format (reversed/docs/uart1_link.md §8):  5A <cmd> <len:u16> <payload>
 *
 * What the original left chip does with each command (0x42013734, decompiled in
 * reversed/src/left/idf_freertos/42013734_uart1_frame_parse.c):
 *
 *   0xA0  EP0 tunnel.  len == 1 and payload[0] == 0x00 starts an EP0 IN session
 *         (it sets a "pending" flag and calls the usbd_ep0 helper); payload[0] ==
 *         0xFF - or a header-only frame - ends the session if one is pending.
 *         Implemented here as the same flag/counter state machine.  Injecting
 *         bytes into TinyUSB's control transfer needs a vendor request hook,
 *         which the device stack does not expose yet, so the tunnel currently
 *         tracks the handshake instead of carrying data.
 *   0xA2  HID report pass-through: payload = [ep, id, len, 0, data...].  The
 *         original filters on the session id (payload[1] == DAT_42001208) and on
 *         a non-zero length, then hands the data to the report writer.  Here the
 *         first frame adopts its session id, later frames must match, and the
 *         data is injected through makcu_link_set_report_sink() - on a HID build
 *         that is tud_hid_report(), on the bench it is a recorder the mx.ei
 *         probe can read.  The endpoint comparison in the original compares
 *         payload[4] (its first data byte) against the descriptor's endpoint
 *         address; which byte really carries the endpoint is still open, so the
 *         rebuild accepts any endpoint for now (see run-17 §3).
 *   0xA3  one-byte payload 0 (device re-attached handshake); counted.
 *   other counted and dropped.
 *
 * Wiring note: the original configures UART1 from two constants we could not
 * recover statically, so the rebuild uses MAKCU_LINK_TX/RX below.  Both are
 * overridable at build time (-DMAKCU_LINK_TX=...) once the real pins are known.
 */
#ifndef MAKCU_LINK_BRIDGE_H
#define MAKCU_LINK_BRIDGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Wiring of the inter-chip link, recovered from the two factory images:
 *
 *   left  uart_event_task (0x420139E4): uart_set_pin(1, *0x42001254, *0x42001250, ...)
 *                                      -> TX = GPIO2, RX = GPIO1
 *   right FUN_4200F644     : uart_set_pin(1, 1, 2, UART_PIN_NO_CHANGE)
 *                                      -> TX = GPIO1, RX = GPIO2   (crossed with the left)
 *   baud: left config word DAT_4200124C = 5,000,000 (the same constant appears once in
 *         the right image, at DAT_42000D14)
 *
 * Override with -DMAKCU_LINK_TX=... if a board revision is wired differently.
 */
#ifndef MAKCU_LINK_TX
#define MAKCU_LINK_TX 2
#endif
#ifndef MAKCU_LINK_RX
#define MAKCU_LINK_RX 1
#endif
#ifndef MAKCU_LINK_BAUD
#define MAKCU_LINK_BAUD 5000000
#endif

#define MAKCU_LINK_EP_COUNT  8
#define MAKCU_LINK_EP_CHUNK  256
#define MAKCU_LINK_INJECT_MAX 192

typedef struct {
    uint32_t frames;
    uint32_t ep0_requests;
    uint32_t ep0_in;              /* 0xA0 with direction 0x00 */
    uint32_t ep0_out;             /* 0xA0 with direction 0xFF / empty payload */
    uint32_t hid_chunks;          /* 0xA2 frames seen */
    uint32_t a3_frames;
    uint32_t unknown;
    uint32_t bad_magic;
    /* 2026-11-09 (run-17): tunnel state machine + report injection */
    uint32_t ep0_starts;          /* 0xA0 0x00 that opened a session */
    uint32_t ep0_ends;            /* 0xA0 0xFF that closed a pending session */
    uint32_t reports_injected;    /* 0xA2 frames that reached the report sink */
    uint32_t reports_dropped;     /* 0xA2 frames rejected (session/length) */
    uint32_t rx_bytes;            /* every byte UART1 delivered, valid frame or not */
} makcu_link_stats_t;

/* Install UART1 and start the bridge task. */
void makcu_link_bridge_init(void);

/* Send one frame on UART1 (builds the 5A header).  Returns bytes written. */
size_t makcu_link_send(uint8_t cmd, const uint8_t *payload, uint16_t len);

/* Frame counters since boot. */
makcu_link_stats_t makcu_link_stats(void);

/* Reassembled bytes for one endpoint (the descriptor clone input). */
size_t makcu_link_chunk(int endpoint, uint8_t *out, size_t cap);

/* Bench: drop the per-endpoint reassembly buffers (they accumulate across
 * sessions, exactly like the original's per-endpoint ring, so a test that wants
 * to assert "what just arrived" has to clear them first). */
void makcu_link_reset_chunks(void);

/* Report sink: the last byte sequence a 0xA2 frame delivered.  A HID build
 * installs the tud_hid_report() writer here; the bench leaves it NULL and reads
 * the payload back through makcu_link_last_injected() + the counters. */
typedef void (*makcu_link_report_fn)(uint8_t ep, const uint8_t *data, uint16_t len);
/* Frames the bridge does not handle itself are offered to this hook (return
 * true when consumed, which suppresses the unknown-command error frame). */
typedef bool (*makcu_link_custom_hook_t)(uint8_t cmd, const uint8_t *payload, uint16_t len);
/* Forget the adopted report session so the next report re-adopts it.  The right
 * chip's reports carry the USB device address as their session id; after the
 * mouse is replugged that address changes, and without this every report is
 * dropped as a session mismatch (the classic "replug once and the mouse stops"). */
/* The session id currently adopted from the report stream (0 = none yet). */
uint8_t makcu_link_session(void);

void makcu_link_reset_session(void);

void makcu_link_set_custom_hook(makcu_link_custom_hook_t fn);

/* Range-registered hooks (2026-11-12).  The single slot above is offered first
 * and keeps its owner (app_main's 0x1E/0x1F handler); a module that needs its
 * own commands registers a [cmd_first..cmd_last] range here instead of replacing
 * it.  Replacing it is what made the vendor channel starve the button path.
 * Up to MAKCU_LINK_HOOK_RANGES ranges; an overlapping registration is refused
 * (returns false) rather than silently shadowing someone else. */
bool makcu_link_add_custom_hook(uint8_t cmd_first, uint8_t cmd_last,
                                makcu_link_custom_hook_t fn);

/* Diagnostics: how many range hooks are registered (bench/self-check). */
bool makcu_link_custom_hook_count(int *ranges);

void makcu_link_set_report_sink(makcu_link_report_fn fn);   /* ep = 0xA2 payload[0] */

/* Bench: bytes of the most recent injected report (mx.ei). */
size_t makcu_link_last_injected(uint8_t *out, size_t cap);

/* Bench: enable/disable the periodic 0xA3 re-arm (mx.hb); returns previous. */
bool makcu_link_set_heartbeat(bool on);

/* Bench: pin the 0xA2 session id (mx.ss); force=false returns to first-frame adoption. */
void makcu_link_force_session(uint8_t session, bool force);

/* Bench: enable/disable handing 0xA2 payloads to the HID path (mx.hk). */
bool makcu_link_enable_sink(bool on);

/* Send a frame and wait for its reply; returns the reply payload length or -1. */
int makcu_link_request(uint8_t cmd, const uint8_t *payload, uint16_t len,
                       uint8_t *out, size_t cap, uint32_t timeout_ms);

/* Bench: command byte + payload of the last frame seen on UART1 (mx.lr). */
size_t makcu_link_last_frame(uint8_t *cmd, uint8_t *out, size_t cap);

/* Bench: is an EP0 tunnel session open? */
bool makcu_link_ep0_pending(void);

/* Bench self-test: enable the internal UART loopback, send one frame through it
 * and wait until the bytes were shifted out.  Loopback stays enabled so the RX
 * side has time to see the frame; call makcu_link_set_loopback(false) to stop. */
size_t makcu_link_loopback_selftest(const uint8_t *payload, uint16_t len);

/* Bench: parse a synthetic frame locally through a private parser (mx.lf).
 * No UART involved, so live traffic cannot interleave with it. */
size_t makcu_link_probe_frame(uint8_t cmd, const uint8_t *payload, uint16_t len);

/* Bench: build an arbitrary frame and push it through the internal loopback. */
size_t makcu_link_send_loopback(uint8_t cmd, const uint8_t *payload, uint16_t len);

/* Bench helper: route UART1 TX back into its own RX. */
void makcu_link_set_loopback(bool on);

#endif /* MAKCU_LINK_BRIDGE_H */
