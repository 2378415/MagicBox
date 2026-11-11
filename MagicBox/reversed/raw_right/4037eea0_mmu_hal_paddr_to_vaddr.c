// 4037eea0  mmu_hal_paddr_to_vaddr  FUN_4037eea0  size=86
// strings: mmu_ll_check_valid_paddr_region(mmu_id, paddr, 1 | p3 9

undefined4
FUN_4037eea0(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (DAT_40375060 < param_2) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x8d,
                 PTR_s_mmu_hal_paddr_to_vaddr_40375068,
                 PTR_s_mmu_ll_check_valid_paddr_region__40375064);
  }
  iVar1 = FUN_4037ee34(param_1,param_2 >> 0x10);
  if (iVar1 == -1) {
    uVar3 = 0;
  }
  else {
    uVar2 = FUN_4037f0c8(param_1,1);
    if (param_4 == 1) {
      uVar4 = DAT_40375074;
    }
    else {
      uVar4 = DAT_40375070;
    }
    *param_5 = param_2 % uVar2 | iVar1 << 0x10 | uVar4;
    uVar3 = 1;
  }
  return uVar3;
}


