// 4201a748  clk_hal_soc_root_get_freq_mhz  FUN_4201a748  size=20
// strings: false

undefined4 FUN_4201a748(void)

{
  uint uVar1;
  
  (*(code *)PTR_FUN_420000a8)
            (PTR_s__IDF_components_hal_esp32s3_clk__42001958,0x1b,
             PTR_s_clk_hal_soc_root_get_freq_mhz_42001954,PTR_s_false_42001950);
  memw();
  uVar1 = *DAT_42000878 >> 0x1e;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      return DAT_42000860;
    }
    if (uVar1 == 0) {
      return DAT_4200195c;
    }
    (*(code *)PTR_FUN_420000a8)
              (PTR_s__IDF_components_hal_esp32s3_incl_42001964,0x21a,
               PTR_s_clk_ll_rtc_slow_get_src_42001960,PTR_s_false_42001950);
  }
  return DAT_42000288;
}


