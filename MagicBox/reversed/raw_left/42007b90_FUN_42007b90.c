// 42007b90  FUN_42007b90  FUN_42007b90  size=224

/* WARNING: Removing unreachable block (ram,0x42007bc1) */

void FUN_42007b90(void)

{
  int iVar1;
  ulonglong *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_a12;
  int iVar11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  
  lVar13 = FUN_42007d34();
  iVar4 = (int)((ulonglong)lVar13 >> 0x20);
  iVar10 = (int)lVar13;
  if (lVar13 == 0) {
LAB_42007ba5:
    puVar2 = DAT_420008cc;
    *(undefined4 *)DAT_420008cc = 0;
    *(undefined4 *)((int)puVar2 + 4) = 0;
    return;
  }
  uVar14 = FUN_42007cf0();
  puVar2 = DAT_420008cc;
  if (uVar14 < *DAT_420008cc) goto LAB_42007ba5;
  if ((int)*DAT_420008cc == 0 && *(int *)((int)DAT_420008cc + 4) == 0) {
    return;
  }
  uVar14 = FUN_42007cf0();
  piVar3 = DAT_420008d0;
  uVar5 = (uint)(uVar14 >> 0x20);
  iVar8 = (int)(uVar14 >> 6);
  iVar1 = (int)(*puVar2 >> 6);
  uVar7 = uVar5 >> 6;
  uVar12 = *(uint *)((int)puVar2 + 4) >> 6;
  in_a12 = (uVar7 - uVar12) - in_a12;
  iVar11 = iVar8 - iVar1;
  if (in_a12 < 1) {
    if (in_a12 != 0) {
      return;
    }
    if (iVar11 == 0) {
      return;
    }
  }
  iVar6 = DAT_420008d0[1];
  *puVar2 = uVar14;
  iVar9 = *piVar3;
  if (iVar6 < 0) {
    in_a12 = iVar6 + in_a12 + iVar11;
    if (in_a12 < 0) {
      *piVar3 = iVar9 + iVar11;
      piVar3[1] = in_a12;
      in_a12 = ((uVar12 + iVar4 + iVar10) - uVar7) - iVar9;
      iVar10 = (iVar1 + iVar10) - iVar8;
      goto LAB_42007c6a;
    }
  }
  else {
    iVar8 = (iVar6 - in_a12) - uVar5;
    if ((0 < iVar8) || ((iVar8 == 0 && (iVar9 - iVar11 != 0)))) {
      iVar10 = iVar10 + iVar11;
      *piVar3 = iVar9 - iVar11;
      piVar3[1] = iVar8;
      in_a12 = iVar9 + iVar4 + in_a12;
      goto LAB_42007c6a;
    }
  }
  iVar10 = iVar10 + iVar9;
  in_a12 = in_a12 + iVar4 + iVar6;
  *(undefined4 *)puVar2 = 0;
  *(undefined4 *)((int)puVar2 + 4) = 0;
LAB_42007c6a:
  FUN_42007d0c(iVar10,in_a12);
  return;
}


