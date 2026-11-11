/* Keyboard output layer (device side).
 *
 * What the original does (addresses from the reversed tree):
 *   0x42010E70 hid_key_down     press one usage id
 *   0x42010F00 hid_key_up       release one usage id
 *   0x42010F8C hid_key_tap      press, wait a random delay in [min,max], release
 *   0x42010FDC hid_type_string  type an ASCII string (shift handled per char)
 *   0x42011098 hid_keys_down    press a batch (<= 6)
 *   0x420110B4 hid_keys_up      release a batch
 *   0x420110D0 hid_keys_combo   press all, then release in reverse
 *   0x4201100C hid_key_state_read  report whether a usage is currently held
 *   0x4202D57C / 0x4202D5C4     bit helpers on the 8-byte HID report
 *
 * This component keeps the 6KRO state (modifiers + six usages), builds the
 * 8-byte boot-keyboard report and hands it to whatever sink is installed
 * (makcu_hiddev in a HID build, the bench trace otherwise).
 */
#ifndef MAKCU_KEYBOARD_H
#define MAKCU_KEYBOARD_H

#include <stdint.h>

#define MAKCU_KBD_REPORT_LEN 8
#define MAKCU_KBD_TRACE      8

/* Sink installed by the USB layer. */
typedef void (*makcu_kbd_emit_fn)(const uint8_t *report8);
extern makcu_kbd_emit_fn makcu_kbd_emit_hook;

/* Install the hooks the protocol layer calls. */
void makcu_keyboard_init(void);

/* Current 8-byte report (modifiers, reserved, six usages). */
const uint8_t *makcu_keyboard_report(void);

/* Ring of the most recent reports, chronological order. */
const uint8_t *makcu_keyboard_trace(unsigned *count);

#endif /* MAKCU_KEYBOARD_H */
