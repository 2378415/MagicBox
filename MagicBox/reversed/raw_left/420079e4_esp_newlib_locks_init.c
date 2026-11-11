// 420079e4  esp_newlib_locks_init  FUN_420079e4  size=90
// strings: handle == (SemaphoreHandle_t) &s_common_mutex | handle == (SemaphoreHandle_t) &s_common_recursiv | esp_newlib_locks_init

void FUN_420079e4(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_30 [12];
  
  iVar1 = DAT_42000880;
  iVar2 = (*(code *)PTR_FUN_420004a8)(1,DAT_42000880);
  if (iVar1 != iVar2) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_locks_c_3c035754_0x18_4200088c,0x172,PTR_s_esp_newlib_locks_init_42000888,
               PTR_s_handle_____SemaphoreHandle_t___s_42000884);
  }
  iVar1 = DAT_42000890;
  iVar2 = (*(code *)PTR_FUN_420004a8)(4,DAT_42000890);
  if (iVar1 != iVar2) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_locks_c_3c035754_0x18_4200088c,0x174,PTR_s_esp_newlib_locks_init_42000888,
               PTR_s_handle_____SemaphoreHandle_t___s_42000894);
  }
  local_30[0] = DAT_42000898;
  (*DAT_4200089c)(local_30,local_30);
  return;
}


