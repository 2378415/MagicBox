// strings: pxEventList

void FUN_4037dce8(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fa4,
                 PTR_s_vTaskPlaceOnEventList_40374fa0,PTR_s_pxEventList_40374f9c);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  uVar1 = rsr(in_PRID);
  memw();
  FUN_4037cc28(param_1,*(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374e18) + 0x18);
  FUN_4037cdc0(param_2,1);
  FUN_4037c094(PTR_DAT_40374ef4);
  return;
}