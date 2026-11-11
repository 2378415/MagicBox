undefined4 FUN_4200653c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000774,0xffffffff);
    for (iVar3 = 0; iVar3 < *DAT_42000780; iVar3 = iVar3 + 1) {
      iVar4 = *DAT_42000778;
      piVar5 = (int *)(iVar3 * 4 + iVar4);
      if (*piVar5 == param_1) {
        iVar2 = *DAT_42000780 + -1;
        *piVar5 = *(int *)(iVar2 * 4 + iVar4);
        iVar3 = (*(code *)PTR_FUN_42000784)(iVar4,iVar2 * 4,DAT_4200077c);
        *DAT_42000778 = iVar3;
        *DAT_42000780 = iVar2;
        uVar1 = 0;
        goto LAB_42006597;
      }
    }
    uVar1 = 0x103;
LAB_42006597:
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000774);
  }
  return uVar1;
}