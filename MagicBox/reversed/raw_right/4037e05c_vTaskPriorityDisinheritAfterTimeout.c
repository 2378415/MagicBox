// 4037e05c  vTaskPriorityDisinheritAfterTimeout  FUN_4037e05c  size=248
// strings: pxTCB->uxMutexesHeld | pxTCB != pxCurrentTCBs[ xPortGetCoreID() ] | vTaskPriorityDisinheritAfterTimeout

void FUN_4037e05c(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint in_t0;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  if (param_1 != 0) {
    iVar6 = *(int *)(param_1 + 0x50);
    if (iVar6 == 0) {
      iVar6 = FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f38,
                           PTR_s_vTaskPriorityDisinheritAfterTime_40374f34,
                           PTR_s_pxTCB_>uxMutexesHeld_40374f2c);
    }
    uVar2 = *(uint *)(param_1 + 0x4c);
    if (*(uint *)(param_1 + 0x4c) < param_2) {
      uVar2 = param_2;
    }
    if ((*(uint *)(param_1 + 0x2c) != uVar2) && (iVar6 == 1)) {
      uVar7 = rsr(in_PRID);
      memw();
      uVar4 = *(uint *)(param_1 + 0x2c);
      if (*(int *)((uVar7 >> 0xd & 1) * 4 + DAT_40374d64) == param_1) {
        uVar2 = in_t0;
        FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f40,
                     PTR_s_vTaskPriorityDisinheritAfterTime_40374f34,
                     PTR_s_pxTCB____pxCurrentTCBs__xPortGet_40374f3c);
        uVar4 = uVar2;
      }
      *(uint *)(param_1 + 0x2c) = uVar2;
      memw();
      if (-1 < *(int *)(param_1 + 0x18)) {
        memw();
        *(uint *)(param_1 + 0x18) = -(uVar2 - 0x19);
      }
      memw();
      if (*(int *)(param_1 + 0x14) == uVar4 * 0x14 + DAT_40374e34) {
        iVar6 = param_1 + 4;
        FUN_4037c980(iVar6);
        uVar2 = *(uint *)(param_1 + 0x2c);
        memw();
        if (*DAT_40374e30 < uVar2) {
          memw();
          *DAT_40374e30 = uVar2;
        }
        iVar1 = DAT_40374e34;
        memw();
        iVar3 = *(int *)(uVar2 * 0x14 + DAT_40374e34 + 4);
        memw();
        *(int *)(param_1 + 8) = iVar3;
        memw();
        memw();
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar3 + 8) + 4) = iVar6;
        memw();
        *(int *)(iVar3 + 8) = iVar6;
        piVar5 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1);
        memw();
        *(int **)(param_1 + 0x14) = piVar5;
        memw();
        memw();
        *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1) = *piVar5 + 1;
      }
    }
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}


