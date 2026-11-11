void FUN_40377770(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint extraout_a3;
  uint uVar1;
  uint uVar2;
  uint in_t0;
  undefined4 local_30 [12];
  
  FUN_40377980();
  local_30[0] = 0;
  FUN_4037ef50(0,param_1,param_2,param_3,param_4,local_30);
  uVar2 = -(DAT_40374800 + -1) & DAT_403747fc;
  if ((-(DAT_40374800 + -1) & DAT_403747fc) == 0) {
    if ((-(DAT_40374808 + -1) & DAT_40374804) != 0) {
      uVar1 = 8;
      goto LAB_403777cf;
    }
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40374814,0x220,
                 PTR_s_cache_ll_l1_get_bus_40374810,PTR_DAT_4037480c);
    uVar2 = extraout_a3;
  }
  uVar1 = 1;
LAB_403777cf:
  memw();
  memw();
  *DAT_40374438 = uVar1 & 1 & *DAT_40374438 ^ *DAT_40374438;
  memw();
  memw();
  *DAT_4037443c = uVar1 >> 2 & *DAT_4037443c ^ *DAT_4037443c;
  if ((uVar2 == 0) && ((-(DAT_40374808 + -1) & DAT_40374804) == 0)) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40374814,0x220,
                 PTR_s_cache_ll_l1_get_bus_40374810,PTR_DAT_4037480c);
  }
  memw();
  memw();
  *DAT_40374438 = uVar1 * 2 & 2 & *DAT_40374438 ^ *DAT_40374438;
  memw();
  memw();
  *DAT_4037443c = uVar1 >> 3 & *DAT_4037443c ^ *DAT_4037443c;
  FUN_40377760(param_2,param_4);
  FUN_40377ad0();
  return;
}