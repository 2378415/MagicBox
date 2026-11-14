/* cmd_evt - opcode 0x1D（重建扩展，非原厂命令）。
 *
 *   .km.evt(1)              订阅全部按键（1=左 2=右 4=中 8=侧4 16=侧5）——**默认穿透**
 *   .km.evt(1,8)            只订阅侧键 4
 *   .km.evt(1,8,1)          订阅并"吃掉"侧键 4（PC 看不到这次点击）
 *   .km.evt(0)              取消订阅（恢复全透传）
 *   .km.evt()               -> evt()\n<mask>
 *
 * 2026-11-11 语义变更：默认从"订阅即消费"改成**订阅即穿透**（只报事件，按键照常给 PC），
 * 想吃掉必须显式传第 3 个参数 1。
 *
 * 注意：文本订阅只负责"消费 + 记录到事件环"，事件本身建议用二进制 EVT_READ /
 * EVT_PUSH 取（见 docs/API-control-port.md）；文本侧没有事件行推送。
 */
#include "makcu_cmd.h"
#include "makcu_evt_hooks.h"
#include "makcu_parse.h"
#include "makcu_reply.h"

void cmd_evt(const char *buf, int len, void *dev,
             const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)dev;
    (void)entry;

    int16_t v[3] = {0};
    const int n = makcu_parse_int16_list(arg, arglen, v, 3);

    if (n == 0) {                                     /* 查询 */
        uint8_t mask = 0;
        if (makcu_evt_mask_hook != NULL) {
            mask = makcu_evt_mask_hook();
        }
        makcu_reply_status("evt()", 5, mask);
        return;
    }
    if (makcu_evt_ctl_hook == NULL) {
        makcu_reply_echo(buf, len);
        return;
    }
    if (v[0] == 0) {
        makcu_evt_ctl_hook(false, 0, false, false);
        makcu_reply_echo(buf, len);
        return;
    }
    const uint8_t mask = (n >= 2) ? (uint8_t)(v[1] & 0x1F) : 0x1F;
    const bool consume = (n >= 3) && (v[2] != 0);
    makcu_evt_ctl_hook(true, mask, false, consume);
    makcu_reply_echo(buf, len);
}
