// 4037f21c  mmu_hal_paddr_to_vaddr  FUN_4037f21c  size=103
// strings: mmu_ll_check_valid_paddr_region(mmu_id, paddr, 1

undefined4 FUN_4037f21c(undefined4 param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_40375124 < param_2) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x8d,
                 PTR_s_mmu_hal_paddr_to_vaddr_40375150,
                 PTR_s_mmu_ll_check_valid_paddr_region__4037514c);
  }
  uVar1 = *DAT_40375140;
  if ((uVar1 & 0x4000) == 0) {
    iVar2 = 2;
    if ((uVar1 >> 0xf & 1) == 0) {
      iVar2 = 1;
    }
    if ((param_3 == iVar2) && (param_2 >> 0x10 == (uVar1 & 0x3fff))) {
      uVar1 = DAT_40375148;
      if (param_4 == 1) {
        uVar1 = DAT_40375144;
      }
      *param_5 = param_2 & 0xffff | uVar1;
      return 1;
    }
  }
  return 0;
}


