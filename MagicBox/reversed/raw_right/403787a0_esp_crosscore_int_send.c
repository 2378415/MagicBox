// 403787a0  esp_crosscore_int_send  FUN_403787a0  size=84
// strings: core_id < CONFIG_FREERTOS_NUMBER_OF_CORES

void FUN_403787a0(int param_1,uint param_2)

{
  uint *puVar1;
  
  if (1 < param_1) {
    FUN_40381d9c(PTR_s_crosscore_int_c_3c0343c8_0x1c_403748f0,0x6d,
                 PTR_s_esp_crosscore_int_send_403748ec,
                 PTR_s_core_id_<_CONFIG_FREERTOS_NUMBER_403748e8);
  }
  FUN_4037bbe8(PTR_DAT_403748e0,0xffffffff);
  puVar1 = (uint *)(param_1 * 4 + DAT_403748f4);
  memw();
  memw();
  *puVar1 = *puVar1 | param_2;
  FUN_4037bd38(PTR_DAT_403748e0);
  if (param_1 == 0) {
    memw();
    *DAT_403748d8 = 1;
  }
  else {
    memw();
    *DAT_403748dc = 1;
  }
  return;
}


