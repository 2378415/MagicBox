// strings: heap_caps_realloc | heap_caps_realloc_default

int FUN_403763a4(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (*(uint *)PTR_DAT_4037468c == 0xffffffff) {
    iVar1 = FUN_40376618(param_1,param_2,DAT_40374690);
    if ((iVar1 == 0) && (param_2 != 0)) {
      FUN_403762fc(param_2,DAT_40374690,PTR_s_heap_caps_realloc_403746a0);
    }
  }
  else {
    if (*(uint *)PTR_DAT_4037468c < param_2) {
      iVar1 = FUN_40376618(param_1,param_2,DAT_40374694);
    }
    else {
      iVar1 = FUN_40376618(param_1,param_2,DAT_40374690);
    }
    if (((iVar1 == 0) && (param_2 != 0)) &&
       (iVar1 = FUN_40376618(param_1,param_2,DAT_40374698), iVar1 == 0)) {
      FUN_403762fc(param_2,DAT_40374698,PTR_s_heap_caps_realloc_default_403746a4);
    }
  }
  return iVar1;
}