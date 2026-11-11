// 42003b80  FUN_42003b80  FUN_42003b80  size=213
// strings: Icache sync parameter configuration error, the e | Dcache sync parameter configuration error, the e | Icache preload parameter configuration error, th | Dcache preload parameter configuration error, th | Write back error occurred while dcache tries to  | The following backtrace may not indicate the cod | MMU entry fault error occurred while accessing t |  (invalid mmu entry)

void FUN_42003b80(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  
  puVar1 = DAT_420003e4;
  uVar2 = 0;
  memw();
  uVar4 = *DAT_420003c4;
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar6 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f)) & uVar4;
    if (uVar6 == 8) {
      memw();
      uVar5 = *puVar1;
      memw();
      uVar3 = *DAT_420003e8;
      puVar7 = PTR_s_Dcache_preload_parameter_configu_420003ec;
LAB_42003bdc:
      FUN_4200330c(puVar7);
      FUN_42003360(uVar5);
      FUN_4200330c(PTR_DAT_420003cc);
      FUN_42003360(uVar3);
      FUN_4200330c(PTR_DAT_420003d0);
    }
    else {
      if (uVar6 < 9) {
        if (uVar6 == 2) {
          memw();
          uVar5 = *DAT_420003d4;
          memw();
          uVar3 = *DAT_420003d8;
          puVar7 = PTR_s_Icache_preload_parameter_configu_420003dc;
        }
        else if (uVar6 == 4) {
          puVar7 = PTR_s_Dcache_sync_parameter_configurat_420003e0;
        }
        else {
          puVar7 = PTR_s_Icache_sync_parameter_configurat_420003c8;
          if (uVar6 != 1) goto LAB_42003c4a;
        }
        goto LAB_42003bdc;
      }
      if (uVar6 == 0x10) {
        FUN_4200330c(PTR_s_Write_back_error_occurred_while_d_420003f0);
        FUN_4200330c(PTR_s_The_following_backtrace_may_not_i_420003f4);
      }
      else if (uVar6 == 0x20) {
        memw();
        uVar5 = *DAT_420003f8;
        FUN_4200330c(PTR_s_MMU_entry_fault_error_occurred_w_420003fc);
        FUN_42003360(uVar5);
        memw();
        if ((*DAT_42000400 & 0x4000) != 0) {
          FUN_4200330c(PTR_s__invalid_mmu_entry__42000404);
        }
        FUN_4200330c(PTR_s__3c039338_0x14_42000408);
      }
    }
LAB_42003c4a:
    uVar2 = uVar2 + 1;
    if (uVar2 == 0x20) {
      FUN_4200330c(PTR_s__3c039338_0x14_42000408);
      return;
    }
  } while( true );
}


