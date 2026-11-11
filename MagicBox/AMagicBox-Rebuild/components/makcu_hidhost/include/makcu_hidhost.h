/* makcu_hidhost - USB host side of the box (right chip).
 *
 * M1 scope: install the ESP-IDF USB host stack, enumerate whatever mouse is
 * plugged into the A port, claim its HID interfaces and record the endpoints.
 * Report forwarding (0xA2), the EP0 tunnel (0xA1) and the OUT channel (0xA5)
 * build on this and land in M2..M4.
 *
 * The factory firmware keeps its host state in three bytes (see
 * makcu_right_frames.h): ready (device attached), session (used by 0x1A/0xA4)
 * and ep0_dir (reported by 0xA0).  We expose the same three values.
 */
#ifndef MAKCU_HIDHOST_H
#define MAKCU_HIDHOST_H

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"

#define MAKCU_HIDHOST_MAX_IF   4
#define MAKCU_HIDHOST_RAW_CONFIG_MAX 256   /* cloned composite configs are ~66 B */
#define MAKCU_HIDHOST_MAX_EP   8

typedef struct {
    uint8_t  iface;          /* bInterfaceNumber                        */
    uint8_t  alt;            /* bAlternateSetting                       */
    uint8_t  in_addr;        /* 0 = none                                */
    uint8_t  out_addr;       /* 0 = none                                */
    uint16_t in_mps;
    uint16_t out_mps;
    uint8_t  in_interval;
    uint8_t  subclass;
    uint8_t  protocol;
} makcu_hidhost_itf_t;

typedef struct {
    bool     attached;       /* enumerated and interfaces claimed */
    uint8_t  dev_addr;       /* USB address - also the "session" value  */
    uint16_t vid;
    uint16_t pid;
    uint8_t  itf_count;
    makcu_hidhost_itf_t itf[MAKCU_HIDHOST_MAX_IF];
} makcu_hidhost_info_t;

/* Install the host stack and start the daemon/client tasks.  Idempotent. */
esp_err_t makcu_hidhost_start(void);

/* True while a device is attached and its HID interfaces are claimed. */
bool makcu_hidhost_attached(void);

/* The factory's "session" byte; 0 when nothing is attached. */
uint8_t makcu_hidhost_session(void);

/* Snapshot of the enumeration result (safe to call any time). */
void makcu_hidhost_info(makcu_hidhost_info_t *out);

/* Sink for incoming HID reports: called from the USB client task context for
 * every completed IN transfer, with the endpoint address and the raw bytes.
 * Implementations must not block. */
typedef void (*makcu_hidhost_sink_t)(uint8_t ep, const uint8_t *data, uint8_t len);
void makcu_hidhost_set_sink(makcu_hidhost_sink_t sink);

/* Synchronous EP0 control transfer for the 0xA1 tunnel: `setup` is the 8-byte
 * USB setup packet, the response is copied into `out` (up to `cap` bytes).
 * Returns the number of bytes received, or -1 on failure/timeout. */
int makcu_hidhost_control(const uint8_t setup[8], uint8_t *out, size_t cap,
                          uint32_t timeout_ms);

/* Authoritative descriptor copies taken from the ESP-IDF host stack when the
 * device was enumerated.  These never go through the 0xA1 control tunnel, so
 * they cannot be corrupted by the 1 kHz report stream (that corruption is why
 * the cloned VID/PID used to drift to 0E8C:F0DB / 0ECC:F0DF). */
int makcu_hidhost_raw_device(uint8_t out[18]);          /* attach-time snapshot */
/* Re-read the device descriptor from the host stack *now*.  The snapshot can be
 * taken before the device settled (receivers re-enumerate), which is how the
 * clone ended up with ids like 0ECC:F0F0. */
int makcu_hidhost_live_device(uint8_t out[18]);
int makcu_hidhost_raw_config(uint8_t *out, size_t cap, uint16_t *total);

/* Submit one OUT transfer to the given endpoint (e.g. 0x05, the vendor
 * channel the HECATE Connect app writes configuration to).  Synchronous:
 * returns 0 on success, -1 on failure/timeout. */
int makcu_hidhost_out(uint8_t ep, const uint8_t *data, uint16_t len,
                      uint32_t timeout_ms);

/* Fire-and-forget variant: submits and returns immediately (0 = submitted).
 * The transfer is freed in its completion callback, so the link task never
 * blocks - that blocking is what made the host's vendor writes time out. */
int makcu_hidhost_out_async(uint8_t ep, const uint8_t *data, uint16_t len);

/* Counters for the bench (0x1C diagnostic frame): submit ok/fail, completions,
 * reports handed to the sink.  Values saturate at 255. */
void makcu_hidhost_sink_latency_add(uint32_t us);
void makcu_hidhost_sink_latency(uint16_t *p50_us, uint16_t *p99_us,
                                uint16_t *max_us, uint32_t *samples);

/* u32 精确计数：done vs fwd 的差 = "读到但没转发"的量，用来判断右片有没有读全。 */
void makcu_hidhost_stats32(uint32_t *submit_ok, uint32_t *submit_fail,
                           uint32_t *complete, uint32_t *forwarded);

void makcu_hidhost_stats(uint16_t *submit_ok, uint16_t *submit_fail,
                         uint16_t *complete, uint16_t *forwarded);

#endif /* MAKCU_HIDHOST_H */
