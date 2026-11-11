/* evt hooks: 文本协议层要能在不依赖 app 的情况下调用按键事件通道。 */
#ifndef MAKCU_EVT_HOOKS_H
#define MAKCU_EVT_HOOKS_H

#include <stdbool.h>
#include <stdint.h>

typedef void    (*makcu_evt_ctl_fn)(bool enable, uint8_t mask, bool push, bool consume);
typedef uint8_t (*makcu_evt_mask_fn)(void);

extern makcu_evt_ctl_fn  makcu_evt_ctl_hook;
extern makcu_evt_mask_fn makcu_evt_mask_hook;

#endif /* MAKCU_EVT_HOOKS_H */
