// 4200e624  cmd_map_entry  size=76  (hand reconstruction)
//
// Only reachable through the opcode jump table at 0x3C03DF08 (opcode 0x16),
// so Ghidra never created a function here.  Everything below is decoded from
// the address-aligned disassembly 0x4200E624..0x4200E66E (see the fallback
// block that ends 4200e56c_cmd_channel_toggle.c) plus 4202d4a8.. helpers.
//
// Mapping-table write: "<index>,<value>" - both values must be non-zero, and
// the reply always echoes the whole command line.
//
// Xtensa call convention of a text handler:
//   a2 = buf, a3 = len, a4 = dev, a5 = entry, a6 = arg, a7 = arglen
void cmd_map_entry(undefined4 buf, uint len, int dev, undefined4 entry,
                   char *arg, uint arglen)

{
  int32_t first, second;
  int i;

  if (arglen == 0) return;                              /* 4200e627 */
  first = parse_int_or_char(arg, arglen);               /* 4200e62e */
  for (i = 0; i < arglen && arg[i] != ','; i++) ;       /* 4200e639 */
  if (i == 0 || i >= arglen) return;                    /* 4200e649 */
  second = parse_int_or_char(arg + i + 1, arglen - 1 - i);   /* 4200e655 */
  if (first == 0 || second == 0) return;                /* 4200e65a/65c */
  map_entry_write(dev, first, second);                  /* 4200e662 -> 4202d4dc */
  uart0_reply(buf, len, 0);                             /* 4200e66b */
}
