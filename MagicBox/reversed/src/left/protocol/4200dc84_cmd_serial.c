// 4200dc84  cmd_serial  size=302  (hand reconstruction, body from the
// no-op-patched Ghidra decompile)
//
// Only reachable through the opcode jump table (opcode 0x1A), so Ghidra never
// created a function here.  0x42010C84 does the actual work
// (serial_read / write / factory reset); this handler owns the text protocol:
//
//   km.serial()          -> "Original: <serial>" / "Spoofed: <serial>"
//   km.serial()          -> same, only when the argument is exactly ")"
//   km.serial(0)         -> clear the spoofed serial (factory value)
//   km.serial(<string>)  -> store <string> as the spoofed serial
//
// Strings involved: "Mouse does not have a serial numberber", "Original",
// "Spoofed", "%s Serial : %s", "Unknown indicator 0x%02X".
void cmd_serial(undefined4 buf, uint len, undefined4 entry2, undefined4 entry,
                char *arg, uint arglen)

{
  undefined1 line[64];
  char text[20];
  byte info[36];
  uint info_len;
  int ok;

  if (arglen == 0 || (arglen == 1 && arg[0] == ')')) {   /* query form */
    info_len = 0;
    ok = serial_read(0, 0, text, 0x15, &info_len, info);
    if (ok == 0) {
      uart0_reply("Mouse does not have a serial numberber", 0x24, 0);
      return;
    }
    if (info[0] == 0xff) {
      snprintf(line, 0x40, "Mouse does not have a serial numberber");
    }
    else if (info[0] < 2) {
      if (info_len < 0x15) text[info_len] = 0;
      snprintf(line, 0x40, "%s Serial : %s",
               info[0] != 0 ? "Spoofed" : "Original", text);
    }
    else {
      snprintf(line, 0x40, "Unknown indicator 0x%02X", info[0]);
    }
    uart0_reply(line, strlen(line), 0);
    return;
  }
  if (arglen == 2 && arg[0] == '0' && arg[1] == ')') {   /* factory reset */
    ok = serial_read(1, 0, 0, 0, 0, 0);
  }
  else {                                                 /* set spoofed serial */
    int n = arglen;
    if (arg[arglen - 1] == ')') n = arglen - 1;
    if (n > 0x14) n = 0x14;
    memcpy(line, arg, n);
    line[n] = 0;
    ok = serial_read(2, line, 0, 0, 0, 0);
  }
  if (ok == 0) uart0_reply("Mouse does not have a serial numberber", 0x24, 0);
  else         uart0_reply(buf, len, 0);
}
