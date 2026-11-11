// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM

void FUN_40378994(uint param_1)

{
  uint uVar1;
  
  if (1 < param_1) {
    FUN_40381d9c(PTR_s_cpu_c_3c031620_0x20_40374908,0x29,PTR_s_esp_cpu_unstall_40374914,
                 PTR_s_core_id_>__0____core_id_<_SOC_CP_40374900);
  }
  if (param_1 == 0) {
    uVar1 = 0xc;
  }
  else {
    uVar1 = 3;
  }
  memw();
  memw();
  *DAT_4037490c = uVar1 & *DAT_4037490c ^ *DAT_4037490c;
  if (param_1 == 0) {
    uVar1 = DAT_403748f8;
  }
  else {
    uVar1 = DAT_403748fc;
  }
  memw();
  memw();
  *DAT_40374910 = uVar1 & *DAT_40374910 ^ *DAT_40374910;
  return;
}