/* Argument parsing shared by the text handlers.
 *
 * Recovered from the parser inlined in cmd_move (0x4200E040-0x4200E160) and
 * reused verbatim by cmd_silent:
 *   - tokens are separated by ',' or ')'; both separators are skipped
 *   - spaces (0x20) and tabs (0x09) are skipped between tokens
 *   - an optional '+' or '-' sign is accepted
 *   - digits accumulate as value = value*10 + d
 *   - the result is clamped to int16 and stored little-endian in an int16 array
 *   - parsing stops at the first token that contains no digit
 */
#ifndef MAKCU_PARSE_H
#define MAKCU_PARSE_H

#include <stdint.h>

/* Parse up to `max` int16 values out of arg[0..arglen). Returns the count. */
int makcu_parse_int16_list(const char *arg, int arglen, int16_t *out, int max);

#endif /* MAKCU_PARSE_H */
