/* cmd_nop - opcode 0x08, handler 0x4200DBA0.
 *
 * Jump-table-only entry (nothing calls it through call8), so Ghidra never made a
 * function there; the body was reconstructed by hand in the old repo.
 *
 *   4200dba0: entry a1, 32
 *   4200dba3: a10 = a2        ; buf
 *   4200dba5: a11 = a3        ; len
 *   4200dba7: a12 = 0         ; status
 *   4200dba9: call8 0x420143E8
 *   4200dbac: retw.n
 *
 * It is not a stub: it answers with the echoed command line.
 */
#include "makcu_cmd.h"
#include "makcu_reply.h"

void cmd_nop(const char *buf, int len, void *dev,
             const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)dev;
    (void)entry;
    (void)arg;
    (void)arglen;

    makcu_reply_echo(buf, len);
}
