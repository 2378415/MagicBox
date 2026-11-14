/* cmd_button_click - opcode 0x05, handler 0x4200DFAC.
 *
 * Shared by every "left()" ... "ms2()" row (target 1..5).  Decompiled:
 *
 *   if (dev == 0) return;                       // no reply at all
 *   n     = entry->len;
 *   name  = entry->name;
 *   flags = button_flags_get(dev, entry->target);   // 0x4202D26C, 0..3
 *   if (n + 2 < 0x21) {
 *       memcpy(out, name, n);  out[n] = '\n';  out[n+1] = flags + '0';
 *       uart0_reply(out, n + 2, 0);
 *   }
 *
 * So `left()` answers "km.left()\n<digit>" where the digit is the per-button
 * status word (bit0 = catch slot, bit1 = axis/lock slot).
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

#include <string.h>

void cmd_button_click(const char *buf, int len, void *dev_ptr,
                      const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)buf;
    (void)len;
    (void)arg;
    (void)arglen;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (dev == NULL || entry == NULL) {
        return;                                  /* original: no dev -> silence */
    }
    const int n = (int)entry->len;
    if (n + 2 >= 0x21) {
        return;
    }
    char content[0x21];
    memcpy(content, entry->name, (size_t)n);
    content[n] = '\n';
    content[n + 1] = (char)('0' + (makcu_button_flags(dev, (int)entry->target) & 0x0F));
    makcu_reply(content, (size_t)(n + 2));
}
