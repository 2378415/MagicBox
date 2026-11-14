/* cmd_silent - opcode 0x19, handler 0x4200E1B0.
 *
 * This is the "silent move": the same argument parser as cmd_move, but the
 * reply is only emitted on the two-argument path.  Address-aligned disassembly
 * of the tail (old repo, 4200e1b0_cmd_silent.c):
 *
 *   4200e332: a9 = count
 *   4200e33a: bnei a9, 2, 0x4200e355   ; count != 2 -> retw, no reply at all
 *   4200e33d: a12 = v[1]
 *   4200e340: a11 = v[0]
 *   4200e343: a10 = dev
 *   4200e349: call8 0x42010D3C          ; pulse_move(dev, v0, v1)
 *   4200e352: call8 uart0_reply
 *   4200e355: retw.n
 *
 * Measured on the original device (old repo dynamic_tests.md §10):
 *   .km.silent()   -> no reply
 *   .km.silent(0)  -> no reply
 *   .km.silent(1)  -> no reply
 *   .km.silent(0,0)-> "km.silent(0,0)\r\n>>> "
 *
 * Bench note: with no host attached to the cloned-device port the original can
 * block inside pulse_move (it waits for the commit semaphore), i.e. the reply
 * never comes.  The rebuild answers immediately because the motion layer is not
 * ported yet; that difference is expected and recorded in the flash report.
 */
#include "makcu_cmd.h"
#include "makcu_mouse_hooks.h"
#include "makcu_parse.h"
#include "makcu_reply.h"

void cmd_silent(const char *buf, int len, void *dev,
                const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)entry;

    if (dev == NULL) {
        return;
    }
    int16_t v[5] = {0};
    const int n = makcu_parse_int16_list(arg, arglen, v, 5);

    if (n != 2) {
        return;                                   /* silent in every other case */
    }
    if (makcu_mouse_pulse_hook != NULL) {
        makcu_mouse_pulse_hook(dev, v[0], v[1]);  /* 0x42010D3C */
    }
    makcu_reply_echo(buf, len);
}
