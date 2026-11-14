/* Argument parser - see include/makcu_parse.h for the recovered semantics. */
#include "makcu_parse.h"

#include <stddef.h>

int makcu_parse_int16_list(const char *arg, int arglen, int16_t *out, int max)
{
    if (arg == NULL || out == NULL || arglen <= 0 || max <= 0) {
        return 0;
    }
    int i = 0;
    int n = 0;
    while (i < arglen && n < max) {
        const char c = arg[i];
        if (c == ',' || c == ')') {          /* separators are pure delimiters */
            i++;
            continue;
        }
        if (c == ' ' || c == '\t') {         /* whitespace between tokens */
            i++;
            continue;
        }
        int negative = 0;
        if (c == '-' || c == '+') {
            negative = (c == '-');
            i++;
        }
        int32_t value = 0;
        int digits = 0;
        while (i < arglen && arg[i] >= '0' && arg[i] <= '9') {
            value = value * 10 + (arg[i] - '0');
            if (value > 0x7FFFFF) {          /* keep the accumulator sane */
                value = 0x7FFFFF;
            }
            digits++;
            i++;
        }
        if (!digits) {
            break;                           /* token without digits ends parsing */
        }
        if (value < -32768) {
            value = -32768;
        }
        if (value > 32767) {
            value = 32767;
        }
        out[n++] = (int16_t)(negative ? -value : value);
    }
    return n;
}
