// strings: idle_task_handle | esp_task_wdt_add(idle_task_handle) | /IDF/components/esp_system/task_wdt/task_wdt.c | subscribe_idle | esp_register_freertos_idle_hook_for_cpu(idle_hoo

void FUN_42012e5c(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    if ((param_1 & 1) != 0) {
      iVar1 = (*(code *)PTR_FUN_42000fb4)(iVar2);
      if (iVar1 == 0) {
        (*(code *)PTR_FUN_42000044)
                  (PTR_s_task_wdt_c_3c034434_0x25_42000f88,0x133,PTR_s_subscribe_idle_42000fa0,
                   PTR_s_idle_task_handle_42000f9c);
      }
      iVar1 = FUN_42012e30();
      if (iVar1 != 0) {
        (*(code *)PTR_FUN_42000840)
                  (iVar1,PTR_s__IDF_components_esp_system_task__42000fa8,0x134,
                   PTR_s_subscribe_idle_42000fa0,PTR_s_esp_task_wdt_add_idle_task_handl_42000fa4);
      }
      iVar1 = FUN_42002a44(PTR_FUN_42000fac,iVar2);
      if (iVar1 != 0) {
        (*(code *)PTR_FUN_42000840)
                  (iVar1,PTR_s__IDF_components_esp_system_task__42000fa8,0x135,
                   PTR_s_subscribe_idle_42000fa0,PTR_s_esp_register_freertos_idle_hook__42000fb0);
      }
    }
    iVar2 = iVar2 + 1;
  }
  return;
}