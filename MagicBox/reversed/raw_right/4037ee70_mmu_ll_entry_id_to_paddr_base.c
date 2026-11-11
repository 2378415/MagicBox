// 4037ee70  mmu_ll_entry_id_to_paddr_base  FUN_4037ee70  size=48
// strings: entry_id < SOC_MMU_ENTRY_NUM

int FUN_4037ee70(undefined4 param_1,uint param_2)

{
  if (0x1ff < param_2) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40375050,0x111,
                 PTR_s_mmu_ll_entry_id_to_paddr_base_4037505c,
                 PTR_s_entry_id_<_SOC_MMU_ENTRY_NUM_40375048);
  }
  return (*(uint *)((param_2 + DAT_40375054) * 4) & 0x3fff) << 0x10;
}


