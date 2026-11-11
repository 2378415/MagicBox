// 4037efc4  cache_hal_freeze  FUN_4037efc4  size=48
// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_freeze

void FUN_4037efc4(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0x112,
                 PTR_s_cache_hal_freeze_403750e8,PTR_s_cache_level_____cache_level_<__C_403750b4);
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      FUN_4037b1f0(0);
      return;
    }
    FUN_4037b1f0(0);
  }
  FUN_4037b20c(0);
  return;
}


