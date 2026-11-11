// strings: heap_caps_malloc | heap_caps_malloc_default

int FUN_40376334(uint param_1)

{
  int iVar1;
  
  if (*(uint *)PTR_DAT_4037468c == 0xffffffff) {
    iVar1 = FUN_40376608(param_1,DAT_40374690);
    if ((iVar1 == 0) && (param_1 != 0)) {
      FUN_403762fc(param_1,DAT_40374690,PTR_s_heap_caps_malloc_40374688);
    }
  }
  else {
    if (*(uint *)PTR_DAT_4037468c < param_1) {
      iVar1 = FUN_40376608(param_1,DAT_40374694);
    }
    else {
      iVar1 = FUN_40376608(param_1,DAT_40374690);
    }
    if (((iVar1 == 0) && (param_1 != 0)) && (iVar1 = FUN_40376608(param_1,DAT_40374698), iVar1 == 0)
       ) {
      FUN_403762fc(param_1,DAT_40374698,PTR_s_heap_caps_malloc_default_4037469c);
    }
  }
  return iVar1;
}