// strings: mmu_hal_check_valid_ext_vaddr_region(mmu_id, vad

int FUN_4037f074(undefined4 param_1,uint param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = FUN_4037eef8(param_1,param_2,1,3);
  if (iVar1 == 0) {
    FUN_40381d9c(PTR_s__IDF_components_hal_mmu_hal_c_4037506c,0x7b,
                 PTR_s_mmu_hal_vaddr_to_paddr_40375094,
                 PTR_s_mmu_hal_check_valid_ext_vaddr_re_40375090);
  }
  uVar4 = param_2 >> 0x10 & 0x1ff;
  iVar1 = FUN_4037edcc(param_1,uVar4);
  if (iVar1 != 0) {
    uVar2 = FUN_4037f0c8(param_1,1);
    uVar3 = FUN_4037ee00(param_1,uVar4);
    *param_4 = uVar3;
    uVar4 = FUN_4037ee70(param_1,uVar4);
    *param_3 = param_2 % uVar2 | uVar4;
  }
  return iVar1;
}