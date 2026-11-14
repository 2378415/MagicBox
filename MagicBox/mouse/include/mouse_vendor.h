/* Unified vendor-channel driver interface.
 *
 * The box sees three kinds of traffic on the vendor channel:
 *   - host OUT (HECATE Connect -> mouse config write, 64 B)
 *   - device IN (mouse -> host answer, 64 B)
 *   - the transport that carries them between the two chips
 *
 * This header is the boundary.  It contains *no* mouse-specific knowledge: the
 * protocol facts (frame layout, command table, reply expectations, rate limits)
 * live in the driver (src/g3mpro.c) so app_main.c and makcu_hiddev never have to
 * look inside a vendor frame again.
 */
#ifndef MOUSE_VENDOR_H
#define MOUSE_VENDOR_H

#include <stdbool.h>
#include <stdint.h>

/* Counters surfaced on the bench (mx.ox).  Field order is ABI: append only. */
typedef struct {
    uint32_t out_frames;      /* vendor OUT frames accepted from the host      */
    uint32_t in_frames;       /* vendor IN frames seen from the device         */
    uint32_t filtered;        /* frames the driver refused as non-vendor       */
    uint32_t heartbeat;       /* keepalive/poll frames (no reply expected)     */
    uint32_t dup;             /* identical OUT frame repeated back to back     */
    uint32_t resend;          /* retransmissions (R4, table driven)            */
    uint8_t  last_out_cmd;
    uint8_t  last_in_cmd;
    uint8_t  dpi_state;       /* G3MPRO_DPI_* (see g3mpro.h)                   */
    uint8_t  dpi_err_step;    /* which DPI step failed, 0 = none               */
    uint8_t  last_out[8];
    uint8_t  last_in[8];
    uint16_t last_len;
} mouse_vendor_stats_t;

typedef struct {
    const char *name;
    /* Identity match.  Receivers report a small family of ids (see the alias
     * policy in makcu_clone), so match() takes the *served* vid/pid. */
    bool     (*match)(uint16_t vid, uint16_t pid);
    /* The single definition of "this is a vendor frame" for this device. */
    bool     (*is_vendor_frame)(const uint8_t *data, uint16_t len);
    /* Routing predicate: any vendor-port traffic (looser than is_vendor_frame so
     * unsolicited notifications with a different length still bypass the mouse
     * path).  NULL = fall back to is_vendor_frame. */
    bool     (*is_vendor_port)(const uint8_t *data, uint16_t len);
    /* true = this command must be answered; only those may be retransmitted. */
    bool     (*expects_reply)(uint8_t cmd);
    /* Minimum spacing between two frames of this kind, milliseconds (0 = free).
     * This is a protocol fact measured on the wire, not a transport policy. */
    uint32_t (*min_gap_ms)(uint8_t cmd);
    /* Called for every accepted frame.  Must be cheap and non-blocking: no I/O. */
    void     (*on_host_out)(const uint8_t *data, uint16_t len);
    void     (*on_dev_in)(const uint8_t *data, uint16_t len);
    void     (*stats)(mouse_vendor_stats_t *out);
} mouse_vendor_drv_t;

/* Pick a driver for the identity the clone currently serves (0/0 = unknown).
 * Called once at boot and again after a re-clone; NULL driver = pass-through. */
void mouse_vendor_init(uint16_t vid, uint16_t pid);

/* NULL when nothing matched: callers must then behave exactly as before. */
const mouse_vendor_drv_t *mouse_vendor_current(void);

bool mouse_vendor_is_vendor_frame(const uint8_t *data, uint16_t len);
bool mouse_vendor_is_vendor_port(const uint8_t *data, uint16_t len);
void mouse_vendor_on_host_out(const uint8_t *data, uint16_t len);
void mouse_vendor_on_dev_in(const uint8_t *data, uint16_t len);
void mouse_vendor_stats(mouse_vendor_stats_t *out);

#endif /* MOUSE_VENDOR_H */
