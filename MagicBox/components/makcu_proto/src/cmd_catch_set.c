/* cmd_catch_set - opcode 0x0A, handler 0x4200DF58.
 *
 * Shared by `catch_ml(` ... `catch_ms2(` (target 1..5).  Decompiled:
 *
 *   if (arglen == 0) return;                        // silence
 *   target = entry->target;
 *   if (*(uint32_t *)(dev->tbl + 0x54 + target*4) == 0   // channel not enabled
 *       || arg[0] - '0' > 1) {                      // parameter must be 0/1
 *       uart0_reply(buf, len, 0);
 *       return;
 *   }
 *   catch_set(dev, target, arg[0] == '1');          // 0x4202D1AC -> tbl +0x168
 *   *DAT_42000DAC = 1;                              // dirty flag
 *   uart0_reply(buf, len, 0);
 *
 * This precondition is why `catch_ml(1)` has no effect on a channel that was
 * never enabled - the reply is emitted but nothing is written.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

void cmd_catch_set(const char *buf, int len, void *dev_ptr,
                   const makcu_cmd_t *entry, const char *arg, int arglen)
{
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen == 0 || entry == NULL) {
        return;
    }
    const int target = (int)entry->target;

    if (dev == NULL
        || makcu_chan_slot(dev, target) == NULL           /* +0x54 slot empty */
        || arg[0] < '0' || arg[0] > '1') {
        makcu_reply_echo(buf, len);
        return;
    }
    makcu_catch_set(dev, target, arg[0] == '1');
    dev->dirty = 1;                                        /* DAT_42000DAC */
    makcu_reply_echo(buf, len);
}
