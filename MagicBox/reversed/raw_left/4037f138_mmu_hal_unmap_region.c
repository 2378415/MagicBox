// 4037f138  mmu_hal_unmap_region  FUN_4037f138  size=131
// strings: vaddr % page_size_in_bytes == 0 | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad | /IDF/components/hal/mmu_hal.c | mmu_hal_unmap_region

void FUN_4037f138(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 & 0xffff) != 0) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x6c,
                 PTR_s_mmu_hal_unmap_region_40375134,PTR_s_vaddr___page_size_in_bytes____0_40375114)
    ;
  }
  iVar1 = DAT_403750d8;
  if (((DAT_40374614 < param_2 + DAT_40374e08) &&
      (iVar1 = DAT_403750e0, DAT_40374614 < param_2 + DAT_403750dc)) ||
     (DAT_40374614 < param_2 + param_3 + iVar1)) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x6d,
                 PTR_s_mmu_hal_unmap_region_40375134,PTR_s_mmu_hal_check_valid_ext_vaddr_re_4037512c
                );
  }
  if ((uint)(param_3 + DAT_403748e8) >> 0x10 != 0) {
    *(undefined4 *)(((param_2 >> 0x10 & 0x1ff) + DAT_40375130) * 4) = DAT_40374460;
  }
  return;
}


