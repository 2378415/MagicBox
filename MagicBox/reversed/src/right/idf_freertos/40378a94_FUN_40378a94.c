// strings: false | /IDF/components/hal/esp32s3/include/hal/mspi_tim | mspi_timing_ll_set_core_clock

void FUN_40378a94(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_2 != 0xa0) {
    if (param_2 < 0xa1) {
      if (param_2 == 0x50) {
        uVar2 = 0;
        goto LAB_40378ada;
      }
      if (param_2 == 0x78) {
        uVar2 = 1;
        goto LAB_40378ada;
      }
    }
    else if (param_2 == 0xf0) {
      uVar2 = 3;
      goto LAB_40378ada;
    }
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40374920,0xa4,
                 PTR_s_mspi_timing_ll_set_core_clock_4037491c,PTR_s_false_40374918);
  }
  uVar2 = 2;
LAB_40378ada:
  puVar1 = (uint *)((DAT_40374924 - param_1) * 0x1000 + 0xec);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffc | uVar2;
  return;
}