// strings: heap != NULL | multi_heap_realloc_impl

int FUN_40380a1c(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_multi_heap_c_3c03316c_0x16_403751dc,0xef,
                 PTR_s_multi_heap_realloc_impl_403751d8,PTR_s_heap____NULL_403751d4);
  }
  if (param_2 == 0) {
    iVar1 = FUN_403809b8(param_1,param_3);
  }
  else {
    FUN_403808b0(param_1,param_2 + -8);
    iVar2 = *param_1;
    if (iVar2 != 0) {
      FUN_4037bf20();
      FUN_4037bf44(iVar2,0xffffffff);
    }
    iVar2 = FUN_40380aa8(param_2);
    iVar1 = FUN_40381700(param_1[4],param_2,param_3);
    if (iVar1 != 0) {
      param_1[1] = param_1[1] + iVar2;
      iVar2 = FUN_40380aa8();
      uVar3 = param_1[1] - iVar2;
      param_1[1] = uVar3;
      if (uVar3 < (uint)param_1[2]) {
        param_1[2] = uVar3;
      }
    }
    iVar2 = *param_1;
    if (iVar2 != 0) {
      FUN_4037bf20();
      FUN_4037c094(iVar2);
    }
  }
  return iVar1;
}