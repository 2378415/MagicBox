// strings: xPortGetCoreID() == 0 | ( ( ( ( pxDelayedTaskList )->uxNumberOfItems ==  | xTaskIncrementTick

/* WARNING: Control flow encountered bad instruction data */

void FUN_4037d5c8(void)

{
  int *piVar1;
  uint *puVar2;
  code *unaff_retaddr;
  uint uVar3;
  code *pcVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *in_t0;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  if ((uVar3 >> 0xd & 1) != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f68,PTR_s_xTaskIncrementTick_40374f64
                 ,PTR_s_xPortGetCoreID______0_40374f60);
  }
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  memw();
  if (*DAT_40374ed8 == 0) {
    memw();
    uVar3 = *DAT_40374edc + 1;
    memw();
    *DAT_40374edc = uVar3;
    puVar6 = DAT_40374ef0;
    if (uVar3 == 0) {
      memw();
      memw();
      piVar5 = DAT_40374eec;
      if (*(int *)*DAT_40374eec != 0) {
        piVar5 = in_t0;
        FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f70,
                     PTR_s_xTaskIncrementTick_40374f64,
                     PTR_s_________pxDelayedTaskList___>uxN_40374f6c);
      }
      piVar8 = DAT_40374f74;
      piVar1 = DAT_40374ee8;
      memw();
      iVar11 = *piVar5;
      memw();
      memw();
      *piVar5 = *DAT_40374ee8;
      memw();
      *piVar1 = iVar11;
      memw();
      memw();
      *piVar8 = *piVar8 + 1;
      puVar6 = DAT_40374ef0;
      memw();
      memw();
      if (*(int *)*piVar5 != 0) {
        (*unaff_retaddr)();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      memw();
      *DAT_40374ef0 = 0xffffffff;
    }
    iVar11 = DAT_40374f78;
    puVar2 = DAT_40374f18;
    piVar1 = DAT_40374eec;
    piVar5 = DAT_40374e18;
    memw();
    if (*puVar6 <= uVar3) {
      memw();
      memw();
      if (*(int *)*DAT_40374eec != 0) {
        pcVar4 = DAT_40374efc;
        do {
          memw();
          memw();
          iVar7 = *(int *)(*(int *)(*piVar1 + 0xc) + 0xc);
          memw();
          if (uVar3 < *(uint *)(iVar7 + 4)) {
            memw();
            *puVar6 = *(uint *)(iVar7 + 4);
            goto LAB_4037d854;
          }
          memw();
          piVar8 = *(int **)(iVar7 + 0x14);
          memw();
          memw();
          iVar13 = iVar7 + 4;
          memw();
          *(undefined4 *)(*(int *)(iVar7 + 8) + 8) = *(undefined4 *)(iVar7 + 0xc);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar7 + 0xc) + 4) = *(undefined4 *)(iVar7 + 8);
          memw();
          if (piVar8[1] == iVar13) {
            memw();
            memw();
            piVar8[1] = *(int *)(iVar7 + 0xc);
          }
          memw();
          *(undefined4 *)(iVar7 + 0x14) = 0;
          memw();
          memw();
          *piVar8 = *piVar8 + -1;
          memw();
          if (*(int *)(iVar7 + 0x28) != 0) {
            memw();
            piVar8 = *(int **)(iVar7 + 0x28);
            memw();
            memw();
            memw();
            *(undefined4 *)(*(int *)(iVar7 + 0x1c) + 8) = *(undefined4 *)(iVar7 + 0x20);
            memw();
            memw();
            memw();
            *(undefined4 *)(*(int *)(iVar7 + 0x20) + 4) = *(undefined4 *)(iVar7 + 0x1c);
            memw();
            if (piVar8[1] == iVar7 + 0x18) {
              memw();
              memw();
              piVar8[1] = *(int *)(iVar7 + 0x20);
            }
            memw();
            *(undefined4 *)(iVar7 + 0x28) = 0;
            memw();
            memw();
            *piVar8 = *piVar8 + -1;
          }
          uVar10 = *(uint *)(iVar7 + 0x2c);
          memw();
          if (*puVar2 < uVar10) {
            memw();
            *puVar2 = uVar10;
          }
          pcVar9 = pcVar4 + uVar10 * 0x14;
          memw();
          iVar12 = *(int *)(pcVar9 + 4);
          iVar14 = *(int *)(iVar7 + 0x44);
          memw();
          *(int *)(iVar7 + 8) = iVar12;
          memw();
          memw();
          *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar12 + 8);
          memw();
          memw();
          *(int *)(*(int *)(iVar12 + 8) + 4) = iVar13;
          memw();
          *(int *)(iVar12 + 8) = iVar13;
          memw();
          *(code **)(iVar7 + 0x14) = pcVar9;
          memw();
          memw();
          *(int *)pcVar9 = *(int *)pcVar9 + 1;
          if ((iVar14 == 0) || (iVar14 == DAT_40374eac || iVar14 == 0)) {
            memw();
            if ((uVar10 <= *(uint *)(*piVar5 + 0x2c)) &&
               ((iVar14 == DAT_40374eac && (memw(), *(uint *)(piVar5[1] + 0x2c) < uVar10)))) {
              memw();
              *(undefined4 *)(iVar11 + 4) = 1;
            }
          }
          else {
            pcVar4 = unaff_retaddr + iVar12;
            if (*(uint *)(*(int *)(unaff_retaddr + 4) + 0x2c) < uVar10) {
              memw();
              *(undefined4 *)(iVar11 + 4) = 1;
            }
          }
          memw();
          memw();
        } while (*(int *)*piVar1 != 0);
      }
      memw();
      *puVar6 = 0xffffffff;
    }
LAB_4037d854:
    memw();
    memw();
    memw();
  }
  else {
    memw();
    memw();
    *DAT_40374f7c = *DAT_40374f7c + 1;
  }
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}