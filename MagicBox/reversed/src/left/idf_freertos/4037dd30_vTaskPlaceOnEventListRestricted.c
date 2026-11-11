// strings: pxEventList | vTaskPlaceOnEventListRestricted

void FUN_4037dd30(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fac,
                 PTR_s_vTaskPlaceOnEventListRestricted_40374fa8,PTR_s_pxEventList_40374f9c);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar1 = DAT_40374e18;
  memw();
  iVar2 = param_1[1];
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  *(int *)(*(int *)((uVar3 >> 0xd & 1) * 4 + DAT_40374e18) + 0x1c) = iVar2;
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  memw();
  *(undefined4 *)(*(int *)((uVar3 >> 0xd & 1) * 4 + iVar1) + 0x20) = *(undefined4 *)(iVar2 + 8);
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  memw();
  *(int *)(*(int *)(iVar2 + 8) + 4) = *(int *)((uVar3 >> 0xd & 1) * 4 + iVar1) + 0x18;
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  *(int *)(iVar2 + 8) = *(int *)((uVar3 >> 0xd & 1) * 4 + iVar1) + 0x18;
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  *(int **)(*(int *)((uVar3 >> 0xd & 1) * 4 + iVar1) + 0x28) = param_1;
  memw();
  uVar4 = 0xffffffff;
  if (param_3 == 0) {
    uVar4 = param_2;
  }
  memw();
  *param_1 = *param_1 + 1;
  FUN_4037cdc0(uVar4,param_3);
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}