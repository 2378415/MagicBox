// 4037dab8  prvSelectHighestPriorityTaskSMP  FUN_4037dab8  size=554
// strings: xTaskScheduled == ( ( BaseType_t ) 1 ) | tasks.c | prvSelectHighestPriorityTaskSMP

void FUN_4037dab8(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  int iVar14;
  undefined1 in_PRID;
  
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  piVar10 = DAT_40374e18;
  uVar5 = rsr(in_PRID);
  uVar5 = uVar5 >> 0xd & 1;
  memw();
  if (*(int *)(uVar5 * 4 + DAT_40374ed8) != 0) {
    memw();
    *(undefined4 *)(DAT_40374f78 + uVar5 * 4) = 1;
LAB_4037dcda:
    FUN_4037bf20();
    FUN_4037c094(PTR_DAT_40374ef4);
    return;
  }
  memw();
  *(undefined4 *)(DAT_40374f78 + uVar5 * 4) = 0;
  memw();
  piVar6 = *(int **)(piVar10[uVar5] + 0x30);
  if ((((*piVar6 != DAT_40374f8c) || (piVar6[1] != *piVar6)) || (piVar6[2] != piVar6[1])) ||
     (piVar6[3] != piVar6[2])) {
    memw();
    memw();
    FUN_4037c13c(piVar10[uVar5],piVar10[uVar5] + 0x34);
  }
  puVar3 = DAT_40374f18;
  uVar5 = rsr(in_PRID);
  puVar12 = (undefined *)(uVar5 >> 0xd & 1);
  memw();
  puVar13 = (undefined *)*DAT_40374f18;
  if (-1 < (int)puVar13) goto LAB_4037db4c;
  do {
    puVar12 = PTR_s_prvSelectHighestPriorityTaskSMP_40374f94;
    puVar13 = PTR_s_xTaskScheduled________BaseType_t_40374f90;
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f98);
LAB_4037db4c:
    iVar8 = DAT_40374efc;
    puVar2 = DAT_40374eac;
    iVar14 = DAT_40374efc + (int)puVar13 * 0x14 + 8;
    bVar1 = false;
    do {
      memw();
      if (*(int *)((int)puVar13 * 0x14 + iVar8) != 0) {
        if (!bVar1) {
          memw();
          *puVar3 = puVar13;
        }
        iVar7 = (int)puVar13 * 0x14 + iVar8;
        memw();
        *(int *)(iVar7 + 4) = iVar14;
        memw();
        memw();
        memw();
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(*(int *)(iVar7 + 4) + 4);
        memw();
        if (iVar14 == *(int *)(iVar7 + 4)) {
          memw();
          memw();
          memw();
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(*(int *)(iVar7 + 4) + 4);
        }
        iVar9 = (int)puVar13 * 0x14 + iVar8;
        memw();
        iVar4 = *(int *)(*(int *)(iVar9 + 4) + 0xc);
        iVar7 = iVar4;
        do {
          if (puVar12 == (undefined *)0x0) {
LAB_4037dbcd:
            memw();
            if (iVar7 != piVar10[1]) {
LAB_4037dbd9:
              puVar11 = *(undefined **)(iVar7 + 0x44);
              if ((puVar12 == puVar11) || (puVar11 == puVar2 || puVar12 == puVar11)) {
                memw();
                piVar10[(int)puVar12] = iVar7;
                memw();
                *(int *)((int)puVar13 * 0x14 + iVar8 + 4) = iVar14;
                memw();
                piVar10 = *(int **)(iVar7 + 0x14);
                memw();
                memw();
                iVar4 = iVar7 + 4;
                memw();
                *(undefined4 *)(*(int *)(iVar7 + 8) + 8) = *(undefined4 *)(iVar7 + 0xc);
                memw();
                memw();
                memw();
                *(undefined4 *)(*(int *)(iVar7 + 0xc) + 4) = *(undefined4 *)(iVar7 + 8);
                memw();
                if (piVar10[1] == iVar4) {
                  memw();
                  memw();
                  piVar10[1] = *(int *)(iVar7 + 0xc);
                }
                memw();
                *(undefined4 *)(iVar7 + 0x14) = 0;
                memw();
                memw();
                *piVar10 = *piVar10 + -1;
                piVar10 = (int *)((int)puVar13 * 0x14 + iVar8);
                memw();
                iVar8 = piVar10[1];
                memw();
                *(int *)(iVar7 + 8) = iVar8;
                memw();
                memw();
                *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar8 + 8);
                memw();
                memw();
                *(int *)(*(int *)(iVar8 + 8) + 4) = iVar4;
                memw();
                *(int *)(iVar8 + 8) = iVar4;
                memw();
                *(int *)(iVar7 + 0x14) = iVar14 + -8;
                memw();
                memw();
                *piVar10 = *piVar10 + 1;
                goto LAB_4037dcda;
              }
            }
          }
          else {
            memw();
            if (iVar7 != *piVar10) {
              if (puVar12 != (undefined *)0x1) goto LAB_4037dbcd;
              goto LAB_4037dbd9;
            }
          }
          memw();
          memw();
          memw();
          *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(*(int *)(iVar9 + 4) + 4);
          memw();
          if (*(int *)(iVar9 + 4) == iVar14) {
            memw();
            memw();
            memw();
            *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(*(int *)(iVar9 + 4) + 4);
          }
          memw();
          iVar7 = *(int *)(*(int *)(iVar9 + 4) + 0xc);
        } while (iVar4 != iVar7);
        bVar1 = true;
      }
      puVar13 = puVar13 + -1;
      iVar14 = iVar14 + -0x14;
    } while (puVar13 != (undefined *)0xffffffff);
  } while( true );
}


