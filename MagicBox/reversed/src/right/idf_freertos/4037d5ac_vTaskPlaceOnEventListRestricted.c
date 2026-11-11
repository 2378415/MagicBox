// strings: pxEventList | vTaskPlaceOnEventListRestricted

void FUN_4037d5ac(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ec8,
                 PTR_s_vTaskPlaceOnEventListRestricted_40374ec4,PTR_s_pxEventList_40374eb8);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  iVar1 = DAT_40374d64;
  memw();
  iVar2 = param_1[1];
  uVar3 = rsr(in_PRID);
  memw();
  memw();
  *(int *)(*(int *)((uVar3 >> 0xd & 1) * 4 + DAT_40374d64) + 0x1c) = iVar2;
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
  memw();
  *param_1 = *param_1 + 1;
  if (param_3 != 0) {
    param_2 = 0xffffffff;
  }
  FUN_4037cdbc(param_2,param_3);
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}