// strings: pxTCB == pxCurrentTCBs[ xPortGetCoreID() ] | pxTCB->uxMutexesHeld | tasks.c | xTaskPriorityDisinherit

undefined4 FUN_4037df74(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int in_t0;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = rsr(in_PRID);
    memw();
    if (*(int *)((uVar3 >> 0xd & 1) * 4 + DAT_40374d64) != param_1) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f28,
                   PTR_s_xTaskPriorityDisinherit_40374f24,
                   PTR_s_pxTCB____pxCurrentTCBs__xPortGet_40374f20);
    }
    iVar4 = *(int *)(param_1 + 0x50);
    if (iVar4 == 0) {
      iVar4 = in_t0;
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f30,
                   PTR_s_xTaskPriorityDisinherit_40374f24,PTR_s_pxTCB_>uxMutexesHeld_40374f2c);
    }
    *(int *)(param_1 + 0x50) = iVar4 + -1;
    if (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x4c)) {
      uVar2 = 0;
    }
    else if (iVar4 + -1 == 0) {
      iVar4 = param_1 + 4;
      FUN_4037c980(iVar4);
      uVar3 = *(uint *)(param_1 + 0x4c);
      *(uint *)(param_1 + 0x2c) = uVar3;
      memw();
      *(uint *)(param_1 + 0x18) = -(uVar3 - 0x19);
      memw();
      if (*DAT_40374e30 < uVar3) {
        memw();
        *DAT_40374e30 = uVar3;
      }
      iVar1 = DAT_40374e34;
      memw();
      iVar5 = *(int *)(uVar3 * 0x14 + DAT_40374e34 + 4);
      memw();
      *(int *)(param_1 + 8) = iVar5;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar5 + 8) + 4) = iVar4;
      memw();
      *(int *)(iVar5 + 8) = iVar4;
      piVar6 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1);
      memw();
      *(int **)(param_1 + 0x14) = piVar6;
      memw();
      memw();
      *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1) = *piVar6 + 1;
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar2;
}