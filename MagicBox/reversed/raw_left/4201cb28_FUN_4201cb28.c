// 4201cb28  FUN_4201cb28  FUN_4201cb28  size=53

void FUN_4201cb28(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (piVar3 != (int *)0x0) {
    while( true ) {
      iVar2 = *piVar3;
      piVar3 = (int *)piVar3[1];
      if (iVar2 == 0) {
        *param_1 = (int)piVar3;
      }
      else {
        *(int **)(iVar2 + 4) = piVar3;
      }
      iVar1 = param_1[2];
      if (piVar3 == (int *)0x0) break;
      *piVar3 = iVar2;
      param_1[2] = iVar1 + -1;
      (*(code *)PTR_FUN_42000570)();
    }
    param_1[1] = iVar2;
    param_1[2] = iVar1 + -1;
    (*(code *)PTR_FUN_42000570)();
  }
  return;
}


