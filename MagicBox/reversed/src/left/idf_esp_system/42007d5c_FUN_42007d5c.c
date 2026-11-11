void FUN_42007d5c(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStack_40 [16];
  int iStack_30;
  int iStack_2c;
  
  FUN_42020b94(auStack_40,0);
  FUN_42007cd8(auStack_40,0);
  uVar10 = FUN_42004fb4();
  uVar11 = (*(code *)PTR_FUN_420008e4)();
  iStack_30 = (int)((ulonglong)uVar11 >> 0x20);
  iStack_2c = (int)uVar11;
  (*(code *)PTR_FUN_420008d8)(DAT_420008e8);
  piVar3 = DAT_420008f0;
  piVar2 = DAT_420008ec;
  memw();
  iVar4 = *DAT_420008ec;
  memw();
  iVar5 = *DAT_420008f0;
  (*(code *)PTR_FUN_420008dc)(DAT_420008e8);
  iVar9 = *DAT_420008e0;
  iVar6 = DAT_420008e0[1];
  iVar8 = ((int)((ulonglong)uVar10 >> 0x20) - iStack_30) - (int)DAT_420008e0;
  iVar7 = iVar9 - ((int)uVar10 - iStack_2c);
  (*(code *)PTR_FUN_420008d8)(DAT_420008e8);
  uVar1 = DAT_420008e8;
  memw();
  *piVar2 = iVar7 + iVar4;
  memw();
  *piVar3 = ((iVar6 - iVar8) - iVar9) + iVar5 + iVar7;
  (*(code *)PTR_FUN_420008dc)(uVar1);
  return;
}