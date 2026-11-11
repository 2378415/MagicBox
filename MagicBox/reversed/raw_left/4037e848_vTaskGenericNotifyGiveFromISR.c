// 4037e848  vTaskGenericNotifyGiveFromISR  FUN_4037e848  size=427
// strings: xTaskToNotify | uxIndexToNotify < 1 | tasks.c | vTaskGenericNotifyGiveFromISR | ( ( &( pxTCB->xEventListItem ) )->pxContainer ) 

void FUN_4037e848(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375044,
                 PTR_s_vTaskGenericNotifyGiveFromISR_40375040,PTR_s_xTaskToNotify_40375014);
  }
  if (param_2 != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375048,
                 PTR_s_vTaskGenericNotifyGiveFromISR_40375040,PTR_s_uxIndexToNotify_<_1_40375008);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  memw();
  cVar1 = *(char *)(param_1 + 0x150);
  memw();
  *(undefined1 *)(param_1 + 0x150) = 2;
  memw();
  memw();
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  if (cVar1 != '\x01') goto LAB_4037e9eb;
  memw();
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_4037504c,
                 PTR_s_vTaskGenericNotifyGiveFromISR_40375040,
                 PTR_s________pxTCB_>xEventListItem_____40375024);
  }
  if (*(int *)(param_1 + 0x44) == DAT_40374eac) {
    memw();
    if ((*DAT_40374ed8 == 0) || (memw(), DAT_40374ed8[1] == 0)) goto LAB_4037e8e8;
LAB_4037e989:
    piVar4 = (int *)(uVar3 * 0x14 + DAT_40374f08);
    memw();
    iVar5 = piVar4[1];
    memw();
    *(int *)(param_1 + 0x1c) = iVar5;
    memw();
    uVar7 = *(uint *)(param_1 + 0x2c);
    memw();
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar5 + 8);
    memw();
    memw();
    *(int *)(*(int *)(iVar5 + 8) + 4) = param_1 + 0x18;
    memw();
    *(int *)(iVar5 + 8) = param_1 + 0x18;
    memw();
    *(int **)(param_1 + 0x28) = piVar4;
    memw();
    memw();
    *piVar4 = *piVar4 + 1;
  }
  else {
    memw();
    if (DAT_40374ed8[*(int *)(param_1 + 0x44)] != 0) goto LAB_4037e989;
LAB_4037e8e8:
    memw();
    piVar4 = *(int **)(param_1 + 0x14);
    memw();
    memw();
    iVar5 = param_1 + 4;
    memw();
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(param_1 + 0xc);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined4 *)(param_1 + 8);
    memw();
    if (piVar4[1] == iVar5) {
      memw();
      memw();
      piVar4[1] = *(int *)(param_1 + 0xc);
    }
    memw();
    *(undefined4 *)(param_1 + 0x14) = 0;
    puVar2 = DAT_40374f18;
    memw();
    memw();
    *piVar4 = *piVar4 + -1;
    uVar7 = *(uint *)(param_1 + 0x2c);
    memw();
    if (*puVar2 < uVar7) {
      memw();
      *puVar2 = uVar7;
    }
    piVar4 = (int *)(uVar7 * 0x14 + DAT_40374efc);
    memw();
    iVar6 = piVar4[1];
    memw();
    *(int *)(param_1 + 8) = iVar6;
    memw();
    memw();
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar6 + 8);
    memw();
    memw();
    *(int *)(*(int *)(iVar6 + 8) + 4) = iVar5;
    memw();
    *(int *)(iVar6 + 8) = iVar5;
    memw();
    *(int **)(param_1 + 0x14) = piVar4;
    memw();
    memw();
    *piVar4 = *piVar4 + 1;
  }
  iVar5 = FUN_4037cce8(param_1,uVar7,0);
  if (iVar5 == 1) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 1;
    }
    memw();
    *(undefined4 *)(uVar3 * 4 + DAT_40374f78) = 1;
  }
LAB_4037e9eb:
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}


