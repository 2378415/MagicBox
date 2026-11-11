// 42008c3c  uart_fstat  FUN_42008c3c  size=45
// strings: fd >= 0 && fd < 3

undefined4 FUN_42008c3c(uint param_1,int param_2)

{
  if (2 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0x15a,PTR_s_uart_fstat_420009f4,
               PTR_s_fd_>__0____fd_<_3_420009e8);
  }
  (*DAT_42000094)(param_2,0,0x58);
  *(undefined4 *)(param_2 + 4) = DAT_420009f8;
  return 0;
}


