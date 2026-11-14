/* cmd_buttons - opcode 0x0C, handler 0x4200DDBC.
 *
 * Decompiled behaviour (tree: left/protocol/4200ddbc_cmd_buttons.c):
 *
 *   is_query = strncmp(entry->name, "buttons()", 9) == 0;
 *   if (arglen == 0 || is_query) {
 *       if (dev) cmd_reply_status(entry->name, 9, buttons_get(dev));
 *       return;                          // no dev: not even a reply
 *   }
 *   if (arglen == 1 && arg[0] == ')') { query as above; return; }
 *   if (arglen == 2 && arg[0] in {'0','1'} && arg[1] == ')') {
 *       buttons_set(dev, arg[0] == '1');
 *       uart0_reply(buf, len, 0);
 *       return;
 *   }
 *   uart0_reply(buf, len, 0);            // anything else: reply only
 *
 * Measured on the original device: `.km.buttons()` -> "km.buttons()\n0\r\n>>> ",
 * `.km.buttons(2)` -> echo only.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_reply.h"

#include <string.h>

void cmd_buttons(const char *buf, int len, void *dev_ptr,
                 const makcu_cmd_t *entry, const char *arg, int arglen)
{
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (entry == NULL) {
        makcu_reply_echo(buf, len);
        return;
    }
    const int is_query = (entry->len >= 9 && memcmp(entry->name, "buttons()", 9) == 0);

    if (arglen == 0 || is_query) {
        if (dev != NULL) {
            makcu_reply_status(entry->name, 9, makcu_buttons_get(dev));
        }
        return;
    }
    if (arglen == 1 && arg[0] == ')') {
        if (dev != NULL) {
            makcu_reply_status(entry->name, 9, makcu_buttons_get(dev));
        }
        return;
    }
    if (arglen == 2 && arg[0] >= '0' && arg[0] <= '1' && arg[1] == ')') {
        makcu_buttons_set(dev, arg[0] == '1');       /* 0x42010C44 */
        makcu_reply_echo(buf, len);
        return;
    }
    makcu_reply_echo(buf, len);
}
