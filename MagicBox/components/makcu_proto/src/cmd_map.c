/* Mapping-table opcodes - cmd_map_16 (0x15, 0x4200EA04) and
 * cmd_map_entry (0x16, 0x4200E624).
 *
 * 0x15: first value through parse_int_or_char, second value parsed inline after
 *       the comma (skip blanks, optional sign, one decimal digit, clamped to
 *       0..0xFF), then map_entry_write16(dev, first, second) and echo.
 * 0x16: two parse_int_or_char values separated by a comma; **both must be
 *       non-zero** before map_entry_write() runs, otherwise the handler returns
 *       without a reply at all (0x4200E65A / 0x4200E65C).
 */
#include "makcu_cmd.h"
#include "makcu_dev.h"
#include "makcu_parse_kbd.h"
#include "makcu_reply.h"

#include <stdint.h>

/* Second value of the 0x15 form: one digit after the comma, clamped to a byte. */
static int parse_second_byte(const char *arg, int arglen)
{
    int i = 0;
    while (i < arglen && arg[i] != ',') {
        i++;
    }
    if (i >= arglen) {
        return 0;
    }
    i++;
    while (i < arglen && (arg[i] == ' ' || arg[i] == '\t')) {
        i++;
    }
    int negative = 0;
    if (i < arglen && (arg[i] == '-' || arg[i] == '+')) {
        negative = (arg[i] == '-');
        i++;
    }
    while (i < arglen && (arg[i] == ' ' || arg[i] == '\t')) {
        i++;
    }
    if (i >= arglen || arg[i] < '0' || arg[i] > '9') {
        return 0;
    }
    int value = arg[i] - '0';
    if (negative) {
        value = -value;
    }
    if (value < 0) {
        value = 0;
    }
    if (value > 0xFF) {
        value = 0xFF;
    }
    return value;
}

void cmd_map_16(const char *buf, int len, void *dev_ptr, const makcu_cmd_t *entry,
                const char *arg, int arglen)
{
    (void)entry;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen <= 0) {
        return;
    }
    const uint16_t first = makcu_parse_int_or_char(arg, arglen);
    const int second = parse_second_byte(arg, arglen);
    if (first == 0) {
        return;                                  /* 0x4200EA04: silent */
    }
    makcu_map_write16(dev, first, second);       /* 0x4202D4A8 -> desc[+0x163] */
    makcu_reply_echo(buf, len);
}

void cmd_map_entry(const char *buf, int len, void *dev_ptr, const makcu_cmd_t *entry,
                   const char *arg, int arglen)
{
    (void)entry;
    makcu_dev_t *dev = (makcu_dev_t *)dev_ptr;

    if (arglen <= 0) {
        return;
    }
    const uint16_t first = makcu_parse_int_or_char(arg, arglen);

    int i = 0;
    while (i < arglen && arg[i] != ',') {
        i++;
    }
    if (i <= 0 || i >= arglen) {
        return;                                  /* 0x4200E649 */
    }
    const uint16_t second = makcu_parse_int_or_char(arg + i + 1, arglen - 1 - i);
    if (first == 0 || second == 0) {
        return;                                  /* 0x4200E65A / 0x4200E65C */
    }
    makcu_map_write(dev, first, second);         /* 0x4202D4DC -> desc[+0x63] */
    makcu_reply_echo(buf, len);
}
