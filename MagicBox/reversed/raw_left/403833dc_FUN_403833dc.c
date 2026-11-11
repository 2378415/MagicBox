// 403833dc  FUN_403833dc  FUN_403833dc  size=28

undefined4 FUN_403833dc(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x105;
  if ((param_2 >> 0x10 == 0xc2) && (0xf < *(uint *)(param_1 + 0x10))) {
    uVar1 = 0;
  }
  return uVar1;
}


