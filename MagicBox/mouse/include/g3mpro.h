/* G3M PRO (HECATE) vendor protocol facts - everything measured, nothing guessed.
 *
 * Sources: USBPcap captures of HECATE Connect talking to the mouse directly
 * (2026-11-10, the old work/usbpcap captures, since purged from the repo) and the
 * bench replays done on 2026-11-12.  Anything not measured is marked [guess] and
 * must stay "no reply expected / free rate" until a capture says otherwise.
 */
#ifndef G3MPRO_H
#define G3MPRO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "mouse_vendor.h"

/* ---- identity (receiver family, unified by the alias policy in makcu_clone) - */
#define G3M_VID_PRIMARY   0x320Fu
#define G3M_PID_PRIMARY   0x706Eu
#define G3M_PID_FAMILY    0xF000u          /* PID mask of the F0Dx receivers */
#define G3M_VID_0E8C      0x0E8Cu
#define G3M_VID_0ECC      0x0ECCu
#define G3M_VID_06CC      0x06CCu
#define G3M_VID_068C      0x068Cu

/* ---- wire shape ---------------------------------------------------------- */
#define G3M_VEN_LEN       64u              /* fixed-length vendor report       */
#define G3M_VEN_RID       0x04u            /* byte 0: HID report id            */
#define G3M_EP_IN_HOST    0x82u            /* vendor/keyboard IN to the PC     */
#define G3M_EP_IN_DEV     0x82u            /* ... and on the device side       */
#define G3M_EP_OUT_HOST   0x03u            /* vendor OUT from the PC           */
#define G3M_EP_OUT_DEV    0x05u            /* vendor OUT to the mouse          */

/* ---- timing (measured) --------------------------------------------------- */
/* Two config writes closer than this lost 5-9% of the answers on replay;
 * 40 ms lost none.  This is why the rate limit belongs to the protocol. */
#define G3M_MIN_WRITE_GAP_MS  40u
#define G3M_MIN_READ_GAP_MS   10u          /* reads are free to poll [guess]   */
#define G3M_ACK_WAIT_MS       20u          /* 2 FreeRTOS ticks @ 100 Hz        */
#define G3M_RESEND_MAX        2u

/* ---- command classes (from the capture; [guess] where noted) -------------- */
#define G3M_CMD_BATTERY   0xAAu            /* heartbeat/poll, PC does not wait  */
#define G3M_CMD_CFG_READ  0x02u            /* read one config block            */
#define G3M_CMD_INFO_1B   0x1Bu
#define G3M_CMD_INFO_1D   0x1Du
#define G3M_CMD_INFO_1F   0x1Fu
#define G3M_CMD_INFO_20   0x20u
#define G3M_CMD_DPI_WRITE 0x35u            /* write DPI block                  */
#define G3M_CMD_DPI_COMMIT 0x37u           /* commit/apply                     */
#define G3M_CMD_POLL_56   0x56u
#define G3M_CMD_POLL_7F   0x7Fu
#define G3M_CMD_POLL_90   0x90u

/* ---- DPI read/write state machine (R4; observed passively until then) ---- */
typedef enum {
    G3MPRO_DPI_IDLE = 0,
    G3MPRO_DPI_READ,        /* 0x02 issued                                    */
    G3MPRO_DPI_VALIDATE,    /* read answered, block looks sane                */
    G3MPRO_DPI_WRITE,       /* 0x35 issued                                    */
    G3MPRO_DPI_COMMIT,      /* 0x37 issued                                    */
    G3MPRO_DPI_VERIFY,      /* 0x02 again, value must match what we wrote      */
    G3MPRO_DPI_OK,
    G3MPRO_DPI_ERR,
} g3mpro_dpi_state_t;

/* The only vendor-frame predicate in the firmware. */
bool g3mpro_is_vendor_frame(const uint8_t *data, uint16_t len);
/* 2026-11-12（R1.4）：**路由用**的判据，比上面宽松——厂商端点上凡是首字节 0x04 的都算厂商流量。
 * 原因：按下鼠标 DPI 键时，设备会主动发一条"状态已变化"的通知，长度不一定是 64 B；
 * 若按 64 B 判定，这条通知会被当成鼠标报告解码掉，HECATE 收不到 → 显示不同步（直插能同步）。
 * 记账/协议解析仍用 64 B 版本（g3mpro_is_vendor_frame）。 */
bool g3mpro_is_vendor_port(const uint8_t *data, uint16_t len);
bool g3mpro_match(uint16_t vid, uint16_t pid);
bool g3mpro_expects_reply(uint8_t cmd);
uint32_t g3mpro_min_gap_ms(uint8_t cmd);
/* Human-readable command name for logs/README tables ("unknown" otherwise). */
const char *g3mpro_cmd_name(uint8_t cmd);

void g3mpro_on_host_out(const uint8_t *data, uint16_t len);
void g3mpro_on_dev_in(const uint8_t *data, uint16_t len);
void g3mpro_note_out(const uint8_t *data, uint16_t len);   /* compat: == on_host_out */
void g3mpro_note_in(const uint8_t *data, uint16_t len);    /* compat: == on_dev_in   */
void g3mpro_stats(mouse_vendor_stats_t *out);

/* 逐条往返延迟（OUT 发出 -> 同 cmd 的 IN 到达），单位 µs。
 * 直连基线：p50 6.6 ms / p90 9.0 ms / max 19.6 ms。经盒子若 p50 明显更大，
 * 就说明盒子内部有等待（不是协议内容问题）。 */
typedef struct {
    uint32_t n;
    uint32_t last_us;
    uint32_t avg_us;
    uint32_t max_us;
    uint32_t p50_us;
    uint32_t p99_us;
} g3mpro_lat_t;
void g3mpro_latency(g3mpro_lat_t *out);

/* 2026-11-12（R1.4 诊断）：帧内容取样器。
 * 记录最近若干条**互不相同**的 64 B OUT / IN 帧（前 12 字节 + 命中次数 + 最近时刻），
 * 用来回答"HECATE 到底有没有读、读回来的内容有没有变"——不需要 USBPcap。
 * 返回写入 out 的字节数（"\n" 分隔的文本行）。 */
size_t g3mpro_dump_distinct(char *out, size_t cap);


#endif /* G3MPRO_H */
