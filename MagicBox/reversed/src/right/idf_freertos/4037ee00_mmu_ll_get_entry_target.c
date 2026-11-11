// strings: entry_id < SOC_MMU_ENTRY_NUM

undefined4 FUN_4037ee00(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (0x1ff < param_2) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40375050,0x100,
                 PTR_s_mmu_ll_get_entry_target_40375058,PTR_s_entry_id_<_SOC_MMU_ENTRY_NUM_40375048)
    ;
  }
  if ((*(uint *)((param_2 + DAT_40375054) * 4) & 0x8000) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}