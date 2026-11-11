// 4037d3f8  vTaskPrioritySet  FUN_4037d3f8  size=311
// strings: uxNewPriority < ( 25 ) | vTaskPrioritySet

void FUN_4037d3f8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 in_PRID;
  
  if (0x18 < param_2) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,0x6e9,PTR_s_vTaskPrioritySet_40374f50,
                 PTR_s_uxNewPriority_<_(_25_)_40374f4c);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  if (param_1 == 0) {
    uVar7 = rsil(3);
    uVar4 = rsr(in_PRID);
    memw();
    param_1 = DAT_40374e18[uVar4 >> 0xd & 1];
    (*DAT_40374db8)(uVar7);
  }
  uVar4 = *(uint *)(param_1 + 0x4c);
  if (param_2 != uVar4) {
    if (uVar4 < param_2) {
      memw();
      iVar3 = 0;
      if ((*DAT_40374e18 != param_1) && (memw(), DAT_40374e18[1] != param_1)) {
        iVar3 = FUN_4037cce8(param_1,param_2,1);
        uVar4 = *(uint *)(param_1 + 0x4c);
      }
    }
    else {
      memw();
      iVar3 = 1;
      if (DAT_40374e18[uVar1] != param_1) {
        memw();
        iVar3 = 0;
        if (DAT_40374e18[uVar1 == 0] == param_1) {
          FUN_4037c130();
          iVar3 = 0;
          uVar4 = *(uint *)(param_1 + 0x4c);
        }
      }
    }
    uVar1 = *(uint *)(param_1 + 0x2c);
    if (uVar1 == uVar4) {
      *(uint *)(param_1 + 0x2c) = param_2;
    }
    memw();
    *(uint *)(param_1 + 0x4c) = param_2;
    if (-1 < *(int *)(param_1 + 0x18)) {
      memw();
      *(uint *)(param_1 + 0x18) = -(param_2 - 0x19);
    }
    iVar6 = DAT_40374efc;
    memw();
    if (*(int *)(param_1 + 0x14) == uVar1 * 0x14 + DAT_40374efc) {
      iVar2 = param_1 + 4;
      FUN_4037cc94(iVar2);
      uVar1 = *(uint *)(param_1 + 0x2c);
      memw();
      if (*DAT_40374f18 < uVar1) {
        memw();
        *DAT_40374f18 = uVar1;
      }
      piVar5 = (int *)(uVar1 * 0x14 + iVar6);
      memw();
      iVar6 = piVar5[1];
      memw();
      *(int *)(param_1 + 8) = iVar6;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar6 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar6 + 8) + 4) = iVar2;
      memw();
      *(int *)(iVar6 + 8) = iVar2;
      memw();
      *(int **)(param_1 + 0x14) = piVar5;
      memw();
      memw();
      *piVar5 = *piVar5 + 1;
    }
    if (iVar3 != 0) {
      uVar1 = rsr(in_PRID);
      FUN_40378e40(uVar1 >> 0xd & 1);
    }
  }
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}


