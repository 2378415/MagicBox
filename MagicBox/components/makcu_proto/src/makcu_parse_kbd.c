/* Keyboard argument parsers - see include/makcu_parse_kbd.h. */
#include "makcu_parse_kbd.h"

#include "makcu_usage.h"

#include <stddef.h>

uint16_t makcu_parse_int_or_char(const char *arg, int len)
{
    if (arg == NULL || len <= 0) {
        return 0;
    }
    if (arg[0] == '\'') {                        /* 'c' form */
        if (len > 2 && arg[len - 1] == '\'') {
            return makcu_char_to_usage((uint8_t)arg[1]);
        }
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
    if (i >= len || arg[i] < '0' || arg[i] > '9') {
        return 0;                                /* original: not a digit -> 0 */
    }
    int32_t value = arg[i] - '0';                /* single digit, as decompiled */
    if (negative) {
        value = -value;
    }
    if (value < -32768) {
        value = -32768;
    }
    if (value > 32767) {
        value = 32767;
    }
    return (uint16_t)value;
}

static int token_at(const char *arg, int start, int stop, int16_t *out)
{
    if (stop <= start) {
        *out = 0;
        return 0;
    }
    const uint16_t v = makcu_parse_int_or_char(arg + start, stop - start);
    *out = (int16_t)v;
    return v != 0;
}

int makcu_parse_list6(const char *arg, int len, int16_t *out)
{
    if (arg == NULL || out == NULL || len <= 0) {
        return 0;
    }
    int count = 0;
    int start = 0;
    for (int i = 0; i < len && count < 6; i++) {
        if (arg[i] == ',' || arg[i] == ')') {
            int16_t v;
            if (start < i) {
                if (token_at(arg, start, i, &v)) {
                    out[count++] = v;
                }
            }
            start = i + 1;
        }
    }
    if (start < len && count < 6) {
        int16_t v;
        if (token_at(arg, start, len, &v)) {
            out[count++] = v;
        }
    }
    return count;
}

void makcu_parse_range(const char *arg, int len, int *first, int *second)
{
    if (first != NULL) {
        *first = 0;
    }
    if (second != NULL) {
        *second = 0;
    }
    if (arg == NULL || len <= 0) {
        return;
    }
    /* Token 1 is the usage/key; the delay window is token 2 and token 3. */
    int commas[2] = {-1, -1};
    int found = 0;
    for (int i = 0; i < len && found < 2; i++) {
        if (arg[i] == ',') {
            commas[found++] = i;
        }
    }
    if (commas[0] < 0) {
        return;
    }
    const int t2_start = commas[0] + 1;
    const int t2_stop = (commas[1] > commas[0]) ? commas[1] : len;
    int16_t v2 = 0;
    token_at(arg, t2_start, t2_stop, &v2);
    if (first != NULL) {
        *first = v2;
    }
    if (commas[1] > commas[0]) {
        int16_t v3 = 0;
        token_at(arg, commas[1] + 1, len, &v3);
        if (second != NULL) {
            *second = v3;
        }
    }
}
