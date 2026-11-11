// strings: false

undefined4 FUN_42013510(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    memw();
    if ((*DAT_42001024 & 4) == 0) {
      uVar1 = 0x140;
    }
    else if ((*DAT_42001024 >> 2 & 1) == 1) {
      uVar1 = 0x1e0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 0) {
        uVar1 = FUN_420134dc();
        return uVar1;
      }
      (*(code *)PTR_FUN_42000044)
                (PTR_s__IDF_components_hal_esp32s3_clk__4200102c,0x1b,
                 PTR_s_clk_hal_soc_root_get_freq_mhz_42001028,PTR_s_false_42001014);
    }
    uVar1 = 0x11;
  }
  return uVar1;
}