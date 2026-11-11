// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM && i | esp_cpu_intr.c | esp_cpu_intr_get_desc

/* (1 unreachable decompiler blocks omitted) */

void FUN_4200779c(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  (*(code *)PTR_FUN_420000a8)
            (PTR_s_esp_cpu_intr_c_3c0347f0_0x2d_42000840,0x47,
             PTR_s_esp_cpu_intr_get_desc_3c03d1ae_2_4200083c,
             PTR_s_core_id_>__0____core_id_<_SOC_CP_42000838);
  uVar2 = *(undefined4 *)((int)(PTR_DAT_42000844 + param_2 * 0x10) + 4);
  uVar1 = *(undefined4 *)(PTR_DAT_42000844 + (param_2 * 4 + param_1) * 4 + 8);
  *param_3 = *(undefined4 *)(PTR_DAT_42000844 + param_2 * 0x10);
  param_3[1] = uVar2;
  param_3[2] = uVar1;
  return;
}