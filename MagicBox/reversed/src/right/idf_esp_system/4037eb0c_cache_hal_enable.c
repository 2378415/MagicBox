// strings: cache_level && (cache_level <= CACHE_LL_LEVEL_NU | cache_hal_enable

void FUN_4037eb0c(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 != 1) {
    param_2 = FUN_40381d9c(PTR_s__IDF_components_hal_cache_hal_c_40374ff0,0xb7,
                           PTR_s_cache_hal_enable_40374ff4,
                           PTR_s_cache_level_____cache_level_<__C_40374fe8);
  }
  cVar1 = DAT_40374fd8[1];
  if (param_2 == 0) {
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = 4;
    }
    (*DAT_40374fe4)(uVar2);
  }
  else if (param_2 == 1) {
    if (*DAT_40374fd8 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40374fe0)(uVar2);
  }
  else {
    if (*DAT_40374fd8 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40374fe0)(uVar2);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    (*DAT_40374fe4)(uVar2);
  }
  return;
}