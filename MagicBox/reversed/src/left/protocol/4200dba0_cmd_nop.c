// 4200dba0  cmd_nop  size=14  (hand reconstruction)
//
// opcode 0x08 of the jump table at 0x3C03DF08.  Nothing calls it through a
// `call8`, so Ghidra never created a function here — the third jump-table-only
// entry after cmd_map_entry (0x16) and cmd_serial (0x1A).
//
// Disassembly (0x4200DBA0..0x4200DBAE, address aligned):
//   4200dba0: entry a1, 32
//   4200dba3: mov.n a10, a2        ; buf
//   4200dba5: mov.n a11, a3        ; len
//   4200dba7: movi.n a12, 0        ; status = 0
//   4200dba9: call8 0x420143E8     ; uart0_reply
//   4200dbac: retw.n
//
// So it is not a stub: it replies with the echoed command line, i.e. the same
// observable behaviour as the "reply only" branch of the other handlers.
void cmd_nop(const char *buf, int len)
{
  uart0_reply(buf, len, 0);
}
