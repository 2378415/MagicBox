// 42001658  FUN_42001658  FUN_42001658  size=39
// strings: flash_ret == ESP_OK

undefined4 FUN_42001658(void)

{
  int iVar1;
  
  FUN_42012b50();
  iVar1 = FUN_42012aa8();
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_startup_funcs_c_3c030134_0x1c_42000040,0x5f,
               PTR_s___esp_system_init_fn_init_flash_4200003c,PTR_s_flash_ret____ESP_OK_42000038);
  }
  (*(code *)PTR_FUN_42000048)();
  return 0;
}


