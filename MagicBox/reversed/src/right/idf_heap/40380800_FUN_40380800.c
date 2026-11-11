void FUN_40380800(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0 && param_2 != 0) {
    FUN_40380760(param_1,param_2 + -8);
    FUN_40380854(param_1);
    iVar1 = FUN_4038096c(param_2);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar1;
    iVar1 = FUN_40380964();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar1;
    FUN_40380984(*(undefined4 *)(param_1 + 0x10),param_2);
    FUN_40380878(param_1);
  }
  return;
}