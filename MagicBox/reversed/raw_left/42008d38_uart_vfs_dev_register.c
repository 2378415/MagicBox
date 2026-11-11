// 42008d38  uart_vfs_dev_register  FUN_42008d38  size=40
// strings: esp_vfs_register_fs('/dev/uart', &s_vfs_uart, ES

int FUN_42008d38(void)

{
  int iVar1;
  
  iVar1 = FUN_4200bf74(PTR_s__dev_uart_42000a0c,PTR_PTR_42000a08,8,0);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000a1c)
              (iVar1,PTR_s__IDF_components_esp_driver_uart__42000a18,0x43b,
               PTR_s_uart_vfs_dev_register_42000a14,PTR_s_esp_vfs_register_fs___dev_uart___42000a10)
    ;
  }
  return iVar1;
}


