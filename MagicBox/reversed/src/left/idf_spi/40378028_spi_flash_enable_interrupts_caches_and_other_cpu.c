// strings: cpuid == s_flash_op_cpu | !(xTaskGetSchedulerState() == taskSCHEDULER_NOT_ | cache_utils.c | spi_flash_enable_interrupts_caches_and_other_cpu

void FUN_40378028(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  puVar1 = PTR_DAT_403748c0;
  uVar4 = rsr(in_PRID);
  memw();
  uVar3 = *(uint *)PTR_DAT_403748c0;
  if (uVar3 != (uVar4 >> 0xd & 1)) {
    FUN_40381ce4(PTR_s_cache_utils_c_3c03a2ac_0x1b_403748bc,0xe2,
                 PTR_s_spi_flash_enable_interrupts_cach_403748dc,
                 PTR_s_cpuid____s_flash_op_cpu_403748d8);
  }
  iVar2 = FUN_4037e0e0();
  if ((uVar3 != 0) && (iVar2 == 1)) {
    FUN_40381ce4(PTR_s_cache_utils_c_3c03a2ac_0x1b_403748bc,0xe4,
                 PTR_s_spi_flash_enable_interrupts_cach_403748dc,
                 PTR_s___xTaskGetSchedulerState______ta_403748e0);
  }
  memw();
  *(undefined4 *)puVar1 = 0xffffffff;
  FUN_40377f14();
  iVar2 = FUN_4037e0e0();
  if (iVar2 != 1) {
    memw();
    *DAT_403748a8 = 1;
  }
  FUN_403769b0();
  iVar2 = FUN_4037e0e0();
  if (iVar2 != 1) {
    FUN_4037d8a0();
  }
  (*(code *)PTR_FUN_403748e4)();
  return;
}