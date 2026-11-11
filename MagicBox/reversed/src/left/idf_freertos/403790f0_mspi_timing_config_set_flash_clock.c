// strings: freqdiv > 0

void FUN_403790f0(uint param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint in_t0;
  
  memw();
  memw();
  *DAT_403749e0 = *DAT_403749e0 & 0xfffffffc;
  uVar1 = 0x50 / param_1;
  if (0x50 < param_1) {
    uVar1 = in_t0;
    FUN_40381ce4(PTR_s_mspi_timing_config_c_3fc95ecc_0x2d_403749ec,0x31,
                 PTR_s_mspi_timing_config_set_flash_clo_403749e8,PTR_s_freqdiv_>_0_403749e4);
  }
  uVar2 = DAT_40374550;
  if (uVar1 == 1) {
    memw();
    *DAT_403749f0 = DAT_40374550;
  }
  else {
    uVar2 = ((uVar1 >> 1) - 1) * 0x100 | (uVar1 - 1) * 0x10001;
    memw();
    *DAT_403749f0 = uVar2;
  }
  if (param_3 != '\0') {
    memw();
    *DAT_403749f4 = uVar2;
  }
  return;
}