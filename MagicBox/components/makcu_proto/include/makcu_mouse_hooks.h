/* Motion hooks.
 *
 * The text handlers (protocol layer) must stay linkable before the motion path
 * exists, and the motion component must be free to appear later in the link
 * order.  So the protocol side calls through these pointers instead of a direct
 * reference; makcu_mouse installs them in makcu_mouse_init().
 *
 * Semantics come from the original call chain:
 *   0x42010BC4  mouse_move(dev, dx, dy, mode)      - 2-arg / 3-4arg path
 *   0x4200F744  mouse_submit_ext(dev, v0..v4)      - 5-arg path
 */
#ifndef MAKCU_MOUSE_HOOKS_H
#define MAKCU_MOUSE_HOOKS_H

#include <stdint.h>

typedef int (*makcu_mouse_move_fn)(void *dev, int16_t dx, int16_t dy, uint32_t mode);
typedef int (*makcu_mouse_move_ext_fn)(void *dev, int16_t v0, int16_t v1,
                                       int16_t v2, int16_t v3, int16_t v4);

/* 0x42010D3C pulse_move: move, wait for the commit semaphore, move back. */
typedef int (*makcu_mouse_pulse_fn)(void *dev, int16_t dx, int16_t dy);

extern makcu_mouse_move_fn     makcu_mouse_move_hook;
extern makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;
extern makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;

/* 0x4200F96C wheel_submit: store the int8 delta, raise the commit request. */
typedef int (*makcu_wheel_fn)(void *dev, int8_t delta);
extern makcu_wheel_fn          makcu_wheel_hook;

#endif /* MAKCU_MOUSE_HOOKS_H */
