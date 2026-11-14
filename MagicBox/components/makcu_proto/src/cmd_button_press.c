/* cmd_button_press - opcode 0x04, handler 0x4200DF30.
 *
 * Shared by "left(" ... "ms2(" (target 1..5): press with `'1'`, release with
 * anything else.  Decompiled:
 *
 *     if (arglen == 0) return;
 *     lock_axis_set(dev, entry->target, arg[0] == '1');   // 0x42010B8C
 *     uart0_reply(buf, len, 0);
 *
 * lock_axis_set -> axis_slot_set (0x4200FA50) writes a uint32 at
 * dev->tbl + 0x9C + target*4 and raises the commit request, so the motion path
 * is what actually produces the HID button report.  That side is still to be
 * ported; the protocol half (echo) is exact.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

void cmd_button_press(const char *buf, int len, void *dev_ptr,
                      const makcu_cmd_t *entry, const char *arg, int arglen)
{
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen == 0 || entry == NULL) {
        return;
    }
    makcu_axis_slot_set(dev, (int)entry->target, arg[0] == '1');
    makcu_reply_echo(buf, len);
}
