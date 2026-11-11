/* cmd_wheel - opcode 0x07, handler 0x4200E358.
 *
 * Decompiled (old repo docs/命令协议 §9.3): parse one signed integer with the
 * usual blank/sign handling, clamp to int16, narrow to int8, hand it to
 * wheel_submit (0x4200F96C) and echo the line.  Unlike cmd_move the reply is
 * unconditional - even an empty argument answers.
 */
#include "makcu_cmd.h"
#include "makcu_mouse_hooks.h"
#include "makcu_reply.h"

#include <stdint.h>

/* Signed integer with optional blanks and sign; clamp at int16 then int8. */
static int8_t parse_delta(const char *arg, int len)
{
    if (arg == NULL || len <= 0) {
        return 0;
    }
    int i = 0;
    while (i < len && (arg[i] == ' ' || arg[i] == '\t')) {
        i++;
    }
    int negative = 0;
    if (i < len && (arg[i] == '-' || arg[i] == '+')) {
        negative = (arg[i] == '-');
        i++;
    }
    while (i < len && (arg[i] == ' ' || arg[i] == '\t')) {
        i++;
    }
    int32_t value = 0;
    int digits = 0;
    while (i < len && arg[i] >= '0' && arg[i] <= '9') {
        value = value * 10 + (arg[i] - '0');
        if (value > 0x7FFFFF) {
            value = 0x7FFFFF;
        }
        digits++;
        i++;
    }
    if (!digits) {
        return 0;
    }
    if (negative) {
        value = -value;
    }
    if (value < -32768) {
        value = -32768;
    }
    if (value > 32767) {
        value = 32767;
    }
    return (int8_t)value;                       /* sext 7 in the original */
}

void cmd_wheel(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
               const char *arg, int arglen)
{
    (void)entry;

    const int8_t delta = parse_delta(arg, arglen);
    if (makcu_wheel_hook != NULL) {
        makcu_wheel_hook(dev, delta);
    }
    makcu_reply_echo(buf, len);
}
