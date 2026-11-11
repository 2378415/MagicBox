// strings: pxTCB == pxCurrentTCBs[ xPortGetCoreID() ] | pxTCB->uxMutexesHeld | tasks.c | xTaskPriorityDisinherit

undefined4 FUN_4037e1fc(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int in_t0;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  if (param_1 != 0) {
    uVar3 = rsr(in_PRID);
    memw();
    iVar4 = *(int *)((uVar3 >> 0xd & 1) * 4 + DAT_40374e18);
    if (iVar4 != param_1) {
      iVar4 = in_t0;
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fe0,
                   PTR_s_xTaskPriorityDisinherit_40374fdc,
                   PTR_s_pxTCB____pxCurrentTCBs__xPortGet_40374fd8);
      in_t0 = iVar4;
    }
    iVar4 = *(int *)(iVar4 + 0x50);
    if (iVar4 == 0) {
      iVar4 = in_t0;
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fe8,
                   PTR_s_xTaskPriorityDisinherit_40374fdc,PTR_s_pxTCB_>uxMutexesHeld_40374fe4);
    }
    *(int *)(param_1 + 0x50) = iVar4 + -1;
    if ((*(int *)(param_1 + 0x2c) != *(int *)(param_1 + 0x4c)) && (iVar4 + -1 == 0)) {
      iVar4 = param_1 + 4;
      FUN_4037cc94(iVar4);
      puVar1 = DAT_40374f18;
      uVar3 = *(uint *)(param_1 + 0x4c);
      memw();
      *(uint *)(param_1 + 0x18) = -(uVar3 - 0x19);
      memw();
      uVar6 = *puVar1;
      *(uint *)(param_1 + 0x2c) = uVar3;
      if (uVar6 < uVar3) {
        memw();
        *puVar1 = uVar3;
      }
      piVar5 = (int *)(uVar3 * 0x14 + DAT_40374efc);
      memw();
      iVar7 = piVar5[1];
      uVar2 = 1;
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
      *(int **)(param_1 + 0x14) = piVar5;
      memw();
      memw();
      *piVar5 = *piVar5 + 1;
      goto LAB_4037e2c3;
    }
  }
  uVar2 = 0;
LAB_4037e2c3:
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar2;
}