// 40378b80  FUN_40378b80  FUN_40378b80  size=78
// strings: freqdiv > 0

void FUN_40378b80(uint param_1)

{
  uint uVar1;
  uint in_t0;
  
  FUN_40378a94(0,0x50);
  uVar1 = 0x50 / param_1;
  if (0x50 < param_1) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_mspi_timing_config_c_3fc95dd4_0x2d_40374930,0x45,
                 PTR_s_mspi_timing_config_set_psram_clo_4037493c,PTR_s_freqdiv_>_0_40374928);
  }
  if (uVar1 == 1) {
    memw();
    *DAT_40374940 = DAT_4037450c;
  }
  else {
    memw();
    *DAT_40374940 = uVar1 - 1 | (uVar1 - 1) * 0x10000 | ((uVar1 >> 1) - 1) * 0x100;
  }
  return;
}


