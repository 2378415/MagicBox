// 4037e934  xTaskGetCurrentTaskHandleForCore  FUN_4037e934  size=39
// strings: ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT

undefined4 FUN_4037e934(uint param_1)

{
  if (1 < param_1) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0x1d2,
                 PTR_s_xTaskGetCurrentTaskHandleForCore_40374fd0,
                 PTR_s_________BaseType_t___xCoreID___>_40374fc4);
  }
  memw();
  return *(undefined4 *)(param_1 * 4 + DAT_40374d64);
}


