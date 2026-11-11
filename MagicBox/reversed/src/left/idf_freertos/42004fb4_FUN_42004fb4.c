void FUN_42004fb4(void)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int in_a12;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  
  (*(code *)PTR_FUN_420004c8)();
  piVar4 = (int *)(*(code *)PTR_FUN_420004dc)(PTR_DAT_42000630,0xffffffff);
  piVar3 = DAT_4200063c;
  puVar2 = PTR_DAT_42000638;
  memw();
  uVar5 = *DAT_42000634;
  if (uVar5 != 0) {
    if (*PTR_DAT_42000638 == '\0') goto LAB_42005011;
    in_a12 = 0;
    piVar4 = DAT_4200063c + 1;
    if (DAT_4200063c[5] == *DAT_4200063c) goto LAB_42005011;
  }
  in_a12 = 0x18;
  piVar4 = (int *)(*DAT_42000094)(DAT_4200063c,0);
LAB_42005011:
  *puVar2 = 0;
  uVar12 = (*(code *)PTR_FUN_42000644)(piVar4);
  iVar6 = (int)((ulonglong)uVar12 >> 0x20);
  uVar7 = (iVar6 - piVar3[3]) - in_a12;
  uVar9 = (int)uVar12 - piVar3[2];
  uVar11 = uVar7 * uVar5;
  uVar10 = (uint)((ulonglong)uVar5 * (ulonglong)uVar9 >> 0x20);
  iVar1 = (int)(CONCAT44(uVar10,uVar5 * uVar9) >> 0x13);
  iVar8 = *piVar3;
  piVar3[2] = (int)uVar12;
  *piVar3 = uVar11 * 0x2000 + iVar1 + iVar8;
  piVar3[1] = (int)(((ulonglong)uVar7 * (ulonglong)uVar5 & 0xffffffff00000000 | (ulonglong)uVar11)
                   >> 0x13) + (uVar10 >> 0x13) + iVar1 + piVar3[1] + iVar8;
  piVar3[3] = iVar6;
  piVar3[5] = *piVar3;
  (*(code *)PTR_FUN_420004c8)(piVar3 + 1);
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000630);
  return;
}