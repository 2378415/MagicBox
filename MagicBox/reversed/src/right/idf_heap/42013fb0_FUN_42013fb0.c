void FUN_42013fb0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  while ((param_1 != param_2 && (iVar1 = (*DAT_4200099c)(param_3,param_1 + 8,0xf), iVar1 != 0))) {
    param_1 = *(int *)(param_1 + 4);
  }
  return;
}