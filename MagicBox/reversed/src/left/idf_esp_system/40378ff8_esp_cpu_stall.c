// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM

void FUN_40378ff8(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (1 < param_1) {
    FUN_40381ce4(PTR_s_cpu_c_3c033be4_0x20_403749d0,0x21,PTR_s_esp_cpu_stall_403749cc,
                 PTR_s_core_id_>__0____core_id_<_SOC_CP_403749c8);
  }
  puVar2 = DAT_403749d8;
  puVar1 = DAT_403749d4;
  if (param_1 == 0) {
    uVar3 = 8;
    uVar4 = 0xfffffff3;
    uVar5 = DAT_403749b8;
    uVar6 = DAT_403749bc;
  }
  else {
    uVar3 = 2;
    uVar4 = 0xfffffffc;
    uVar5 = DAT_403749c0;
    uVar6 = DAT_403749c4;
  }
  memw();
  memw();
  *DAT_403749d4 = uVar4 & *DAT_403749d4;
  memw();
  memw();
  *puVar1 = uVar3 | *puVar1;
  memw();
  memw();
  *puVar2 = *puVar2 & uVar6;
  memw();
  memw();
  *puVar2 = *puVar2 | uVar5;
  return;
}