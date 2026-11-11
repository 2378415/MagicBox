// strings: start_ptr

undefined4 * FUN_4202eb90(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_multi_heap_c_3c03316c_0x16_42001f68,0x85,
               PTR_s_multi_heap_register_impl_42001f64,PTR_s_start_ptr_42001f60);
  }
  if (0x13 < param_2) {
    iVar2 = param_2 - 0x14;
    iVar1 = FUN_4202efd4(param_1 + 5,iVar2,0);
    param_1[4] = iVar1;
    if (iVar1 != 0) {
      *param_1 = 0;
      iVar1 = (*(code *)PTR_FUN_42001f6c)();
      param_1[1] = iVar2 - iVar1;
      param_1[3] = iVar2;
      param_1[2] = iVar2 - iVar1;
      return param_1;
    }
  }
  return (undefined4 *)0x0;
}