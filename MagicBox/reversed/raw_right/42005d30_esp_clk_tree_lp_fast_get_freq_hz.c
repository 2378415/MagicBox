// 42005d30  esp_clk_tree_lp_fast_get_freq_hz  FUN_42005d30  size=82
// strings: false

uint FUN_42005d30(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  memw();
  if ((*DAT_42000694 & 0x20000000) == 0) {
    iVar1 = FUN_420134dc();
    uVar2 = (uint)(iVar1 * DAT_42000698) >> 1;
  }
  else {
    if ((*DAT_42000694 >> 0x1d & 1) != 1) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_esp_clk_tree_common_c_3c032150_0x25_4200067c,200,
                 PTR_s_esp_clk_tree_lp_fast_get_freq_hz_420006a0,PTR_s_false_4200069c);
    }
    uVar2 = FUN_42005d14(param_1);
    memw();
    uVar2 = uVar2 / ((*DAT_42000694 >> 0xc & 7) + 1);
  }
  return uVar2;
}


