// 4037f078  mmu_hal_map_region  FUN_4037f078  size=192
// strings: vaddr % page_size_in_bytes == 0 | paddr % page_size_in_bytes == 0 | /IDF/components/hal/mmu_hal.c | mmu_hal_map_region | mmu_ll_check_valid_paddr_region(mmu_id, paddr, l | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad

void FUN_4037f078(undefined4 param_1,int param_2,uint param_3,uint param_4,uint param_5,
                 uint *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_3 & 0xffff) != 0) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x54,PTR_s_mmu_hal_map_region_40375118
                 ,PTR_s_vaddr___page_size_in_bytes____0_40375114);
  }
  if ((param_4 & 0xffff) != 0) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x55,PTR_s_mmu_hal_map_region_40375118
                 ,PTR_s_paddr___page_size_in_bytes____0_40375120);
  }
  if (DAT_40375124 < ((param_5 - 1) + param_4 | param_4 | param_5)) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x56,PTR_s_mmu_hal_map_region_40375118
                 ,PTR_s_mmu_ll_check_valid_paddr_region__40375128);
  }
  iVar1 = DAT_403750d8;
  if (((DAT_40374614 < param_3 + DAT_40374e08) &&
      (iVar1 = DAT_403750e0, DAT_40374614 < param_3 + DAT_403750dc)) ||
     (DAT_40374614 < param_3 + param_5 + iVar1)) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x57,PTR_s_mmu_hal_map_region_40375118
                 ,PTR_s_mmu_hal_check_valid_ext_vaddr_re_4037512c);
  }
  param_4 = param_4 >> 0x10;
  uVar3 = param_5 + DAT_403748e8 >> 0x10;
  *param_6 = param_5 + DAT_403748e8 & 0xffff0000;
  iVar2 = DAT_40375130;
  iVar1 = DAT_403748ec;
  if (uVar3 != 0) {
    do {
      *(uint *)(((param_3 >> 0x10 & 0x1ff) + iVar2) * 4) = param_4 | (uint)(param_2 != 1) << 0xf;
      param_3 = param_3 + iVar1;
      param_4 = param_4 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}


