/* Hidden keyboard opcodes 0x0D..0x14 - handlers 0x4200EC48 / EB1C / E9D0 /
 * DE80 / ED74 / E6F0 / E718 / E998.
 *
 * None of these has a text command in the 43-entry table; they are reachable
 * only through the opcode jump table (and, on the original, only from internal
 * callers).  Their protocol half is identical in shape:
 *
 *     parse the arguments -> if the parse produced something, call the HID
 *     writer and echo the whole line; otherwise stay silent.
 *
 * The HID writers themselves (makcu_keyboard) are not ported yet, so each call
 * goes through a hook; the reply decision still matches the original because it
 * only depends on the parse result.
 */
#include "makcu_cmd.h"
#include "makcu_kbd_hooks.h"
#include "makcu_parse_kbd.h"
#include "makcu_reply.h"

#include <string.h>

/* ---------------------------------------------------------------- 0x0D / 0x0E */
static void key_single(const char *buf, int len, void *dev,
                       const char *arg, int arglen, int down)
{
    if (arglen <= 0) {
        return;
    }
    const uint16_t usage = makcu_parse_int_or_char(arg, arglen);
    if (usage == 0) {
        return;                                   /* original: silent */
    }
    if (down ? (makcu_key_down_hook != NULL) : (makcu_key_up_hook != NULL)) {
        (down ? makcu_key_down_hook : makcu_key_up_hook)(dev, usage);
    }
    makcu_reply_echo(buf, len);
}

void cmd_key_down(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                  const char *arg, int arglen)
{
    (void)entry;
    key_single(buf, len, dev, arg, arglen, 1);
}

void cmd_key_up(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                const char *arg, int arglen)
{
    (void)entry;
    key_single(buf, len, dev, arg, arglen, 0);
}

/* ---------------------------------------------------------------- 0x0F tap */
void cmd_key_tap(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                 const char *arg, int arglen)
{
    (void)entry;
    if (arglen <= 0) {
        return;
    }
    const uint16_t usage = makcu_parse_int_or_char(arg, arglen);
    int min_ms = 0;
    int max_ms = 0;
    makcu_parse_range(arg, arglen, &min_ms, &max_ms);
    if (usage == 0) {
        return;
    }
    if (makcu_key_tap_hook != NULL) {
        makcu_key_tap_hook(dev, usage, min_ms, max_ms);
    }
    makcu_reply_echo(buf, len);
}

/* ------------------------------------------------------- 0x10 string typing */
void cmd_set_string(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                    const char *arg, int arglen)
{
    (void)entry;
    if (arglen <= 2 || arg[0] != '\'' || arg[arglen - 1] != '\'') {
        return;                                   /* original: silent */
    }
    int n = arglen - 2;
    if (n > 0x3F) {
        n = 0x3F;
    }
    char text[0x3F + 1];
    memcpy(text, arg + 1, (size_t)n);
    text[n] = '\0';
    if (makcu_type_string_hook != NULL) {
        makcu_type_string_hook(dev, text, n);
    }
    makcu_reply_echo(buf, len);
}

/* ------------------------------------------------------- 0x12 / 0x13 batches */
static void keys_batch(const char *buf, int len, void *dev, const char *arg,
                       int arglen, int down)
{
    if (arglen <= 0) {
        return;
    }
    int16_t usages[6] = {0};
    const int count = makcu_parse_list6(arg, arglen, usages);
    if (count == 0) {
        return;
    }
    if (down ? (makcu_keys_down_hook != NULL) : (makcu_keys_up_hook != NULL)) {
        (down ? makcu_keys_down_hook : makcu_keys_up_hook)(dev, usages, count);
    }
    makcu_reply_echo(buf, len);
}

void cmd_keys_down(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                   const char *arg, int arglen)
{
    (void)entry;
    keys_batch(buf, len, dev, arg, arglen, 1);
}

void cmd_keys_up(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                 const char *arg, int arglen)
{
    (void)entry;
    keys_batch(buf, len, dev, arg, arglen, 0);
}

/* ------------------------------------------------------------ 0x14 combo */
void cmd_keys_combo(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                    const char *arg, int arglen)
{
    (void)entry;
    if (arglen <= 0) {
        return;
    }
    int16_t usages[6] = {0};
    const int count = makcu_parse_list6(arg, arglen, usages);
    int min_ms = 0;
    int max_ms = 0;
    makcu_parse_range(arg, arglen, &min_ms, &max_ms);
    if (count == 0) {
        return;
    }
    if (makcu_keys_combo_hook != NULL) {
        makcu_keys_combo_hook(dev, usages, count, min_ms, max_ms);
    }
    makcu_reply_echo(buf, len);
}

/* ------------------------------------------------------- 0x11 key state */
void cmd_key_state(const char *buf, int len, void *dev, const makcu_cmd_t *entry,
                   const char *arg, int arglen)
{
    if (arglen <= 0 || entry == NULL) {
        return;
    }
    const uint16_t usage = makcu_parse_int_or_char(arg, arglen);
    if (usage == 0) {
        return;
    }
    const uint8_t state = (makcu_key_state_hook != NULL)
                          ? (uint8_t)makcu_key_state_hook(dev, usage)
                          : 0;
    makcu_reply_status(entry->name, (int)entry->len, state);
}
