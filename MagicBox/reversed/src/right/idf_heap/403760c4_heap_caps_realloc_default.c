// strings: heap_caps_realloc_default

int FUN_403760c4(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (*(uint *)PTR_DAT_4037464c == 0xffffffff) {
    iVar1 = FUN_40376098(param_1,param_2,DAT_40374650);
  }
  else {
    if (*(uint *)PTR_DAT_4037464c < param_2) {
      iVar1 = FUN_40376384(param_1,param_2,DAT_40374654);
    }
    else {
      iVar1 = FUN_40376384(param_1,param_2,DAT_40374650);
    }
    if (iVar1 == 0 && param_2 != 0) {
      iVar1 = FUN_40376384(param_1,param_2,DAT_40374658);
    }
    if (param_2 != 0 && iVar1 == 0) {
      FUN_40375fec(param_2,DAT_40374658,PTR_s_heap_caps_realloc_default_40374664);
    }
  }
  return iVar1;
}