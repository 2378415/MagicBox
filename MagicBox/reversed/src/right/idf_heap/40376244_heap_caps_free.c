// strings: heap != NULL && 'free() target pointer is outsid | heap_caps_base.c | heap_caps_free

void FUN_40376244(int param_1)

{
  int iVar1;
  int in_t0;
  
  if (param_1 != 0) {
    if ((uint)(param_1 + DAT_40374698) <= DAT_40374670) {
      param_1 = *(int *)(param_1 + -4);
    }
    for (iVar1 = *DAT_4037469c;
        (iVar1 != 0 &&
        (((*(int *)(iVar1 + 0x1c) == 0 || (param_1 < *(int *)(iVar1 + 0xc))) ||
         (*(int *)(iVar1 + 0x10) <= param_1)))); iVar1 = *(int *)(iVar1 + 0x20)) {
    }
    if (iVar1 == 0) {
      iVar1 = in_t0;
      FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x4a,PTR_s_heap_caps_free_403746a4,
                   PTR_s_heap____NULL_____free___target_p_403746a0);
    }
    FUN_40380800(*(undefined4 *)(iVar1 + 0x1c));
  }
  return;
}