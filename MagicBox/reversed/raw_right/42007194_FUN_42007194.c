// 42007194  FUN_42007194  FUN_42007194  size=49
// strings: fd >= 0 && fd < 3

undefined4 FUN_42007194(uint param_1,int param_2)

{
  if (2 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0x15a,PTR_s_uart_fstat_42000800,
               PTR_s_fd_>__0____fd_<_3_420007f4);
  }
  (*DAT_42000240)(param_2,0,0x58);
  *(undefined4 *)(param_2 + 4) = DAT_42000804;
  return 0;
}


