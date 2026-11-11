// 42008c88  uart_fsync  FUN_42008c88  size=62
// strings: fd >= 0 && fd < 3 | Pm7@L

undefined4 FUN_42008c88(uint param_1)

{
  int iVar1;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0x194,PTR_s_uart_fsync_42000a00,
               PTR_s_fd_>__0____fd_<_3_420009e8);
  }
  iVar1 = *(int *)(PTR_PTR_42000978 + param_1 * 4);
  (*(code *)PTR_FUN_420000b8)(iVar1 + 0xc);
  (*DAT_42000200)(param_1);
  (*(code *)PTR_FUN_420000bc)(iVar1 + 0xc);
  return 0;
}


