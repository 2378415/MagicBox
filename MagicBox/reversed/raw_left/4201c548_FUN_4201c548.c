// 4201c548  FUN_4201c548  FUN_4201c548  size=38

undefined4 FUN_4201c548(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_42001a44;
  if ((*(char *)(param_1 + 0x12) != '\0') &&
     (uVar1 = DAT_42001a7c, *(char *)(param_1 + 0x11) == '\0')) {
    uVar1 = FUN_4201c2b4(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0xff,param_2
                        );
  }
  return uVar1;
}


