/* cmd_move - opcode 0x06, handler 0x4200E024.
 *
 * Reconstructed from the no-op-patched decompile plus the address-aligned
 * disassembly (old repo docs/reconstruction_patterns.md §2):
 *
 *   n = parse_int16_list(arg, arglen)      ; up to 5 values
 *   if (n < 2)  return;                    ; 0x4200E17A: silent, not even a reply
 *   if (n == 2) mode = 1;
 *   else {
 *       mode = (uint16_t)v[2];
 *       if (n == 5) { mouse_submit_ext(dev, v0..v4); goto reply; }
 *       if (mode < 2) mode = 1;
 *   }
 *   mouse_move(dev, v0, v1, mode);         ; 0x42010BC4
 * reply:
 *   uart0_reply(buf, len, 0);              ; 0x4200E1A4
 *
 * Motion is called through makcu_mouse_hooks so this file links before the
 * submission queue is ported.
 */
#include "makcu_cmd.h"
#include "makcu_mouse_hooks.h"
#include "makcu_parse.h"
#include "makcu_reply.h"

void cmd_move(const char *buf, int len, void *dev,
              const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)entry;

    int16_t v[5] = {0};
    const int n = makcu_parse_int16_list(arg, arglen, v, 5);

    if (n < 2) {
        return;                                    /* silent: no reply at all */
    }
    if (n == 5) {
        if (makcu_mouse_move_ext_hook != NULL) {
            makcu_mouse_move_ext_hook(dev, v[0], v[1], v[2], v[3], v[4]);
        }
    } else {
        uint32_t mode = 1;
        if (n != 2) {
            mode = (uint32_t)(uint16_t)v[2];
            if (mode < 2) {
                mode = 1;
            }
        }
        if (makcu_mouse_move_hook != NULL) {
            makcu_mouse_move_hook(dev, v[0], v[1], mode);
        }
    }
    makcu_reply_echo(buf, len);
}
