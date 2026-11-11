undefined4
FUN_4201c6bc(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  uVar1 = DAT_42001a44;
  if ((*(char *)(param_1 + 0x12) != '\0') &&
     (uVar1 = DAT_42001a7c, *(char *)(param_1 + 0x11) == '\0')) {
    uVar1 = FUN_4201c0ec(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         param_3,param_4,param_5);
  }
  return uVar1;
}