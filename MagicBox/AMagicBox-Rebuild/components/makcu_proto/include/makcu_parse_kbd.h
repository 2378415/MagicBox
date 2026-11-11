/* Keyboard argument parsers - reimplementations of the three helpers the hidden
 * keyboard opcodes use.
 *
 *   parse_int_or_char (0x4200E458): 'c' form -> char_to_usage; otherwise a
 *       signed/single-digit decimal with optional surrounding blanks.  The
 *       original really does consume only one digit (the decompile reads one
 *       character, rejects it if it is not 0..9, clamps and returns), so
 *       "42" yields 4 - reproduced here rather than "fixed".
 *   parse_list6 (0x4200E670): split on ',' or ')', each token through
 *       parse_int_or_char, store int16, count the non-zero ones, max 6.
 *   parse_range (0x4200E740): the two numbers that follow the first token
 *       (tap delay window / combo delay window).
 */
#ifndef MAKCU_PARSE_KBD_H
#define MAKCU_PARSE_KBD_H

#include <stdint.h>

uint16_t makcu_parse_int_or_char(const char *arg, int len);
int      makcu_parse_list6(const char *arg, int len, int16_t *out);
void     makcu_parse_range(const char *arg, int len, int *first, int *second);

#endif /* MAKCU_PARSE_KBD_H */
