// 4200473c  esp_log_cache_set_level  FUN_4200473c  size=107
// strings: i == 0 || s_log_cache[(i - 1) / 2].generation <  | esp_log_cache_set_level

void FUN_4200473c(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = DAT_42000574;
  puVar4 = (undefined4 *)*DAT_42000578;
  if (puVar4 != (undefined4 *)0x0) {
    puVar3 = DAT_42000574;
    puVar5 = (undefined4 *)0x0;
    while (iVar2 = (*DAT_42000568)(*puVar3,param_1), iVar2 != 0) {
      puVar6 = (undefined4 *)((int)puVar5 + 1);
      puVar3 = puVar3 + 2;
      if (puVar4 == puVar6) {
        return;
      }
      puVar5 = puVar1 + ((uint)puVar5 & 0xfffffffe);
      if ((uint)puVar5[1] >> 3 < (uint)puVar1[(int)puVar6 * 2 + 1] >> 3) {
        puVar5 = puVar6;
      }
      else {
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_log_binary_heap_c_3c032f7c_0x37_42000584,0x54,
                   PTR_s_esp_log_cache_set_level_42000580,
                   PTR_s_i____0____s_log_cache__i___1____2_4200057c);
      }
    }
    puVar1[(int)puVar5 * 2 + 1] = puVar1[(int)puVar5 * 2 + 1] & 0xfffffff8 | param_2 & 7;
  }
  return;
}


