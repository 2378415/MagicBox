// 4037d974  vTaskPrioritySet  FUN_4037d974  size=339
// strings: uxNewPriority < ( 25 )

void FUN_4037d974(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 in_PRID;
  
  if (0x18 < param_2) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,0x6e9,PTR_s_vTaskPrioritySet_40374ef8,
                 PTR_s_uxNewPriority_<_(_25_)_40374ef4);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  if (param_1 == 0) {
    param_1 = FUN_4037d934();
  }
  if (param_2 != *(uint *)(param_1 + 0x4c)) {
    if (*(uint *)(param_1 + 0x4c) < param_2) {
      memw();
      if (*DAT_40374d64 == param_1) {
        bVar1 = false;
      }
      else {
        memw();
        if (DAT_40374d64[1] == param_1) {
          bVar1 = false;
        }
        else {
          iVar3 = FUN_4037ca58(param_1,param_2,1);
          bVar1 = true;
          if (iVar3 != 1) {
            bVar1 = false;
          }
        }
      }
    }
    else {
      memw();
      if (DAT_40374d64[uVar4] == param_1) {
        bVar1 = true;
      }
      else {
        memw();
        if (DAT_40374d64[uVar4 == 0] == param_1) {
          FUN_4037bdd4();
          bVar1 = false;
        }
        else {
          bVar1 = false;
        }
      }
    }
    iVar3 = *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 0x4c) == iVar3) {
      *(uint *)(param_1 + 0x2c) = param_2;
    }
    *(uint *)(param_1 + 0x4c) = param_2;
    memw();
    if (-1 < *(int *)(param_1 + 0x18)) {
      memw();
      *(uint *)(param_1 + 0x18) = -(param_2 - 0x19);
    }
    memw();
    if (*(int *)(param_1 + 0x14) == iVar3 * 0x14 + DAT_40374e34) {
      iVar3 = param_1 + 4;
      FUN_4037c980(iVar3);
      uVar4 = *(uint *)(param_1 + 0x2c);
      memw();
      if (*DAT_40374e30 < uVar4) {
        memw();
        *DAT_40374e30 = uVar4;
      }
      iVar2 = DAT_40374e34;
      memw();
      iVar5 = *(int *)(uVar4 * 0x14 + DAT_40374e34 + 4);
      memw();
      *(int *)(param_1 + 8) = iVar5;
      memw();
      memw();
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 8);
      memw();
      memw();
      *(int *)(*(int *)(iVar5 + 8) + 4) = iVar3;
      memw();
      *(int *)(iVar5 + 8) = iVar3;
      piVar6 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar2);
      memw();
      *(int **)(param_1 + 0x14) = piVar6;
      memw();
      memw();
      *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar2) = *piVar6 + 1;
    }
    if (bVar1) {
      uVar4 = rsr(in_PRID);
      FUN_403787f4(uVar4 >> 0xd & 1);
    }
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}


