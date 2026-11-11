// 4037f1c0  mmu_hal_vaddr_to_paddr  FUN_4037f1c0  size=90
// strings: mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad

undefined4 FUN_4037f1c0(undefined4 param_1,uint param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((DAT_40374614 < param_2 + DAT_40374e08) && (DAT_40374614 < param_2 + DAT_403750dc)) {
    FUN_40381ce4(PTR_s__IDF_components_hal_mmu_hal_c_4037511c,0x7b,
                 PTR_s_mmu_hal_vaddr_to_paddr_4037513c,
                 PTR_s_mmu_hal_check_valid_ext_vaddr_re_40375138);
  }
  uVar2 = *(uint *)((param_2 >> 0x10 & 0x1ff) * 4 + DAT_40375140);
  uVar1 = 0;
  if ((uVar2 & 0x4000) == 0) {
    uVar1 = 1;
    uVar3 = 2;
    if ((uVar2 >> 0xf & 1) == 0) {
      uVar3 = 1;
    }
    *param_4 = uVar3;
    *param_3 = (uVar2 & 0x3fff) << 0x10 | param_2 & 0xffff;
  }
  return uVar1;
}


