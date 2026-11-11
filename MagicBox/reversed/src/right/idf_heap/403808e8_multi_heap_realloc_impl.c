// strings: heap != NULL

int FUN_403808e8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_multi_heap_c_3c030c40_0x16_40375124,0xef,
                 PTR_s_multi_heap_realloc_impl_40375120,PTR_s_heap____NULL_4037511c);
  }
  if (param_2 == 0) {
    iVar1 = FUN_40380898(param_1,param_3);
  }
  else {
    FUN_40380760(param_1,param_2 + -8);
    iVar1 = 0;
    if (param_1 != 0) {
      FUN_40380854(param_1);
      iVar2 = FUN_4038096c(param_2);
      iVar1 = FUN_40381794(*(undefined4 *)(param_1 + 0x10),param_2,param_3);
      if (iVar1 != 0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar2;
        iVar2 = FUN_4038096c();
        uVar3 = *(int *)(param_1 + 4) - iVar2;
        *(uint *)(param_1 + 4) = uVar3;
        if (uVar3 < *(uint *)(param_1 + 8)) {
          *(uint *)(param_1 + 8) = uVar3;
        }
      }
      FUN_40380878(param_1);
    }
  }
  return iVar1;
}