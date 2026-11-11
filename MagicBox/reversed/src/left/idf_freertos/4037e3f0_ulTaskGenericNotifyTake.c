// strings: uxIndexToWait < 1 | ulTaskGenericNotifyTake

void FUN_4037e3f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined1 in_PRID;
  
  if (param_1 != 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375004,
                 PTR_s_ulTaskGenericNotifyTake_40375000,PTR_s_uxIndexToWait_<_1_40374ffc);
  }
  puVar2 = PTR_DAT_40374ef4;
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar1 = DAT_40374e18;
  uVar4 = rsr(in_PRID);
  piVar5 = (int *)((uVar4 >> 0xd & 1) * 4 + DAT_40374e18);
  memw();
  memw();
  if (*(int *)(*piVar5 + 0x14c) == 0) {
    memw();
    memw();
    *(undefined1 *)(*piVar5 + 0x150) = 1;
    if (param_3 != 0) {
      FUN_4037cdc0(param_3,1);
      uVar4 = rsr(in_PRID);
      FUN_40378e40(uVar4 >> 0xd & 1);
    }
  }
  FUN_4037c094(puVar2);
  FUN_4037bf44(puVar2,0xffffffff);
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  piVar5 = (int *)(uVar4 * 4 + iVar1);
  memw();
  memw();
  iVar3 = *(int *)(*piVar5 + 0x14c);
  if (iVar3 != 0) {
    memw();
    iVar6 = *piVar5;
    if (param_2 == 0) {
      memw();
      *(int *)(iVar6 + 0x14c) = iVar3 + -1;
    }
    else {
      memw();
      *(undefined4 *)(iVar6 + 0x14c) = 0;
    }
  }
  memw();
  memw();
  *(undefined1 *)(*(int *)(iVar1 + uVar4 * 4) + 0x150) = 0;
  FUN_4037c094(puVar2);
  return;
}