/* Keyboard hooks - NULL until makcu_keyboard installs the HID writers. */
#include "makcu_kbd_hooks.h"

makcu_key_fn        makcu_key_down_hook;
makcu_key_fn        makcu_key_up_hook;
makcu_key_tap_fn    makcu_key_tap_hook;
makcu_type_fn       makcu_type_string_hook;
makcu_keys_fn       makcu_keys_down_hook;
makcu_keys_fn       makcu_keys_up_hook;
makcu_keys_combo_fn makcu_keys_combo_hook;
makcu_key_state_fn  makcu_key_state_hook;
