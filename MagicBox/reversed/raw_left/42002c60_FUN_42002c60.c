// 42002c60  FUN_42002c60  FUN_42002c60  size=40
// strings: flash_ret == ESP_OK

int FUN_42002c60(void)

{
  int iVar1;
  
  FUN_42019bf4();
  iVar1 = FUN_42019ab8();
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_startup_funcs_c_3c0308a8_0x1c_42000188,0x5f,
               PTR_s___esp_system_init_fn_init_flash_3c03c443_1_42000184,
               PTR_s_flash_ret____ESP_OK_42000180);
  }
  (*(code *)PTR_FUN_4200018c)();
  return iVar1;
}


