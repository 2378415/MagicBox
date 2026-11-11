// 42016b98  FUN_42016b98  FUN_42016b98  size=40

undefined4 FUN_42016b98(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_42000a0c)(0xffffffff,param_1,1);
  uVar1 = (*DAT_42000a0c)(uVar1,param_1 + 8,0x10);
  uVar1 = (*DAT_42000a0c)(uVar1,param_1 + 3,1);
  return uVar1;
}


