undefined4 FUN_4200958c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000928,0xffffffff);
    for (iVar2 = 0; iVar2 < *DAT_42000930; iVar2 = iVar2 + 1) {
      iVar3 = *DAT_4200092c;
      piVar4 = (int *)(iVar2 * 4 + iVar3);
      if (*piVar4 == param_1) {
        iVar2 = *DAT_42000930 + -1;
        *piVar4 = *(int *)(iVar2 * 4 + iVar3);
        iVar3 = (*(code *)PTR_FUN_42000784)(iVar3,iVar2 * 4,DAT_4200077c);
        *DAT_4200092c = iVar3;
        *DAT_42000930 = iVar2;
        if (iVar2 == 0) {
          FUN_42009aa8(0);
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
        }
        goto LAB_420095ef;
      }
    }
    uVar1 = 0x103;
LAB_420095ef:
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000928);
  }
  return uVar1;
}