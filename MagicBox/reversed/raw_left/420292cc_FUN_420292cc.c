// 420292cc  FUN_420292cc  FUN_420292cc  size=309

uint FUN_420292cc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = 0;
  if (*(int *)(param_2 + 0x10) <= *(int *)(param_1 + 0x10)) {
    iVar5 = *(int *)(param_2 + 0x10) + -1;
    puVar4 = (uint *)(param_2 + 0x14);
    puVar3 = (uint *)(param_1 + 0x14);
    puVar6 = puVar3 + iVar5;
    uVar1 = *puVar6 / (puVar4[iVar5] + 1);
    if ((puVar4[iVar5] + 1 <= *puVar6) &&
       (uVar7 = (*puVar4 & 0xffff) * uVar1, uVar8 = (*puVar3 & 0xffff) - (uVar7 & 0xffff),
       *puVar3 = (((*puVar3 >> 0x10) - ((*puVar4 >> 0x10) * uVar1 + (uVar7 >> 0x10) & 0xffff)) +
                 ((int)uVar8 >> 0x10)) * 0x10000 | uVar8 & 0xffff, *puVar6 == 0)) {
      while ((puVar6 = puVar6 + -1, puVar3 < puVar6 && (*puVar6 == 0))) {
        iVar5 = iVar5 + -1;
      }
      *(int *)(param_1 + 0x10) = iVar5;
    }
    iVar2 = FUN_4202a6cc(param_1);
    if (-1 < iVar2) {
      uVar7 = (*puVar3 & 0xffff) - (*puVar4 & 0xffff);
      *puVar3 = (((*puVar3 >> 0x10) - (*puVar4 >> 0x10)) + ((int)uVar7 >> 0x10)) * 0x10000 |
                uVar7 & 0xffff;
      puVar4 = puVar3 + iVar5;
      if (*puVar4 == 0) {
        while ((puVar4 = puVar4 + -1, puVar3 < puVar4 && (*puVar4 == 0))) {
          iVar5 = iVar5 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar5;
      }
      uVar1 = uVar1 + 1;
    }
  }
  return uVar1;
}


