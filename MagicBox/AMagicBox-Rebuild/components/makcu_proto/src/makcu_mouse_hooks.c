/* Motion hooks - NULL until makcu_mouse installs them. */
#include "makcu_mouse_hooks.h"

makcu_mouse_move_fn     makcu_mouse_move_hook;
makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;
makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;
makcu_wheel_fn          makcu_wheel_hook;
