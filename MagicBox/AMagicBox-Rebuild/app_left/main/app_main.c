/* app_left: device side of the MAKCU box.
 *
 * This file only wires up what already exists in the rebuild:
 *   - UART0 control port at 115200 8N1 (docs/00-facts.md §5)
 *   - text frame = '.km.<command>' terminated by CR, "km." stripped before
 *     dispatch (docs/10-abi.md)
 *   - command lookup through the extracted 43-entry table
 *   - handler dispatch through the extracted 27-entry opcode table
 *   - reply framing "km." + content + "\r\n>>> " (components/makcu_proto)
 *
 * The handlers themselves live in the makcu_* components and are still being
 * ported; a NULL slot means "not ported yet" and is reported once at boot
 * instead of silently answering nothing.
 */
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "driver/uart.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_system.h"
#include "soc/rtc_cntl_reg.h"
#include "nvs_flash.h"

#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "control_bin.h"
#include "btn_evt.h"
#include "btn_trace.h"
#include "makcu_mouse_hooks.h"
#include "makcu_sumv.h"
#include "makcu_sumv_hooks.h"
#include "makcu_evt_hooks.h"
#include "makcu_mouse.h"
#include "makcu_hiddev.h"
#include "makcu_keyboard.h"
#include "makcu_link_bridge.h"
#include "makcu_right_frames.h"   /* mx.rf: the right chip's reply builder */
#include "makcu_clone.h"
#include "tusb.h"
#include "makcu_reply.h"

#define CONTROL_UART      UART_NUM_0
/* 2026-11-10: 115200 -> 921600.  The control port is now also the low-latency
 * link for an external host (Android over the CH343; see control_bin.c), and at
 * 115200 a single text command already cost 1.4 ms on the wire.  The console baud
 * in sdkconfig is raised to the same value so ESP_LOG and the protocol share one
 * line without garbage. */
#define CONTROL_BAUD      921600
#define CONTROL_RX_BUF    2048
#define CONTROL_TX_BUF    1024     /* non-zero: a reply must not stall command intake */
#define CONTROL_LINE_MAX  256
#define CONTROL_PREFIX    "km."
#define CONTROL_TEXT_MARK '.'

static const char *TAG = "makcu-left";

static void mt_tap(uint8_t ep, const uint8_t *data, uint16_t len);   /* defined below */

/* sumv / makcu_mouse 注入路径的取样点：mx.mt 原本只在 link_report_to_mouse()
 * 里 tap，看不到注入。ep=0x00 标记"注入"，报告按 4 字节 int8 布局记录
 * （buttons, dx, dy, wheel）。 */
static void mouse_hook_tap(const makcu_report_t *r)
{
    if (r != NULL) {
        const uint8_t b[4] = { r->buttons, (uint8_t)r->dx, (uint8_t)r->dy, (uint8_t)r->wheel };
        mt_tap(0x00, b, 4);
        makcu_hiddev_report(r);
    }
}

/* Bench observability: remember the last HID mouse report so the mx.rp test
 * command can read it back.  A real HID layer would replace this hook. */
static void bench_report(const makcu_report_t *r)
{
    (void)r;                       /* makcu_mouse keeps its own copy */
}

/* Bench convenience: the control protocol is served on UART0 (the CH343 wiring
 * on the production box) *and* on the chip's own USB-Serial-JTAG port.  The
 * second path lets the rebuild be exercised with only the native USB cable
 * attached, which is how the bring-up bench is wired right now.  The final
 * firmware can drop it by removing MB_CONTROL_USB_JTAG below. */
#if MB_HID_DEVICE
#define MB_CONTROL_USB_JTAG 0   /* OTG owns D+/D- */
#else
#define MB_CONTROL_USB_JTAG 1
#endif

#if MB_CONTROL_USB_JTAG
#include "driver/usb_serial_jtag.h"
#endif

/* uart0_reply equivalent: the reply helpers hand us the finished frame. */
static void control_write(const void *data, size_t len)
{
    uart_write_bytes(CONTROL_UART, data, len);
#if MB_CONTROL_USB_JTAG
    usb_serial_jtag_write_bytes(data, len, 0);
#endif
}

/* Provided by the components as they get ported; weak so the app links early. */
__attribute__((weak)) void makcu_frame_router_init(void) {}

/* 0xA2 -> mouse commit layer (the original right chip uses queue + drain too).
 * Injecting straight into tud_hid_report() from the link task loses 99% of the
 * reports: TinyUSB claims the IN endpoint and does not release it when
 * usbd_edpt_xfer() refuses (measured 78 ok / 9399 failed, report run-20). */
/* Forward decimator: if the link delivers the same report twice (or the host
 * would accelerate our stream harder than the real mouse), dropping every Nth
 * report restores the physical speed while keeping the per-report magnitude. */
static uint32_t s_fwd_div = 1;

static uint32_t s_fwd_cnt;
static uint32_t s_fwd_drop;

/* Button / wheel bookkeeping (mx.bw): the pass-through must forward these too,
 * and a counter makes the check independent of when we happen to poll. */
static volatile uint32_t s_btn_events;   /* reports with a non-zero button byte */
static volatile uint32_t s_wheel_events; /* reports with a non-zero wheel byte */
static volatile int32_t  s_wheel_sum;    /* signed sum of wheel deltas */
static volatile uint8_t  s_last_buttons;
static volatile uint8_t  s_btn_or;      /* OR of every button byte seen (mx.bo) */

static int32_t s_res_x;      /* 12-bit -> 8-bit residue, keeps fast flicks intact */
static int32_t s_res_y;

static int32_t sign_extend_12(int32_t v)
{
    v &= 0x0FFF;
    return (v & 0x0800) ? (v - 0x1000) : v;
}

/* --------------------------- motion trace (mx.mt)
 * Timestamped tap on the 0xA2 path: every report that reaches the HID layer is
 * copied with its arrival time, so the forwarded motion can be analysed offline
 * (interval distribution, speed/acceleration profile, sensor quantisation).
 * The raw bytes are kept - the offline side decodes whatever layout the cloned
 * mouse uses.  3072 entries is ~3 s of 1 kHz traffic; 36 KB of .bss. */
#define MT_N 3072
typedef struct {
    uint32_t t_us;
    uint8_t  ep;
    uint8_t  len;
    uint8_t  data[8];
} mt_entry_t;
static mt_entry_t        s_mt[MT_N];
static volatile uint32_t s_mt_head;     /* next write slot */
static volatile uint32_t s_mt_count;    /* stored entries, <= MT_N */
static volatile bool     s_mt_on;
static char              s_mt_dump[600];  /* one reply chunk (MAKCU_REPLY_MAX-11) */

static void mt_tap(uint8_t ep, const uint8_t *data, uint16_t len)
{
    if (!s_mt_on) {
        return;
    }
    mt_entry_t *e = &s_mt[s_mt_head];
    e->t_us = (uint32_t)esp_timer_get_time();
    e->ep = ep;
    e->len = (uint8_t)((len > sizeof(e->data)) ? sizeof(e->data) : len);
    memcpy(e->data, data, e->len);
    s_mt_head = (s_mt_head + 1u) % MT_N;
    if (s_mt_count < MT_N) {
        s_mt_count++;
    }
}

/* Pure decode (no residue, no side effects): 12-bit packed X/Y -> int8. */
static void unpack_report_12bit(const uint8_t *data, uint16_t len,
                                int8_t *dx, int8_t *dy, int8_t *wheel)
{
    s_last_buttons = data[0];
    s_btn_or |= data[0];
    if (data[0] != 0) {
        s_btn_events++;
    }
    if (len >= 5 && data[4] != 0) {
        s_wheel_events++;
        s_wheel_sum += (int8_t)data[4];
    }

    const int32_t x12 = sign_extend_12((int32_t)data[1] | ((int32_t)(data[2] & 0x0F) << 8));
    const int32_t y12 = sign_extend_12((int32_t)(data[2] >> 4) | ((int32_t)data[3] << 4));
    int32_t x = x12, y = y12;
    if (x > 127) { x = 127; }
    if (x < -128) { x = -128; }
    if (y > 127) { y = 127; }
    if (y < -128) { y = -128; }
    *dx = (int8_t)x;
    *dy = (int8_t)y;
    *wheel = (len >= 5) ? (int8_t)data[4] : 0;
}

static int8_t take_i8(int32_t *res)
{
    int32_t v = *res;
    if (v > 127) { v = 127; }
    if (v < -128) { v = -128; }
    *res -= v;
    return (int8_t)v;
}

/* 0xA2 -> mouse commit layer.
 *
 * The real mouse reports 12-bit signed X/Y packed into three bytes:
 *   byte1 = x[7:0]
 *   byte2 = x[11:8] | (y[3:0] << 4)
 *   byte3 = y[11:4]
 *   byte4 = wheel
 * Reading byte2 as an 8-bit Y axis is what made Y run 16x too fast (its low four
 * bits sit in the high nibble) while X felt slow. */
/* ---------------------------------------------------------- auto clone
 *
 * The factory left chip does not ship a fixed identity: it asks the right chip to
 * run USB control transfers against the real mouse (the 0xA1 EP0 tunnel) and
 * clones whatever descriptors come back.  We do the same at boot, before
 * makcu_hiddev_init(), so the device enumerates with the real identity and no
 * re-enumeration trick is needed.
 */
static uint8_t utf16le_to_ascii(const uint8_t *in, size_t len, char *out, size_t cap)
{
    size_t o = 0;
    for (size_t i = 2; i + 1 < len && o + 1 < cap; i += 2) {
        const uint8_t ch = in[i];
        if (ch == 0) {
            break;
        }
        out[o++] = (char)ch;
    }
    out[o] = 0;
    return (uint8_t)o;
}

static int tunnel_get(uint8_t type, uint8_t index, uint16_t value, uint16_t length,
                      uint8_t *out, size_t cap)
{
    /* bmRequestType 0x80 = device-to-host, standard, device */
    uint8_t bm = 0x80;
    /* The HID report descriptor lives on the *interface*: composite devices
     * (e.g. a wireless mouse receiver with two HID interfaces) reject the
     * device-recipient form outright. */
    if (type == 0x22) {
        bm = 0x81;
    }
    (void)type;
    const uint8_t setup[8] = {
        bm, 0x06,
        (uint8_t)(value & 0xFF), (uint8_t)(value >> 8),
        (uint8_t)(index & 0xFF), (uint8_t)(index >> 8),
        (uint8_t)(length & 0xFF), (uint8_t)(length >> 8),
    };
    return makcu_link_request(0xA1, setup, sizeof(setup), out, cap, 400);
}

static volatile int s_autoclone_status;   /* 0=未跑 1=成功 2=回退 */

/* A device may expose several HID interfaces (the G3M PRO receiver has two).
 * Our USB stack serves one interface, so pick the one whose report descriptor
 * describes a mouse (05 01 09 02) and crop the configuration around it. */
static bool report_is_mouse(const uint8_t *rep, size_t len)
{
    for (size_t i = 0; i + 3 < len; i++) {
        if (rep[i] == 0x05 && rep[i + 1] == 0x01 && rep[i + 2] == 0x09 && rep[i + 3] == 0x02) {
            return true;
        }
    }
    return false;
}

/* Big buffers live in .bss: the console task stack is small (a composite mouse
 * needs a 128-byte config, a 128-byte report descriptor and a 192-byte tunnel
 * frame, which overflowed km_uart0 when they were automatic). */
static uint8_t s_ac_buf[MAKCU_LINK_INJECT_MAX];
static uint8_t s_ac_cfg[MAKCU_CLONE_CONFIG_MAX];
static uint8_t s_ac_single[MAKCU_CLONE_CONFIG_MAX];
static uint8_t s_ac_rep[MAKCU_CLONE_REPORT_MAX];
/* Captured HID interfaces of the device (mouse + keyboard/vendor).  Stored
 * separately because makcu_clone_adopt() clears the clone before filling it. */
static uint8_t  s_ac_if_n;
static uint8_t  s_ac_if_ep[MAKCU_CLONE_IF_MAX];
static uint8_t  s_ac_if_rid[MAKCU_CLONE_IF_MAX];
static uint16_t s_ac_if_len[MAKCU_CLONE_IF_MAX];
static uint8_t  s_ac_if_rep[MAKCU_CLONE_IF_MAX][MAKCU_CLONE_REPORT_MAX];

/* Which source produced the descriptors (mx.vs): 1 = right chip's local host
 * stack (0x1B/0x1D), 2 = 0xA1 control tunnel fallback, 0 = failed. */
static volatile uint8_t s_src_dev, s_src_cfg;

/* Read the device descriptor from the right chip's own host stack.  It never
 * crosses the control tunnel, so the 1 kHz report stream cannot corrupt it. */
static int raw_device_get(uint8_t out[18])
{
    uint8_t dummy = 0;
    const int n = makcu_link_request(0x1B, &dummy, 1, out, 18, 300);
    if (n >= 18 && out[0] == 18 && out[1] == 0x01 && out[17] >= 1) {
        return 18;
    }
    return -1;
}

/* Read the configuration descriptor in fragments; verifies total length, the
 * offset echo and wTotalLength before accepting it. */
