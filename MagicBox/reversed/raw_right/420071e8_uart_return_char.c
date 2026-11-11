// 420071e8  uart_return_char  FUN_420071e8  size=38
// strings: s_ctx[fd]->peek_char == NONE

void FUN_420071e8(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_t0;
  
  iVar1 = *(int *)(PTR_PTR_42000770 + param_1 * 4);
  if (*(int *)(iVar1 + 4) != -1) {
    iVar1 = in_t0;
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0x10b,PTR_s_uart_return_char_42000810,
               PTR_s_s_ctx_fd__>peek_char____NONE_4200080c);
  }
  *(undefined4 *)(iVar1 + 4) = param_2;
  return;
}


