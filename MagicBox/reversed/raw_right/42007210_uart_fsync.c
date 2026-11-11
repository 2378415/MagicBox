// 42007210  uart_fsync  FUN_42007210  size=65
// strings: fd >= 0 && fd < 3 | Lk7@

undefined4 FUN_42007210(uint param_1)

{
  int iVar1;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0x194,PTR_s_uart_fsync_42000814,
               PTR_s_fd_>__0____fd_<_3_420007f4);
  }
  iVar1 = *(int *)(PTR_PTR_42000770 + param_1 * 4);
  (*(code *)PTR_FUN_42000818)(iVar1 + 0xc);
  (*DAT_420000e4)(param_1 & 0xff);
  (*(code *)PTR_FUN_4200081c)(iVar1 + 0xc);
  return 0;
}


