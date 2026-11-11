void FUN_4037f890(int param_1,uint param_2)

{
  uint local_30;
  
  memw();
  memw();
  memw();
  local_30 = *(uint *)(param_1 + 8) & DAT_403750e4;
  memw();
  memw();
  memw();
  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffe;
  memw();
  local_30 = local_30 | DAT_403748a8;
  memw();
  if (param_2 == 4) {
    memw();
    local_30 = local_30 | DAT_403750d0;
    memw();
  }
  else if (param_2 < 5) {
    if (param_2 == 2) {
      memw();
      local_30 = local_30 | DAT_40374450;
      memw();
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        memw();
        local_30 = local_30 & DAT_40374a74;
        memw();
      }
      else if (param_2 != 1) goto LAB_4037f9f5;
    }
    else {
      if (param_2 != 3) {
LAB_4037f9f5:
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      memw();
      local_30 = local_30 | DAT_403749a0;
      memw();
    }
  }
  else if (param_2 == 0x10) {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    local_30 = local_30 | 0x270;
    memw();
  }
  else if (param_2 == 0x11) {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    local_30 = local_30 | 0x270;
    memw();
    memw();
    memw();
    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;
  }
  else {
    if (param_2 != 5) goto LAB_4037f9f5;
    memw();
    local_30 = local_30 | DAT_40374890;
    memw();
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = local_30;
  return;
}