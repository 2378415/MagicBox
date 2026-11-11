// strings: esp_task_stack_is_sane_cache_disabled() | s_flash_op_cpu == -1 | spi_flash_disable_interrupts_caches_and_other_cp | other_cpuid == 1

void FUN_40377f70(void)

{
  char *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined1 auStack_20 [32];
  
  if ((DAT_403748b0 < auStack_20 + DAT_403746c4) && (DAT_40374608 < auStack_20 + DAT_40374604)) {
    FUN_40381ce4(PTR_s_cache_utils_c_3c03a2ac_0x1b_403748bc,0x98,
                 PTR_s_spi_flash_disable_interrupts_cac_403748b8,
                 PTR_s_esp_task_stack_is_sane_cache_dis_403748b4);
  }
  (*(code *)PTR_FUN_403748d0)();
  puVar2 = PTR_DAT_403748c0;
  uVar5 = rsr(in_PRID);
  uVar5 = uVar5 >> 0xd & 1;
  memw();
  if (*(int *)PTR_DAT_403748c0 != -1) {
    FUN_40381ce4(PTR_s_cache_utils_c_3c03a2ac_0x1b_403748bc,0xa0,
                 PTR_s_spi_flash_disable_interrupts_cac_403748b8,PTR_s_s_flash_op_cpu_____1_403748c4
                );
  }
  memw();
  *(uint *)puVar2 = uVar5;
  iVar4 = FUN_4037e0e0();
  puVar3 = PTR_LAB_403748cc;
  pcVar1 = DAT_403748ac;
  if (iVar4 == 1) {
    if (uVar5 == 0) goto LAB_40378020;
    FUN_40381ce4(PTR_s_cache_utils_c_3c03a2ac_0x1b_403748bc,0xaa,
                 PTR_s_spi_flash_disable_interrupts_cac_403748b8,PTR_s_other_cpuid____1_403748c8);
  }
  while( true ) {
    FUN_4037d530();
    uVar5 = rsr(in_PRID);
    uVar5 = uVar5 >> 0xd & 1;
    memw();
    *(uint *)puVar2 = uVar5;
    memw();
    *pcVar1 = '\0';
    iVar4 = (*(code *)PTR_FUN_403748d4)(uVar5 == 0,puVar3,uVar5 == 0);
    if (iVar4 == 0) break;
    FUN_4037d8a0();
  }
  do {
    memw();
  } while (*pcVar1 == '\0');
LAB_40378020:
  FUN_4037695c();
  FUN_40377ef4();
  return;
}