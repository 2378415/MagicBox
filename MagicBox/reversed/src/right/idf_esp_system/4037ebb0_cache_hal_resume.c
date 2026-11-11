// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_resume

void FUN_4037ebb0(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 != 1) {
    param_2 = FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0xd1,
                           PTR_s_cache_hal_resume_40374ffc,
                           PTR_s_cache_level_____cache_level_<__C_40374fe8);
  }
  cVar1 = DAT_40374fd8[1];
  if (param_2 == 0) {
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = 4;
    }
    (*DAT_40374498)(uVar2);
  }
  else if (param_2 == 1) {
    if (*DAT_40374fd8 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40375000)(uVar2);
  }
  else {
    if (*DAT_40374fd8 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40375000)(uVar2);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40374498)(uVar2);
  }
  return;
}