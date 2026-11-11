/* Channel-table opcodes - cmd_dump_channels (0x17, 0x4200DBB0) and
 * cmd_channel_toggle (0x18, 0x4200E56C).
 *
 * 0x17 dump: walk idx 0..255, take the first entry whose three flags are all
 *     set (desc[+0x269] enable, desc[+0x369] present, dev[+0x636] third flag),
 *     format it with "%d" into a 16-byte buffer and reply that; if none matches
 *     (always the case on a fresh device) reply the literal "0".
 *
 * 0x18 toggle:  idx = parse_int_or_char(arg, arglen);
 *     if (dev == 0 || dev->desc == 0)   -> reply only
 *     if (idx > 255)                    -> reply only
 *     if (desc[idx + 0x369] == 0)       -> reply only        ("present" gate)
 *     find ',' ; flag = comma[1]
 *     desc[idx + 0x269] = (flag == '1');
 *     makcu_resend_flag  = (flag == '1') ? 0 : 1;            (0x3FC99FA3)
 *     reply only
 * Everything in this handler answers with the echoed line; the only silent path
 * is a missing argument.
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_parse_kbd.h"
#include "makcu_reply.h"

#include <stdio.h>
#include <string.h>

void cmd_dump_channels(const char *buf, int len, void *dev_ptr,
                       const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)buf;
    (void)len;
    (void)entry;
    (void)arg;
    (void)arglen;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (dev != NULL) {
        for (int idx = 0; idx < 0x100; idx++) {
            if (makcu_desc_enabled(dev, idx)
                && makcu_desc_present(dev, idx)
                && makcu_desc_flag(dev, idx)) {
                char text[0x10];
                const int n = snprintf(text, sizeof(text), "%d", idx);
                makcu_reply(text, (size_t)n);          /* FUN_4202058C("%d") */
                return;
            }
        }
    }
    makcu_reply("0", 1);                               /* literal at 0x3C034FA0 */
}

void cmd_channel_toggle(const char *buf, int len, void *dev_ptr,
                        const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)entry;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen <= 0) {
        return;                                        /* silent: no argument */
    }
    if (dev == NULL) {
        makcu_reply_echo(buf, len);
        return;
    }
    const uint16_t idx = makcu_parse_int_or_char(arg, arglen);
    if (idx > 0xFF || !makcu_desc_present(dev, idx)) {  /* 0x4200E5AA / E5BB */
        makcu_reply_echo(buf, len);
        return;
    }
    const char *comma = memchr(arg, ',', (size_t)arglen);
    if (comma == NULL || (comma - arg) == 0
        || (comma - arg) >= arglen - 1) {              /* 0x4200E5D9 / E5DF */
        makcu_reply_echo(buf, len);
        return;
    }
    const char flag = comma[1];
    makcu_desc_set_enabled(dev, idx, flag == '1');     /* 0x4200E5F4 */
    makcu_resend_flag = (flag == '1') ? 0 : 1;         /* 0x4200E5FF / E611 */
    makcu_reply_echo(buf, len);
}
