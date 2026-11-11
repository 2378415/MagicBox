// 4037eb78  cache_hal_suspend  FUN_4037eb78  size=47
// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU

void FUN_4037eb78(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0xc6,
                 PTR_s_cache_hal_suspend_40374ff8,PTR_s_cache_level_____cache_level_<__C_40374fe8);
  }
  if (param_2 == 0) {
    FUN_4037ada4();
  }
  else if (param_2 == 1) {
    FUN_4037ad88();
  }
  else {
    FUN_4037ad88();
    FUN_4037ada4();
  }
  return;
}


