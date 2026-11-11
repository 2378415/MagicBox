// 4201e298  FUN_4201e298  FUN_4201e298  size=40

undefined4 FUN_4201e298(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_42000cd4)(0xffffffff,param_1,1);
  uVar1 = (*DAT_42000cd4)(uVar1,param_1 + 8,0x10);
  uVar1 = (*DAT_42000cd4)(uVar1,param_1 + 3,1);
  return uVar1;
}


