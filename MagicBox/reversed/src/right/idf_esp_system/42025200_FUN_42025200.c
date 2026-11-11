undefined4 FUN_42025200(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 in_IBREAKENABLE;
  undefined1 in_IBREAKA0;
  undefined1 in_IBREAKA1;
  
  if (param_1 == 1) {
    wsr(in_IBREAKA1,param_2);
  }
  else {
    wsr(in_IBREAKA0,param_2);
  }
  uVar1 = rsr(in_IBREAKENABLE);
  wsr(in_IBREAKENABLE,uVar1 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)));
  return 0;
}