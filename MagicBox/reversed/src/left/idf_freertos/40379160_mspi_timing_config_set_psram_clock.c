// strings: freqdiv > 0

void FUN_40379160(uint param_1)

{
  uint uVar1;
  uint in_t0;
  
  memw();
  memw();
  *DAT_403749e0 = *DAT_403749e0 & 0xfffffffc;
  uVar1 = 0x50 / param_1;
  if (0x50 < param_1) {
    uVar1 = in_t0;
    FUN_40381ce4(PTR_s_mspi_timing_config_c_3fc95ecc_0x2d_403749ec,0x45,
                 PTR_s_mspi_timing_config_set_psram_clo_403749f8,PTR_s_freqdiv_>_0_403749e4);
  }
  if (uVar1 == 1) {
    memw();
    *DAT_403749fc = DAT_40374550;
  }
  else {
    memw();
    *DAT_403749fc = ((uVar1 >> 1) - 1) * 0x100 | (uVar1 - 1) * 0x10001;
  }
  return;
}