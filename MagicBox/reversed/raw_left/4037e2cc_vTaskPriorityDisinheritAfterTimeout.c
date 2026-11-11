// 4037e2cc  vTaskPriorityDisinheritAfterTimeout  FUN_4037e2cc  size=228
// strings: pxTCB->uxMutexesHeld | pxTCB != pxCurrentTCBs[ xPortGetCoreID() ] | vTaskPriorityDisinheritAfterTimeout

void FUN_4037e2cc(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int in_t0;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x50);
    if (iVar2 == 0) {
      iVar2 = in_t0;
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374ff0,
                   PTR_s_vTaskPriorityDisinheritAfterTime_40374fec,
                   PTR_s_pxTCB_>uxMutexesHeld_40374fe4);
      in_t0 = iVar2;
    }
    uVar5 = *(uint *)(param_1 + 0x4c);
    iVar4 = *(int *)(param_1 + 0x2c);
    iVar1 = (param_2 < uVar5) * uVar5 + (param_2 >= uVar5) * param_2;
    if ((iVar2 == 1) && (iVar4 != iVar1)) {
      uVar5 = rsr(in_PRID);
      memw();
      if (*(int *)((uVar5 >> 0xd & 1) * 4 + DAT_40374e18) == param_1) {
        iVar4 = in_t0;
        FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374ff8,
                     PTR_s_vTaskPriorityDisinheritAfterTime_40374fec,
                     PTR_s_pxTCB____pxCurrentTCBs__xPortGet_40374ff4);
      }
      memw();
      *(int *)(param_1 + 0x2c) = iVar1;
      if (-1 < *(int *)(param_1 + 0x18)) {
        memw();
        *(int *)(param_1 + 0x18) = -(iVar1 + -0x19);
      }
      iVar2 = DAT_40374efc;
      memw();
      if (*(int *)(param_1 + 0x14) == iVar4 * 0x14 + DAT_40374efc) {
        iVar4 = param_1 + 4;
        FUN_4037cc94(iVar4);
        uVar5 = *(uint *)(param_1 + 0x2c);
        memw();
        if (*DAT_40374f18 < uVar5) {
          memw();
          *DAT_40374f18 = uVar5;
        }
        piVar3 = (int *)(uVar5 * 0x14 + iVar2);
        memw();
        iVar2 = piVar3[1];
        memw();
        *(int *)(param_1 + 8) = iVar2;
        memw();
        memw();
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar2 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar2 + 8) + 4) = iVar4;
        memw();
        *(int *)(iVar2 + 8) = iVar4;
        memw();
        *(int **)(param_1 + 0x14) = piVar3;
        memw();
        memw();
        *piVar3 = *piVar3 + 1;
      }
    }
  }
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}


