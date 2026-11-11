undefined4 FUN_4201e26c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_42000cd4)(0xffffffff,param_1,4);
  uVar1 = (*DAT_42000cd4)(uVar1,param_1 + 8,0x10);
  uVar1 = (*DAT_42000cd4)(uVar1,param_1 + 0x18,8);
  return uVar1;
}