static int raw_config_get(uint8_t *out, size_t cap)
{
    size_t got = 0;
    uint16_t total = 0;

    for (int guard = 0; guard < 16; guard++) {
        uint8_t req[3] = { (uint8_t)(got & 0xFF), (uint8_t)(got >> 8), 64 };
        uint8_t rep[MAKCU_LINK_MAX_FIELD];
        const int n = makcu_link_request(0x1D, req, 3, rep, sizeof(rep), 300);
        if (n < 5) {
            return -1;
        }
        const uint16_t t   = (uint16_t)(rep[0] | (rep[1] << 8));
        const uint16_t off = (uint16_t)(rep[2] | (rep[3] << 8));
        if (t < 9 || t > cap || off != got) {
            return -1;
        }
        total = t;
        const size_t chunk = (size_t)n - 4u;
        memcpy(out + got, &rep[4], chunk);
        got += chunk;
        if (got >= total) {
            break;
        }
    }
    if (got < 9 || out[1] != 0x02) {
        return -1;
    }
    const size_t wt = (size_t)(out[2] | (out[3] << 8));
    if (wt < 9 || wt > got || wt != total) {
        return -1;
    }
    return (int)wt;
}

/* The cloned configuration is served to the host, so we are free to move the
 * vendor OUT endpoint to a low endpoint number: the ESP32-S3 DWC2 core has fewer
 * OUT endpoints than IN ones, and opening 0x05 fails (which aborts TinyUSB's
 * HID class init *after* the IN endpoint was opened - the exact symptom of
 * "IN reports work, OUT never completes"). The right chip still submits to the
 * mouse's real 0x05, so only the host-facing address changes. */
static void patch_out_endpoint(uint8_t *cfg, size_t cfg_len)
{
    for (size_t i = 0; i + 6 < cfg_len; ) {
        const uint8_t dlen = cfg[i];
        if (dlen < 2) {
            return;
        }
        if (cfg[i + 1] == 0x05 && (cfg[i + 2] & 0x80) == 0 && cfg[i + 2] != 0x00) {
            if (cfg[i + 2] == 0x05) {
                cfg[i + 2] = 0x03;      /* vendor OUT: 0x05 -> 0x03 */
            }
        }
        i += dlen;
    }
}

