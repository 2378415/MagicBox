/* (1 unreachable decompiler blocks omitted) */

void FUN_42005f3c(void)

{
  ulonglong *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  
  lVar14 = FUN_42006130();
  iVar3 = (int)((ulonglong)lVar14 >> 0x20);
  iVar7 = (int)lVar14;
  if ((lVar14 == 0) || (uVar15 = FUN_420060ec(), uVar15 < *DAT_420006f4)) {
    puVar1 = DAT_420006f4;
    *(undefined4 *)DAT_420006f4 = 0;
    *(undefined4 *)((int)puVar1 + 4) = 0;
  }
  if ((int)*DAT_420006f4 != 0 || *(int *)((int)DAT_420006f4 + 4) != 0) {
    uVar15 = FUN_420060ec();
    uVar10 = (uint)(uVar15 >> 6);
    iVar4 = (int)((uVar15 >> 6) >> 0x20);
    uVar5 = *(uint *)((int)DAT_420006f4 + 4) << 0x1a | (uint)*DAT_420006f4 >> 6;
    uVar9 = *(uint *)((int)DAT_420006f4 + 4) >> 6;
    iVar11 = iVar4 - uVar9;
    if (uVar10 < uVar5) {
      iVar11 = iVar11 + -1;
    }
    uVar13 = uVar10 - uVar5;
    if ((0 < iVar11) || ((iVar11 == 0 && (uVar13 != 0)))) {
      *DAT_420006f4 = uVar15;
      puVar2 = DAT_420006f8;
      puVar1 = DAT_420006f4;
      uVar6 = *DAT_420006f8;
      uVar8 = DAT_420006f8[1];
      if ((int)uVar8 < 0) {
        uVar12 = uVar8 + iVar11;
        if (uVar6 + uVar13 < uVar13) {
          uVar12 = uVar12 + 1;
        }
        if ((int)uVar12 < 0) {
          *DAT_420006f8 = uVar6 + uVar13;
          puVar2[1] = uVar12;
          iVar4 = uVar9 - iVar4;
          if (uVar5 < uVar10) {
            iVar4 = iVar4 + -1;
          }
          iVar7 = iVar7 + (uVar5 - uVar10);
          iVar3 = (int)puVar2 + iVar3 + iVar4;
        }
        else {
          iVar7 = iVar7 + uVar6;
          iVar3 = uVar5 + iVar3 + uVar8;
          *(undefined4 *)DAT_420006f4 = 0;
          *(undefined4 *)((int)puVar1 + 4) = 0;
        }
      }
      else {
        iVar4 = uVar8 - iVar11;
        if (uVar6 < uVar13) {
          iVar4 = iVar4 + -1;
        }
        if ((iVar4 < 1) && ((iVar4 != 0 || (uVar6 - uVar13 == 0)))) {
          iVar7 = iVar7 + uVar6;
          iVar3 = (uVar6 - uVar13) + iVar3 + uVar8;
          *(undefined4 *)DAT_420006f4 = 0;
          *(undefined4 *)((int)puVar1 + 4) = 0;
        }
        else {
          *(int *)(iVar7 + 0x20) = iVar11;
          *(int *)(uVar6 + 4) = iVar4;
          iVar7 = iVar7 + uVar13;
          iVar3 = uVar6 + iVar3 + iVar11;
        }
      }
      FUN_42006108(iVar7,iVar3);
    }
  }
  return;
}