// 42002d40  FUN_42002d40  FUN_42002d40  size=40
// strings: heap_size <= HEAP_SIZE_MAX

void FUN_42002d40(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_420003ec < (uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc))) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_heap_caps_init_c_3c030b38_0x16_420003f8,0x21,PTR_s_register_heap_420003f4,
               PTR_s_heap_size_<__HEAP_SIZE_MAX_420003f0);
  }
  uVar1 = FUN_4202653c();
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}


