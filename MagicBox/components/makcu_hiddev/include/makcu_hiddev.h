/* USB HID device (device side): bring-up and report forwarding. */
#ifndef MAKCU_HIDDEV_H
#define MAKCU_HIDDEV_H

#include <stdbool.h>
#include <stdint.h>

#include "makcu_mouse.h"        /* makcu_report_t */

/* Initialise the PHY + TinyUSB device stack and start the tud_task loop. */
void makcu_hiddev_init(void);

/* Re-enumerate so a changed descriptor store takes effect. */
void makcu_hiddev_rebind(void);

/* True when tusb_init() succeeded. */
bool makcu_hiddev_init_ok(void);

/* True once the host has configured us (tud_mount_cb). */
bool makcu_hiddev_mounted(void);

/* Send one 4-byte mouse report (buttons, dx, dy, wheel). */
void makcu_hiddev_report(const makcu_report_t *r);

/* Send a report body verbatim (0xA2 pass-through from the right chip).  The
 * active descriptor's Report ID convention decides whether an ID is prefixed. */
void makcu_hiddev_report_raw(const uint8_t *data, uint16_t len);

/* Raw-injection counters (mx.hv): attempts / accepted by the stack / endpoint busy. */
/* Send the bytes exactly as received (clone declares the same layout). */
void makcu_hiddev_report_verbatim(const uint8_t *data, uint16_t len);

/* Same, but routed to the HID interface that owns this endpoint (composite clone). */
void makcu_hiddev_report_verbatim_ep(uint8_t ep, const uint8_t *data, uint16_t len);

/* Vendor-frame predicate, injected by the application (2026-11-12).
 * The generic HID layer must not know "64 bytes / first byte 0x04": that is
 * protocol knowledge and it lives in mouse/src/g3mpro.c.  Pass NULL to disable. */
void makcu_hiddev_set_ven_filter(bool (*fn)(const uint8_t *data, uint16_t len));
uint32_t makcu_hiddev_ven_frames(void);
/* 厂商/键盘 IN 队列（R1.2）：入队/发出/丢弃/当前深度。正常稳定态 dropped 应恒为 0。 */
void makcu_hiddev_ven_queue(uint32_t *queued, uint32_t *sent, uint32_t *dropped,
                            uint8_t *depth);

/* 控制请求取样（mx.vd）：G/S + 实例 + report_id + type + len + 次数。 */
size_t makcu_hiddev_ctl_dump(char *out, size_t cap);
/* 2026-11-12：真实鼠标透传入口（带"注入主持权"窗口）。
 * 注入按键（0x32）活跃期间，透传报告的按键位会被对齐到注入状态，
 * 避免真实鼠标的空闲 0x00 报告把注入的按下/松开盖掉。 */
void makcu_hiddev_passthrough(uint8_t ep, const uint8_t *data, uint16_t len);
void makcu_hiddev_btn_hold_ms(uint32_t ms);
/* 2026-11-13（P1-1）：只保护 mask 里"被注入按住"的位，其余位保持真实值。
 * 注入（0x32）的语义收敛为"这个键位由注入主持"，物理点击用其它键不再被连带抹掉。 */
void makcu_hiddev_btn_hold_bits(uint8_t mask, uint32_t ms);
/* 主持权窗口内，引擎层的按键状态必须同步成"线上状态"，否则真实鼠标的空闲 0x00
 * 会把 s_buttons 改回 0，导致随后注入的"松开"被当成无变化而丢掉（实测 80 次/秒末条丢失）。 */
bool makcu_hiddev_btn_hold_active(void);
uint8_t makcu_hiddev_btn_wire_state(void);

/* Called from tud_hid_report_complete_cb(): the safe moment to queue the next
 * report (the endpoint was just released). */
void makcu_hiddev_set_pump_hook(void (*fn)(void));

/* Reports the host actually completed (mx.hq): send-vs-taken evidence. */
void makcu_hiddev_complete_count(uint32_t *done);

/* Endpoint probe (mx.hr): ready_fail count + ready/suspended/mounted flags. */
void makcu_hiddev_link_state(uint32_t *ready_fail, bool *ready,
                             bool *suspended, bool *mounted);
/* All-callers send counters (mx.hs): ok, busy, failed, no_mount, mounted. */
void makcu_hiddev_send_stats(uint32_t *ok, uint32_t *busy,
                             uint32_t *failed, uint32_t *no_mount, bool *mounted);

void makcu_hiddev_raw_stats(uint32_t *attempts, uint32_t *sent,
                            uint32_t *not_ready, uint32_t *wake,
                            uint32_t *no_mount, bool *mounted);

/* Send the 8-byte boot-keyboard report (modifiers, reserved, six usages). */
void makcu_hiddev_kbd_report(const uint8_t *report8);

/* OUT data written by the host (the 0xA5 source): called from the TinyUSB
 * control task with the HID instance, report id and raw bytes.  Used to forward
 * vendor writes on to the right chip. */
typedef void (*makcu_hiddev_out_hook_t)(uint8_t instance, uint8_t report_id,
                                        const uint8_t *data, uint16_t len);
void makcu_hiddev_set_out_hook(makcu_hiddev_out_hook_t hook);

/* Dual-interface send counters (mx.ds). */
void makcu_hiddev_ep_stats(uint32_t *sent, uint32_t *failed);

/* Input-report size (bytes) derived from the cloned mouse interface's report
 * descriptor, 0 when unknown.  `mx.rb` reads it back: a report shorter than what
 * the descriptor declares is accepted by the stack and then silently dropped by
 * the host (cursor does not move). */
uint8_t makcu_hiddev_report_bytes(void);

/* 按键队列统计（0x3E HID_STAT）：
 *   in          入队次数
 *   sent        真正上了总线的次数
 *   wait_max_us 入队 → 上总线的最大延迟
 *   overflow    队列满而没接下的次数（正常 0；旧报告永远不会被新报告挤掉） */
void makcu_hiddev_button_stats(uint16_t *in, uint16_t *sent, uint16_t *wait_max_us,
                               uint16_t *overflow);

/* 0x42 LAST_HID：out[0]=report_id, out[1]=长度, out[2..9]=报告前 8 字节 */
void makcu_hiddev_last_report(uint8_t *out, uint8_t max);

/* S2：真正上线报告里的按键字节变化次数与洪泛窗口计数（0x3E/0x3F 用） */
void makcu_hiddev_btn_wire(uint16_t *chg, uint16_t *flood, uint16_t *merged, uint16_t *cancel);

/* S4：最近 8 条上线报告的按键字节（最新在最后） */
/* A（2026-11-11）：出队时被改写按键字节的报告数（应≈按下瞬间队列深度）。 */
uint16_t makcu_hiddev_btn_stamped(void);
/* 2026-11-12 取证：把"引入按键变化"的报告按发送路径拆分（直发 / 队列）。 */
void makcu_hiddev_btn_split(uint32_t *direct_chg, uint32_t *queued_chg);

void makcu_hiddev_btn_history(uint8_t *out, uint8_t max);

#endif /* MAKCU_HIDDEV_H */
