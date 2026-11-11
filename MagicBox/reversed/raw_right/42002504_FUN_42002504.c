// 42002504  FUN_42002504  FUN_42002504  size=312
// strings: Icache sync parameter configuration error, the e | Icache preload parameter configuration error, th | Dcache sync parameter configuration error, the e | Dcache preload parameter configuration error, th | Write back error occurred while dcache tries to  | The following backtrace may not indicate the cod | MMU entry fault error occurred while accessing t |  (invalid mmu entry)

void FUN_42002504(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  uVar2 = *DAT_4200028c;
  uVar1 = 0;
  uVar3 = 0;
  for (uVar4 = 0; (int)uVar4 < 0x20; uVar4 = uVar4 + 1) {
    uVar5 = 1 << 0x20 - (0x20 - (uVar4 & 0x1f)) & uVar2;
    if (uVar5 == 8) {
      memw();
      uVar3 = *DAT_420002ac;
      memw();
      uVar1 = *DAT_420002b0;
      FUN_42001e2c(PTR_s_Dcache_preload_parameter_configu_420002b4);
      FUN_42001e58(uVar3);
      FUN_42001e2c(PTR_DAT_42000294);
      FUN_42001e58(uVar1);
      FUN_42001e2c(PTR_DAT_42000298);
    }
    else if (uVar5 < 9) {
      if (uVar5 == 2) {
        memw();
        uVar3 = *DAT_4200029c;
        memw();
        uVar1 = *DAT_420002a0;
        FUN_42001e2c(PTR_s_Icache_preload_parameter_configu_420002a4);
        FUN_42001e58(uVar3);
        FUN_42001e2c(PTR_DAT_42000294);
        FUN_42001e58(uVar1);
        FUN_42001e2c(PTR_DAT_42000298);
      }
      else if (uVar5 == 4) {
        FUN_42001e2c(PTR_s_Dcache_sync_parameter_configurat_420002a8);
        FUN_42001e58(uVar3);
        FUN_42001e2c(PTR_DAT_42000294);
        FUN_42001e58(uVar1);
        FUN_42001e2c(PTR_DAT_42000298);
      }
      else if (uVar5 == 1) {
        FUN_42001e2c(PTR_s_Icache_sync_parameter_configurat_42000290);
        FUN_42001e58(uVar3);
        FUN_42001e2c(PTR_DAT_42000294);
        FUN_42001e58(uVar1);
        FUN_42001e2c(PTR_DAT_42000298);
      }
    }
    else if (uVar5 == 0x10) {
      FUN_42001e2c(PTR_s_Write_back_error_occurred_while_d_420002b8);
      FUN_42001e2c(PTR_s_The_following_backtrace_may_not_i_420002bc);
    }
    else if (uVar5 == 0x20) {
      memw();
      uVar3 = *DAT_420002c0;
      FUN_42001e2c(PTR_s_MMU_entry_fault_error_occurred_w_420002c4);
      FUN_42001e58(uVar3);
      memw();
      if ((*DAT_420002c8 & 0x4000) != 0) {
        FUN_42001e2c(PTR_s__invalid_mmu_entry__420002cc);
      }
      FUN_42001e2c(PTR_DAT_420002d0);
    }
  }
  FUN_42001e2c(PTR_DAT_420002d0);
  return;
}


