// 4037caf4  prvSelectHighestPriorityTaskSMP  FUN_4037caf4  size=483
// strings: xTaskScheduled == ( ( BaseType_t ) 1 ) | tasks.c | prvSelectHighestPriorityTaskSMP

void FUN_4037caf4(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined1 in_PRID;
  
  uVar7 = rsr(in_PRID);
  uVar7 = uVar7 >> 0xd & 1;
  memw();
  iVar6 = *DAT_40374e30;
  bVar1 = false;
  bVar2 = false;
  do {
    if ((iVar6 < 0) || (!(bool)(bVar2 ^ 1))) {
      if (!bVar2) {
        FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374e40,
                     PTR_s_prvSelectHighestPriorityTaskSMP_40374e3c,
                     PTR_s_xTaskScheduled________BaseType_t_40374e38);
      }
      return;
    }
    memw();
    if (*(int *)(DAT_40374e34 + iVar6 * 0x14) != 0) {
      if (!bVar1) {
        memw();
        *DAT_40374e30 = iVar6;
        bVar1 = true;
      }
      iVar3 = iVar6 * 0x14 + DAT_40374e34;
      iVar8 = iVar3 + 8;
      memw();
      *(int *)(iVar3 + 4) = iVar8;
      memw();
      memw();
      memw();
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(*(int *)(iVar3 + 4) + 4);
      memw();
      if (iVar8 == *(int *)(iVar3 + 4)) {
        iVar3 = DAT_40374e34 + iVar6 * 0x14;
        memw();
        memw();
        memw();
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(*(int *)(iVar3 + 4) + 4);
      }
      memw();
      iVar9 = *(int *)(*(int *)(DAT_40374e34 + iVar6 * 0x14 + 4) + 0xc);
      iVar3 = iVar9;
      do {
        for (uVar4 = 0; uVar4 < 2; uVar4 = uVar4 + 1) {
          if ((uVar4 != uVar7) && (memw(), *(int *)(uVar4 * 4 + DAT_40374d64) == iVar3))
          goto LAB_4037cc60;
        }
        if ((*(uint *)(iVar3 + 0x44) == uVar7) || (*(uint *)(iVar3 + 0x44) == DAT_403747f4)) {
          memw();
          *(int *)(uVar7 * 4 + DAT_40374d64) = iVar3;
          memw();
          *(int *)(DAT_40374e34 + iVar6 * 0x14 + 4) = iVar8;
          memw();
          piVar5 = *(int **)(iVar3 + 0x14);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 8) + 8) = *(undefined4 *)(iVar3 + 0xc);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 0xc) + 4) = *(undefined4 *)(iVar3 + 8);
          memw();
          iVar8 = iVar3 + 4;
          if (piVar5[1] == iVar8) {
            memw();
            memw();
            piVar5[1] = *(int *)(iVar3 + 0xc);
          }
          memw();
          *(undefined4 *)(iVar3 + 0x14) = 0;
          memw();
          memw();
          *piVar5 = *piVar5 + -1;
          piVar5 = (int *)(DAT_40374e34 + iVar6 * 0x14);
          memw();
          iVar9 = piVar5[1];
          memw();
          *(int *)(iVar3 + 8) = iVar9;
          memw();
          memw();
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar9 + 8);
          memw();
          memw();
          *(int *)(*(int *)(iVar9 + 8) + 4) = iVar8;
          memw();
          *(int *)(iVar9 + 8) = iVar8;
          memw();
          *(int **)(iVar3 + 0x14) = piVar5;
          memw();
          memw();
          *piVar5 = *piVar5 + 1;
          bVar2 = true;
          break;
        }
LAB_4037cc60:
        iVar3 = DAT_40374e34 + iVar6 * 0x14;
        memw();
        memw();
        memw();
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(*(int *)(iVar3 + 4) + 4);
        memw();
        if (iVar8 == *(int *)(iVar3 + 4)) {
          iVar3 = DAT_40374e34 + iVar6 * 0x14;
          memw();
          memw();
          memw();
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(*(int *)(iVar3 + 4) + 4);
        }
        memw();
        iVar3 = *(int *)(*(int *)(DAT_40374e34 + iVar6 * 0x14 + 4) + 0xc);
      } while (iVar9 != iVar3);
    }
    iVar6 = iVar6 + -1;
  } while( true );
}


