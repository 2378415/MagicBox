// 42005af8  FUN_42005af8  FUN_42005af8  size=68
// strings: core_id >= 0 && core_id < SOC_CPU_CORES_NUM && i | esp_cpu_intr.c | esp_cpu_intr_get_desc

void FUN_42005af8(int param_1,int param_2,undefined4 *param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  (*(code *)PTR_FUN_42000044)
            (PTR_s_esp_cpu_intr_c_3c03205c_0x2d_42000654,0x47,
             PTR_s_esp_cpu_intr_get_desc_3c036f3e_2_42000650,
             PTR_s_core_id_>__0____core_id_<_SOC_CP_4200064c);
  puVar1 = PTR_DAT_42000658;
  puVar2 = (undefined4 *)(PTR_DAT_42000658 + param_2 * 0x10);
  *param_3 = *puVar2;
  param_3[1] = puVar2[1];
  param_3[2] = *(undefined4 *)(puVar1 + (param_2 * 4 + param_1) * 4 + 8);
  return;
}


