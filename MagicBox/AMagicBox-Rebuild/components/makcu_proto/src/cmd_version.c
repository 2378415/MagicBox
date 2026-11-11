/* cmd_version - opcode 0x09, handler 0x4200DC6C.
 *
 * Original (patched decompile + objdump):
 *   4200dc6c: entry a1, 80
 *   4200dc6f: a11 = a1 + 32            ; &len
 *   4200dc72: a10 = a1                 ; buffer
 *   4200dc75: call8 0x42010C30         ; version_get(buf, &len) -> "MAKCU", 5
 *   4200dc78: a11 = *(a1+32)           ; len
 *   4200dc7b: a12 = 0
 *   4200dc7d: a10 = a1
 *   4200dc7f: call8 0x420143E8         ; uart0_reply(buf, len, 0)
 *
 * So the reply is "km." + "MAKCU" + "\r\n>>> " and the command text is not
 * echoed (the version string replaces it).  Measured: .km.version() and
 * .km.version both answer "km.MAKCU\r\n>>> ".
 */
#include "makcu_cmd.h"
#include "makcu_reply.h"

#define VERSION_STRING      "MAKCU"
#define VERSION_STRING_LEN  5

void cmd_version(const char *buf, int len, void *dev,
                 const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)buf;
    (void)len;
    (void)dev;
    (void)entry;
    (void)arg;
    (void)arglen;

    makcu_reply(VERSION_STRING, VERSION_STRING_LEN);   /* version_get + uart0_reply */
}
