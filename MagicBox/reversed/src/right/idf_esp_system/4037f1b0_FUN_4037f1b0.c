// strings: &C8&S

void FUN_4037f1b0(int param_1,uint param_2)

{
  uint local_30;
  uint uStack_2c;
  
  memw();
  memw();
  memw();
  memw();
  memw();
  local_30 = *(uint *)(param_1 + 8) & DAT_403750c8;
  memw();
  memw();
  uStack_2c = *(uint *)(param_1 + 0x10) & DAT_403750cc;
  memw();
  if (param_2 == 3) {
    memw();
    memw();
    memw();
    local_30 = local_30 | DAT_40374450 | 0x20;
    memw();
    memw();
    uStack_2c = uStack_2c | DAT_40374658;
    memw();
  }
  else if (param_2 < 4) {
    if (1 < param_2) {
      if (param_2 != 2) {
LAB_4037f2b4:
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      memw();
      local_30 = local_30 | DAT_40374450;
      memw();
      memw();
      uStack_2c = uStack_2c | DAT_40374658;
      memw();
    }
  }
  else if (param_2 == 4) {
    memw();
    local_30 = local_30 | DAT_40374454;
    memw();
    memw();
    uStack_2c = uStack_2c | DAT_403748a8;
    memw();
  }
  else {
    if (param_2 != 5) goto LAB_4037f2b4;
    memw();
    memw();
    memw();
    local_30 = local_30 | DAT_40374454 | 0x40;
    memw();
    memw();
    uStack_2c = uStack_2c | DAT_403748a8;
    memw();
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = local_30;
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = uStack_2c;
  return;
}