// 4200910c  FUN_4200910c  FUN_4200910c  size=55

void FUN_4200910c(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 * 4 + DAT_42000a40);
  uVar1 = *(uint *)(iVar4 + 0x30);
  if (uVar1 != *(uint *)(iVar4 + 0x2c)) {
    iVar5 = *(int *)(iVar4 + 0x38);
    do {
      piVar2 = (int *)(uVar1 * 4 + iVar5);
      iVar3 = *piVar2 - param_2;
      *piVar2 = iVar3;
      uVar1 = uVar1 + 1 & -*(int *)(iVar4 + 0x34);
      if (iVar3 < 0) {
        *(uint *)(iVar4 + 0x30) = uVar1;
      }
    } while (uVar1 != *(uint *)(iVar4 + 0x2c));
  }
  return;
}


