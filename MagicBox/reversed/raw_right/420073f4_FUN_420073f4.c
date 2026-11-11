// 420073f4  FUN_420073f4  FUN_420073f4  size=38
// strings: esp_vfs_register_fs('/dev/uart', &s_vfs_uart, ES

void FUN_420073f4(void)

{
  int iVar1;
  
  iVar1 = FUN_42009f0c(PTR_s__dev_uart_42000830,PTR_PTR_4200082c,8,0);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000840)
              (iVar1,PTR_s__IDF_components_esp_driver_uart__4200083c,0x43b,
               PTR_s_uart_vfs_dev_register_42000838,PTR_s_esp_vfs_register_fs___dev_uart___42000834)
    ;
  }
  return;
}


