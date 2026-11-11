// 42016dac  FUN_42016dac  FUN_42016dac  size=85

int * FUN_42016dac(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *in_t0;
  
  piVar1 = (int *)FUN_42016ea8();
  piVar3 = param_1 + -0xc;
  piVar2 = (int *)*piVar1;
  iVar4 = param_1[1] + DAT_42001124;
  if (*param_1 + DAT_42001120 < DAT_42001120) {
    iVar4 = iVar4 + 1;
  }
  if ((iVar4 == 0) && (*param_1 + DAT_42001120 < 2)) {
    iVar5 = param_1[-7];
    iVar4 = iVar5 + 1;
    if (iVar5 < 0) {
      iVar4 = -(iVar5 + -1);
    }
    param_1[-7] = iVar4;
    piVar1[1] = piVar1[1] + -1;
    if (piVar2 != piVar3) {
      param_1[-8] = (int)piVar2;
      *piVar1 = (int)piVar3;
    }
    piVar2 = (int *)param_1[-2];
  }
  else {
    if (piVar2 != (int *)0x0) {
      piVar3 = in_t0;
      piVar1 = (int *)FUN_42016f38();
    }
    *piVar1 = (int)piVar3;
  }
  return piVar2;
}


