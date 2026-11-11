// strings: false

void FUN_40379160(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *DAT_403749a4 >> 0x1e;
  if (((uVar1 != 1) && (uVar1 != 2)) && (uVar1 != 0)) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_403749b8,0x21a,
                 PTR_s_clk_ll_rtc_slow_get_src_403749b4,PTR_s_false_403749b0);
  }
  return;
}