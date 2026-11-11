// 42004980  register_heap  FUN_42004980  size=75
// strings: heap_size <= HEAP_SIZE_MAX | heap_init

void FUN_42004980(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_4200059c < (uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc))) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_heap_caps_init_c_3c032fe4_0x16_420005a8,0x21,PTR_s_register_heap_420005a4,
               PTR_s_heap_size_<__HEAP_SIZE_MAX_420005a0);
  }
  iVar1 = FUN_4202eb90();
  *(int *)(param_1 + 0x1c) = iVar1;
  if ((iVar1 != 0) && (3 < *(uint *)PTR_DAT_42000028)) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_420005b0,uVar2,PTR_s_heap_init_420005ac,*(undefined4 *)(param_1 + 0x1c))
    ;
  }
  return;
}


