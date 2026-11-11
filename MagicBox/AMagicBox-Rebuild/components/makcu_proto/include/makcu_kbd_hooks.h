/* Keyboard/mouse-report hooks.
 *
 * All eight hidden keyboard opcodes end in one of these calls, then reply.  The
 * real implementations live in makcu_keyboard (HID report writes) and are not
 * ported yet, so the protocol layer calls through pointers and keeps the wire
 * behaviour identical (reply with the echoed line when the parse succeeded).
 */
#ifndef MAKCU_KBD_HOOKS_H
#define MAKCU_KBD_HOOKS_H

#include <stdint.h>

typedef int (*makcu_key_fn)(void *dev, uint16_t usage);
typedef int (*makcu_key_tap_fn)(void *dev, uint16_t usage, int min_ms, int max_ms);
typedef int (*makcu_type_fn)(void *dev, const char *text, int len);
typedef int (*makcu_keys_fn)(void *dev, const int16_t *usages, int count);
typedef int (*makcu_keys_combo_fn)(void *dev, const int16_t *usages, int count,
                                   int min_ms, int max_ms);
typedef int (*makcu_key_state_fn)(void *dev, uint16_t usage);

extern makcu_key_fn        makcu_key_down_hook;      /* 0x42010E70 */
extern makcu_key_fn        makcu_key_up_hook;        /* 0x42010F00 */
extern makcu_key_tap_fn    makcu_key_tap_hook;       /* 0x42010F8C */
extern makcu_type_fn       makcu_type_string_hook;   /* 0x42010FDC */
extern makcu_keys_fn       makcu_keys_down_hook;     /* 0x42011098 */
extern makcu_keys_fn       makcu_keys_up_hook;       /* 0x420110B4 */
extern makcu_keys_combo_fn makcu_keys_combo_hook;    /* 0x420110D0 */
extern makcu_key_state_fn  makcu_key_state_hook;     /* 0x4201100C */

#endif /* MAKCU_KBD_HOOKS_H */
