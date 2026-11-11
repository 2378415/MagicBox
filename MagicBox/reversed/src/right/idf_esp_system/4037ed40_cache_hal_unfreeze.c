// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU

void FUN_4037ed40(int param_1,int param_2)

{
  if (param_1 != 1) {
    FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0x119,
                 PTR_s_cache_hal_unfreeze_40375020,PTR_s_cache_level_____cache_level_<__C_40374fe8);
  }
  if (param_2 == 0) {
    (*DAT_40375028)();
  }
  else if (param_2 == 1) {
    (*DAT_40375024)();
  }
  else {
    (*DAT_40375024)();
    (*DAT_40375028)();
  }
  return;
}