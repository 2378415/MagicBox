// 4201dd60  FUN_4201dd60  FUN_4201dd60  size=108

int FUN_4201dd60(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = param_1[5];
  iVar1 = DAT_42001a5c;
  if (iVar3 != 0) {
    piVar2 = (int *)param_1[3];
    piVar4 = piVar2;
    if (piVar2[3] == -0x10) {
      iVar1 = FUN_4201dc84();
      if (iVar1 != 0) {
        return iVar1;
      }
      piVar4 = (int *)param_1[3];
      iVar3 = param_1[5];
    }
    iVar1 = *piVar4;
    piVar4 = (int *)piVar4[1];
    if (iVar1 == 0) {
      param_1[3] = (int)piVar4;
    }
    else {
      *(int **)(iVar1 + 4) = piVar4;
    }
    if (piVar4 == (int *)0x0) {
      param_1[4] = iVar1;
    }
    else {
      *piVar4 = iVar1;
    }
    iVar1 = param_1[1];
    param_1[5] = iVar3 + -1;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 4) = piVar2;
    }
    piVar2[1] = 0;
    *piVar2 = iVar1;
    param_1[1] = (int)piVar2;
    if (*param_1 == 0) {
      *param_1 = (int)piVar2;
    }
    param_1[2] = param_1[2] + 1;
    FUN_4201dc70(piVar2,param_1[9]);
    iVar1 = 0;
    param_1[9] = param_1[9] + 1;
  }
  return iVar1;
}


