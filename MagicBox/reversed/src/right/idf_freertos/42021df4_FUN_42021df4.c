ulonglong FUN_42021df4(int param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar3 = *(int *)(param_1 + 0x10);
  puVar2 = (uint *)(param_1 + 0x14);
  puVar5 = puVar2 + iVar3 + -1;
  uVar4 = *puVar5;
  iVar1 = FUN_4202180c(uVar4);
  *param_2 = -(iVar1 + -0x20);
  if (iVar1 < 0xb) {
    uVar10 = -(iVar1 + -0xb);
    uVar6 = uVar4 >> (uVar10 & 0x1f);
    uVar8 = 0;
    if (puVar2 < puVar5) {
      uVar8 = puVar2[iVar3 + -2];
    }
    uVar4 = uVar4 << 0x20 - (0x20 - (iVar1 + 0x15U & 0x1f));
  }
  else {
    uVar7 = 0;
    if (puVar2 < puVar5) {
      puVar5 = puVar2 + iVar3 + -2;
      uVar7 = *puVar5;
    }
    uVar9 = iVar1 - 0xb;
    if (uVar9 == 0) goto LAB_42021e7c;
    uVar6 = (uint)(CONCAT44(uVar4,uVar7) >> 0x20 - (uVar9 & 0x1f));
    uVar10 = -(iVar1 + -0x2b);
    uVar8 = 0;
    if (puVar2 < puVar5) {
      uVar8 = puVar5[-1];
    }
    uVar4 = uVar7 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  uVar7 = uVar4 | uVar8 >> (uVar10 & 0x1f);
  uVar4 = uVar6;
LAB_42021e7c:
  return CONCAT44(uVar4,uVar7) | 0x3ff0000000000000;
}