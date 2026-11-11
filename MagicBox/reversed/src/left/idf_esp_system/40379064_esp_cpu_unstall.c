// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM

void FUN_40379064(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (1 < param_1) {
    FUN_40381ce4(PTR_s_cpu_c_3c033be4_0x20_403749d0,0x29,PTR_s_esp_cpu_unstall_403749dc,
                 PTR_s_core_id_>__0____core_id_<_SOC_CP_403749c8);
  }
  uVar2 = DAT_403749c4;
  uVar1 = DAT_403749bc;
  memw();
  if (param_1 == 0) {
    memw();
    *DAT_403749d4 = *DAT_403749d4 & 0xfffffff3;
    uVar2 = uVar1;
  }
  else {
    memw();
    *DAT_403749d4 = *DAT_403749d4 & 0xfffffffc;
  }
  memw();
  memw();
  *DAT_403749d8 = uVar2 & *DAT_403749d8;
  return;
}