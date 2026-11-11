// 4202653c  FUN_4202653c  FUN_4202653c  size=78
// strings: start_ptr

undefined4 * FUN_4202653c(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_multi_heap_c_3c030c40_0x16_420014b8,0x85,
               PTR_s_multi_heap_register_impl_420014b4,PTR_s_start_ptr_420014b0);
  }
  if (param_2 < 0x14) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar3 = param_2 - 0x14;
    iVar1 = FUN_42026a3c(param_1 + 5,iVar3,0);
    param_1[4] = iVar1;
    puVar2 = (undefined4 *)0x0;
    if (iVar1 != 0) {
      *param_1 = 0;
      iVar1 = (*(code *)PTR_FUN_420014bc)();
      param_1[1] = iVar3 - iVar1;
      param_1[3] = iVar3;
      param_1[2] = iVar3 - iVar1;
      puVar2 = param_1;
    }
  }
  return puVar2;
}


