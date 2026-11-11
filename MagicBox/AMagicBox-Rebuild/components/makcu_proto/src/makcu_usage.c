/* ASCII -> HID usage table - see include/makcu_usage.h. */
#include "makcu_usage.h"

uint16_t makcu_char_to_usage(uint8_t c)
{
    if (c >= 'a' && c <= 'z') {
        return (uint16_t)(4 + (c - 'a'));
    }
    if (c >= 'A' && c <= 'Z') {
        return (uint16_t)(4 + (c - 'A'));       /* case-insensitive, like the original */
    }
    if (c >= '1' && c <= '9') {
        return (uint16_t)(30 + (c - '1'));
    }
    switch (c) {
    case '0':  return 39;
    case '\r':
    case '\n': return 40;
    case 0x1B: return 41;   /* ESC   */
    case 0x08: return 42;   /* BS    */
    case '\t': return 43;   /* TAB   */
    case ' ':  return 44;   /* SPACE */
    case '-':  return 45;
    case '=':  return 46;
    case '[':  return 47;
    case ']':  return 48;
    case '\\': return 49;
    case ';':  return 51;
    case '\'': return 52;
    case '`':  return 53;
    case ',':  return 54;
    case '.':  return 55;
    case '/':  return 56;
    default:   return 0;
    }
}
