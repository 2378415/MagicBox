/* Mouse commit layer.
 *
 * The original split (addresses from the reversed tree):
 *   0x42010BC4 mouse_move(dev,x,y,mode)        mode<2 -> default submit, else mode submit
 *   0x4200F8E4 mouse_submit_default(dev,x,y)   pending dx/dy, move flag, commit request
 *   0x4200F744 mouse_submit_ext(dev,...,w,v)   extended form (mode 1..0x3FF)
 *   0x4200EFEC mouse_submit(...)               the Bezier interpolation engine
 *   0x4200F96C wheel_submit(dev,delta)         pending wheel + commit request
 *   0x4200F848 mouse_commit_task               waits for the request, emits reports
 *   0x42010D3C pulse_move(dev,dx,dy)           forward, wait, backward, wait
 *
 * What is ported here:
 *   - the whole queue/request layer (flags, pending values, task wake-up);
 *   - the report emission path, behind makcu_hid_report_hook();
 *   - the int8 step split (ceil(span/127) reports, one random bow per move) with
 *     a largest-remainder pass so the steps sum to the request exactly.
 *
 * What is still approximate (see docs/40-status.md): the Bezier interpolation in
 * 0x4200EFEC (32 KB of decompiled C, uses cos/sin/__fixdfsi).  The rebuild uses a
 * quadratic Bezier with a random perpendicular control offset instead of the
 * original's random rotation + double-precision easing: same observable shape
 * (bowed path, bounded excursion, exact sum), not bit-identical numbers.
 */
#ifndef MAKCU_MOUSE_H
#define MAKCU_MOUSE_H

#include <stdint.h>
#include <stdbool.h>

/* One HID mouse report as the device side will send it. */
typedef struct {
    int8_t  dx;
    int8_t  dy;
    int8_t  wheel;
    uint8_t buttons;
} makcu_report_t;

/* Provided by the HID device layer (or the bench test hook). */
typedef void (*makcu_hid_report_fn)(const makcu_report_t *report);
extern makcu_hid_report_fn makcu_hid_report_hook;

/* Last report emitted (bench observability, used by the mx.rp test command). */
const makcu_report_t *makcu_mouse_last_report(void);

/* Cumulative delta of every report emitted since boot (mx.rt).  Lets a test
 * assert that the int8 step split conserves the request exactly, even when the
 * report ring only keeps the newest 16. */
void makcu_mouse_totals(int32_t *dx, int32_t *dy, int32_t *wheel);

/* Ring of the most recent reports, for the mx.rq trace command and the T2
 * checks that assert "how the movement was split". */
#define MAKCU_REPORT_TRACE 16
const makcu_report_t *makcu_mouse_trace(unsigned *count);

/* Bring the commit layer up and install the mouse hooks used by the protocol. */
void makcu_mouse_init(void);

/* Pass-through submission: ADD to the pending delta instead of replacing it, so
 * a 1 kHz source feeding a ~100 Hz commit task never loses motion. */
int makcu_mouse_submit_delta(int16_t dx, int16_t dy, int8_t wheel);

/* Button state carried by the next emitted report (report byte 0). */
void makcu_mouse_set_buttons(uint8_t buttons);

/* 只同步按键状态（不发报告、不计入审计）：透传路径用它保持与引擎一致。 */
void makcu_mouse_sync_buttons(uint8_t buttons);
/* 2026-11-12: is a button-change request still pending?  hiddev uses this to decide
 * whether an engine report may carry its own button byte: everything except an
 * explicit request (0x32 BUTTON / set_buttons) must keep the last on-wire byte. */
bool makcu_mouse_btn_requested(void);
/* 2026-11-12：注入按键事件（0x32），强制立即上线、不受 2 ms 让路窗口影响。 */
void makcu_mouse_emit_event(uint8_t buttons);

/* 按键回环审计：in_chg = 请求的按键变化数，out_chg = 实际发出的变化数，
 * extra = 超出请求的多发次数。正常终态 in_chg == out_chg 且 extra == 0。 */
void makcu_mouse_btn_audit(uint32_t *in_chg, uint32_t *out_chg, uint32_t *extra);

/* Emit one report right away (button-only changes have no displacement to queue). */
void makcu_mouse_emit_now(int8_t dx, int8_t dy, int8_t wheel);

/* 按键变化优先级最高：立即设置并补发一条零位移报告，绕过 pending 合并与转发去抖。 */
void makcu_mouse_button_priority(uint8_t buttons);

/* Pass-through forward: emit this report's delta *unchanged* when the endpoint is
 * free.  Batching small deltas into one bigger report changes Windows pointer
 * acceleration (it is computed per report), which makes the cursor feel faster
 * than the physical mouse.  Only when the endpoint is busy does the delta fall
 * into the accumulator, and makcu_mouse_pump() flushes it afterwards. */
void makcu_mouse_forward(int8_t dx, int8_t dy, int8_t wheel, uint8_t buttons);

/* Emit at most one int8-sized step of the pending delta, keeping the remainder.
 * Called from the HID report-complete callback: the endpoint has just been
 * released, so the report cannot collide with a transfer that is still in
 * flight (that collision is what leaks TinyUSB's endpoint claim). */
void makcu_mouse_pump(void);

/* Task body; call from a task created by the app. */
void makcu_mouse_task(void *arg);

#endif /* MAKCU_MOUSE_H */

