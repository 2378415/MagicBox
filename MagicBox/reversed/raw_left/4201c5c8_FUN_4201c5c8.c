// 4201c5c8  FUN_4201c5c8  FUN_4201c5c8  size=36

undefined4 FUN_4201c5c8(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = DAT_42001a44;
  if (*(char *)(param_1 + 0x12) != '\0') {
    uVar1 = FUN_4201c3f4(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         param_3,param_4);
  }
  return uVar1;
}


