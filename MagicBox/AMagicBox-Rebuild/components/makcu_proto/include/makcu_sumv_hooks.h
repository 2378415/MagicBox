/* sumv hooks: the text protocol layer must stay linkable without the engine
 * component (same pattern as makcu_mouse_hooks.h).  The engine installs these in
 * makcu_sumv_init(); the app wires them up.
 */
#ifndef MAKCU_SUMV_HOOKS_H
#define MAKCU_SUMV_HOOKS_H

#include <stdbool.h>
#include <stdint.h>

typedef bool (*makcu_sumv_start_fn)(int16_t dx, int16_t dy, uint16_t speed,
                                    uint16_t dur_ms, uint8_t mode, uint8_t seed);
typedef void (*makcu_sumv_stop_fn)(void);
typedef bool (*makcu_sumv_active_fn)(void);

extern makcu_sumv_start_fn  makcu_sumv_start_hook;
extern makcu_sumv_stop_fn   makcu_sumv_stop_hook;
extern makcu_sumv_active_fn makcu_sumv_active_hook;

#endif /* MAKCU_SUMV_HOOKS_H */
