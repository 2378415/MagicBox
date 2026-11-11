// strings: s_periph_ref_counts > 0 | periph_rtc_dig_clk8m_disable

void FUN_4201abe4(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *in_t0;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420019ac,0xffffffff);
  pbVar1 = (byte *)(uint)*DAT_420019b0;
  pbVar2 = DAT_420019b0;
  if (pbVar1 == (byte *)0x0) {
    pbVar1 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_clk_ctrl_os_c_3c03b3ec_0x20_420019c8,0x46,
               PTR_s_periph_rtc_dig_clk8m_disable_420019c4,PTR_s_s_periph_ref_counts_>_0_420019c0);
    pbVar2 = pbVar1;
  }
  *pbVar2 = (byte)(pbVar1 + -1);
  if (((uint)(pbVar1 + -1) & 0xff) == 0) {
    *DAT_420019b4 = 0;
    (*(code *)PTR_FUN_420019bc)();
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_420019ac);
  return;
}