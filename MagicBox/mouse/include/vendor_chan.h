/* Dedicated vendor channel between the two chips.
 *
 * Deliberately parallel to the 0xA2 motion/button stream: separate queue,
 * separate task, own sequence numbers.  The motion path must never be able to
 * starve the vendor path and vice versa (2026-11-12 incident: a synchronous
 * 0xA5 request inside the report path made HECATE feel "frozen").
 *
 * Link frames (5 Mbaud UART1, same 5A <cmd> <len:u16> framing as everything else):
 *
 *   0xB0  left -> right   <seq:u8><ep:u8><len:u16><data...>   host OUT downlink
 *   0xB1  right -> left   <seq:u8><ep:u8><len:u16><data...>   device IN uplink
 *   0xB2  right -> left   <seq:u8><rc:u8>                     accepted (rc=0)
 *
 * 0xB1 was already reserved in makcu_link.h (MAKCU_LINK_B1) but had no handler;
 * this module is its owner.
 *
 * Staged delivery (see mouse/README.md):
 *   MB_VENDOR_CHANNEL undefined -> legacy: vchan_out() forwards to the 0xA5
 *   queue path registered by the app (byte-for-byte the old behaviour).
 *   MB_VENDOR_CHANNEL=1         -> real 0xB0 frames + 0xB2 ACK.
 */
#ifndef VENDOR_CHAN_H
#define VENDOR_CHAN_H

#include <stdbool.h>
#include <stdint.h>

#define VCHAN_OUT 0xB0u
#define VCHAN_IN  0xB1u
#define VCHAN_ACK 0xB2u

#define VCHAN_QDEPTH 16

/* Transport used in legacy mode: enqueue the frame on the old 0xA5 path.
 * Returns 0 when accepted.  Installed by app_main at boot. */
typedef int  (*vchan_tx_fn)(uint8_t ep, const uint8_t *data, uint16_t len);
/* Uplink sink: called with every device-side vendor IN frame. */
typedef void (*vchan_in_fn)(uint8_t ep, const uint8_t *data, uint16_t len);

typedef struct {
    uint32_t tx_frames;     /* frames handed to the transport / 0xB0 frames    */
    uint32_t tx_fail;       /* transport refused (queue full, no link)         */
    uint32_t rx_frames;     /* device IN frames forwarded up                   */
    uint32_t ack_ok;        /* 0xB2 with rc=0                                  */
    uint32_t ack_timeout;   /* 0xB2 never arrived                              */
    uint32_t drop;          /* queue full, frame dropped                       */
    uint32_t retry;         /* right chip retried a busy OUT pool              */
    uint32_t rtt_max_us;    /* worst 0xB0 -> 0xB2 round trip                   */
} vchan_stats_t;

void vchan_set_legacy_tx(vchan_tx_fn fn);
void vchan_set_in_sink(vchan_in_fn fn);

/* Creates the queue/task in channel mode, verifies the transport in legacy mode.
 * Returns 0 when the channel is usable. */
int  vchan_init(void);

/* Send one vendor frame.  wait_ack_ms == 0 means fire-and-forget (the only sane
 * value on the 1 kHz path); in legacy mode the argument is ignored because that
 * path is already asynchronous. */
int  vchan_out(uint8_t ep, const uint8_t *data, uint16_t len, uint32_t wait_ack_ms);

/* Device-side vendor IN frame arriving from the right chip. */
void vchan_on_dev_in(uint8_t ep, const uint8_t *data, uint16_t len);

/* Link-level hook: registered for the 0xB0..0xB2 range only.  Never touches the
 * single custom-hook slot (that belongs to app_main's 0x1E/0x1F handler). */
bool vchan_on_frame(uint8_t cmd, const uint8_t *payload, uint16_t len);

vchan_stats_t vchan_stats(void);

#endif /* VENDOR_CHAN_H */
