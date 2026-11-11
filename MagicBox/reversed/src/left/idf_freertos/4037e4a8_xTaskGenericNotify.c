// strings: uxIndexToNotify < 1 | xTaskToNotify | tasks.c | xTaskGenericNotify | &5/&E& | xTickCount == ( TickType_t ) 0 | ( ( &( pxTCB->xEventListItem ) )->pxContainer ) 

undefined4 FUN_4037e4a8(int param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint in_t0;
  undefined1 in_PRID;
  
  if (param_2 != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375010,PTR_s_xTaskGenericNotify_4037500c
                 ,PTR_s_uxIndexToNotify_<_1_40375008);
  }
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375018,PTR_s_xTaskGenericNotify_4037500c
                 ,PTR_s_xTaskToNotify_40375014);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  if (param_5 != (undefined4 *)0x0) {
    memw();
    *param_5 = *(undefined4 *)(param_1 + 0x14c);
  }
  memw();
  uVar3 = (uint)*(byte *)(param_1 + 0x150);
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
          uVar3 = in_t0;
          FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375020,
                       PTR_s_xTaskGenericNotify_4037500c,
                       PTR_s_xTickCount______TickType_t___0_4037501c);
        }
        goto LAB_4037e559;
      }
      if (uVar3 == 2) {
        uVar2 = 0;
        goto LAB_4037e62c;
      }
    }
    memw();
    *(uint *)(param_1 + 0x14c) = param_3;
  }
LAB_4037e559:
  if (uVar3 == 1) {
    memw();
    piVar4 = *(int **)(param_1 + 0x14);
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
    if (piVar4[1] == iVar6) {
      memw();
      memw();
      piVar4[1] = *(int *)(param_1 + 0xc);
    }
    memw();
    *(undefined4 *)(param_1 + 0x14) = 0;
    puVar1 = DAT_40374f18;
    memw();
    memw();
    *piVar4 = *piVar4 + -1;
    uVar3 = *(uint *)(param_1 + 0x2c);
    memw();
    if (*puVar1 < uVar3) {
      memw();
      *puVar1 = uVar3;
    }
    piVar4 = (int *)(uVar3 * 0x14 + DAT_40374efc);
    memw();
    iVar5 = piVar4[1];
    memw();
    *(int *)(param_1 + 8) = iVar5;
    memw();
    memw();
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 8);
    memw();
    memw();
    *(int *)(*(int *)(iVar5 + 8) + 4) = iVar6;
    memw();
    *(int *)(iVar5 + 8) = iVar6;
    memw();
    *(int **)(param_1 + 0x14) = piVar4;
    memw();
    memw();
    *piVar4 = *piVar4 + 1;
    memw();
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375028,
                   PTR_s_xTaskGenericNotify_4037500c,PTR_s________pxTCB_>xEventListItem_____40375024
                  );
    }
    iVar6 = FUN_4037cce8(param_1);
    if (iVar6 == 1) {
      uVar3 = rsr(in_PRID);
      FUN_40378e40(uVar3 >> 0xd & 1);
    }
  }
  uVar2 = 1;
LAB_4037e62c:
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar2;
}