// strings: handle == (SemaphoreHandle_t) &s_common_mutex | handle == (SemaphoreHandle_t) &s_common_recursiv | esp_newlib_locks_init

void FUN_42005d88(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_30 [12];
  
  iVar1 = DAT_420006a4;
  iVar2 = (*(code *)PTR_FUN_42000378)(1,DAT_420006a4);
  if (iVar1 != iVar2) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_locks_c_3c032e6c_0x18_420006b0,0x172,PTR_s_esp_newlib_locks_init_420006ac,
               PTR_s_handle_____SemaphoreHandle_t___s_420006a8);
  }
  iVar1 = DAT_420006b4;
  iVar2 = (*(code *)PTR_FUN_42000378)(4,DAT_420006b4);
  if (iVar1 != iVar2) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_locks_c_3c032e6c_0x18_420006b0,0x174,PTR_s_esp_newlib_locks_init_420006ac,
               PTR_s_handle_____SemaphoreHandle_t___s_420006b8);
  }
  local_30[0] = DAT_420006bc;
  (*DAT_420006c0)(local_30,local_30);
  return;
}