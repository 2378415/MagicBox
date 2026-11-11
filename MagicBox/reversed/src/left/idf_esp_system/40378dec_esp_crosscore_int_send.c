// strings: core_id < CONFIG_FREERTOS_NUMBER_OF_CORES

void FUN_40378dec(int param_1,uint param_2)

{
  undefined *puVar1;
  uint *puVar2;
  
  if (1 < param_1) {
    FUN_40381ce4(PTR_s_crosscore_int_c_3c03a920_0x1c_403749a0,0x6d,
                 PTR_s_esp_crosscore_int_send_4037499c,
                 PTR_s_core_id_<_CONFIG_FREERTOS_NUMBER_40374998);
  }
  FUN_4037bf44(PTR_DAT_40374990,0xffffffff);
  puVar1 = PTR_DAT_40374990;
  puVar2 = (uint *)(param_1 * 4 + DAT_403749a4);
  memw();
  memw();
  *puVar2 = *puVar2 | param_2;
  FUN_4037c094(puVar1);
  if (param_1 == 0) {
    memw();
    *DAT_40374988 = 1;
  }
  else {
    memw();
    *DAT_4037498c = 1;
  }
  return;
}