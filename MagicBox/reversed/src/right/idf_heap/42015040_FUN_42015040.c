undefined4 FUN_42015040(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar1 = DAT_4200108c;
  }
  else if (*(char *)(param_1 + 0x11) == '\0') {
    uVar1 = FUN_42014428(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0xff,param_2
                        );
  }
  else {
    uVar1 = DAT_420010c0;
  }
  return uVar1;
}