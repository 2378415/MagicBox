// 4037d564  vTaskPlaceOnEventList  FUN_4037d564  size=71
// strings: pxEventList

void FUN_4037d564(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ec0,
                 PTR_s_vTaskPlaceOnEventList_40374ebc,PTR_s_pxEventList_40374eb8);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar1 = rsr(in_PRID);
  memw();
  FUN_4037c924(param_1,*(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374d64) + 0x18);
  FUN_4037cdbc(param_2,1);
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}


