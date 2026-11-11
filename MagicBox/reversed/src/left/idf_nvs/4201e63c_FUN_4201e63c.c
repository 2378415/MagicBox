void FUN_4201e63c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  piVar1 = (int *)FUN_4201e6c0();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    return;
  }
  uVar4 = *(int *)(iVar2 + 0x30) + DAT_42001b04;
  iVar3 = *(int *)(iVar2 + 0x34) + DAT_42001b08;
  if (uVar4 < DAT_42001b04) {
    iVar3 = iVar3 + 1;
  }
  if ((iVar3 == 0) && (uVar4 < 2)) {
    iVar3 = *(int *)(iVar2 + 0x14);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) {
        *piVar1 = *(int *)(iVar2 + 0x10);
      }
    }
    else {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar2 + 0x10);
        goto LAB_4201e67e;
      }
      if (iVar3 == -1) {
        iVar2 = in_t0;
        FUN_4201e770();
        iVar3 = iVar2;
      }
    }
    *(int *)(iVar2 + 0x14) = iVar3;
  }
  else {
    iVar3 = 0;
LAB_4201e67e:
    *piVar1 = iVar3;
    FUN_4201ea1c(iVar2 + 0x30);
  }
  return;
}