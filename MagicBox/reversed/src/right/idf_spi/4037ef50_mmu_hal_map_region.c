// strings: vaddr % page_size_in_bytes == 0 | paddr % page_size_in_bytes == 0 | /IDF/components/hal/mmu_hal.c | mmu_hal_map_region | mmu_ll_check_valid_paddr_region(mmu_id, paddr, l | mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad

void FUN_4037ef50(undefined4 param_1,int param_2,uint param_3,uint param_4,uint param_5,
                 undefined4 *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = FUN_4037f0c8(param_1,1);
  uVar2 = uVar1;
  if (param_3 % uVar1 != 0) {
    uVar2 = FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x54,
                         PTR_s_mmu_hal_map_region_4037507c,
                         PTR_s_vaddr___page_size_in_bytes____0_40375078);
  }
  if (param_4 % uVar2 != 0) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x55,PTR_s_mmu_hal_map_region_4037507c
                 ,PTR_s_paddr___page_size_in_bytes____0_40375080);
  }
  if (((DAT_40375060 < param_4) || (DAT_40375060 < param_5)) ||
     (DAT_40375060 < (param_4 + param_5) - 1)) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x56,PTR_s_mmu_hal_map_region_4037507c
                 ,PTR_s_mmu_ll_check_valid_paddr_region__40375084);
  }
  else {
    iVar3 = FUN_4037eef8(param_1,param_3,param_5,3);
    if (iVar3 != 0) goto LAB_4037efca;
  }
  FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x57,PTR_s_mmu_hal_map_region_4037507c,
               PTR_s_mmu_hal_check_valid_ext_vaddr_re_40375088);
LAB_4037efca:
  uVar2 = ((uVar1 + param_5) - 1) / uVar1;
  uVar4 = FUN_4037f0c8(param_1,uVar2);
  *param_6 = uVar4;
  param_4 = param_4 >> 0x10;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    if (param_2 == 1) {
      uVar5 = 0;
    }
    else {
      uVar5 = DAT_40374454;
    }
    *(uint *)(((param_3 >> 0x10 & 0x1ff) + DAT_40375054) * 4) = param_4 | uVar5;
    param_3 = param_3 + uVar1;
    param_4 = param_4 + 1;
  }
  return;
}