undefined8 FUN_4202aa38(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x3ff0000000000000;
  if (param_1 < 0x18) {
    uVar1 = *(undefined8 *)(PTR_DAT_42001d84 + param_1 * 8);
  }
  else {
    do {
      param_1 = param_1 + -1;
      uVar1 = (*DAT_42000e30)((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,DAT_42001d90);
    } while (param_1 != 0);
  }
  return uVar1;
}