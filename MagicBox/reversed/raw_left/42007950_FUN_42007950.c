// 42007950  FUN_42007950  FUN_42007950  size=79

int FUN_42007950(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_42000864;
  iVar2 = DAT_42000874;
  if (param_1 != 1) {
    if (param_1 == 0) {
      iVar2 = *DAT_42000864;
      if (iVar2 == 0) {
        (*(code *)PTR_FUN_420001b0)(1,100);
        iVar2 = (*(code *)PTR_FUN_42000868)();
        *piVar1 = iVar2;
      }
    }
    else {
      if (param_1 != 2) {
        return 0;
      }
      (*(code *)PTR_FUN_420001b0)(1,100);
      iVar2 = (*(code *)PTR_FUN_42000868)();
      *DAT_42000864 = iVar2;
    }
    iVar2 = iVar2 << 8;
  }
  return iVar2;
}


