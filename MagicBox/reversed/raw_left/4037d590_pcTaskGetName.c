// 4037d590  pcTaskGetName  FUN_4037d590  size=53
// strings: pxTCB

int FUN_4037d590(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    uVar2 = rsil(3);
    uVar1 = rsr(in_PRID);
    memw();
    param_1 = *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374e18);
    (*DAT_40374db8)(uVar2);
    if (param_1 == 0) {
      FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f5c,PTR_s_pcTaskGetName_40374f58,
                   PTR_s_pxTCB_40374f54);
    }
  }
  return param_1 + 0x34;
}


