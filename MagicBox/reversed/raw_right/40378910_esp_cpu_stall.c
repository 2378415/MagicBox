// 40378910  esp_cpu_stall  FUN_40378910  size=130
// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM

void FUN_40378910(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (1 < param_1) {
    FUN_40381d9c(PTR_s_cpu_c_3c031620_0x20_40374908,0x21,PTR_s_esp_cpu_stall_40374904,
                 PTR_s_core_id_>__0____core_id_<_SOC_CP_40374900);
  }
  puVar1 = DAT_4037490c;
  if (param_1 == 0) {
    iVar5 = 2;
    uVar3 = 0xc;
    iVar4 = 0x1a;
    uVar2 = DAT_403748f8;
  }
  else {
    iVar5 = 0;
    uVar3 = 3;
    iVar4 = 0x14;
    uVar2 = DAT_403748fc;
  }
  memw();
  memw();
  *DAT_4037490c = uVar3 & *DAT_4037490c ^ *DAT_4037490c;
  memw();
  memw();
  *puVar1 = *puVar1 | 2 << 0x20 - (0x20 - iVar5);
  puVar1 = DAT_40374910;
  memw();
  memw();
  *DAT_40374910 = uVar2 & *DAT_40374910 ^ *DAT_40374910;
  memw();
  memw();
  *puVar1 = *puVar1 | 0x21 << 0x20 - (0x20 - iVar4);
  return;
}


