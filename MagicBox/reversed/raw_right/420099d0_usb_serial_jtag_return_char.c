// 420099d0  usb_serial_jtag_return_char  FUN_420099d0  size=36
// strings: s_ctx.peek_char == NONE

void FUN_420099d0(undefined4 param_1,undefined4 param_2)

{
  if (*(int *)PTR_DAT_42000920 != -1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_usb_serial_jtag_vfs_c_3c033148_0x30_42000944,0xdf,
               PTR_s_usb_serial_jtag_return_char_42000940,PTR_s_s_ctx_peek_char____NONE_4200093c);
  }
  *(undefined4 *)PTR_DAT_42000920 = param_2;
  return;
}


