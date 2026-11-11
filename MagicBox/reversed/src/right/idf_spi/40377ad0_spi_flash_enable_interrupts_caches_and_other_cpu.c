// strings: cpuid == s_flash_op_cpu | !(xTaskGetSchedulerState() == taskSCHEDULER_NOT_ | cache_utils.c | spi_flash_enable_interrupts_caches_and_other_cpu

void FUN_40377ad0(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  if (*(uint *)PTR_DAT_40374838 != uVar2) {
    FUN_40381d9c(PTR_s_cache_utils_c_3c034168_0x1b_40374834,0xe2,
                 PTR_s_spi_flash_enable_interrupts_cach_40374860,
                 PTR_s_cpuid____s_flash_op_cpu_4037485c);
  }
  iVar1 = FUN_4037db0c();
  if ((iVar1 == 1) && (uVar2 != 0)) {
    FUN_40381d9c(PTR_s_cache_utils_c_3c034168_0x1b_40374834,0xe4,
                 PTR_s_spi_flash_enable_interrupts_cach_40374860,
                 PTR_s___xTaskGetSchedulerState______ta_40374864);
  }
  memw();
  *(undefined4 *)PTR_DAT_40374838 = 0xffffffff;
  FUN_40377a78(uVar2,*(undefined4 *)(uVar2 * 4 + DAT_4037484c));
  iVar1 = FUN_4037db0c();
  if (iVar1 != 1) {
    memw();
    *DAT_40374858 = 1;
  }
  FUN_4037660c();
  iVar1 = FUN_4037db0c();
  if (iVar1 != 1) {
    FUN_4037dc74();
  }
  (*(code *)PTR_FUN_40374868)();
  return;
}