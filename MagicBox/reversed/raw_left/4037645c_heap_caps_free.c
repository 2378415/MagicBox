// 4037645c  heap_caps_free  FUN_4037645c  size=74
// strings: heap != NULL && 'free() target pointer is outsid | heap_caps_base.c | heap_caps_free

void FUN_4037645c(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if ((uint)(param_1 + DAT_403746ac) <= DAT_403746b0) {
      param_1 = *(int *)(param_1 + -4);
    }
    for (iVar1 = *DAT_403746b4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      if (((*(int *)(iVar1 + 0x1c) != 0) && (*(int *)(iVar1 + 0xc) <= param_1)) &&
         (param_1 < *(int *)(iVar1 + 0x10))) goto LAB_403764a1;
    }
    FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x4a,PTR_s_heap_caps_free_403746bc,
                 PTR_s_heap____NULL_____free___target_p_403746b8);
LAB_403764a1:
    FUN_40380954();
  }
  return;
}


