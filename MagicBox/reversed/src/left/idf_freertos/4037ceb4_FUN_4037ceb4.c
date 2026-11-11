void FUN_4037ceb4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar8 = DAT_40374efc;
  piVar1 = DAT_40374ef8;
  memw();
  memw();
  *DAT_40374ef8 = *DAT_40374ef8 + 1;
  memw();
  if (*piVar1 == 1) {
    iVar7 = iVar8;
    do {
      iVar5 = iVar7 + 0x14;
      FUN_4037cbbc(iVar7);
      uVar2 = DAT_40374f00;
      iVar7 = iVar5;
    } while (iVar8 + 500 != iVar5);
    FUN_4037cbbc(DAT_40374f00);
    uVar3 = DAT_40374f04;
    FUN_4037cbbc(DAT_40374f04);
    FUN_4037cbbc(DAT_40374f08);
    FUN_4037cbbc(DAT_40374f0c);
    FUN_4037cbbc(DAT_40374ee0);
    FUN_4037cbbc(DAT_40374ee4);
    memw();
    *DAT_40374eec = uVar2;
    memw();
    *DAT_40374ee8 = uVar3;
  }
  piVar1 = DAT_40374f10;
  uVar9 = *(uint *)(param_1 + 0x2c);
  memw();
  if (*DAT_40374e18 == 0) {
    iVar7 = *(int *)(param_1 + 0x44);
    if ((iVar7 == 0) || (iVar7 == DAT_40374eac || iVar7 == 0)) {
      memw();
      *DAT_40374e18 = param_1;
      goto LAB_4037cff0;
    }
  }
  memw();
  if (DAT_40374e18[1] == 0) {
    iVar7 = *(int *)(param_1 + 0x44);
    if ((iVar7 == 1) || (iVar7 == DAT_40374eac || iVar7 == 1)) {
      memw();
      DAT_40374e18[1] = param_1;
      goto LAB_4037cff0;
    }
  }
  memw();
  if (*DAT_40374f10 == 0) {
    memw();
    if (*DAT_40374e18 != 0) {
      iVar7 = *(int *)(param_1 + 0x44);
      if (((iVar7 == 0) || (iVar7 == DAT_40374eac || iVar7 == 0)) &&
         (memw(), *(uint *)(*DAT_40374e18 + 0x2c) <= uVar9)) {
        memw();
        *DAT_40374e18 = param_1;
        goto LAB_4037cff0;
      }
    }
    memw();
    if (DAT_40374e18[1] != 0) {
      iVar7 = *(int *)(param_1 + 0x44);
      if (((iVar7 == 1) || (iVar7 == DAT_40374eac || iVar7 == 1)) &&
         (memw(), *(uint *)(DAT_40374e18[1] + 0x2c) <= uVar9)) {
        memw();
        DAT_40374e18[1] = param_1;
      }
    }
  }
LAB_4037cff0:
  puVar4 = DAT_40374f18;
  memw();
  uVar10 = *DAT_40374f18;
  *DAT_40374f14 = *DAT_40374f14 + 1;
  if (uVar10 < uVar9) {
    memw();
    *puVar4 = uVar9;
  }
  piVar6 = (int *)(uVar9 * 0x14 + iVar8);
  memw();
  iVar8 = piVar6[1];
  memw();
  *(int *)(param_1 + 8) = iVar8;
  memw();
  memw();
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar8 + 8);
  memw();
  memw();
  *(int *)(*(int *)(iVar8 + 8) + 4) = param_1 + 4;
  memw();
  *(int *)(iVar8 + 8) = param_1 + 4;
  memw();
  *(int **)(param_1 + 0x14) = piVar6;
  memw();
  memw();
  *piVar6 = *piVar6 + 1;
  memw();
  if ((*piVar1 != 0) && (iVar8 = FUN_4037cce8(param_1,uVar9,1), iVar8 == 1)) {
    uVar9 = rsr(in_PRID);
    FUN_40378e40(uVar9 >> 0xd & 1);
  }
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}