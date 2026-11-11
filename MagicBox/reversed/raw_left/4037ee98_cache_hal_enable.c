// 4037ee98  cache_hal_enable  FUN_4037ee98  size=65
// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_enable

void FUN_4037ee98(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 1) {
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0xb7,PTR_s_cache_hal_enable_403750c0
                 ,PTR_s_cache_level_____cache_level_<__C_403750b4);
  }
  bVar1 = DAT_403750a4[1];
  if (param_2 != 0) {
    if (param_2 == 1) {
      (*DAT_403750ac)();
      return;
    }
    (*DAT_403750ac)((uint)*DAT_403750a4 << 2);
  }
  (*DAT_403750b0)((uint)bVar1 << 2);
  return;
}


