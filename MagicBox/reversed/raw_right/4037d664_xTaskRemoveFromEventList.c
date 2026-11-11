// 4037d664  xTaskRemoveFromEventList  FUN_4037d664  size=504
// strings: pxUnblockedTCB | tasks.c | xTaskRemoveFromEventList | uxSchedulerSuspended[ uxPendCore ] != ( UBaseTyp

void FUN_4037d664(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined1 in_PRID;
  
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  memw();
  if (*param_1 != 0) {
    uVar4 = rsr(in_PRID);
    uVar4 = uVar4 >> 0xd & 1;
    memw();
    iVar1 = *(int *)(param_1[3] + 0xc);
    if (iVar1 == 0) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ed4,
                   PTR_s_xTaskRemoveFromEventList_40374ed0,PTR_s_pxUnblockedTCB_40374ecc);
    }
    memw();
    piVar5 = *(int **)(iVar1 + 0x28);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(iVar1 + 0x1c) + 8) = *(undefined4 *)(iVar1 + 0x20);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 4) = *(undefined4 *)(iVar1 + 0x1c);
    memw();
    iVar2 = iVar1 + 0x18;
    if (piVar5[1] == iVar2) {
      memw();
      memw();
      piVar5[1] = *(int *)(iVar1 + 0x20);
    }
    memw();
    *(undefined4 *)(iVar1 + 0x28) = 0;
    memw();
    memw();
    *piVar5 = *piVar5 + -1;
    iVar3 = FUN_4037c9d4(iVar1);
    if (iVar3 == 1) {
      memw();
      piVar5 = *(int **)(iVar1 + 0x14);
      memw();
      memw();
      memw();
      *(undefined4 *)(*(int *)(iVar1 + 8) + 8) = *(undefined4 *)(iVar1 + 0xc);
      memw();
      memw();
      memw();
      *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4) = *(undefined4 *)(iVar1 + 8);
      memw();
      iVar2 = iVar1 + 4;
      if (piVar5[1] == iVar2) {
        memw();
        memw();
        piVar5[1] = *(int *)(iVar1 + 0xc);
      }
      memw();
      *(undefined4 *)(iVar1 + 0x14) = 0;
      memw();
      memw();
      *piVar5 = *piVar5 + -1;
      uVar6 = *(uint *)(iVar1 + 0x2c);
      memw();
      if (*DAT_40374e30 < uVar6) {
        memw();
        *DAT_40374e30 = uVar6;
      }
      iVar3 = DAT_40374e34;
      memw();
      iVar7 = *(int *)(uVar6 * 0x14 + DAT_40374e34 + 4);
      memw();
      *(int *)(iVar1 + 8) = iVar7;
      memw();
      memw();
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar7 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar7 + 8) + 4) = iVar2;
      memw();
      *(int *)(iVar7 + 8) = iVar2;
      piVar5 = (int *)(*(int *)(iVar1 + 0x2c) * 0x14 + iVar3);
      memw();
      *(int **)(iVar1 + 0x14) = piVar5;
      memw();
      memw();
      *(int *)(*(int *)(iVar1 + 0x2c) * 0x14 + iVar3) = *piVar5 + 1;
    }
    else {
      uVar6 = uVar4;
      if (*(uint *)(iVar1 + 0x44) != DAT_403747f4) {
        uVar6 = *(uint *)(iVar1 + 0x44);
      }
      memw();
      if (*(int *)(uVar6 * 4 + DAT_40374e18) == 0) {
        FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374edc,
                     PTR_s_xTaskRemoveFromEventList_40374ed0,
                     PTR_s_uxSchedulerSuspended__uxPendCore_40374ed8);
      }
      iVar3 = DAT_40374e88;
      piVar5 = (int *)(uVar6 * 0x14 + DAT_40374e88);
      memw();
      iVar7 = piVar5[1];
      memw();
      *(int *)(iVar1 + 0x1c) = iVar7;
      memw();
      memw();
      *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar7 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar7 + 8) + 4) = iVar2;
      memw();
      *(int *)(iVar7 + 8) = iVar2;
      memw();
      *(int **)(iVar1 + 0x28) = piVar5;
      memw();
      memw();
      *(int *)(uVar6 * 0x14 + iVar3) = *piVar5 + 1;
    }
    iVar1 = FUN_4037ca58(iVar1,*(undefined4 *)(iVar1 + 0x2c),0);
    if (iVar1 == 1) {
      memw();
      *(undefined4 *)(uVar4 * 4 + DAT_40374eac) = 1;
    }
  }
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  else {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  return;
}


