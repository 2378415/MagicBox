// strings: false | clk_ll_rtc_slow_get_src

void FUN_40379068(int param_1)

{
  uint uVar1;
  uint in_t0;
  
  memw();
  uVar1 = *DAT_403749a4 >> 0x1e;
  if (((uVar1 != 1) && (uVar1 != 2)) && (uVar1 != 0)) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_403749b8,0x21a,
                 PTR_s_clk_ll_rtc_slow_get_src_403749b4,PTR_s_false_403749b0);
  }
  if (param_1 == 2 && uVar1 != 2) {
    (*(code *)PTR_FUN_403749bc)(0,1);
  }
  else if (param_1 != 2 && uVar1 == 2) {
    (*(code *)PTR_FUN_403749bc)(0);
  }
  if (param_1 == 1) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0x3fffffff | DAT_403745e0;
  }
  else if (param_1 == 2) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0x3fffffff | DAT_4037450c;
  }
  else {
    if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_40381ce0();
    }
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0x3fffffff;
  }
  if (param_1 == 1) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | 0x100;
  }
  else {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0xfffffeff;
  }
  (*DAT_40374434)(300);
  return;
}