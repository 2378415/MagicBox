// strings: pxUnblockedTCB | uxSchedulerSuspended[ uxPendCore ] != ( UBaseTyp | tasks.c | xTaskRemoveFromEventList

void FUN_4037dde4(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  uint in_t0;
  undefined1 in_PRID;
  
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  memw();
  if (*param_1 == 0) goto LAB_4037dfac;
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  iVar8 = *(int *)(param_1[3] + 0xc);
  if (iVar8 == 0) {
    iVar8 = FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fb8,
                         PTR_s_xTaskRemoveFromEventList_40374fb4,PTR_s_pxUnblockedTCB_40374fb0);
  }
  memw();
  piVar4 = *(int **)(iVar8 + 0x28);
  memw();
  memw();
  puVar10 = (undefined *)(iVar8 + 0x18);
  memw();
  *(undefined4 *)(*(int *)(iVar8 + 0x1c) + 8) = *(undefined4 *)(iVar8 + 0x20);
  memw();
  memw();
  memw();
  *(undefined4 *)(*(int *)(iVar8 + 0x20) + 4) = *(undefined4 *)(iVar8 + 0x1c);
  memw();
  if ((undefined *)piVar4[1] == puVar10) {
    memw();
    memw();
    piVar4[1] = *(int *)(iVar8 + 0x20);
  }
  memw();
  *(undefined4 *)(iVar8 + 0x28) = 0;
  uVar6 = DAT_40374eac;
  memw();
  uVar3 = *(uint *)(iVar8 + 0x44);
  memw();
  *piVar4 = *piVar4 + -1;
  if (uVar3 == uVar6) {
    memw();
    if ((*DAT_40374ed8 == 0) || (memw(), DAT_40374ed8[1] == 0)) goto LAB_4037de99;
    uVar3 = uVar2;
LAB_4037df39:
    memw();
    uVar6 = uVar3 << 2;
    if (DAT_40374ed8[uVar3] == 0) {
      puVar10 = PTR_s_xTaskRemoveFromEventList_40374fb4;
      uVar3 = in_t0;
      iVar8 = FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fc0,
                           PTR_s_xTaskRemoveFromEventList_40374fb4,
                           PTR_s_uxSchedulerSuspended__uxPendCore_40374fbc);
      uVar6 = uVar3;
    }
    uVar9 = *(uint *)(iVar8 + 0x2c);
    piVar4 = (int *)((uVar6 + uVar3) * 4 + DAT_40374f08);
    memw();
    iVar7 = piVar4[1];
    memw();
    *(int *)(iVar8 + 0x1c) = iVar7;
    memw();
    memw();
    *(undefined4 *)(iVar8 + 0x20) = *(undefined4 *)(iVar7 + 8);
    memw();
    memw();
    *(undefined **)(*(int *)(iVar7 + 8) + 4) = puVar10;
    memw();
    *(undefined **)(iVar7 + 8) = puVar10;
    memw();
    *(int **)(iVar8 + 0x28) = piVar4;
    memw();
    memw();
    *piVar4 = *piVar4 + 1;
  }
  else {
    memw();
    if (DAT_40374ed8[uVar3] != 0) goto LAB_4037df39;
LAB_4037de99:
    memw();
    piVar4 = *(int **)(iVar8 + 0x14);
    memw();
    memw();
    iVar7 = iVar8 + 4;
    memw();
    *(undefined4 *)(*(int *)(iVar8 + 8) + 8) = *(undefined4 *)(iVar8 + 0xc);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(iVar8 + 0xc) + 4) = *(undefined4 *)(iVar8 + 8);
    memw();
    if (piVar4[1] == iVar7) {
      memw();
      memw();
      piVar4[1] = *(int *)(iVar8 + 0xc);
    }
    memw();
    *(undefined4 *)(iVar8 + 0x14) = 0;
    puVar1 = DAT_40374f18;
    memw();
    memw();
    *piVar4 = *piVar4 + -1;
    uVar9 = *(uint *)(iVar8 + 0x2c);
    memw();
    if (*puVar1 < uVar9) {
      memw();
      *puVar1 = uVar9;
    }
    piVar4 = (int *)(uVar9 * 0x14 + DAT_40374efc);
    memw();
    iVar5 = piVar4[1];
    memw();
    *(int *)(iVar8 + 8) = iVar5;
    memw();
    memw();
    *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(iVar5 + 8);
    memw();
    memw();
    *(int *)(*(int *)(iVar5 + 8) + 4) = iVar7;
    memw();
    *(int *)(iVar5 + 8) = iVar7;
    memw();
    *(int **)(iVar8 + 0x14) = piVar4;
    memw();
    memw();
    *piVar4 = *piVar4 + 1;
  }
  iVar8 = FUN_4037cce8(iVar8,uVar9,0);
  if (iVar8 == 1) {
    memw();
    *(undefined4 *)(uVar2 * 4 + DAT_40374f78) = 1;
  }
LAB_4037dfac:
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}