static bool autoclone_from_link(void)
{
    uint8_t *buf = s_ac_buf;
    uint8_t zero = 0;

    /* Wait for the right chip to hold a device (0xA0 replies 0x00). */
    bool present = false;
    for (int i = 0; i < 80; i++) {   /* up to 8 s: the mouse may need time after a board reset */
        if (makcu_link_request(0xA0, &zero, 1, buf, sizeof(buf), 200) == 1 && buf[0] == 0x00) {
            present = true;
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    /* Our 0xA0 state probe is also the EP0 session start: close it again on every
     * path (including "no device") so the link is left as we found it. */
    {
        const uint8_t close = 0xFF;
        (void)makcu_link_request(0xA0, &close, 1, NULL, 0, 100);
    }
    if (!present) {
        return false;
    }

    uint8_t dev[18];
    /* The control tunnel is the trustworthy source for the device descriptor:
     * reading it out of the host stack's cached struct returned bit-flipped ids
     * (0E8C / 0ECC / 06CC / 068C instead of 320F), which then propagated into
     * the clone.  0x1B is kept as a fallback and a cross-check only. */
    s_src_dev = 2;
    int n = tunnel_get(0x01, 0, 0x0100, sizeof(dev), dev, sizeof(dev));
    if (n < 18 || dev[0] != 18 || dev[1] != 0x01) {
        s_src_dev = 1;
        n = raw_device_get(dev);
    }
    if (n < 18 || dev[0] != 18 || dev[1] != 0x01) {
        s_src_dev = 0;
        return false;
    }

    uint8_t *cfg = s_ac_cfg;
    /* Same reasoning as the device descriptor: the control tunnel is the source
     * that was verified end to end, and the configuration descriptor decides how
     * the host binds endpoints and HID collections.  Use it first; the local
     * snapshot (0x1D) stays as a fallback. */
    s_src_cfg = 2;
    n = tunnel_get(0x02, 0, 0x0200, (uint16_t)sizeof(s_ac_cfg), cfg, sizeof(s_ac_cfg));
    if (n < 9 || cfg[1] != 0x02) {
        s_src_cfg = 1;
        n = raw_config_get(cfg, sizeof(s_ac_cfg));
    }
    if (n < 9 || cfg[1] != 0x02) {
        s_src_cfg = 0;
        return false;
    }
    size_t cfg_len = (size_t)n;
    const size_t cfg_total = (size_t)(cfg[2] | (cfg[3] << 8));
    if (cfg_total < cfg_len) {
        cfg_len = cfg_total;                 /* trust wTotalLength when it is shorter */
    }

    /* Walk the configuration: for every HID interface read its report descriptor
     * and keep the first one that looks like a mouse. */
    uint8_t *rep = s_ac_rep;
    s_ac_if_n = 0;
    size_t rep_got = 0;
    uint8_t mouse_iface = 0;
    uint8_t mouse_ep = 0x81;
    bool found = false;

    size_t iface_off = 0, hid_off = 0, ep_off = 0;
    size_t mouse_iface_off = 0;
    uint8_t iface_num = 0;
    uint16_t hid_rep_len = 0;
    uint8_t ep_addr = 0;

    for (size_t i = 0; i + 1 < cfg_len;) {
        const uint8_t dlen = cfg[i];
        const uint8_t dtype = cfg[i + 1];
        if (dlen < 2) {
            break;
        }
        if (dtype == 0x04) {                       /* interface */
            iface_off = i;
            iface_num = cfg[i + 2];
            hid_off = 0;
            hid_rep_len = 0;
            ep_off = 0;
            ep_addr = 0;
        } else if (dtype == 0x21 && i + 9 <= cfg_len) {  /* HID */
            hid_off = i;
            hid_rep_len = (uint16_t)(cfg[i + 7] | (cfg[i + 8] << 8));
        } else if (dtype == 0x05 && i + 2 < cfg_len) {   /* endpoint */
            const uint8_t addr = cfg[i + 2];
            if ((addr & 0x80) != 0 && ep_off == 0) {     /* first IN endpoint */
                ep_off = i;
                ep_addr = addr;
            }
        }
        i += dlen;

        /* Evaluate at the end of an interface block (next interface or the end). */
        const bool block_end = (i >= cfg_len) || (cfg[i + 1] == 0x04);
        if (block_end && hid_off != 0 && hid_rep_len != 0) {
            const uint16_t want = (hid_rep_len > sizeof(s_ac_rep)) ? (uint16_t)sizeof(s_ac_rep) : hid_rep_len;
            const int rn = tunnel_get(0x22, iface_num, 0x2200, want, rep, sizeof(s_ac_rep));
            if (rn > 0) {
                /* keep every interface (mouse first is not guaranteed); the mouse
                 * one also becomes the "primary" identity served by the stack. */
                if (s_ac_if_n < MAKCU_CLONE_IF_MAX) {
                    uint8_t rid = 0;
                    for (int k = 0; k + 1 < rn; k++) {
                        if (rep[k] == 0x85) { rid = rep[k + 1]; break; }
                    }
                    const uint8_t ep = (ep_off != 0) ? ep_addr : 0x81;
                    memcpy(s_ac_if_rep[s_ac_if_n], rep, (size_t)rn);
                    s_ac_if_len[s_ac_if_n] = (uint16_t)rn;
                    s_ac_if_ep[s_ac_if_n] = ep;
                    s_ac_if_rid[s_ac_if_n] = rid;
                    s_ac_if_n++;
                    if (!found && report_is_mouse(rep, (size_t)rn)) {
                        rep_got = (size_t)rn;
                        mouse_iface = iface_num;
                        mouse_ep = ep;
                        mouse_iface_off = iface_off;
                        found = true;
                    }
                }
            }
        }
    }
    if (!found) {
        return false;
    }
    (void)mouse_ep;

    /* Crop the configuration to just this interface: config + interface + HID +
     * endpoint(s).  Interface numbers are renumbered to 0 since we serve one. */
    uint8_t *single = s_ac_single;
    size_t out = 0;
    /* Known-good single-interface skeleton (identical to the 30FA fixture that is
     * verified working on this bench): 34 bytes, boot mouse, 64-byte IN packet.
     * Only wDescriptorLength is patched to the real report length, so this
     * isolates "our configuration template" from "the device's descriptors". */
    static const uint8_t tmpl[34] = {
        0x09, 0x02, 0x22, 0x00, 0x01, 0x01, 0x00, 0xA0, 0x32,
        0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x01, 0x02, 0x00,
        0x09, 0x21, 0x11, 0x01, 0x00, 0x01, 0x22, 0x00, 0x00,
        0x07, 0x05, 0x81, 0x03, 0x40, 0x00, 0x01,
    };
    memcpy(single, tmpl, sizeof(tmpl));
    single[25] = (uint8_t)(rep_got & 0xFF);
    single[26] = (uint8_t)(rep_got >> 8);
    out = sizeof(tmpl);
    (void)mouse_iface_off;
    (void)mouse_ep;

    /* Any Report ID item (0x85) means reports must carry the id byte. */
    uint8_t report_id = 0;
    for (size_t i = 0; i + 1 < rep_got; i++) {
        if (rep[i] == 0x85) {
            report_id = rep[i + 1];
            break;
        }
    }

    char mfr[24] = "", prod[24] = "", serial[24] = "";
    if (dev[14] != 0) {
        n = tunnel_get(0x03, 0, (uint16_t)(0x0300 | dev[14]), 0x3F, buf, sizeof(buf));
        if (n > 2) { utf16le_to_ascii(buf, (size_t)n, mfr, sizeof(mfr)); }
    }
    if (dev[15] != 0) {
        n = tunnel_get(0x03, 0, (uint16_t)(0x0300 | dev[15]), 0x3F, buf, sizeof(buf));
        if (n > 2) { utf16le_to_ascii(buf, (size_t)n, prod, sizeof(prod)); }
    }
    if (dev[16] != 0) {
        n = tunnel_get(0x03, 0, (uint16_t)(0x0300 | dev[16]), 0x3F, buf, sizeof(buf));
        if (n > 2) { utf16le_to_ascii(buf, (size_t)n, serial, sizeof(serial)); }
    }
    if (serial[0] == 0) {
        /* The mouse has no serial of its own; use this unit's persistent random
         * one so the host sees a stable, unique instance per box. */
        makcu_clone_serial_get(serial);
    }

    /* NOTE: the interface is cropped to one because the USB stack runs a single
     * HID instance; the *full* 66-byte composite config is captured in
     * s_ac_cfg/s_ac_if_* for the dual-instance work (see D37). */
#if defined(MB_DUAL_IF)
    /* Serve the device's own composite configuration (mouse + keyboard/vendor)
     * so the host can talk to MI_01 as well; the per-interface report
     * descriptors come from s_ac_if_*. */
    patch_out_endpoint(cfg, cfg_len);
    if (!makcu_clone_adopt(dev, sizeof(dev), cfg, cfg_len, rep, rep_got,
                           mfr, prod, serial, report_id)) {
        return false;
    }
    for (uint8_t k = 0; k < s_ac_if_n && k < MAKCU_CLONE_IF_MAX; k++) {
        (void)makcu_clone_set_interface(k, s_ac_if_ep[k], s_ac_if_rep[k],
                                        s_ac_if_len[k], s_ac_if_rid[k]);
    }
#else
    if (!makcu_clone_adopt(dev, sizeof(dev), single, out, rep, rep_got,
                           mfr, prod, serial, report_id)) {
        return false;
    }
    (void)cfg; (void)cfg_len;
#endif
    return true;
}

/* Host wrote to a HID OUT endpoint (vendor channel): forward it to the right
 * chip as 0xA5 <ep> <len:u16> <data...> so it reaches the mouse. */
static volatile uint32_t s_out_reports;   /* OUT reports received from the host   */
static volatile uint32_t s_out_ok;        /* ... that the right chip acknowledged */
static volatile uint32_t s_in82;
static uint8_t s_in82_last[8];          /* 0x82 IN frames forwarded to the host */
static uint8_t s_out_last[8];
static volatile uint8_t s_out_ack = 0xFD;   /* last 0xA5 reply: rc, 0xFE=timeout */

/* OUT forwarding is asynchronous: the TinyUSB callback must return immediately,
 * otherwise the next host write cannot be armed and the acks start timing out
 * (measured: only 66 of 184 writes were acknowledged while it blocked). */
#define OUTQ_DEPTH   6
#define OUTQ_MAX     80
typedef struct {
    uint8_t  ep;
    uint16_t len;
    uint8_t  data[OUTQ_MAX];
} out_item_t;
static QueueHandle_t s_outq;
static volatile uint32_t s_out_dropped;

static void out_to_right(uint8_t instance, uint8_t report_id, const uint8_t *data, uint16_t len)
{
    s_out_reports++;
    for (uint8_t i = 0; i < 8u && i < len; i++) { s_out_last[i] = data[i]; }
    (void)report_id;
    const makcu_clone_t *c = makcu_clone_get();
    (void)instance;
    (void)c;
    /* The mouse's own vendor OUT endpoint (the host-facing number may differ). */
    uint8_t ep = 0x05;
    if (s_outq == NULL) {
        return;
    }
    out_item_t item;
    item.ep = ep;
    item.len = (len > OUTQ_MAX) ? OUTQ_MAX : len;
    memcpy(item.data, data, item.len);
    if (xQueueSend(s_outq, &item, 0) != pdTRUE) {
        s_out_dropped++;
    }
}

static void out_worker(void *arg)
{
    (void)arg;
    out_item_t item;
    for (;;) {
        if (xQueueReceive(s_outq, &item, portMAX_DELAY) != pdTRUE) {
            continue;
        }
        uint8_t payload[OUTQ_MAX + 3];
        payload[0] = item.ep;
        payload[1] = (uint8_t)(item.len & 0xFF);
        payload[2] = (uint8_t)(item.len >> 8);
        memcpy(&payload[3], item.data, item.len);
        uint8_t ack[8];
        /* The right chip may block its link task for up to 300 ms while the
         * USB host submits the OUT transfer, so wait longer than that here -
         * otherwise the reply arrives just after we gave up (measured: ok was
         * only 30/106 with a 300 ms wait). */
        const int n = makcu_link_request(0xA5, payload, (uint16_t)(item.len + 3),
                                         ack, sizeof(ack), 600);
        if (n > 0) {
            s_out_ok++;
            s_out_ack = (n >= 3) ? ack[0] : 0xFFu;
        } else {
            s_out_ack = 0xFEu;
        }
    }
}

/* 0x1E <present>: the right chip tells us the physical device appeared or
 * disappeared.  Re-enumerate our own USB device accordingly - that is exactly
 * what "replug the left cable" does by hand, and it is the only thing that
 * clears the host-side HID state which otherwise stops delivering input for
 * good after the device is unplugged once. */
static bool s_usb_disconnected;
static volatile bool s_reclone_check;
static bool clone_matches_device(void);   /* defined below, used by heal_task */

/* Runs outside the link task so the tunnel requests cannot deadlock it.
 *
 * 只在收到"设备出现"通知时检查一次：曾经试过"每 5 s 自查 if_count==0"，结果在回归
 * 跑到一半时触发重克隆 + tud_disconnect/connect，控制台日志插进协议流、HID 重新枚举，
 * 直接打翻逐字节比对的用例。残 clone 的兜底靠开机那一层（见 app_main 的 cloned 判定）。 */
static void heal_task(void *arg)
{
    (void)arg;
    for (;;) {
        vTaskDelay(pdMS_TO_TICKS(200));
        if (!s_reclone_check) {
            continue;
        }
        s_reclone_check = false;
        vTaskDelay(pdMS_TO_TICKS(250));      /* let the report stream settle */

        bool changed = false;
        if (!clone_matches_device()) {
            ESP_LOGW(TAG, "clone does not match the device: re-cloning");
            if (autoclone_from_link()) {
                changed = true;
            }
        }
        if (changed) {
            tud_disconnect();
            vTaskDelay(pdMS_TO_TICKS(150));
            tud_connect();
            ESP_LOGW(TAG, "re-enumerated with the new clone");
        }
    }
}

/* Compare the served clone with what the device reports right now.  A mismatch
 * means the clone came from a different (or older) mouse - e.g. boot-time
 * auto-clone failed because the mouse was not plugged in yet, and the firmware
 * fell back to a stale fixture whose report format does not match (16-bit vs
 * 12-bit deltas => "the cursor moves too slow" and the buttons stop working). */
static bool clone_matches_device(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c == NULL || !c->valid) {
        return false;
    }
    uint8_t dev[18];
    const int n = tunnel_get(0x01, 0, 0x0100, sizeof(dev), dev, sizeof(dev));
    if (n < 18 || dev[0] != 18 || dev[1] != 0x01) {
        return true;                 /* cannot check: do not force a re-clone */
    }
#if defined(MB_DUAL_IF)
    if (c->if_count == 0) {
        return false;                /* 复合构建下没有接口 = 残 clone，必须重来 */
    }
#endif
    const uint16_t vid = (uint16_t)(dev[8] | (dev[9] << 8));
    const uint16_t pid = (uint16_t)(dev[10] | (dev[11] << 8));
    /* Accept the alias-mapped identity as a match (0E8C.. -> 320F:706E). */
    uint8_t mapped[18];
    memcpy(mapped, dev, sizeof(mapped));
    (void)makcu_clone_apply_id_policy(mapped);
    if (c->device[8] != mapped[8] || c->device[9] != mapped[9] ||
        c->device[10] != mapped[10] || c->device[11] != mapped[11]) {
        return false;
    }
    /* Same identity: the report descriptor length must match too, otherwise the
     * clone's report format is wrong for this device. */
    const uint8_t ridx = (c->if_count > 0) ? (uint8_t)(c->ifs[0].report_len) : 0u;
    (void)ridx;
    return true;
}

static void handle_presence(uint8_t present)
{
    /* The right chip re-enumerates the mouse after a replug, which gives it a new
     * USB address - and that address is the session id carried in every 0xA2
     * report.  Re-adopt it, otherwise every report after the replug is dropped. */
    makcu_link_reset_session();

    if (present == 0u) {
        tud_disconnect();
        s_usb_disconnected = true;
        ESP_LOGW(TAG, "device gone: disconnected from the host");
        return;
    }
    /* The clone check needs the EP0 tunnel, and tunnel_get() blocks waiting for a
     * reply that only THIS task can parse - doing it here deadlocks the link task
     * for the whole timeout and the RX ring overflows (reports are lost, which the
     * user sees as "the cursor is much slower than the real mouse").  Hand the
     * work to a dedicated task instead. */
    s_reclone_check = true;

    if (s_usb_disconnected) {
        tud_disconnect();
        vTaskDelay(pdMS_TO_TICKS(150));
        s_usb_disconnected = false;
        tud_connect();
        ESP_LOGW(TAG, "device back: re-enumerating on the host");
    }
}

static bool custom_hook(uint8_t cmd, const uint8_t *payload, uint16_t len)
{
    if (cmd == 0x1E && len >= 1u) {
        handle_presence(payload[0]);
        return true;
    }
    if (cmd == 0x1F && len > 0u) {
        /* Right-chip log line: print it here so a single console shows both. */
        char line[200];
        const size_t n = (len < sizeof(line) - 6) ? len : sizeof(line) - 6;
        memcpy(line, "[R] ", 4);
        memcpy(line + 4, payload, n);
        line[4 + n] = '\n';
        uart_write_bytes(UART_NUM_0, line, 5 + n);
        return true;
    }
    return false;
}

/* --------------------------- latency instrumentation (mx.lat)
 * Two clocks are not synchronised across the chips, so absolute end-to-end latency
 * cannot be measured.  What CAN be measured without any protocol change:
 *   - the interval between consecutive reports (=> effective report rate),
 *   - how long this chip spends per report,
 *   - (queried over the link) how long the right chip spends forwarding one report.
 * Together those point at whichever side is the bottleneck.  Sampled 1 in 4. */
#define LAT_IB   256                 /* interval buckets: 100 us */
#define LAT_PB   256                 /* process buckets:  10 us  */
static uint32_t s_lat_int[LAT_IB];
static uint32_t s_lat_proc[LAT_PB];
static uint32_t s_lat_n;
static int64_t  s_lat_last_us;
static uint8_t  s_lat_skip;

static uint32_t lat_pct(const uint32_t *hist, int buckets, int pct)
{
    uint32_t total = 0, acc = 0;
    for (int i = 0; i < buckets; i++) { total += hist[i]; }
    if (total == 0) { return 0; }
    for (int i = 0; i < buckets; i++) {
        acc += hist[i];
        if (acc * 100u >= total * (uint32_t)pct) { return (uint32_t)(i + 1); }
    }
    return (uint32_t)buckets;
}

static void lat_sample(int64_t t0, int64_t t1)
{
    if (++s_lat_skip < 4) {
        return;
    }
    s_lat_skip = 0;
    const int64_t dt = t1 - t0;
    uint32_t b = (uint32_t)(dt / 10);
    if (b >= LAT_PB) { b = LAT_PB - 1; }
    s_lat_proc[b]++;
    if (s_lat_last_us != 0) {
        uint32_t ib = (uint32_t)((t0 - s_lat_last_us) / 100);
        if (ib >= LAT_IB) { ib = LAT_IB - 1; }
        s_lat_int[ib]++;
    }
    s_lat_last_us = t1;
    s_lat_n++;
}

/* --------------------- sumv 屏蔽层的状态与计数
 * sumv 运行期间真实鼠标的运动被丢弃（按键/滚轮透传），这里只保留"上一次的按键
 * 状态"用来判断是否需要把一条零位移报告发出去。 */
static uint8_t s_mute_btn;
/* 短按抗抖：松开后这段时间内的再次按下视为微动抖动（真实鼠标透传路径用） */
#define RELEASE_GUARD_MS 20u
static uint32_t s_btn_bounce_swallowed;
/* 诊断计数：看清"报告有没有从左片进来" */
static uint32_t s_link_frames;        /* 进入 link_report_to_mouse 的帧数 */
static uint32_t s_link_btn_nonzero;   /* 其中按键字节非 0 的帧数 */
static uint32_t s_link_btn_changes;
static volatile uint8_t s_link_last_ep;
static volatile uint8_t s_link_last_len;
static uint8_t s_link_last_data[8];   /* 其中按键字节发生变化的帧数 */

/* 0x45 用：which 0=link_frames 1=btn_nonzero 2=fwd_drop 3=swallowed */
uint32_t btn_diag_counts(uint8_t which)
{
    switch (which) {
    case 0: return s_link_frames;
    case 1: return s_link_btn_nonzero;
    case 2: return s_fwd_drop;
    case 3: return s_btn_bounce_swallowed;
    default: return 0;
    }
}

/* 最近一帧进入 ep=0x82 的原始报告（8 字节） */
extern uint8_t s_in82_last[8];
void btn_diag_last_frame(uint8_t *out)
{
    if (out == NULL) { return; }
    for (int i = 0; i < 8; i++) { out[i] = s_link_last_data[i]; }
}

uint8_t btn_diag_last_ep(void) { return s_link_last_ep; }
uint8_t btn_diag_last_len(void) { return s_link_last_len; }
uint32_t btn_diag_counts(uint8_t which);

static void sumv_dropped(void)
{
    makcu_sumv_note_mute_dropped();
}

static void sumv_forwarded(void)
{
    makcu_sumv_note_button_forwarded();
}

/* .km.move 等旧入口在 sumv 运行期间被拒（避免双运动源互相拉扯）。 */
static makcu_mouse_move_fn s_move_hook_orig;

static int move_hook_guarded(void *dev, int16_t dx, int16_t dy, uint32_t mode)
{
    if (makcu_sumv_active()) {
        return -1;
    }
    return (s_move_hook_orig != NULL) ? s_move_hook_orig(dev, dx, dy, mode) : -1;
}

/* 文本层通过 hook 调用引擎，避免 makcu_proto 反向依赖组件。 */
static void btn_evt_ctl_adapter(bool enable, uint8_t mask, bool push, bool consume)
{
    btn_evt_ctl(enable, mask, push, consume);
}

static bool sumv_start_adapter(int16_t dx, int16_t dy, uint16_t speed,
                              uint16_t dur_ms, uint8_t mode, uint8_t seed)
{
    makcu_sumv_req_t req;
    memset(&req, 0, sizeof(req));
    req.dx = dx;
    req.dy = dy;
    req.speed = speed;              /* 0 → 引擎用默认 400 counts/s */
    req.dur_ms = dur_ms;
    req.mode = mode;
    req.seed = seed;
    return makcu_sumv_start(&req);
}

static void link_report_to_mouse(uint8_t ep, const uint8_t *data, uint16_t len)
{
    if (data == NULL || len < 4) {
        return;
    }
    mt_tap(ep, data, len);          /* mx.mt: record what the HID layer is about to get */
    if (makcu_sumv_active()) {
        /* sumv 独占运动权：真实鼠标的 X/Y 丢掉，按键与滚轮照常透传。
         * 只在 (按键变化 | 滚轮 | pan) 时才发——否则真实鼠标 540-900 条/秒的
         * 零位移报告会把 1000 槽/s 的端点时隙吃光，把 sumv 的 1 kHz 挤掉。 */
        const uint8_t nbytes = makcu_hiddev_report_bytes();
        uint8_t btn;
        int8_t wheel;
        bool has_pan = false;
        int8_t pan = 0;
        if (nbytes >= 7 && len >= 7) {
            btn = (uint8_t)(data[0] & 0x1F);
            wheel = (int8_t)data[5];
            pan = (int8_t)data[6];
            has_pan = true;
        } else if (len >= 5) {
            btn = data[0];
            wheel = (int8_t)data[4];
        } else {
            sumv_dropped();
            return;
        }
        btn = btn_evt_filter(btn);          /* 订阅即消费：被订阅的位不转发 */
        const bool btn_changed = (btn != s_mute_btn);
        const bool aux = (wheel != 0) || (has_pan && pan != 0);
        if (btn_changed) {
            /* 按键优先级最高：立刻更新并补一条零位移报告，不等引擎的下一条注入，
             * 也不会被引擎带着旧按键缓存的报告盖回去（那会造成游戏里的双击/开镜闪断）。 */
            makcu_mouse_button_priority(btn);
            if (aux) {
                makcu_mouse_forward(0, 0, wheel, btn);
            }
            sumv_forwarded();
        } else if (aux) {
            makcu_mouse_forward(0, 0, wheel, btn);
            sumv_forwarded();
        } else {
            sumv_dropped();
        }
        s_mute_btn = btn;
        return;
    }
    /* 订阅即消费：被订阅的真实按键位要从转发给 PC 的报告里抹掉。
     * 需要改写报告，所以这里准备一份本地副本（最多 8 字节）。 */
    uint8_t fwd_buf[8];
    const uint8_t *fwd = data;
    uint16_t fwd_len = len;
    {
        const uint8_t nbytes = makcu_hiddev_report_bytes();
        if (nbytes >= 7 && len >= 7) {
            const uint8_t raw = (uint8_t)(data[0] & 0x1F);
            const uint8_t f = btn_evt_filter(raw);
            if (f != raw) {
                const uint16_t n = (len > (uint16_t)sizeof(fwd_buf)) ? (uint16_t)sizeof(fwd_buf) : len;
                memcpy(fwd_buf, data, n);
                fwd_buf[0] = (uint8_t)((data[0] & (uint8_t)~0x1F) | (f & 0x1F));
                fwd = fwd_buf;
                fwd_len = n;
            }
        } else if (len >= 5) {
            const uint8_t raw = data[0];
            const uint8_t f = btn_evt_filter(raw);
            if (f != raw) {
                const uint16_t n = (len > (uint16_t)sizeof(fwd_buf)) ? (uint16_t)sizeof(fwd_buf) : len;
                memcpy(fwd_buf, data, n);
                fwd_buf[0] = f;
                fwd = fwd_buf;
                fwd_len = n;
            }
        }
    }
    /* 诊断：统计从左片入口进来的每一帧，以及其中带按键/按键变化的帧数。
     * 用来判断"物理点击有没有到达左片"，而不是靠猜。 */
    s_link_frames++;
    /* 记录最近一帧（任意端点）的 ep/len/前 6 字节，供 0x45 读回 */
    s_link_last_ep = ep;
    s_link_last_len = (len > 8) ? 8 : (uint8_t)len;
    for (uint8_t bi = 0; bi < 8; bi++) {
        s_link_last_data[bi] = (bi < len) ? data[bi] : 0;
    }
    if ((data[0] & 0x1F) != 0) {
        s_link_btn_nonzero++;
    }
    if ((data[0] & 0x1F) != (uint8_t)(s_last_buttons & 0x1F)) {
        s_link_btn_changes++;
    }
    if (s_fwd_div > 1) {
        if ((s_fwd_cnt++ % s_fwd_div) != 0) {
            s_fwd_drop++;
            return;
        }
    }
    /* 让屏蔽层看到的“上次已转发按键”跟真实转发保持一致。
     * 缺这句会出严重 bug：按键在瞄准外按下（走正常路径，s_mute_btn 没被更新），
     * 松开却落在瞄准窗口内 —— 屏蔽层判定“没变化”直接丢弃，而引擎注入的每条报告都带着
     * 缓存的 s_buttons=按下，PC 就卡在按住（左键一直射击）。 */
    s_mute_btn = (uint8_t)(fwd[0] & 0x1F);
    /* 短按抗抖（真实鼠标透传）：
     * 微动在"很快的一下"时会出现 松开→几毫秒内又按下，PC 端就像按了两次。
     * 规则：松开后 RELEASE_GUARD_MS 内的**再次按下**直接吞掉（人不可能这么快连按），
     * 其余变化一律原样转发，不引入任何延迟。 */
    {
        static uint8_t  s_fwd_btn_last;
        static uint32_t s_fwd_release_us;
        const uint32_t now_us = (uint32_t)esp_timer_get_time();
        uint8_t btn_now = (uint8_t)(fwd[0] & 0x1F);
        bool swallowed = false;
        const uint8_t pressed = (uint8_t)(btn_now & (uint8_t)~s_fwd_btn_last);
        if (pressed != 0
                && (uint32_t)(now_us - s_fwd_release_us) < (RELEASE_GUARD_MS * 1000u)) {
            /* 抖动：保留旧位，等于把这次"按下"吞掉（必要时先拷一份，别改原始缓冲） */
            btn_now = s_fwd_btn_last;
            if (fwd != fwd_buf) {
                const uint16_t n = (len > (uint16_t)sizeof(fwd_buf))
                        ? (uint16_t)sizeof(fwd_buf) : len;
                memcpy(fwd_buf, data, n);
                fwd = fwd_buf;
                fwd_len = n;
            }
            fwd_buf[0] = (uint8_t)((fwd_buf[0] & (uint8_t)~0x1F) | (btn_now & 0x1F));
            s_btn_bounce_swallowed++;
            swallowed = true;
        }
        if ((s_fwd_btn_last & (uint8_t)~btn_now) != 0) {
            s_fwd_release_us = now_us;      /* 记录松开时刻 */
        }
        if (btn_now != s_fwd_btn_last || swallowed) {
            /* 每一次真实按键变化（含被抗抖吞掉的那次）都留痕，供 0x44 读回 */
            btn_trace_add((uint8_t)(data[0] & 0x1F), btn_now,
                    swallowed ? BTN_TRACE_SRC_SWALLOW : BTN_TRACE_SRC_PASS);
        }
        s_fwd_btn_last = btn_now;
        s_mute_btn = btn_now;
    }
    /* S1：真实报告的按键字节同步进 mouse 层状态（不发送、不计审计）。
     * 不做这件事时，引擎注入携带的 s_buttons 与真实报告字节不一致，
     * hiddev 会把每条报告都判成"按键变化"→ 假按键洪泛（实测 824 条 / 50 ms 等待）。 */
    makcu_mouse_sync_buttons(s_mute_btn);
    s_last_buttons = data[0];
    s_btn_or |= data[0];
    if (data[0] != 0) {
        s_btn_events++;
    }
    if (len >= 5 && data[4] != 0) {
        s_wheel_events++;
        s_wheel_sum += (int8_t)data[4];
    }

    /* If the clone declares the same 5-byte 12-bit layout the right chip forwards,
     * pass the payload through untouched: no 12->8 conversion, no precision loss. */
    const int64_t lat_t0 = esp_timer_get_time();
    if (ep == 0x82) {
        s_in82++;
        for (uint8_t i = 0; i < 8u && i < len; i++) { s_in82_last[i] = data[i]; }
    }
    if (makcu_clone_wants_raw_report() && len >= 5) {
        /* Forward the report at its full length: the mouse we cloned may carry
         * more than buttons+XY (the G3M PRO sends 7 bytes: 5 buttons, X16, Y16,
         * wheel, AC pan), and truncating silently drops wheel/pan. */
#if defined(MB_DUAL_IF)
        makcu_hiddev_report_verbatim_ep(ep, fwd, fwd_len);
#else
        (void)ep;
        makcu_hiddev_report_verbatim(fwd, fwd_len);
#endif
        lat_sample(lat_t0, esp_timer_get_time());   /* verbatim path (the common one) */
        return;
    }
    const int32_t x12 = sign_extend_12((int32_t)data[1] | ((int32_t)(data[2] & 0x0F) << 8));
    const int32_t y12 = sign_extend_12((int32_t)(data[2] >> 4) | ((int32_t)data[3] << 4));
    const int8_t wheel = (len >= 5) ? (int8_t)data[4] : 0;

    s_res_x += x12;
    s_res_y += y12;
    const int8_t dx = take_i8(&s_res_x);
    const int8_t dy = take_i8(&s_res_y);

    makcu_mouse_forward(dx, dy, wheel, fwd[0]);
    lat_sample(lat_t0, esp_timer_get_time());
}

static void report_missing_handlers(void)
{
    int missing = 0;
    for (unsigned i = 0; i < makcu_opcode_count; i++) {
        if (makcu_opcode_table[i] == NULL) {
            ESP_LOGW(TAG, "opcode 0x%02x has no handler yet", i);
            missing++;
        }
    }
    ESP_LOGI(TAG, "%u commands, %u opcodes, %d handlers still missing",
             makcu_cmd_count, makcu_opcode_count, missing);
}

/* Dispatch one line without its trailing CR and without the "km." prefix. */
#ifndef MB_DEBUG_OPCODE
#define MB_DEBUG_OPCODE 0      /* bench builds pass -DMB_DEBUG_OPCODE=1 */
#endif

#if MB_DEBUG_OPCODE
/* Test harness only: "mx.<hex opcode> <args>" calls a handler directly so the
 * opcodes that have no text command (0x0D..0x18) can be exercised.  A shipped
 * build must leave MB_DEBUG_OPCODE at 0. */
static int hexval(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

static int handle_debug_line(const char *line, int len)
{
    if (len < 4 || line[0] != 'm' || line[1] != 'x' || line[2] != '.') {
        return 0;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'l') {
        /* recovery path: reboot straight into the ROM downloader so the bench
         * can always flash a new image (OTG/HID builds have no CDC console) */
        REG_WRITE(RTC_CNTL_OPTION1_REG, RTC_CNTL_FORCE_DOWNLOAD_BOOT);
        esp_restart();
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'v') {
        /* full hex dump of what the device stack would hand to the host */
        const uint8_t *dev = tud_descriptor_device_cb();
        const uint8_t *cfg = tud_descriptor_configuration_cb(0);
        const uint8_t *rep = tud_hid_descriptor_report_cb(0);
        const makcu_clone_t *c = makcu_clone_get();
        const unsigned cfg_len = (c != NULL && c->valid && c->config_len) ? c->config_len : 34u;
        const unsigned rep_len = (c != NULL && c->valid && c->report_len) ? c->report_len : 52u;
        char out[256];
        size_t at = 0;
        at += (size_t)snprintf(out + at, sizeof(out) - at, "init=%u mnt=%u ",
                               makcu_hiddev_init_ok() ? 1u : 0u,
                               makcu_hiddev_mounted() ? 1u : 0u);
        for (unsigned i = 0; i < 18; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev[i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " ");
        for (unsigned i = 0; i < cfg_len; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", cfg[i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " rep%u:%02x", rep_len, rep[0]);
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'c' && line[4] == 'l') {
        /* clone fixture: mx.cl (default A) / mx.cl <1|2|3|4> / mx.cc to clear */
        int which = MAKCU_CLONE_FIXTURE_MOUSE_A;
        if (len > 6 && line[6] >= '1' && line[6] <= '4') {
            which = line[6] - '0';
        }
        const bool ok = makcu_clone_apply_fixture(which);
        const makcu_clone_t *c = makcu_clone_get();
        char out[32];
        const int n = snprintf(out, sizeof(out), "%d:%02x%02x:%02x%02x",
                               ok ? 1 : 0, c->device[9], c->device[8],
                               c->device[11], c->device[10]);
        makcu_reply(out, (size_t)n);
        /* Descriptors are only read while enumerating.  A software reset leaves
         * the USB PHY attached and the host stops enumerating, so the clone takes
         * effect on the next real reset (flash or replug) - see docs D23. */
        return 1;
    }
    if (len >= 5 && line[3] == 'c' && line[4] == 'c') {
        makcu_clone_clear();
        makcu_reply("0", 1);
        return 1;
    }
    if (len >= 6 && line[3] == 'l' && line[4] == 'b' && line[5] == '0') {
        makcu_link_set_loopback(false);
        makcu_reply("0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 'b') {
        /* loopback bench: route UART1 TX into its own RX, send one 0xA2 chunk */
        const uint8_t payload[9] = { 0x01, 0x22, 0x05, 0x00, 0xDE, 0xAD, 0xBE, 0xEF, 0x11 };
        const size_t sent = makcu_link_loopback_selftest(payload, sizeof(payload));
        char out[16];
        const int n = snprintf(out, sizeof(out), "%u", (unsigned)sent);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 's') {
        /* frames, ep0_requests, ep0_in, ep0_out, hid_chunks, a3, unknown,
         * ep0_starts, ep0_ends, injected, dropped, rx_bytes */
        const makcu_link_stats_t st = makcu_link_stats();
        char out[128];
        const int n = snprintf(out, sizeof(out), "%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u",
                               (unsigned)st.frames, (unsigned)st.ep0_requests,
                               (unsigned)st.ep0_in, (unsigned)st.ep0_out,
                               (unsigned)st.hid_chunks, (unsigned)st.a3_frames,
                               (unsigned)st.unknown, (unsigned)st.ep0_starts,
                               (unsigned)st.ep0_ends, (unsigned)st.reports_injected,
                               (unsigned)st.reports_dropped, (unsigned)st.rx_bytes);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' &&
        ((line[4] == 'f' && (len < 6 || line[5] != 'x')) || line[4] == 'n')) {
        /* mx.lf <cmd hex> <payload hex>: frame through the internal loopback.
         * mx.ln <cmd hex> <payload hex>: frame on the wire, loopback off - the
         * liveness probe for the right chip, which answers every frame it sees. */
        char hexbuf[224];
        size_t hn = 0;
        for (int i = 5; i < len && hn < sizeof(hexbuf); i++) {
            if (line[i] == ' ') {
                continue;
            }
            hexbuf[hn++] = line[i];
        }
        if (hn < 2) {
            return 1;
        }
        const int h1 = hexval(hexbuf[0]);
        const int l1 = hexval(hexbuf[1]);
        if (h1 < 0 || l1 < 0) {
            return 1;
        }
        const uint8_t cmd = (uint8_t)((h1 << 4) | l1);
        uint8_t payload[96];
        size_t plen = 0;
        for (size_t i = 2; i + 1 < hn && plen < sizeof(payload); i += 2) {
            const int ph = hexval(hexbuf[i]);
            const int pl = hexval(hexbuf[i + 1]);
            if (ph < 0 || pl < 0) {
                break;
            }
            payload[plen++] = (uint8_t)((ph << 4) | pl);
        }
        size_t sent;
        if (line[4] == 'f') {
            sent = makcu_link_probe_frame(cmd, payload, (uint16_t)plen);
        } else {
            makcu_link_set_loopback(false);
            sent = makcu_link_send(cmd, payload, (uint16_t)plen);
        }
        char out[16];
        const int n = snprintf(out, sizeof(out), "%u", (unsigned)sent);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'e' && line[4] == 'i') {
        /* mx.ei -> hex of the last report a 0xA2 frame injected */
        uint8_t buf[MAKCU_LINK_INJECT_MAX];
        const size_t n = makcu_link_last_injected(buf, sizeof(buf));
        char out[MAKCU_LINK_INJECT_MAX * 2 + 1];
        size_t at = 0;
        for (size_t i = 0; i < n; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", buf[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 'r') {
        /* mx.lr -> "cmd=<xx> len=<n> data=<hex>" of the last frame on UART1 */
        uint8_t cmd = 0;
        uint8_t buf[MAKCU_LINK_INJECT_MAX];
        const size_t n = makcu_link_last_frame(&cmd, buf, sizeof(buf));
        char out[MAKCU_LINK_INJECT_MAX * 2 + 32];
        size_t at = (size_t)snprintf(out, sizeof(out), "cmd=%02x len=%u data=", cmd, (unsigned)n);
        for (size_t i = 0; i < n && at + 2 < sizeof(out); i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", buf[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'b') {
        /* mx.hb <0|1> -> silence the periodic 0xA3 (bench timing determinism) */
        const char *a = line + 5;
        while (*a == ' ') { a++; }
        const bool on = (*a != '0');
        makcu_link_set_heartbeat(on);
        makcu_reply(on ? "1" : "0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'a' && line[4] == 's') {
        char out[16];
        const int cnt = snprintf(out, sizeof(out), "%d", s_autoclone_status);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'a' && line[4] == 'c') {
        const bool ok = autoclone_from_link();
        const makcu_clone_t *c = makcu_clone_get();
        char out[40];
        const int cnt = snprintf(out, sizeof(out), "%d:%02x%02x:%02x%02x:%u",
                                 ok ? 1 : 0, c->device[9], c->device[8],
                                 c->device[11], c->device[10], (unsigned)c->report_len);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'b' && line[4] == 'w') {
        /* mx.bw -> btn_events, wheel_events, wheel_sum, last_buttons */
        char out[48];
        const int cnt = snprintf(out, sizeof(out), "%u,%u,%d,%u",
                                 (unsigned)s_btn_events, (unsigned)s_wheel_events,
                                 (int)s_wheel_sum, (unsigned)s_last_buttons);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 6 && line[3] == 'd' && line[4] == 'u') {
        /* mx.du <hex...> -> decode a raw report with the 12-bit unpacker */
        size_t k = 5;
        while (k < len && line[k] == ' ') { k++; }
        uint8_t raw[8];
        size_t rn = 0;
        for (size_t i = 0; (k + i) < len && rn < sizeof(raw); i += 2) {
            const int h = hexval(line[k + i]);
            const int l = ((k + i + 1) < len) ? hexval(line[k + i + 1]) : 0;
            if (h < 0 || l < 0) { break; }
            raw[rn++] = (uint8_t)((h << 4) | l);
        }
        if (rn < 4) {
            makcu_reply("short", 5);
            return 1;
        }
        int8_t dx = 0, dy = 0, dw = 0;
        unpack_report_12bit(raw, (uint16_t)rn, &dx, &dy, &dw);
        char out[32];
        const int cnt = snprintf(out, sizeof(out), "%d,%d,%d", dx, dy, dw);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 6 && line[3] == 'f' && line[4] == 's') {
        /* mx.fs <n> -> forward 1 of every n reports (1 = forward everything) */
        size_t i = 5;
        while (i < len && line[i] == ' ') { i++; }
        unsigned n = 0;
        while (i < len && line[i] >= '0' && line[i] <= '9') {
            n = n * 10 + (unsigned)(line[i] - '0');
            i++;
        }
        if (n == 0) { n = 1; }
        if (n > 8) { n = 8; }
        s_fwd_div = n;
        s_fwd_cnt = 0;
        s_fwd_drop = 0;
        char out[16];
        const int cnt = snprintf(out, sizeof(out), "%u", (unsigned)n);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 6 && line[3] == 's' && line[4] == 's') {
        /* mx.ss <hex|00> -> pin the 0xA2 session id; 00 returns to auto */
        size_t j = 5;
        while (j < len && line[j] == ' ') { j++; }
        unsigned val = 0;
        for (int i = 0; i < 2 && (j + (size_t)i) < len; i++) {
            const char ch = line[j + (size_t)i];
            val <<= 4;
            if (ch >= '0' && ch <= '9') { val |= (unsigned)(ch - '0'); }
            else if (ch >= 'a' && ch <= 'f') { val |= (unsigned)(ch - 'a' + 10); }
            else if (ch >= 'A' && ch <= 'F') { val |= (unsigned)(ch - 'A' + 10); }
        }
        makcu_link_force_session((uint8_t)val, val != 0);
        makcu_reply(val != 0 ? "forced" : "auto", val != 0 ? 6 : 4);
        return 1;
    }
    if (len >= 6 && line[3] == 'h' && line[4] == 'k') {
        /* mx.hk <0|1> -> keep 0xA2 out of the HID path (bench isolation) */
        const char *arg = line + 5;
        while (*arg == ' ') { arg++; }
        const bool on = (*arg != '0');
        makcu_link_enable_sink(on);
        makcu_reply(on ? "1" : "0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'r') {
        /* mx.hr -> ready_fail, ready, suspended, mounted */
        uint32_t rf = 0;
        bool rdy = false, sus = false, mnt2 = false;
        makcu_hiddev_link_state(&rf, &rdy, &sus, &mnt2);
        char out[64];
        const int n = snprintf(out, sizeof(out), "%u,%u,%u,%u",
                               (unsigned)rf, rdy ? 1u : 0u, sus ? 1u : 0u, mnt2 ? 1u : 0u);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'd') {
        /* mx.rd -> report descriptor we actually serve (dumped with a length cap,
         * because the console reply buffer is 256 bytes). */
        const makcu_clone_t *c = makcu_clone_get();
        const uint8_t *rep = tud_hid_descriptor_report_cb(0);
        unsigned n = (c != NULL && c->valid && c->report_len) ? c->report_len : 52u;
        const size_t max = (len > 7 && line[5] == ' ') ? 120u : 60u;   /* mx.rd 120 */
        char out[260];
        size_t at = (size_t)snprintf(out, sizeof(out), "len=%u ", n);
        for (unsigned i = 0; i < n && i < max && at + 2 < sizeof(out); i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", rep[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 6 && line[3] == 'v' && line[4] == 'p') {
        /* mx.vp <vid4><pid4> -> patch the cloned device descriptor's VID/PID
         * (bench: the host can wedge a whole VID family, so we move the clone to
         * a family that enumerates). Takes effect after mx.rs. */
        const char *a = line + 5;
        while (*a == ' ') { a++; }
        if (strncmp(a, "clear", 5) == 0) {
            /* mx.vp clear: drop the persisted override so the identity comes
             * from the device alone (takes effect after mx.rs). */
            const bool ok = makcu_clone_identity_override_save(0, 0);
            makcu_reply(ok ? "cleared" : "nvs-fail", ok ? 7u : 8u);
            return 1;
        }
        unsigned v = 0, p = 0;
        for (int i = 0; i < 4 && a[i] != 0; i++) { v = (v << 4) | (unsigned)hexval(a[i]); }
        const char *b = a + 4;
        while (*b == ' ') { b++; }
        for (int i = 0; i < 4 && b[i] != 0; i++) { p = (p << 4) | (unsigned)hexval(b[i]); }
        makcu_clone_t *c = makcu_clone_mutable();
        if (c == NULL || !c->valid) {
            makcu_reply("no-clone", 8);
            return 1;
        }
        const bool saved = makcu_clone_identity_override_save((uint16_t)v, (uint16_t)p);
        c->vid_ovr = (uint16_t)v;
        c->pid_ovr = (uint16_t)p;
        if (!saved) {
            makcu_reply("nvs-fail", 8);
            return 1;
        }
        c->device[8] = (uint8_t)(v & 0xFF);
        c->device[9] = (uint8_t)(v >> 8);
        c->device[10] = (uint8_t)(p & 0xFF);
        c->device[11] = (uint8_t)(p >> 8);
        char out[16];
        const int cnt = snprintf(out, sizeof(out), "%04x:%04x", v, p);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'i' && line[4] == 'f') {
        /* mx.if -> if_count, then per interface: len:ep:rid */
        const makcu_clone_t *c = makcu_clone_get();
        char out[80];
        size_t at = (size_t)snprintf(out, sizeof(out), "%u", c ? (unsigned)c->if_count : 0u);
        if (c != NULL) {
            for (uint8_t k = 0; k < c->if_count && k < MAKCU_CLONE_IF_MAX; k++) {
                at += (size_t)snprintf(out + at, sizeof(out) - at, " %u:%02x:%u",
                                       (unsigned)c->ifs[k].report_len,
                                       (unsigned)c->ifs[k].ep_in,
                                       (unsigned)c->ifs[k].report_id);
            }
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'x' && line[4] == 't') {
        /* mx.xt: invoke the HID OUT callback by hand (plumbing self-test) */
        extern unsigned int tud_hid_out_count(void);
        static uint8_t fake[64];
        for (unsigned i = 0; i < sizeof(fake); i++) { fake[i] = (uint8_t)i; }
        tud_hid_set_report_cb(1, 4, HID_REPORT_TYPE_OUTPUT, fake, sizeof(fake));
        char out[48];
        const int cnt = snprintf(out, sizeof(out), "xt,out=%u,ok=%u,tdr=%u",
                                 (unsigned)s_out_reports, (unsigned)s_out_ok,
                                 tud_hid_out_count());
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 6 && line[3] == 'l' && line[4] == 'f' && line[5] == 'x') {
        /* mx.lfx <report hex>: inject one report with the session and length
         * filled in automatically (hand-filling the session is what made the
         * bench injections silently disappear - it must equal the right chip's
         * current device address). */
        const char *h = line + 6;
        while (*h == ' ') { h++; }
        uint8_t payload[MAKCU_LINK_MAX_FIELD];
        uint16_t dlen = 0;
        while (h[0] != 0 && h[1] != 0 && dlen < sizeof(payload) - 4) {
            if (h[0] == ' ') { h++; continue; }
            const int hi = hexval(h[0]), lo = hexval(h[1]);
            if (hi < 0 || lo < 0) { break; }
            payload[4 + dlen] = (uint8_t)((hi << 4) | lo);
            dlen++;
            h += 2;
        }
        if (dlen == 0) {
            makcu_reply("no-data", 7);
            return 1;
        }
        const uint8_t sess = makcu_link_session();
        payload[0] = 0x81;                     /* mouse IN endpoint */
        payload[1] = sess != 0 ? sess : 1;
        payload[2] = (uint8_t)dlen;
        payload[3] = 0;
        /* Must go through the loopback: a plain send hands the frame to the right
         * chip, which does not handle 0xA2 and answers with an error frame - so the
         * injection never reaches this chip's own sink. */
        (void)makcu_link_send_loopback(0xA2, payload, (uint16_t)(dlen + 4u));
        char out[24];
        const int cnt = snprintf(out, sizeof(out), "sent,%u,%u", (unsigned)payload[1], (unsigned)dlen);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 6 && line[3] == 'l' && line[4] == 'h') {
        /* mx.lh <page 0..7> —— 导出"相邻两条转发报告间隔"的直方图（每桶 100 µs，共 256 桶）。
         * 这就是 PC 侧 HID 节奏在左片看到的样子：桶 n 表示间隔落在 [n*100, (n+1)*100) µs。
         * 每页 16 桶（16 页），格式 "idx:count" 用 ';' 分隔，便于上位机解析。 */
        /* 注意：line 不是 NUL 结尾（长度由 len 给），必须按 len 有界扫描，
         * 否则会读到缓冲区里的残留字节 —— 之前用指针 while 就栽在这（page 解析成随机值）。 */
        int page = 0;
        int arg = 5;
        while (arg < len && line[arg] == ' ') { arg++; }
        while (arg < len && line[arg] >= '0' && line[arg] <= '9') {
            page = page * 10 + (line[arg] - '0');
            arg++;
        }
        if (page < 0) { page = 0; }
        if (page > 15) { page = 15; }
        char out[256];
        int pos = 0;
        for (int i = 0; i < 16; i++) {
            const int idx = page * 16 + i;
            pos += snprintf(out + pos, sizeof(out) - (size_t)pos, "%s%d:%lu",
                            i ? ";" : "", idx, (unsigned long)s_lat_int[idx]);
            if (pos > 200) { break; }
        }
        makcu_reply(out, (size_t)pos);
        return 1;
    }
    if (len >= 6 && line[3] == 'l' && line[4] == 'a' && line[5] == 't') {
        uint8_t dummy = 0;
        uint8_t rp[8] = { 0 };
        const int rn = makcu_link_request(0x21, &dummy, 1, rp, sizeof(rp), 200);
        const uint16_t rp50 = (uint16_t)(rp[0] | (rp[1] << 8));
        const uint16_t rp99 = (uint16_t)(rp[2] | (rp[3] << 8));
        const uint16_t rmax = (uint16_t)(rp[4] | (rp[5] << 8));
        char out[160];
        /* int_p50/int_p99: interval between consecutive reports (us) => report rate.
         * proc_p50/p99:   time this chip spends per report (us).
         * r_p50/p99/max:  right chip's per-report forward time (us), queried over the
         *                 link (0x21); 255 means the right chip did not answer. */
        const int n = snprintf(out, sizeof(out),
                               "int=%lu/%luus,proc=%lu/%luus,n=%lu;r=%u/%u/%uus,n8=%u",
                               (unsigned long)(lat_pct(s_lat_int, LAT_IB, 50) * 100u),
                               (unsigned long)(lat_pct(s_lat_int, LAT_IB, 99) * 100u),
                               (unsigned long)(lat_pct(s_lat_proc, LAT_PB, 50) * 10u),
                               (unsigned long)(lat_pct(s_lat_proc, LAT_PB, 99) * 10u),
                               (unsigned long)s_lat_n,
                               (unsigned)rp50, (unsigned)rp99, (unsigned)rmax,
                               (unsigned)rp[6]);
        (void)rn;
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 's' && line[4] == 'n') {
        const makcu_clone_t *c = makcu_clone_get();
        char out[32];
        const int cnt = snprintf(out, sizeof(out), "%s",
                                 (c != NULL && c->valid) ? c->strings[2] : "(none)");
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'v' && line[4] == 's') {
        /* mx.vs -> descriptor source: dev,cfg (1=right local, 2=tunnel, 0=fail) */
        char out[24];
        const int cnt = snprintf(out, sizeof(out), "%u,%u",
                                 (unsigned)s_src_dev, (unsigned)s_src_cfg);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'm' && line[4] == 'v') {
        /* mx.mv [speed [max_report]] —— sumv 的运行时默认值
         *   mx.mv            读：speed,max_report,cap
         *   mx.mv 20000      只改默认速度
         *   mx.mv 20000 127  同时改"每报告最多多少 counts"（= 速度上限/1000）
         * max_report 决定真正的速度天花板：1 kHz × max_report counts/s。 */
        int arg = 5;
        while (arg < len && line[arg] == ' ') { arg++; }
        if (arg < len) {
            uint32_t v = 0;
            while (arg < len && line[arg] >= '0' && line[arg] <= '9') {
                v = v * 10u + (uint32_t)(line[arg] - '0');
                arg++;
            }
            while (arg < len && line[arg] == ' ') { arg++; }
            uint32_t w = 0;
            if (arg < len) {
                while (arg < len && line[arg] >= '0' && line[arg] <= '9') {
                    w = w * 10u + (uint32_t)(line[arg] - '0');
                    arg++;
                }
            }
            makcu_sumv_set_defaults((uint16_t)(v > 65535u ? 65535u : v),
                                    (uint8_t)(w > 255u ? 255u : w));
        }
        uint16_t sp = 0;
        uint8_t mr = 0;
        makcu_sumv_get_defaults(&sp, &mr);
        const uint8_t eff = makcu_sumv_mr_for_speed(sp);
        char out[80];
        const int n = snprintf(out, sizeof(out), "%u,%s,mr=%u,cap=%lu",
                               (unsigned)sp, mr == 0 ? "auto" : "fixed",
                               (unsigned)eff, (unsigned long)1000ul * eff);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'm' && line[4] == 't') {
        /* mx.mt            -> "on|off,<count>/<cap>"
         * mx.mt on|off|clr -> arm / disarm / clear
         * mx.mt d          -> dump every stored entry, in reply-sized chunks:
         *                     header "d <total>", then lines
         *                     "<t_us>,<ep>,<len>,<report hex>"
         * Used for the motion-fidelity analysis (tools/trace_motion.py): the
         * timestamps are this chip's clock at the moment the report reached the
         * HID layer, so the interval/speed statistics describe what the PC got,
         * not what the mouse's sensor produced. */
        /* NOTE: the console line buffer is NOT NUL-terminated past `len` and is
         * reused across commands, so every argument test below is length-bounded
         * (a plain strncmp(line + 5, "on", 2) matched the previous command's
         * leftovers and made a bare `mx.mt` answer "on"). */
        const int arg_at = 5;
        int arg = arg_at;
        while (arg < len && line[arg] == ' ') { arg++; }
        const char *a = line + arg;
        const int alen = len - arg;
        if (alen >= 2 && memcmp(a, "on", 2) == 0) {
            s_mt_head = 0;
            s_mt_count = 0;
            s_mt_on = true;
            makcu_reply("on", 2);
            return 1;
        }
        if (alen >= 3 && memcmp(a, "off", 3) == 0) {
            s_mt_on = false;
            makcu_reply("off", 3);
            return 1;
        }
        if (alen >= 3 && memcmp(a, "clr", 3) == 0) {
            s_mt_head = 0;
            s_mt_count = 0;
            makcu_reply("clr", 3);
            return 1;
        }
        if (alen >= 1 && a[0] == 'd') {
            /* Freeze first: draining 3072 entries takes ~8 s at 115200, and the
             * ring keeps being written while we dump - without this the oldest
             * entries would be overwritten mid-transfer and the dump would mix
             * two different windows. */
            s_mt_on = false;
            const uint32_t total = s_mt_count;
            const uint32_t start = (uint32_t)((s_mt_head + MT_N - total) % MT_N);
            char hdr[24];
            const int hn = snprintf(hdr, sizeof(hdr), "d %u", (unsigned)total);
            makcu_reply(hdr, (size_t)hn);
            uint32_t i = 0;
            while (i < total) {
                size_t at = 0;
                while (i < total && at + 40u < sizeof(s_mt_dump)) {
                    const mt_entry_t *e = &s_mt[(start + i) % MT_N];
                    at += (size_t)snprintf(s_mt_dump + at, sizeof(s_mt_dump) - at,
                                           "\n%lu,%02x,%u,",
                                           (unsigned long)e->t_us, (unsigned)e->ep,
                                           (unsigned)e->len);
                    for (uint8_t k = 0; k < e->len && k < sizeof(e->data); k++) {
                        at += (size_t)snprintf(s_mt_dump + at, sizeof(s_mt_dump) - at,
                                               "%02x", e->data[k]);
                    }
                    i++;
                }
                makcu_reply(s_mt_dump, at);
            }
            return 1;
        }
        char st[32];
        const int n = snprintf(st, sizeof(st), "%s,%u/%u", s_mt_on ? "on" : "off",
                               (unsigned)s_mt_count, (unsigned)MT_N);
        makcu_reply(st, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'b') {
        /* mx.rb -> input-report size derived from the served descriptor, plus the
         * descriptor length and report id the mouse interface carries.  A report
         * shorter than this is accepted by the stack and dropped by the host. */
        const makcu_clone_t *c = makcu_clone_get();
        char out[64];
        const int n = snprintf(out, sizeof(out), "bytes=%u desc=%u rid=%u",
                               (unsigned)makcu_hiddev_report_bytes(),
                               (unsigned)((c != NULL && c->if_count > 0) ? c->ifs[0].report_len
                                                                         : (c ? c->report_len : 0u)),
                               (unsigned)((c != NULL && c->if_count > 0) ? c->ifs[0].report_id
                                                                        : (c ? c->report_id : 0u)));
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'e' && line[4] == 'v') {
        /* mx.ev -> 按键事件通道状态
         * enabled,mask,pending,cur,last_fwd,seq,count,overflow,auto_released,push,consume */
        btn_evt_stat_t st;
        btn_evt_stat(&st);
        char out[96];
        const int n = snprintf(out, sizeof(out), "%u,%02x,%02x,%02x,%02x,%u,%u,%lu,%u,%u,%u",
                               st.enabled ? 1u : 0u, st.mask, st.pending, st.cur, st.last_fwd,
                               (unsigned)st.head_seq, (unsigned)st.count,
                               (unsigned long)st.overflow,
                               st.auto_released ? 1u : 0u, st.push ? 1u : 0u,
                               st.consume ? 1u : 0u);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 's' && line[4] == 'v') {
        /* mx.sv -> sumv 状态与计数
         * active,samples,aborted,rounds,dropped,forwarded,speed_eff,remain_ms */
        makcu_sumv_stats_t st;
        makcu_sumv_stats(&st);
        char out[128];
        const int n = snprintf(out, sizeof(out), "%u,%lu,%lu,%lu,%lu,%lu,%lu,%lu",
                               st.active ? 1u : 0u,
                               (unsigned long)st.samples, (unsigned long)st.aborted,
                               (unsigned long)st.rounds, (unsigned long)st.mute_dropped,
                               (unsigned long)st.btn_forwarded,
                               (unsigned long)st.speed_eff, (unsigned long)st.remain_ms);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 's') {
        uint32_t s = 0, f = 0;
        makcu_hiddev_ep_stats(&s, &f);
        char out[40];
        const int cnt = snprintf(out, sizeof(out), "%u,%u", (unsigned)s, (unsigned)f);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'z') {
        /* mx.hz —— 左片侧速率（u32 计数，精确；不依赖右片那套会饱和的 u16）。
         * 连读两次即可得到 dt 与 rates：
         *   frames/s    左片每秒收到多少 0xA2 帧（= 右片喂过来的报告率）
         *   injected/s  每秒真正进到 HID 路径的条数
         *   dropped     期间丢弃数（应恒为 0）
         *   B/s         UART1 每秒收到的字节
         * 判据：鼠标在动时 frames/s 若明显低于鼠标自身上报率（1000/500 Hz），
         * 说明右片/链路没喂满；同时看 mx.hi 的 rate 定位是哪一侧。 */
        static uint32_t s_hz_frames, s_hz_chunks, s_hz_inj, s_hz_drop, s_hz_bytes;
        static int64_t  s_hz_t_us;
        static bool     s_hz_valid;
        const makcu_link_stats_t st = makcu_link_stats();
        const int64_t now = esp_timer_get_time();
        const int32_t dt_ms = s_hz_valid ? (int32_t)((now - s_hz_t_us) / 1000) : 0;
        char out[128];
        if (s_hz_valid && dt_ms > 0) {
            const unsigned d_f = (unsigned)(st.frames - s_hz_frames);
            const unsigned d_c = (unsigned)(st.hid_chunks - s_hz_chunks);
            const unsigned d_i = (unsigned)(st.reports_injected - s_hz_inj);
            const unsigned d_d = (unsigned)(st.reports_dropped - s_hz_drop);
            const unsigned d_b = (unsigned)(st.rx_bytes - s_hz_bytes);
            const int n = snprintf(out, sizeof(out),
                                   "dt=%dms frames=%u/s chunks=%u/s inj=%u/s drop=%u B=%u/s",
                                   (int)dt_ms,
                                   (unsigned)((uint64_t)d_f * 1000u / (unsigned)dt_ms),
                                   (unsigned)((uint64_t)d_c * 1000u / (unsigned)dt_ms),
                                   (unsigned)((uint64_t)d_i * 1000u / (unsigned)dt_ms),
                                   d_d,
                                   (unsigned)((uint64_t)d_b * 1000u / (unsigned)dt_ms));
            makcu_reply(out, (size_t)n);
        } else {
            makcu_reply("hz: first", 9);
        }
        s_hz_frames = st.frames;
        s_hz_chunks = st.hid_chunks;
        s_hz_inj = st.reports_injected;
        s_hz_drop = st.reports_dropped;
        s_hz_bytes = st.rx_bytes;
        s_hz_t_us = now;
        s_hz_valid = true;
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'i') {
        /* mx.hi: ask the right chip for its 0x1C host-status frame and decode it.
         * This is the only probe that actually READS the right chip's host state:
         * `mx.ln 1c` only prints how many bytes were written, and the 1 kHz 0xA2
         * stream overwrites `mx.lr` almost immediately. */
        uint8_t dummy = 0;
        /* 40 字节：右片 0x1C 帧现在 36 B（12 头 + 4×u16 + 4×u32），32 会截断。 */
        uint8_t rp[40] = { 0 };
        const int rn = makcu_link_request(0x1C, &dummy, 1, rp, sizeof(rp), 300);
        if (rn < 12) {
            makcu_reply("no-reply", 8);
            return 1;
        }
        char out[200];
        const unsigned vid = (unsigned)(rp[2] | (rp[3] << 8));
        const unsigned pid = (unsigned)(rp[4] | (rp[5] << 8));
        const unsigned ok   = (rn >= 14) ? (unsigned)(rp[12] | (rp[13] << 8)) : 0u;
        const unsigned fail = (rn >= 16) ? (unsigned)(rp[14] | (rp[15] << 8)) : 0u;
        const unsigned done = (rn >= 18) ? (unsigned)(rp[16] | (rp[17] << 8)) : 0u;
        const unsigned fwd  = (rn >= 20) ? (unsigned)(rp[18] | (rp[19] << 8)) : 0u;
        /* 右片这几个 u16 计数器满 65535 就饱和（实测两次读都 +0）。
         * 2026-11-11：右片 0x1C 帧加长到 36 B，尾部追加 ok/fail/done/fwd 的 u32 精确值。
         * 回包长度 >= 36 时优先用精确值（并把它们换算成"自上次调用以来的速率"）。 */
        uint32_t ok32 = 0, fail32 = 0, done32 = 0, fwd32 = 0;
        const bool have32 = (rn >= 36);
        if (have32) {
            ok32   = (uint32_t)rp[20] | ((uint32_t)rp[21] << 8) |
                     ((uint32_t)rp[22] << 16) | ((uint32_t)rp[23] << 24);
            fail32 = (uint32_t)rp[24] | ((uint32_t)rp[25] << 8) |
                     ((uint32_t)rp[26] << 16) | ((uint32_t)rp[27] << 24);
            done32 = (uint32_t)rp[28] | ((uint32_t)rp[29] << 8) |
                     ((uint32_t)rp[30] << 16) | ((uint32_t)rp[31] << 24);
            fwd32  = (uint32_t)rp[32] | ((uint32_t)rp[33] << 8) |
                     ((uint32_t)rp[34] << 16) | ((uint32_t)rp[35] << 24);
        }
        static uint32_t s_hi_ok, s_hi_done, s_hi_fwd;
        static int64_t  s_hi_t_us;
        static bool     s_hi_valid;
        const int64_t hi_now = esp_timer_get_time();
        const int32_t hi_dt_ms = s_hi_valid ? (int32_t)((hi_now - s_hi_t_us) / 1000) : 0;
        const uint32_t cur_ok   = have32 ? ok32   : (uint32_t)(uint16_t)ok;
        const uint32_t cur_done = have32 ? done32 : (uint32_t)(uint16_t)done;
        const uint32_t cur_fwd  = have32 ? fwd32  : (uint32_t)(uint16_t)fwd;
        unsigned ok_ps = 0, done_ps = 0, fwd_ps = 0;
        if (s_hi_valid && hi_dt_ms > 0) {
            const uint32_t d_ok   = cur_ok   - s_hi_ok;      /* u32 直减；没有 32 位时靠回绕 */
            const uint32_t d_done = cur_done - s_hi_done;
            const uint32_t d_fwd  = cur_fwd  - s_hi_fwd;
            ok_ps   = (unsigned)((uint64_t)d_ok   * 1000u / (unsigned)hi_dt_ms);
            done_ps = (unsigned)((uint64_t)d_done * 1000u / (unsigned)hi_dt_ms);
            fwd_ps  = (unsigned)((uint64_t)d_fwd  * 1000u / (unsigned)hi_dt_ms);
        }
        s_hi_ok = cur_ok;
        s_hi_done = cur_done;
        s_hi_fwd = cur_fwd;
        s_hi_t_us = hi_now;
        s_hi_valid = true;
        const int n = snprintf(out, sizeof(out),
                               "att=%u addr=%u id=%04x:%04x itf=%u ep=%02x:%02x,%02x:%02x "
                               "gate=%u ok=%u fail=%u done=%u fwd=%u "
                               "rate(ok/done/fwd)=%u/%u/%u/s dt=%dms ex=%s",
                               (unsigned)rp[0], (unsigned)rp[1], vid, pid,
                               (unsigned)rp[6], (unsigned)rp[7], (unsigned)rp[8],
                               (unsigned)rp[9], (unsigned)rp[10], (unsigned)rp[11],
                               have32 ? (unsigned)ok32 : ok,
                               have32 ? (unsigned)fail32 : fail,
                               have32 ? (unsigned)done32 : done,
                               have32 ? (unsigned)fwd32 : fwd,
                               ok_ps, done_ps, fwd_ps, (int)hi_dt_ms,
                               have32 ? "ok" : "u16");
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'f' && line[4] == 'v') {
        /* mx.fv: compile-time force vs. runtime override vs. what is served */
        const makcu_clone_t *c = makcu_clone_get();
        char out[96];
#ifdef MB_FORCE_VID
        const unsigned fv = MB_FORCE_VID, fp = MB_FORCE_PID;
#else
        const unsigned fv = 0, fp = 0;
#endif
        const int cnt = snprintf(out, sizeof(out),
                                 "force=%04x:%04x ovr=%04x:%04x dev=%02x%02x%02x%02x",
                                 fv, fp,
                                 c ? (unsigned)c->vid_ovr : 0u,
                                 c ? (unsigned)c->pid_ovr : 0u,
                                 c ? c->device[8] : 0u, c ? c->device[9] : 0u,
                                 c ? c->device[10] : 0u, c ? c->device[11] : 0u);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'o' && line[4] == 'x') {
        /* mx.ox -> OUT reports received / acked, 0x82 IN frames, last OUT head */
        char out[80];
        size_t at = (size_t)snprintf(out, sizeof(out), "%u,%u,%u,ack=%02x,",
                                     (unsigned)s_out_reports, (unsigned)s_out_ok,
                                     (unsigned)s_in82, (unsigned)s_out_ack);
        at += (size_t)snprintf(out + at, sizeof(out) - at, "%u,",
                               (unsigned)s_out_dropped);
        for (unsigned i = 0; i < 8u && at + 2 < sizeof(out); i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", s_out_last[i]);
        }
        if (at + 10 < sizeof(out)) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, ",in82=");
            for (unsigned i = 0; i < 8u; i++) {
                at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", s_in82_last[i]);
            }
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'b' && line[4] == 'o') {
        /* mx.bo -> OR of all button bytes seen: which button bits ever arrived */
        char out[24];
        const int cnt = snprintf(out, sizeof(out), "0x%02x,%u",
                                 (unsigned)s_btn_or, (unsigned)s_last_buttons);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'q') {
        uint32_t done = 0;
        makcu_hiddev_complete_count(&done);
        char out[16];
        const int cnt = snprintf(out, sizeof(out), "%u", (unsigned)done);
        makcu_reply(out, (size_t)cnt);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 's') {
        makcu_reply("reboot", 6);
        vTaskDelay(pdMS_TO_TICKS(100));
        esp_restart();
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 's') {
        /* mx.hs -> all HID sends: ok, busy, failed, no_mount, mnt */
        uint32_t ok = 0, busy = 0, failed = 0, nomount = 0;
        bool mnt = false;
        makcu_hiddev_send_stats(&ok, &busy, &failed, &nomount, &mnt);
        char out[96];
        const int n = snprintf(out, sizeof(out), "%u,%u,%u,%u,%u",
                               (unsigned)ok, (unsigned)busy, (unsigned)failed,
                               (unsigned)nomount, mnt ? 1u : 0u);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'h' && line[4] == 'v') {
        /* mx.hv -> enqueued, sent, dropped(overflow), wake, no_mount, mnt */
        uint32_t att = 0, sent = 0, busy = 0, wake = 0, nomount = 0;
        bool mnt = false;
        makcu_hiddev_raw_stats(&att, &sent, &busy, &wake, &nomount, &mnt);
        char out[96];
        const int n = snprintf(out, sizeof(out), "%u,%u,%u,%u,%u,%u",
                               (unsigned)att, (unsigned)sent, (unsigned)busy,
                               (unsigned)wake, (unsigned)nomount, mnt ? 1u : 0u);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    if (len >= 5 && line[3] == 'e' && line[4] == 'f') {
        /* mx.ef -> EP0 tunnel session state */
        makcu_reply(makcu_link_ep0_pending() ? "1" : "0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'f') {
        /* mx.rf <cmd hex> [payload hex] -> the reply frame the RIGHT chip would
         * send for that input (same portable function app_right uses). */
        char hexbuf[224];
        size_t hn = 0;
        for (int i = 5; i < len && hn < sizeof(hexbuf); i++) {
            if (line[i] == ' ') {
                continue;
            }
            hexbuf[hn++] = line[i];
        }
        if (hn < 2) {
            return 1;
        }
        const int h1 = hexval(hexbuf[0]);
        const int l1 = hexval(hexbuf[1]);
        if (h1 < 0 || l1 < 0) {
            return 1;
        }
        uint8_t payload[96];
        size_t plen = 0;
        for (size_t i = 2; i + 1 < hn && plen < sizeof(payload); i += 2) {
            const int ph = hexval(hexbuf[i]);
            const int pl = hexval(hexbuf[i + 1]);
            if (ph < 0 || pl < 0) {
                break;
            }
            payload[plen++] = (uint8_t)((ph << 4) | pl);
        }
        static makcu_right_state_t st;           /* zeroed = freshly booted right chip */
        uint8_t reply[MAKCU_LINK_HEADER + MAKCU_LINK_MAX_FIELD];
        const size_t n = makcu_right_reply((uint8_t)((h1 << 4) | l1), payload,
                                           (uint16_t)plen, &st, reply, sizeof(reply));
        char out[MAKCU_LINK_HEADER * 2 + 8];
        size_t at = 0;
        for (size_t i = 0; i < n && at + 2 < sizeof(out); i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", reply[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'l' && line[4] == 'z') {
        /* mx.lz -> clear the per-endpoint reassembly buffers */
        makcu_link_reset_chunks();
        makcu_reply("0", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'c') {
        /* mx.dc <endpoint> -> hex of what the bridge reassembled */
        int ep = 0;
        if (len > 6 && line[6] >= '0' && line[6] <= '7') {
            ep = line[6] - '0';
        }
        uint8_t buf[64];
        const size_t n = makcu_link_chunk(ep, buf, sizeof(buf));
        char out[64 * 2 + 1];
        size_t at = 0;
        for (size_t i = 0; i < n; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", buf[i]);
        }
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'd') {
        /* bench: dump the descriptor tables that no protocol command can read
         * back - the mapping handlers and cmd_channel_toggle are write-only on
         * the wire, so this is the only way to prove what they stored.
         *   w   = desc[+0x63 + i]   (map_write,   opcode 0x16)
         *   w16 = desc[+0x163 + i]  (map_write16, opcode 0x15)
         *   en  = desc[+0x269 + i]  (channel enable, opcode 0x18 writes)
         *   pr  = desc[+0x369 + i]  ("present" gate read by 0x18 / 0x17)
         *   th  = desc[+0x636 + i]  (third flag read by 0x17)
         *   rs  = makcu_resend_flag (0x3FC99FA3) */
        makcu_dev_t *dev = makcu_dev_instance();
        char out[160];
        size_t at = 0;
        at += (size_t)snprintf(out + at, sizeof(out) - at, "w=");
        for (int i = 0; i < 16; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev->desc[0x63 + i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " w16=");
        for (int i = 0; i < 16; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev->desc[0x163 + i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " en=");
        for (int i = 0; i < 8; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev->desc[0x269 + i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " pr=");
        for (int i = 0; i < 8; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev->desc[0x369 + i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " th=");
        for (int i = 0; i < 8; i++) {
            at += (size_t)snprintf(out + at, sizeof(out) - at, "%02x", dev->desc[0x636 + i]);
        }
        at += (size_t)snprintf(out + at, sizeof(out) - at, " rs=%u", (unsigned)makcu_resend_flag);
        makcu_reply(out, at);
        return 1;
    }
    if (len >= 5 && line[3] == 'd' && line[4] == 'p') {
        /* mx.dp <idx>: test-only - set the "present" bit so the 0x18 write path
         * (which is gated on it) can be exercised on a fresh device. */
        int idx = 0;
        if (len > 6 && line[6] >= '0' && line[6] <= '7') {
            idx = line[6] - '0';
        }
        makcu_dev_instance()->desc[0x369 + idx] = 1;
        makcu_reply("1", 1);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'k') {
        unsigned count = 0;
        const uint8_t *tr = makcu_keyboard_trace(&count);
        char out[MAKCU_KBD_TRACE * MAKCU_KBD_REPORT_LEN * 2 + 1];
        size_t n = 0;
        for (unsigned i = 0; i < count * MAKCU_KBD_REPORT_LEN; i++) {
            n += (size_t)snprintf(out + n, sizeof(out) - n, "%02x", tr[i]);
        }
        makcu_reply(out, n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'q') {
        /* trace dump: every report as 3 hex bytes, most recent last */
        unsigned count = 0;
        const makcu_report_t *tr = makcu_mouse_trace(&count);
        char out[16 * 6 + 1];
        size_t n = 0;
        for (unsigned i = 0; i < count; i++) {
            n += (size_t)snprintf(out + n, sizeof(out) - n, "%02x%02x%02x",
                                  (unsigned)(uint8_t)tr[i].dx,
                                  (unsigned)(uint8_t)tr[i].dy,
                                  (unsigned)(uint8_t)tr[i].wheel);
        }
        makcu_reply(out, n);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 'p') {
        const makcu_report_t *r = makcu_mouse_last_report();
        char out[7];
        snprintf(out, sizeof(out), "%02x%02x%02x",
                 (unsigned)(uint8_t)r->dx, (unsigned)(uint8_t)r->dy, (unsigned)(uint8_t)r->wheel);
        makcu_reply(out, 6);
        return 1;
    }
    if (len >= 5 && line[3] == 'r' && line[4] == 't') {
        /* cumulative deltas since boot: proves the step split conserves the
         * request even for moves longer than the 16-entry report ring */
        int32_t tdx = 0, tdy = 0, tw = 0;
        makcu_mouse_totals(&tdx, &tdy, &tw);
        char out[48];
        const int n = snprintf(out, sizeof(out), "%ld,%ld,%ld",
                               (long)tdx, (long)tdy, (long)tw);
        makcu_reply(out, (size_t)n);
        return 1;
    }
    const int hi = hexval(line[3]);
    const int lo = (len > 4) ? hexval(line[4]) : 0;
    if (hi < 0 || lo < 0) {
        return 1;
    }
    const unsigned opcode = (unsigned)((hi << 4) | lo);
    if (opcode >= makcu_opcode_count || makcu_opcode_table[opcode] == NULL) {
        return 1;
    }
    int arg_at = 5;
    while (arg_at < len && (line[arg_at] == ' ' || line[arg_at] == ',')) {
        arg_at++;
    }
    const char *arg = line + arg_at;
    const int arglen = len - arg_at;
    static const makcu_cmd_t synthetic = { "mx", 2, 0, 1, 0 };
    makcu_opcode_table[opcode](arg, arglen, makcu_dev_instance(), &synthetic, arg, arglen);
    return 1;
}
#endif

static void handle_line(const char *line, int len)
{
    if (len <= 0) {
        return;
    }
#if MB_DEBUG_OPCODE
    if (handle_debug_line(line, len)) {
        return;
    }
#endif
    int skip = 0;
    const makcu_cmd_t *entry = makcu_lookup(line, len, &skip);
    if (entry == NULL) {
        return;                      /* unknown command: no reply at all */
    }
    if (entry->opcode >= makcu_opcode_count) {
        return;
    }
    makcu_handler_t fn = makcu_opcode_table[entry->opcode];
    if (fn == NULL) {
        return;                      /* not ported yet: same as "no reply" */
    }
    fn(line, len, makcu_dev_instance(), entry, line + skip, len - skip);
}

/* Control-port byte sink: binary fast path first, otherwise assemble a text line.
 * State is file scope because the task now delivers the bytes of one UART event at
 * a time (see control_port_task). */
static QueueHandle_t s_control_evt;
static uint8_t       s_rx[1024];
static char          s_line[CONTROL_LINE_MAX];
static size_t        s_used;

static void control_process(const uint8_t *buf, int n)
{
    for (int i = 0; i < n; i++) {
        const uint8_t byte = buf[i];
        /* A 0x5A may only open a frame at line start, so a 'Z' inside a text
         * command is still ordinary text. */
        if (cb_feed(byte, s_used == 0)) {
            continue;
        }
        if (byte == '\r' || byte == '\n') {
            if (s_used > 0) {
                const char *p = s_line;
                int len = (int)s_used;
                if (len > 0 && p[0] == CONTROL_TEXT_MARK) {   /* '.' frame marker */
                    p++;
                    len--;
                }
                if (len > 3 && memcmp(p, CONTROL_PREFIX, 3) == 0) {
                    p += 3;                                   /* "km." is re-added on reply */
                    len -= 3;
                }
                handle_line(p, len);
            }
            s_used = 0;
            continue;
        }
        if (s_used + 1 >= sizeof(s_line)) {   /* overlong: drop and resync */
            s_used = 0;
            continue;
        }
        s_line[s_used++] = (char)byte;
    }
}

static void control_port_task(void *arg)
{
    (void)arg;
    /* Bulk reads + the driver's event queue.
     *
     * Byte-at-a-time reads cost 5-15 us of syscall overhead each (fatal at 92
     * kB/s), and `uart_read_bytes(buf, 1024, 20ms)` waits for the FULL length or
     * the timeout - measured 2026-11-10: every reply was ~20 ms late because a
     * 12-byte frame never filled the buffer.  Reading exactly event.size bytes
     * with a zero timeout removes both problems; the queue tells us when data is
     * really there. */
    uart_event_t ev;
    /* CONFIG_FREERTOS_HZ is 100 on this board, so pdMS_TO_TICKS(5) is ZERO and a
     * short timeout would turn this loop into a spin that starves IDLE0 (measured:
     * task watchdog fired with "CPU 0: km_uart0").  Block for real instead: the
     * event queue is the only thing that should wake this task. */
#if MB_CONTROL_USB_JTAG
    const TickType_t idle_wait = 1;          /* one tick: leaves room for the JTAG poll */
#else
    const TickType_t idle_wait = portMAX_DELAY;
#endif
    for (;;) {
        if (s_control_evt != NULL &&
            xQueueReceive(s_control_evt, &ev, idle_wait) == pdTRUE) {
            if (ev.type == UART_DATA && ev.size > 0) {
                size_t want = ev.size;
                if (want > sizeof(s_rx)) {
                    want = sizeof(s_rx);
                }
                const int got = uart_read_bytes(CONTROL_UART, s_rx, want, 0);
                if (got > 0) {
                    control_process(s_rx, got);
                }
            } else if (ev.type == UART_FIFO_OVF || ev.type == UART_BUFFER_FULL) {
                uart_flush_input(CONTROL_UART);
                xQueueReset(s_control_evt);
            }
            continue;                       /* drain the queue before idling */
        }
#if MB_CONTROL_USB_JTAG
        const int jg = usb_serial_jtag_read_bytes(s_rx, sizeof(s_rx), 0);
        if (jg > 0) {
            control_process(s_rx, jg);
        }
#endif
    }
}

void app_main(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    const uart_config_t cfg = {
        .baud_rate = CONTROL_BAUD,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    ESP_ERROR_CHECK(uart_driver_install(CONTROL_UART, CONTROL_RX_BUF, CONTROL_TX_BUF, 20, &s_control_evt, 0));
    ESP_ERROR_CHECK(uart_param_config(CONTROL_UART, &cfg));

#if MB_CONTROL_USB_JTAG
    /* Bench path: accept the same protocol on the native USB-Serial-JTAG port. */
    usb_serial_jtag_driver_config_t jtag_cfg = {
        .tx_buffer_size = 512,
        .rx_buffer_size = CONTROL_RX_BUF,
    };
    if (usb_serial_jtag_driver_install(&jtag_cfg) != ESP_OK) {
        ESP_LOGW(TAG, "usb-serial-jtag driver not installed; UART0 only");
    }
#endif

    makcu_dev_reset();
    makcu_reply_set_writer(control_write);
    cb_reset(control_write);            /* binary fast path shares the same writer */
    makcu_hid_report_hook = bench_report;
    /* A previously pinned identity (mx.vp) lives in NVS and must be in place
     * before the auto-clone runs, so adopt() keeps it. */
    makcu_clone_identity_override_load();

    makcu_mouse_init();
    makcu_keyboard_init();
    /* sumv：1000 Hz 拟人化相对移动。文本层通过 hook 调它，旧 .km.move 入口在
     * sumv 运行期间被拒（双运动源会互相拉扯）。 */
    btn_evt_init();                     /* 按键事件通道（订阅即消费） */
    makcu_evt_ctl_hook = btn_evt_ctl_adapter;
    makcu_evt_mask_hook = btn_evt_mask;
    makcu_sumv_init();
    makcu_sumv_start_hook = sumv_start_adapter;
    makcu_sumv_stop_hook = makcu_sumv_stop;
    makcu_sumv_active_hook = makcu_sumv_active;
    s_move_hook_orig = makcu_mouse_move_hook;
    makcu_mouse_move_hook = move_hook_guarded;
    makcu_link_bridge_init();
#if MB_CLONE_FIXTURE
#if MB_CLONE_FIXTURE == 99
    /* Auto-clone: read the descriptors of whatever mouse is behind the right chip
     * over the 0xA1 EP0 tunnel, then enumerate as that device.  Falls back to the
     * byte-exact fixture when no mouse answered in time. */
    bool cloned = autoclone_from_link();
#if defined(MB_DUAL_IF)
    if (cloned) {
        const makcu_clone_t *c0 = makcu_clone_get();
        if (c0 == NULL || c0->if_count == 0) {
            /* 复合接口一个都没抓到 = 这份 clone 是残的。实测出现过 `mx.as=1` 但
             * `mx.if=0`、PC 侧看到的其实是 4 字节 fixture，注入/屏蔽全部错位。
             * 给右片 300 ms 再抓一次，还不行就按失败处理（交给自愈重试）。 */
            vTaskDelay(pdMS_TO_TICKS(300));
            cloned = autoclone_from_link();
            const makcu_clone_t *c1 = makcu_clone_get();
            if (c1 != NULL && c1->if_count > 0) {
                ESP_LOGW(TAG, "auto-clone needed a retry (interfaces were empty)");
            } else {
                ESP_LOGE(TAG, "auto-clone captured 0 interfaces: treating as failure");
                cloned = false;
            }
        }
    }
#endif
    if (!cloned) {
        /* 右片（host）刚上电时可能还没枚举到鼠标 —— 单次探测失败就退回 4 字节夹具，
         * 之后真实鼠标的 7 字节报告会被当 12-bit 解，位移/按键全错（实测在台架回归里
         * 表现为"跑一半开始成片失败"，`mx.if` 变 0、`mx.rb` 变 bytes=4）。
         * 所以这里多等一会儿：最多 10 次 × 300 ms。 */
        for (int attempt = 1; attempt <= 10 && !cloned; attempt++) {
            vTaskDelay(pdMS_TO_TICKS(300));
            cloned = autoclone_from_link();
            if (cloned) {
                const makcu_clone_t *c = makcu_clone_get();
                if (c == NULL || c->if_count == 0) {
                    cloned = false;
                } else {
                    ESP_LOGW(TAG, "auto-clone ok after %d retries", attempt);
                }
            }
        }
    }
    if (cloned) {
        s_autoclone_status = 1;
        ESP_LOGI(TAG, "auto-clone ok");
    } else {
        s_autoclone_status = 2;
        const makcu_clone_t *prev = makcu_clone_get();
        if (prev != NULL && prev->valid && prev->from_device) {
            /* Keep what we cloned last time: the right chip loses the mouse on a
             * left-chip reset, so the boot probe often cannot see a device, but a
             * stored clone still gives the host the right identity. */
            ESP_LOGW(TAG, "auto-clone: no device, keeping the stored clone");
        } else {
            ESP_LOGW(TAG, "auto-clone: no device, falling back to fixture REAL");
            (void)makcu_clone_apply_fixture(MAKCU_CLONE_FIXTURE_REAL);
            /* 实测：左片 mx.rs 重启后，右片要过几秒才重新枚举到鼠标，开机那 3 s 里抓不到，
             * 一旦退回 4 字节夹具就一直错着（PC 看到 bytes=4，真实 7 字节报告被按 12-bit 解）。
             * 这里挂一个"请自愈"标记：heal 任务 ~2 s 后会再抓一次，成功就重新枚举成真实克隆。
             * 只挂一次（不是周期轮询），不会干扰台架测试的时序。 */
            s_reclone_check = true;
        }
    }
#else
    /* Bench: load a canned identity before the device stack enumerates, so the
     * very first enumeration already uses the cloned descriptors. */
    makcu_clone_apply_fixture(MB_CLONE_FIXTURE);
#endif
#endif
#if MB_HID_DEVICE
    makcu_hiddev_init();
    makcu_hid_report_hook = mouse_hook_tap;            /* mouse reports over USB (+ mx.mt tap) */
    makcu_kbd_emit_hook = makcu_hiddev_kbd_report;     /* keyboard reports over USB */
    makcu_link_set_custom_hook(custom_hook);
    makcu_link_set_report_sink(link_report_to_mouse);   /* 0xA2 -> mouse layer */
    xTaskCreate(heal_task, "km_heal", 4096, NULL, 4, NULL);

    makcu_hiddev_set_out_hook(out_to_right);            /* host OUT -> 0xA5 */

    s_outq = xQueueCreate(OUTQ_DEPTH, sizeof(out_item_t));
    if (s_outq != NULL) {
        xTaskCreate(out_worker, "km_outq", 4096, NULL, 8, NULL);
    }
    makcu_hiddev_set_pump_hook(makcu_mouse_pump);       /* host-paced emission */
#endif
    report_missing_handlers();
    makcu_frame_router_init();

    xTaskCreate(control_port_task, "km_uart0", 6144, NULL, 10, NULL);
    ESP_LOGI(TAG, "control port up at %d baud", CONTROL_BAUD);
}
