void FUN_40380954(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0 && param_1 != (int *)0x0)) {
    FUN_403808b0(param_1,param_2 + -8);
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_4037bf20();
      FUN_4037bf44(iVar1,0xffffffff);
    }
    iVar1 = FUN_40380aa8(param_2);
    param_1[1] = param_1[1] + iVar1;
    iVar1 = FUN_40380aa0();
    param_1[1] = param_1[1] + iVar1;
    FUN_40380ac0(param_1[4],param_2);
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_4037bf20();
      FUN_4037c094(iVar1);
    }
  }
  return;
}