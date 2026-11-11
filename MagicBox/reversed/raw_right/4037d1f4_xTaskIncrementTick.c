// 4037d1f4  xTaskIncrementTick  FUN_4037d1f4  size=704
// strings: xPortGetCoreID() == 0 | ( ( ( ( pxDelayedTaskList )->uxNumberOfItems ==  | xTaskIncrementTick

void FUN_4037d1f4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  if ((uVar3 >> 0xd & 1) != 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374e9c,PTR_s_xTaskIncrementTick_40374e98
                 ,PTR_s_xPortGetCoreID______0_40374e94);
  }
  iVar2 = FUN_4037bbc4();
  if (iVar2 == 0) {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  memw();
  if (*DAT_40374e18 == 0) {
    memw();
    uVar3 = *DAT_40374e68 + 1;
    memw();
    *DAT_40374e68 = uVar3;
    if (uVar3 == 0) {
      memw();
      memw();
      if (*(int *)*DAT_40374e1c != 0) {
        FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ea4,
                     PTR_s_xTaskIncrementTick_40374e98,
                     PTR_s_________pxDelayedTaskList___>uxN_40374ea0);
      }
      piVar4 = DAT_40374e70;
      memw();
      iVar2 = *DAT_40374e1c;
      memw();
      memw();
      *DAT_40374e1c = *DAT_40374e70;
      memw();
      *piVar4 = iVar2;
      memw();
      memw();
      *DAT_40374ea8 = *DAT_40374ea8 + 1;
      FUN_4037ca1c();
    }
    memw();
    if (*DAT_40374e20 <= uVar3) {
      while( true ) {
        memw();
        memw();
        if (*(int *)*DAT_40374e1c == 0) break;
        memw();
        memw();
        iVar2 = *(int *)(*(int *)(*DAT_40374e1c + 0xc) + 0xc);
        memw();
        if (uVar3 < *(uint *)(iVar2 + 4)) {
          memw();
          *DAT_40374e20 = *(uint *)(iVar2 + 4);
          goto LAB_4037d460;
        }
        memw();
        piVar4 = *(int **)(iVar2 + 0x14);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 8) + 8) = *(undefined4 *)(iVar2 + 0xc);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4) = *(undefined4 *)(iVar2 + 8);
        memw();
        iVar7 = iVar2 + 4;
        if (piVar4[1] == iVar7) {
          memw();
          memw();
          piVar4[1] = *(int *)(iVar2 + 0xc);
        }
        memw();
        *(undefined4 *)(iVar2 + 0x14) = 0;
        memw();
        memw();
        *piVar4 = *piVar4 + -1;
        memw();
        if (*(int *)(iVar2 + 0x28) != 0) {
          memw();
          piVar4 = *(int **)(iVar2 + 0x28);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 8) = *(undefined4 *)(iVar2 + 0x20);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar2 + 0x20) + 4) = *(undefined4 *)(iVar2 + 0x1c);
          memw();
          if (piVar4[1] == iVar2 + 0x18) {
            memw();
            memw();
            piVar4[1] = *(int *)(iVar2 + 0x20);
          }
          memw();
          *(undefined4 *)(iVar2 + 0x28) = 0;
          memw();
          memw();
          *piVar4 = *piVar4 + -1;
        }
        uVar5 = *(uint *)(iVar2 + 0x2c);
        memw();
        if (*DAT_40374e30 < uVar5) {
          memw();
          *DAT_40374e30 = uVar5;
        }
        iVar1 = DAT_40374e34;
        memw();
        iVar6 = *(int *)(uVar5 * 0x14 + DAT_40374e34 + 4);
        memw();
        *(int *)(iVar2 + 8) = iVar6;
        memw();
        memw();
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar6 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar6 + 8) + 4) = iVar7;
        memw();
        *(int *)(iVar6 + 8) = iVar7;
        piVar4 = (int *)(*(int *)(iVar2 + 0x2c) * 0x14 + iVar1);
        memw();
        *(int **)(iVar2 + 0x14) = piVar4;
        memw();
        memw();
        *(int *)(*(int *)(iVar2 + 0x2c) * 0x14 + iVar1) = *piVar4 + 1;
        iVar7 = *(int *)(iVar2 + 0x44);
        if (iVar7 == 0 || iVar7 == DAT_403747f4) {
          memw();
          if (((*(uint *)(iVar2 + 0x2c) <= *(uint *)(*DAT_40374d64 + 0x2c)) &&
              (iVar7 == DAT_403747f4)) &&
             (memw(), *(uint *)(DAT_40374d64[1] + 0x2c) < *(uint *)(iVar2 + 0x2c))) {
            memw();
            *(undefined4 *)(DAT_40374eac + 4) = 1;
          }
        }
        else {
          memw();
          if (*(uint *)(DAT_40374d64[1] + 0x2c) < *(uint *)(iVar2 + 0x2c)) {
            memw();
            *(undefined4 *)(DAT_40374eac + 4) = 1;
          }
        }
      }
      memw();
      *DAT_40374e20 = 0xffffffff;
    }
LAB_4037d460:
    memw();
    memw();
    memw();
  }
  else {
    memw();
    memw();
    *DAT_40374eb0 = *DAT_40374eb0 + 1;
  }
  iVar2 = FUN_4037bbc4();
  if (iVar2 == 0) {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  else {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  return;
}


