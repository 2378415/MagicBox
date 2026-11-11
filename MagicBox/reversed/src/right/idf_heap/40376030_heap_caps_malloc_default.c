// strings: heap_caps_malloc_default

int FUN_40376030(uint param_1)

{
  int iVar1;
  
  if (*(uint *)PTR_DAT_4037464c == 0xffffffff) {
    iVar1 = FUN_40376004(param_1,DAT_40374650);
  }
  else {
    if (*(uint *)PTR_DAT_4037464c < param_1) {
      iVar1 = FUN_40376374(param_1,DAT_40374654);
    }
    else {
      iVar1 = FUN_40376374(param_1,DAT_40374650);
    }
    if (iVar1 == 0 && param_1 != 0) {
      iVar1 = FUN_40376374(param_1,DAT_40374658);
    }
    if (param_1 != 0 && iVar1 == 0) {
      FUN_40375fec(param_1,DAT_40374658,PTR_s_heap_caps_malloc_default_4037465c);
    }
  }
  return iVar1;
}