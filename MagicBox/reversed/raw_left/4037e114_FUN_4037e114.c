// 4037e114  FUN_4037e114  FUN_4037e114  size=229

undefined4 FUN_4037e114(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar7 = DAT_40374e18;
  uVar6 = rsr(in_PRID);
  uVar6 = uVar6 >> 0xd & 1;
  uVar3 = 0;
  if (param_1 != 0) {
    iVar5 = uVar6 * 4;
    piVar8 = (int *)(uVar6 * 4 + DAT_40374e18);
    memw();
    if (*(uint *)(param_1 + 0x2c) < *(uint *)(*piVar8 + 0x2c)) {
      memw();
      if (-1 < *(int *)(param_1 + 0x18)) {
        memw();
        memw();
        *(int *)(param_1 + 0x18) = -(*(int *)(*piVar8 + 0x2c) + -0x19);
      }
      iVar1 = DAT_40374efc;
      memw();
      if (*(int *)(param_1 + 0x14) == *(uint *)(param_1 + 0x2c) * 0x14 + DAT_40374efc) {
        iVar4 = param_1 + 4;
        FUN_4037cc94(iVar4);
        puVar2 = DAT_40374f18;
        memw();
        uVar6 = *(uint *)(*(int *)(iVar7 + iVar5) + 0x2c);
        memw();
        uVar9 = *DAT_40374f18;
        *(uint *)(param_1 + 0x2c) = uVar6;
        if (uVar9 < uVar6) {
          memw();
          *puVar2 = uVar6;
        }
        piVar8 = (int *)(uVar6 * 0x14 + iVar1);
        memw();
        iVar7 = piVar8[1];
        memw();
        *(int *)(param_1 + 8) = iVar7;
        memw();
        memw();
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar7 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar7 + 8) + 4) = iVar4;
        memw();
        *(int *)(iVar7 + 8) = iVar4;
        memw();
        *(int **)(param_1 + 0x14) = piVar8;
        memw();
        memw();
        *piVar8 = *piVar8 + 1;
      }
      else {
        memw();
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(iVar7 + iVar5) + 0x2c);
      }
      uVar3 = 1;
    }
    else {
      memw();
      uVar3 = *(undefined4 *)(param_1 + 0x4c);
    }
  }
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar3;
}


