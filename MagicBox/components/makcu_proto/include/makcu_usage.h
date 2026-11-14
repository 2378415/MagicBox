/* ASCII -> HID keyboard usage id.
 *
 * Recovered from char_to_usage (0x4202D2A0): the decompiled switch tree matches
 * the standard HID usage table exactly (the sampled arms agree: 'g'->0x0A,
 * 'd'->0x07, 'p'->0x13, 'q'->0x14, 'r'->0x15, 's'->0x16, 'u'->0x18, 'v'->0x19,
 * 'x'->0x1B, 'y'->0x1C, 'z'->0x1D, letters are case-insensitive).
 */
#ifndef MAKCU_USAGE_H
#define MAKCU_USAGE_H

#include <stdint.h>

/* Returns 0 for characters without a usage id (the original does the same and
 * the handlers then stay silent). */
uint16_t makcu_char_to_usage(uint8_t c);

#endif /* MAKCU_USAGE_H */
