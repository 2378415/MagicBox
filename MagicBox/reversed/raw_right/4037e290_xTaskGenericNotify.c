// 4037e290  xTaskGenericNotify  FUN_4037e290  size=462
// strings: uxIndexToNotify < 1 | xTaskToNotify | tasks.c | xTaskGenericNotify | &51&E= | xTickCount == ( TickType_t ) 0 | ( ( &( pxTCB->xEventListItem ) )->pxContainer ) 

undefined4 FUN_4037e290(int param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint in_t0;
  undefined1 in_PRID;
  
  if (param_2 != 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f58,PTR_s_xTaskGenericNotify_40374f54
                 ,PTR_s_uxIndexToNotify_<_1_40374f50);
  }
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f60,PTR_s_xTaskGenericNotify_40374f54
                 ,PTR_s_xTaskToNotify_40374f5c);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  if (param_5 != (undefined4 *)0x0) {
    memw();
    *param_5 = *(undefined4 *)((param_2 + 0x50) * 4 + param_1 + 0xc);
  }
  pbVar3 = (byte *)(param_1 + param_2 + 0x150);
  memw();
  uVar6 = (uint)*pbVar3;
  memw();
  *pbVar3 = 2;
  if (param_4 == 2) {
    iVar7 = (param_2 + 0x50) * 4 + param_1;
    memw();
    memw();
    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
  }
  else if (param_4 < 3) {
    if (param_4 != 0) {
      if (param_4 == 1) {
        iVar7 = (param_2 + 0x50) * 4 + param_1;
        memw();
        memw();
        *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | param_3;
      }
      else {
LAB_4037e350:
        memw();
        if (*DAT_40374e68 != 0) {
          uVar6 = in_t0;
          FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f68,
                       PTR_s_xTaskGenericNotify_40374f54,
                       PTR_s_xTickCount______TickType_t___0_40374f64);
        }
      }
    }
  }
  else if (param_4 == 3) {
    memw();
    *(uint *)((param_2 + 0x50) * 4 + param_1 + 0xc) = param_3;
  }
  else {
    if (param_4 != 4) goto LAB_4037e350;
    if (uVar6 == 2) {
      uVar2 = 0;
      goto LAB_4037e45b;
    }
    memw();
    *(uint *)((param_2 + 0x50) * 4 + param_1 + 0xc) = param_3;
  }
  if (uVar6 == 1) {
    memw();
    piVar4 = *(int **)(param_1 + 0x14);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(param_1 + 0xc);
    memw();
    memw();
    memw();
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined4 *)(param_1 + 8);
    memw();
    iVar7 = param_1 + 4;
    if (piVar4[1] == iVar7) {
      memw();
      memw();
      piVar4[1] = *(int *)(param_1 + 0xc);
    }
    memw();
    *(undefined4 *)(param_1 + 0x14) = 0;
    memw();
    memw();
    *piVar4 = *piVar4 + -1;
    uVar6 = *(uint *)(param_1 + 0x2c);
    memw();
    if (*DAT_40374e30 < uVar6) {
      memw();
      *DAT_40374e30 = uVar6;
    }
    iVar1 = DAT_40374e34;
    memw();
    iVar5 = *(int *)(uVar6 * 0x14 + DAT_40374e34 + 4);
    memw();
    *(int *)(param_1 + 8) = iVar5;
    memw();
    memw();
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 8);
    memw();
    memw();
    *(int *)(*(int *)(iVar5 + 8) + 4) = iVar7;
    memw();
    *(int *)(iVar5 + 8) = iVar7;
    piVar4 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1);
    memw();
    *(int **)(param_1 + 0x14) = piVar4;
    memw();
    memw();
    *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1) = *piVar4 + 1;
    memw();
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f70,
                   PTR_s_xTaskGenericNotify_40374f54,PTR_s________pxTCB_>xEventListItem_____40374f6c
                  );
    }
    iVar7 = FUN_4037ca58(param_1,*(undefined4 *)(param_1 + 0x2c),0);
    if (iVar7 == 1) {
      uVar6 = rsr(in_PRID);
      FUN_403787f4(uVar6 >> 0xd & 1);
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
LAB_4037e45b:
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar2;
}


