// 4201b438  FUN_4201b438  FUN_4201b438  size=93

void FUN_4201b438(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x38);
  while (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar3 = (int *)piVar3[1];
    if (iVar2 == 0) {
      *(int **)(param_1 + 0x38) = piVar3;
    }
    else {
      *(int **)(iVar2 + 4) = piVar3;
    }
    if (piVar3 == (int *)0x0) {
      *(int *)(param_1 + 0x3c) = iVar2;
    }
    else {
      *piVar3 = iVar2;
    }
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
    (*(code *)PTR_FUN_42000570)();
    piVar3 = *(int **)(param_1 + 0x38);
  }
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != 0) {
    for (iVar1 = *(int *)(iVar2 + -4) * 0x54 + iVar2; iVar2 != iVar1; iVar1 = iVar1 + -0x54) {
      FUN_4201cb60(iVar1 + -0x10);
    }
    (*(code *)PTR_FUN_42000570)((int *)(iVar2 + -4));
  }
  return;
}


