int FUN_42007894(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_42000864;
  iVar2 = DAT_42000288;
  if (param_1 != 1) {
    if (param_1 == 2) {
      (*(code *)PTR_FUN_420001b0)(2,100);
      iVar2 = (*(code *)PTR_FUN_42000868)();
      *(int *)(DAT_42000864 + 4) = iVar2;
    }
    else {
      iVar2 = 0;
      if (param_1 == 0) {
        iVar2 = *(int *)(DAT_42000864 + 4);
        if (iVar2 == 0) {
          (*(code *)PTR_FUN_420001b0)(2,100);
          iVar2 = (*(code *)PTR_FUN_42000868)();
          *(int *)(iVar1 + 4) = iVar2;
        }
      }
    }
  }
  return iVar2;
}