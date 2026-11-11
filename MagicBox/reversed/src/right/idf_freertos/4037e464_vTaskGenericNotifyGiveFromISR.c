// strings: xTaskToNotify | uxIndexToNotify < 1 | tasks.c | vTaskGenericNotifyGiveFromISR | ( ( &( pxTCB->xEventListItem ) )->pxContainer ) 

void FUN_4037e464(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f78,
                 PTR_s_vTaskGenericNotifyGiveFromISR_40374f74,PTR_s_xTaskToNotify_40374f5c);
  }
  if (param_2 != 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f7c,
                 PTR_s_vTaskGenericNotifyGiveFromISR_40374f74,PTR_s_uxIndexToNotify_<_1_40374f50);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  pcVar5 = (char *)(param_1 + param_2 + 0x150);
  memw();
  cVar1 = *pcVar5;
  memw();
  *pcVar5 = '\x02';
  iVar3 = (param_2 + 0x50) * 4 + param_1;
  memw();
  memw();
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
  if (cVar1 == '\x01') {
    memw();
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f80,
                   PTR_s_vTaskGenericNotifyGiveFromISR_40374f74,
                   PTR_s________pxTCB_>xEventListItem_____40374f6c);
    }
    iVar3 = FUN_4037c9d4(param_1);
    if (iVar3 == 1) {
      memw();
      piVar8 = *(int **)(param_1 + 0x14);
      memw();
      memw();
      memw();
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(param_1 + 0xc);
      memw();
      memw();
      memw();
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined4 *)(param_1 + 8);
      memw();
      iVar3 = param_1 + 4;
      if (piVar8[1] == iVar3) {
        memw();
        memw();
        piVar8[1] = *(int *)(param_1 + 0xc);
      }
      memw();
      *(undefined4 *)(param_1 + 0x14) = 0;
      memw();
      memw();
      *piVar8 = *piVar8 + -1;
      uVar6 = *(uint *)(param_1 + 0x2c);
      memw();
      if (*DAT_40374e30 < uVar6) {
        memw();
        *DAT_40374e30 = uVar6;
      }
      iVar2 = DAT_40374e34;
      memw();
      iVar7 = *(int *)(uVar6 * 0x14 + DAT_40374e34 + 4);
      memw();
      *(int *)(param_1 + 8) = iVar7;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar7 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar7 + 8) + 4) = iVar3;
      memw();
      *(int *)(iVar7 + 8) = iVar3;
      piVar8 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar2);
      memw();
      *(int **)(param_1 + 0x14) = piVar8;
      memw();
      memw();
      *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar2) = *piVar8 + 1;
    }
    else {
      piVar8 = (int *)(uVar4 * 0x14 + DAT_40374e88);
      memw();
      iVar3 = piVar8[1];
      memw();
      *(int *)(param_1 + 0x1c) = iVar3;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar3 + 8) + 4) = param_1 + 0x18;
      memw();
      *(int *)(iVar3 + 8) = param_1 + 0x18;
      memw();
      *(int **)(param_1 + 0x28) = piVar8;
      memw();
      memw();
      *piVar8 = *piVar8 + 1;
    }
    iVar3 = FUN_4037ca58(param_1,*(undefined4 *)(param_1 + 0x2c),0);
    if (iVar3 == 1) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 1;
      }
      memw();
      *(undefined4 *)(uVar4 * 4 + DAT_40374eac) = 1;
    }
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}