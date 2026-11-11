undefined4 FUN_40382ef4(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 >> 0x10 == 0xc2) {
    if (*(uint *)(param_1 + 0x10) < 0x10) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x105;
    }
  }
  else {
    uVar1 = 0x105;
  }
  return uVar1;
}