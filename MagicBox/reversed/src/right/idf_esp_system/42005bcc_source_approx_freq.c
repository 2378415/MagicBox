// strings: source_approx_freq | clk_tree_rtc_slow_calibration

void FUN_42005bcc(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = FUN_4201349c();
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_esp_clk_tree_common_c_3c032150_0x25_4200067c,0x42,
                 PTR_s_clk_tree_rtc_slow_calibration_42000678,PTR_s_source_approx_freq_42000674);
    }
    iVar1 = (*DAT_420000d0)(DAT_42000680,0x7a);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000090)(0);
  }
  if (iVar1 != 0) {
    FUN_420032d0(iVar1);
  }
  return;
}