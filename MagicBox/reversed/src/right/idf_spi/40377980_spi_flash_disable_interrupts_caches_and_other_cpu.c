// strings: esp_task_stack_is_sane_cache_disabled() | s_flash_op_cpu == -1 | spi_flash_disable_interrupts_caches_and_other_cp | other_cpuid == 1

void FUN_40377980(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_PRID;
  undefined1 auStack_20 [32];
  
  if ((DAT_40374828 < auStack_20 + DAT_4037466c) && (DAT_403745dc < auStack_20 + DAT_403745d8)) {
    FUN_40381d9c(PTR_s_cache_utils_c_3c034168_0x1b_40374834,0x98,
                 PTR_s_spi_flash_disable_interrupts_cac_40374830,
                 PTR_s_esp_task_stack_is_sane_cache_dis_4037482c);
  }
  (*(code *)PTR_FUN_40374850)();
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  if (*(int *)PTR_DAT_40374838 != -1) {
    FUN_40381d9c(PTR_s_cache_utils_c_3c034168_0x1b_40374834,0xa0,
                 PTR_s_spi_flash_disable_interrupts_cac_40374830,PTR_s_s_flash_op_cpu_____1_4037483c
                );
  }
  memw();
  *(uint *)PTR_DAT_40374838 = uVar2;
  iVar1 = FUN_4037db0c();
  if (iVar1 == 1) {
    uVar3 = 0;
    if (uVar2 == 0) goto LAB_40377a3f;
    FUN_40381d9c(PTR_s_cache_utils_c_3c034168_0x1b_40374834,0xaa,
                 PTR_s_spi_flash_disable_interrupts_cac_40374830,PTR_s_other_cpuid____1_40374840);
  }
  while( true ) {
    FUN_4037d194();
    uVar2 = rsr(in_PRID);
    uVar3 = uVar2 >> 0xd & 1;
    memw();
    *(uint *)PTR_DAT_40374838 = uVar3;
    memw();
    *DAT_40374844 = '\0';
    iVar1 = (*(code *)PTR_FUN_40374854)(uVar3 == 0,PTR_LAB_40374848,uVar3 == 0);
    if (iVar1 == 0) break;
    FUN_4037dc74();
  }
  do {
    memw();
  } while (*DAT_40374844 == '\0');
LAB_40377a3f:
  FUN_40376598();
  FUN_40377970(uVar3,uVar3 * 4 + DAT_4037484c);
  return;
}