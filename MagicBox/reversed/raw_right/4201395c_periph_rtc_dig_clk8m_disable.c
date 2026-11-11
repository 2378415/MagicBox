// 4201395c  periph_rtc_dig_clk8m_disable  FUN_4201395c  size=79
// strings: s_periph_ref_counts > 0 | periph_rtc_dig_clk8m_disable

void FUN_4201395c(void)

{
  uint uVar1;
  uint in_t0;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42001054,0xffffffff);
  uVar1 = (uint)*DAT_42001058;
  if (uVar1 == 0) {
    uVar1 = in_t0;
    (*(code *)PTR_FUN_42000044)
              (PTR_s_clk_ctrl_os_c_3c035e48_0x20_42001070,0x46,
               PTR_s_periph_rtc_dig_clk8m_disable_4200106c,PTR_s_s_periph_ref_counts_>_0_42001068);
  }
  *DAT_42001058 = (byte)(uVar1 - 1);
  if ((uVar1 - 1 & 0xff) == 0) {
    *DAT_4200105c = 0;
    (*(code *)PTR_FUN_42001064)();
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42001054);
  return;
}


