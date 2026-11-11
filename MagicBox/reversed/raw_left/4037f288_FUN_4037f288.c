// 4037f288  FUN_4037f288  FUN_4037f288  size=71

uint FUN_4037f288(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (((param_4 & 2) == 0) || (DAT_40374614 < (uint)(param_2 + DAT_40374e08))) {
    uVar1 = 0;
    if (((param_4 & 1) != 0) && ((uint)(param_2 + DAT_403750dc) <= DAT_40374614)) {
      uVar1 = -(DAT_40374614 - 1) & 0xff;
    }
  }
  else {
    uVar1 = -(DAT_40374614 - 1);
  }
  return uVar1;
}


