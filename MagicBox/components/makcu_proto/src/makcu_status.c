/* Status-append helper - reimplementation of cmd_reply_status (0x4200DC18).
 *
 * Original decompile:
 *     iVar1 = strncmp(name, DAT_42000D90, 8);
 *     if (iVar1 == 0) { len = 0xB; digit_at = 10; name_len = 9; name = "buttons()"; }
 *     else            { if (name_len + 2 > 0x20) return; len = name_len + 2;
 *                       digit_at = name_len + 1; }
 *     memcpy(out, name, name_len);
 *     out[name_len]     = '\n';
 *     out[digit_at]     = status + '0';
 *     uart0_reply(out, len, 0);
 *
 * So the reply content is "<name>\n<digit>", with the buttons family always
 * normalised to "buttons()" - which is why the measured reply to
 * `.km.buttons()` is `km.buttons()\n0\r\n>>> `.
 */
#include "makcu_reply.h"

#include <string.h>

#define MAKCU_STATUS_MAX  0x20           /* original: name_len + 2 <= 0x20 */

size_t makcu_reply_status(const char *name, int name_len, uint8_t status)
{
    char content[MAKCU_STATUS_MAX + 1];
    int use_name_len = name_len;
    const char *use_name = name;

    if (name == NULL || name_len < 0) {
        return 0;
    }
    if (name_len >= 8 && memcmp(name, "buttons(", 8) == 0) {
        use_name = "buttons()";          /* both table rows answer as buttons() */
        use_name_len = 9;
    }
    if (use_name_len + 2 > MAKCU_STATUS_MAX || use_name_len < 1) {
        return 0;
    }
    memcpy(content, use_name, (size_t)use_name_len);
    content[use_name_len] = '\n';
    content[use_name_len + 1] = (char)('0' + (status & 0x0F));
    return makcu_reply(content, (size_t)(use_name_len + 2));
}
