// 40378afc  mspi_timing_config_set_flash_clock  FUN_40378afc  size=129
// strings: freqdiv > 0

void FUN_40378afc(uint param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  uint in_t0;
  
  FUN_40378a2c(0,0x50);
  uVar1 = 0x50 / param_1;
  if (0x50 < param_1) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_mspi_timing_config_c_3fc95dd4_0x2d_40374930,0x31,
                 PTR_s_mspi_timing_config_set_flash_clo_4037492c,PTR_s_freqdiv_>_0_40374928);
  }
  if (uVar1 == 1) {
    memw();
    *DAT_40374934 = DAT_4037450c;
  }
  else {
    memw();
    *DAT_40374934 = uVar1 - 1 | (uVar1 - 1) * 0x10000 | ((uVar1 >> 1) - 1) * 0x100;
  }
  if (param_3 != '\0') {
    if (uVar1 == 1) {
      memw();
      *DAT_40374938 = DAT_4037450c;
    }
    else {
      memw();
      *DAT_40374938 = uVar1 - 1 | (uVar1 - 1) * 0x10000 | ((uVar1 >> 1) - 1) * 0x100;
    }
  }
  return;
}


