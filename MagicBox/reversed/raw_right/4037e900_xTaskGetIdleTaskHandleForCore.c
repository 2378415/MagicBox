// 4037e900  xTaskGetIdleTaskHandleForCore  FUN_4037e900  size=52
// strings: ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT | ( xIdleTaskHandle[ xCoreID ] != ((void *)0) ) | freertos_tasks_c_additions.h | xTaskGetIdleTaskHandleForCore

void FUN_4037e900(uint param_1)

{
  if (1 < param_1) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0x1c4,
                 PTR_s_xTaskGetIdleTaskHandleForCore_40374fc8,
                 PTR_s_________BaseType_t___xCoreID___>_40374fc4);
  }
  if (*(int *)(param_1 * 4 + DAT_40374fb0) == 0) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0x1c5,
                 PTR_s_xTaskGetIdleTaskHandleForCore_40374fc8,
                 PTR_s___xIdleTaskHandle__xCoreID________40374fcc);
  }
  return;
}


