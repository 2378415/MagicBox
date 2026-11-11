// strings: cache_level <= CACHE_LL_LEVEL_NUMS | false

undefined4 FUN_4037ed80(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (1 < param_1) {
    FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0x121,
                 PTR_s_cache_hal_get_cache_line_size_40375030,
                 PTR_s_cache_level_<__CACHE_LL_LEVEL_NU_4037502c);
  }
  if (param_1 == 1) {
    if (param_2 == 0) {
      uVar1 = (*DAT_40375044)();
      return uVar1;
    }
    if (param_2 == 1) {
      uVar1 = (*DAT_40375040)();
      return uVar1;
    }
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_4037503c,0x202,
                 PTR_s_cache_ll_get_line_size_40375038,PTR_s_false_40375034);
  }
  return 0;
}