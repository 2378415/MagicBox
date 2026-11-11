undefined4 FUN_4202aac8(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar1 = (int)param_2 >> 5;
  piVar3 = (int *)(param_1 + 0x14);
  if (iVar4 < iVar1) {
    iVar1 = iVar4;
  }
  else if (((iVar1 < iVar4) && ((param_2 & 0x1f) != 0)) &&
          (piVar3[iVar1] !=
           ((uint)piVar3[iVar1] >> (param_2 & 0x1f)) << 0x20 - (0x20 - (param_2 & 0x1f)))) {
    return 1;
  }
  piVar2 = piVar3 + iVar1;
  do {
    if (piVar2 <= piVar3) {
      return 0;
    }
    piVar2 = piVar2 + -1;
  } while (*piVar2 == 0);
  return 1;
}