// 4037edcc  mmu_ll_check_entry_valid  FUN_4037edcc  size=51
// strings: entry_id < SOC_MMU_ENTRY_NUM

bool FUN_4037edcc(undefined4 param_1,uint param_2)

{
  if (0x1ff < param_2) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40375050,0xf0,
                 PTR_s_mmu_ll_check_entry_valid_4037504c,PTR_s_entry_id_<_SOC_MMU_ENTRY_NUM_40375048
                );
  }
  return (*(uint *)((param_2 + DAT_40375054) * 4) >> 0xe & 1) == 0;
}


