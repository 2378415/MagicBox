/* Binary fast path on the UART0 control port (main/control_bin.c).
 *
 * The text protocol (".km.move(...)") stays the human/bench interface; this is the
 * low-latency interface an external host (Android over the CH343) uses instead.
 * Wire format, little endian:
 *
 *      +0  5A             magic
 *      +1  cmd
 *      +2  seq            echoed in replies, used for gap/loss accounting
 *      +3  len (u16)      payload length
 *      +5  payload[len]
 *      +5+len crc8        poly 0x07, over cmd..payload (i.e. bytes 1 .. 4+len)
 *
 * Interaction path is fire-and-forget: MOTION_PLAN / BUTTON / WHEEL never answer.
 * Only QUERY and PING reply (cmd | 0x80, same seq).  Because there is no ack, the
 * only way to see loss is the sequence gap and CRC counters that QUERY 0 returns.
 *
 * MOTION_PLAN currently drives the existing submit hook (the chunked/Bezier
 * engine); when the 1000 Hz planner lands it is swapped in here and `plan_engine`
 * in QUERY 1 flips from 0 to 1.
 */
#ifndef CONTROL_BIN_H
#define CONTROL_BIN_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Command bytes.  Replies use cmd | 0x80. */
#define CB_CMD_MOTION_PLAN 0x31
#define CB_CMD_BUTTON      0x32
#define CB_CMD_WHEEL       0x33
#define CB_CMD_QUERY       0x34
#define CB_CMD_PING        0x35
/* 重建扩展：拟人化相对移动（1000 Hz 采样，见 makcu_sumv） */
#define CB_CMD_SUMV        0x36
#define CB_CMD_SUMV_STOP   0x37
#define CB_CMD_SUMV_STATE  0x38
/* 按键事件（订阅即消费）：见 app_left/main/btn_evt.h */
#define CB_CMD_EVT_CTL     0x39
#define CB_CMD_EVT_READ    0x3A
#define CB_CMD_EVT_STAT    0x3B
#define CB_CMD_AIM         0x3C   /* 瞄准专用：dx dy max_ms flags [dead_min] */
#define CB_CMD_AIM_STATE   0x3D   /* 12 B 状态 */
#define CB_CMD_HID_STAT    0x3E   /* 8 B：btn_in, btn_sent, wait_max_us, btn_overflow */
#define CB_CMD_BTN_AUDIT   0x3F   /* 12 B：in_chg, out_chg, extra（按键回环审计） */
#define CB_CMD_AIM_RESET   0x40   /* 清空 AIM_STATE 累计量（rounds/aborted/死区/上次结果） */
#define CB_CMD_EVT_RESET   0x41   /* 清空事件环与统计（overflow/seq） */
#define CB_CMD_BTN_CNT     0x45   /* 16 B 诊断计数：link_frames/btn_nonzero/fwd_drop/swallowed */
#define CB_CMD_BTN_LOG     0x44   /* 请求 since u16；回 total u16, count u8, count×8B 记录 */
#define CB_CMD_LAST_HID    0x42   /* 10 B：上一条 HID 报告（rid, len, 8 字节） */
/* 异步段 0xE0-0xEF：设备主动发，不带 |0x80 的回包语义 */
#define CB_EVT_PUSH        0xE1
#define CB_REPLY_FLAG      0x80

#define CB_MAX_PAYLOAD 64

/* Writer used for replies; the app passes its UART0 writer. */
typedef void (*cb_write_fn)(const void *data, size_t len);

void cb_reset(cb_write_fn writer);

/* Feed one byte.  `at_line_start` is true while the text assembler is empty - a
 * 0x5A may only open a frame there, so a 'Z' inside a text command cannot be
 * mistaken for a frame start.  Returns true when the byte was consumed by the
 * frame parser. */
bool cb_feed(uint8_t byte, bool at_line_start);

void cb_stats(uint32_t *pkts, uint32_t *crc_err, uint32_t *len_err,
              uint32_t *gaps, uint8_t *last_seq, uint32_t *plans);

#endif /* CONTROL_BIN_H */
