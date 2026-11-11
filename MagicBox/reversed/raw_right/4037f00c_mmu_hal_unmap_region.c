// 4037f00c  mmu_hal_unmap_region  FUN_4037f00c  size=99
// strings: vaddr % page_size_in_bytes == 0 | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad

void FUN_4037f00c(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_4037f0c8(param_1,1);
  if (param_2 % uVar1 != 0) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x6c,
                 PTR_s_mmu_hal_unmap_region_4037508c,PTR_s_vaddr___page_size_in_bytes____0_40375078)
    ;
  }
  iVar2 = FUN_4037eef8(param_1,param_2,param_3,3);
  if (iVar2 == 0) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x6d,
                 PTR_s_mmu_hal_unmap_region_4037508c,PTR_s_mmu_hal_check_valid_ext_vaddr_re_40375088
                );
  }
  for (uVar3 = ((uVar1 + param_3) - 1) / uVar1; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)(((param_2 >> 0x10 & 0x1ff) + DAT_40375054) * 4) = DAT_40374450;
    param_2 = param_2 + uVar1;
  }
  return;
}


