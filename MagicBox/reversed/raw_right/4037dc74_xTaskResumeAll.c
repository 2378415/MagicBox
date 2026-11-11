// 4037dc74  xTaskResumeAll  FUN_4037dc74  size=488
// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) | xTaskResumeAll

undefined4 FUN_4037dc74(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined1 in_PRID;
  
  iVar2 = FUN_4037db0c();
  if (iVar2 != 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f1c,PTR_s_xTaskResumeAll_40374f18,
                 PTR_s_____xTaskGetSchedulerState________40374f14);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar5 = rsr(in_PRID);
  uVar5 = uVar5 >> 0xd & 1;
  piVar6 = (int *)(uVar5 * 4 + DAT_40374e18);
  memw();
  memw();
  *piVar6 = *piVar6 + -1;
  memw();
  if (*piVar6 == 0) {
    memw();
    if (*DAT_40374e5c == 0) {
      uVar3 = 0;
    }
    else {
      iVar2 = 0;
      while (memw(), *(int *)(uVar5 * 0x14 + DAT_40374e88) != 0) {
        memw();
        iVar2 = *(int *)(*(int *)(uVar5 * 0x14 + DAT_40374e88 + 0xc) + 0xc);
        memw();
        piVar6 = *(int **)(iVar2 + 0x28);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 8) = *(undefined4 *)(iVar2 + 0x20);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 0x20) + 4) = *(undefined4 *)(iVar2 + 0x1c);
        memw();
        if (piVar6[1] == iVar2 + 0x18) {
          memw();
          memw();
          piVar6[1] = *(int *)(iVar2 + 0x20);
        }
        memw();
        *(undefined4 *)(iVar2 + 0x28) = 0;
        memw();
        memw();
        *piVar6 = *piVar6 + -1;
        memw();
        piVar6 = *(int **)(iVar2 + 0x14);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 8) + 8) = *(undefined4 *)(iVar2 + 0xc);
        memw();
        memw();
        memw();
        *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4) = *(undefined4 *)(iVar2 + 8);
        memw();
        iVar4 = iVar2 + 4;
        if (piVar6[1] == iVar4) {
          memw();
          memw();
          piVar6[1] = *(int *)(iVar2 + 0xc);
        }
        memw();
        *(undefined4 *)(iVar2 + 0x14) = 0;
        memw();
        memw();
        *piVar6 = *piVar6 + -1;
        uVar7 = *(uint *)(iVar2 + 0x2c);
        memw();
        if (*DAT_40374e30 < uVar7) {
          memw();
          *DAT_40374e30 = uVar7;
        }
        iVar1 = DAT_40374e34;
        memw();
        iVar8 = *(int *)(uVar7 * 0x14 + DAT_40374e34 + 4);
        memw();
        *(int *)(iVar2 + 8) = iVar8;
        memw();
        memw();
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar8 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar8 + 8) + 4) = iVar4;
        memw();
        *(int *)(iVar8 + 8) = iVar4;
        piVar6 = (int *)(*(int *)(iVar2 + 0x2c) * 0x14 + iVar1);
        memw();
        *(int **)(iVar2 + 0x14) = piVar6;
        memw();
        memw();
        *(int *)(*(int *)(iVar2 + 0x2c) * 0x14 + iVar1) = *piVar6 + 1;
        iVar4 = FUN_4037ca58(iVar2,*(undefined4 *)(iVar2 + 0x2c),1);
        if (iVar4 == 1) {
          memw();
          DAT_40374eac[uVar5] = 1;
        }
      }
      if (iVar2 != 0) {
        FUN_4037ca1c();
      }
      if (uVar5 == 0) {
        memw();
        iVar2 = *DAT_40374eb0;
        if (iVar2 != 0) {
          do {
            iVar4 = FUN_4037d1f4();
            if (iVar4 != 0) {
              memw();
              *DAT_40374eac = 1;
            }
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          memw();
          *DAT_40374eb0 = 0;
        }
      }
      memw();
      uVar3 = 0;
      if (DAT_40374eac[uVar5] != 0) {
        uVar5 = rsr(in_PRID);
        FUN_403787f4(uVar5 >> 0xd & 1);
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = 0;
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar3;
}


