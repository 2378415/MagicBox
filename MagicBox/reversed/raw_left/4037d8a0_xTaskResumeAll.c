// 4037d8a0  xTaskResumeAll  FUN_4037d8a0  size=534
// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) | xTaskResumeAll

undefined4 FUN_4037d8a0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  undefined1 in_PRID;
  
  iVar5 = DAT_40374ed8;
  uVar9 = rsil(3);
  memw();
  if (*DAT_40374f10 == 0) {
LAB_4037d8f9:
    (*DAT_40374db8)();
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f88,PTR_s_xTaskResumeAll_40374f84,
                 PTR_s_____xTaskGetSchedulerState________40374f80);
LAB_4037d90e:
    puVar2 = DAT_40374f78;
    puVar1 = DAT_40374f18;
    iVar5 = DAT_40374efc;
    memw();
    if (*DAT_40374ef8 != 0) {
      piVar4 = (int *)((param_1 + param_2) * 4 + DAT_40374f08);
      memw();
      if (*piVar4 != 0) {
        puVar6 = (undefined4 *)((int)DAT_40374f78 + param_1);
        do {
          memw();
          iVar3 = *(int *)(piVar4[3] + 0xc);
          memw();
          piVar7 = *(int **)(iVar3 + 0x28);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 0x1c) + 8) = *(undefined4 *)(iVar3 + 0x20);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 0x20) + 4) = *(undefined4 *)(iVar3 + 0x1c);
          memw();
          if (piVar7[1] == iVar3 + 0x18) {
            memw();
            memw();
            piVar7[1] = *(int *)(iVar3 + 0x20);
          }
          memw();
          *(undefined4 *)(iVar3 + 0x28) = param_4;
          memw();
          iVar11 = iVar3 + 4;
          memw();
          *piVar7 = *piVar7 + -1;
          memw();
          piVar7 = *(int **)(iVar3 + 0x14);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 8) + 8) = *(undefined4 *)(iVar3 + 0xc);
          memw();
          memw();
          memw();
          *(undefined4 *)(*(int *)(iVar3 + 0xc) + 4) = *(undefined4 *)(iVar3 + 8);
          memw();
          if (piVar7[1] == iVar11) {
            memw();
            memw();
            piVar7[1] = *(int *)(iVar3 + 0xc);
          }
          memw();
          *(undefined4 *)(iVar3 + 0x14) = param_4;
          memw();
          uVar10 = *(uint *)(iVar3 + 0x2c);
          memw();
          *piVar7 = *piVar7 + -1;
          memw();
          if (*puVar1 < uVar10) {
            memw();
            *puVar1 = uVar10;
          }
          piVar7 = (int *)(uVar10 * 0x14 + iVar5);
          memw();
          iVar8 = piVar7[1];
          memw();
          *(int *)(iVar3 + 8) = iVar8;
          memw();
          memw();
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar8 + 8);
          memw();
          memw();
          *(int *)(*(int *)(iVar8 + 8) + 4) = iVar11;
          memw();
          *(int *)(iVar8 + 8) = iVar11;
          memw();
          *(int **)(iVar3 + 0x14) = piVar7;
          memw();
          memw();
          *piVar7 = *piVar7 + 1;
          iVar3 = FUN_4037cce8();
          if (iVar3 == 1) {
            memw();
            *puVar6 = 1;
          }
          memw();
        } while (*piVar4 != 0);
        memw();
        memw();
        if (*(int *)*DAT_40374eec == 0) {
          memw();
          *DAT_40374ef0 = 0xffffffff;
        }
        else {
          memw();
          memw();
          memw();
          memw();
          *DAT_40374ef0 = **(undefined4 **)(*DAT_40374eec + 0xc);
        }
      }
      piVar4 = DAT_40374f7c;
      if (param_2 == 0) {
        memw();
        iVar5 = *DAT_40374f7c;
        if (iVar5 != 0) {
          do {
            iVar3 = FUN_4037d5c8();
            if (iVar3 != 0) {
              memw();
              *puVar2 = 1;
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          memw();
          *piVar4 = 0;
        }
      }
      memw();
      if (*(int *)((int)puVar2 + param_1) != 0) {
        uVar10 = rsr(in_PRID);
        FUN_40378e40(uVar10 >> 0xd & 1);
        uVar9 = 1;
        goto LAB_4037dab0;
      }
    }
  }
  else {
    uVar10 = rsr(in_PRID);
    memw();
    if (*(int *)((uVar10 >> 0xd & 1) * 4 + DAT_40374ed8) == 0) goto LAB_4037d8f9;
    (*DAT_40374db8)(uVar9);
    FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
    uVar10 = rsr(in_PRID);
    param_2 = uVar10 >> 0xd & 1;
    piVar4 = (int *)(param_2 * 4 + iVar5);
    memw();
    param_1 = param_2 << 2;
    memw();
    *piVar4 = *piVar4 + -1;
    memw();
    param_4 = 0;
    if (*piVar4 == 0) goto LAB_4037d90e;
  }
  uVar9 = 0;
LAB_4037dab0:
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar9;
}


