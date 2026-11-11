// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_resume

void FUN_4037ef08(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 1) {
    FUN_40381ce4(PTR_s__IDF_components_hal_cache_hal_c_403750bc,0xd1,PTR_s_cache_hal_resume_403750c8
                 ,PTR_s_cache_level_____cache_level_<__C_403750b4);
  }
  bVar1 = DAT_403750a4[1];
  if (param_2 != 0) {
    if (param_2 == 1) {
      (*DAT_403750cc)();
      return;
    }
    (*DAT_403750cc)((uint)*DAT_403750a4 << 2);
  }
  (*DAT_403744d0)((uint)bVar1 << 2);
  return;
}