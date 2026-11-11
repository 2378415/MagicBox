// 4037ee64  cache_hal_disable  FUN_4037ee64  size=50
// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_disable

void FUN_4037ee64(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0xac,
                 PTR_s_cache_hal_disable_403750b8,PTR_s_cache_level_____cache_level_<__C_403750b4);
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      (*DAT_403745ac)();
      return;
    }
    (*DAT_403745ac)();
  }
  (*DAT_403745b0)();
  return;
}


