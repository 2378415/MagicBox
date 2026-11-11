// strings: /IDF/components/esp_system/task_wdt/task_wdt.c | subscribe_idle | esp_register_freertos_idle_hook_for_cpu(idle_hoo | idle_task_handle | esp_task_wdt_add(idle_task_handle)

void FUN_42019f30(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_420018b4;
  if (param_1 != 0) {
    iVar3 = 0;
    do {
      for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = (*(code *)PTR_FUN_420018bc)(iVar3);
      if (iVar2 == 0) {
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_task_wdt_c_3c03aad8_0x25_4200188c,0x133,PTR_s_subscribe_idle_420018a8,
                   PTR_s_idle_task_handle_420018a4);
      }
      iVar2 = FUN_42019ee4();
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_42000a1c)
                  (iVar2,PTR_s__IDF_components_esp_system_task__420018b0,0x134,
                   PTR_s_subscribe_idle_420018a8,PTR_s_esp_task_wdt_add_idle_task_handl_420018ac);
      }
      iVar2 = FUN_42004048(puVar1,iVar3);
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_42000a1c)
                  (iVar2,PTR_s__IDF_components_esp_system_task__420018b0,0x135,
                   PTR_s_subscribe_idle_420018a8,PTR_s_esp_register_freertos_idle_hook__420018b8);
      }
      param_1 = param_1 >> 1;
      iVar3 = iVar3 + 1;
    } while (param_1 != 0);
  }
  return;
}