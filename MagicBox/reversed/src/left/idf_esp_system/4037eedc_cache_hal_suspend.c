// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_suspend

void FUN_4037eedc(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0xc6,
                 PTR_s_cache_hal_suspend_403750c4,PTR_s_cache_level_____cache_level_<__C_403750b4);
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      FUN_4037b1b0();
      return;
    }
    FUN_4037b1b0();
  }
  FUN_4037b1cc();
  return;
}