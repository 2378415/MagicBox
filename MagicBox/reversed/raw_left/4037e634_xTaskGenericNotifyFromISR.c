// 4037e634  xTaskGenericNotifyFromISR  FUN_4037e634  size=528
// strings: xTaskToNotify | uxIndexToNotify < 1 | tasks.c | xTaskGenericNotifyFromISR | &5/&E& | xTickCount == ( TickType_t ) 0 | ( ( &( pxTCB->xEventListItem ) )->pxContainer ) 

undefined4
FUN_4037e634(int param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint in_t0;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375030,
                 PTR_s_xTaskGenericNotifyFromISR_4037502c,PTR_s_xTaskToNotify_40375014);
  }
  if (param_2 != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375034,
                 PTR_s_xTaskGenericNotifyFromISR_4037502c,PTR_s_uxIndexToNotify_<_1_40375008);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  if (param_5 != (undefined4 *)0x0) {
    memw();
    *param_5 = *(undefined4 *)(param_1 + 0x14c);
  }
  memw();
  uVar4 = (uint)*(byte *)(param_1 + 0x150);
  memw();
  *(undefined1 *)(param_1 + 0x150) = 2;
  if (param_4 == 2) {
    memw();
    memw();
    *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  }
  else if (param_4 < 3) {
    if (param_4 != 0) {
      memw();
      memw();
      *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | param_3;
    }
  }
  else {
    if (param_4 != 3) {
      if (param_4 != 4) {
        memw();
        if (*DAT_40374edc != 0) {
          uVar4 = in_t0;
          FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375038,
                       PTR_s_xTaskGenericNotifyFromISR_4037502c,
                       PTR_s_xTickCount______TickType_t___0_4037501c);
        }
        goto LAB_4037e6ed;
      }
      if (uVar4 == 2) {
        uVar2 = 0;
        goto LAB_4037e840;
      }
    }
    memw();
    *(uint *)(param_1 + 0x14c) = param_3;
  }
LAB_4037e6ed:
  if (uVar4 == 1) {
    memw();
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_4037503c,
                   PTR_s_xTaskGenericNotifyFromISR_4037502c,
                   PTR_s________pxTCB_>xEventListItem_____40375024);
    }
    if (*(int *)(param_1 + 0x44) == DAT_40374eac) {
      memw();
      if ((*DAT_40374ed8 == 0) || (memw(), DAT_40374ed8[1] == 0)) goto LAB_4037e738;
LAB_4037e7d9:
      piVar5 = (int *)(uVar3 * 0x14 + DAT_40374f08);
      memw();
      iVar6 = piVar5[1];
      memw();
      *(int *)(param_1 + 0x1c) = iVar6;
      memw();
      uVar4 = *(uint *)(param_1 + 0x2c);
      memw();
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar6 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar6 + 8) + 4) = param_1 + 0x18;
      memw();
      *(int *)(iVar6 + 8) = param_1 + 0x18;
      memw();
      *(int **)(param_1 + 0x28) = piVar5;
      memw();
      memw();
      *piVar5 = *piVar5 + 1;
    }
    else {
      memw();
      if (DAT_40374ed8[*(int *)(param_1 + 0x44)] != 0) goto LAB_4037e7d9;
LAB_4037e738:
      memw();
      piVar5 = *(int **)(param_1 + 0x14);
      memw();
      memw();
      iVar6 = param_1 + 4;
      memw();
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(param_1 + 0xc);
      memw();
      memw();
      memw();
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined4 *)(param_1 + 8);
      memw();
      if (piVar5[1] == iVar6) {
        memw();
        memw();
        piVar5[1] = *(int *)(param_1 + 0xc);
      }
      memw();
      *(undefined4 *)(param_1 + 0x14) = 0;
      puVar1 = DAT_40374f18;
      memw();
      memw();
      *piVar5 = *piVar5 + -1;
      uVar4 = *(uint *)(param_1 + 0x2c);
      memw();
      if (*puVar1 < uVar4) {
        memw();
        *puVar1 = uVar4;
      }
      piVar5 = (int *)(uVar4 * 0x14 + DAT_40374efc);
      memw();
      iVar7 = piVar5[1];
      memw();
      *(int *)(param_1 + 8) = iVar7;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar7 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar7 + 8) + 4) = iVar6;
      memw();
      *(int *)(iVar7 + 8) = iVar6;
      memw();
      *(int **)(param_1 + 0x14) = piVar5;
      memw();
      memw();
      *piVar5 = *piVar5 + 1;
    }
    iVar6 = FUN_4037cce8(param_1,uVar4,0);
    if (iVar6 == 1) {
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 1;
      }
      memw();
      *(undefined4 *)(uVar3 * 4 + DAT_40374f78) = 1;
    }
  }
  uVar2 = 1;
LAB_4037e840:
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar2;
}


