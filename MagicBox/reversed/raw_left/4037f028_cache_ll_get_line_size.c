// 4037f028  cache_ll_get_line_size  FUN_4037f028  size=75
// strings: cache_level <= CACHE_LL_LEVEL_NUMS | false

undefined4 FUN_4037f028(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint in_t0;
  
  if (1 < param_1) {
    param_1 = in_t0;
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0x121,
                 PTR_s_cache_hal_get_cache_line_size_403750fc,
                 PTR_s_cache_level_<__CACHE_LL_LEVEL_NU_403750f8);
  }
  uVar1 = 0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      uVar1 = (*DAT_40375110)();
    }
    else if (param_2 == 1) {
      uVar1 = (*DAT_4037510c)();
    }
    else {
      FUN_40381ce4(PTR_s__IDF_components_hal_esp32s3_incl_40375108,0x202,
                   PTR_s_cache_ll_get_line_size_40375104,PTR_s_false_40375100);
      uVar1 = 0;
    }
  }
  return uVar1;
}


