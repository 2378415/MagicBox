// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU

void FUN_4037ead0(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0xac,
                 PTR_s_cache_hal_disable_40374fec,PTR_s_cache_level_____cache_level_<__C_40374fe8);
  }
  if (param_2 == 0) {
    (*DAT_4037456c)();
  }
  else if (param_2 == 1) {
    (*DAT_40374568)();
  }
  else {
    (*DAT_40374568)();
    (*DAT_4037456c)();
  }
  return;
}