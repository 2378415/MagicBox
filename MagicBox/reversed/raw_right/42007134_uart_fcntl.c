// 42007134  uart_fcntl  FUN_42007134  size=89
// strings: fd >= 0 && fd < 3

undefined4 FUN_42007134(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0x168,PTR_s_uart_fcntl_420007f8,
               PTR_s_fd_>__0____fd_<_3_420007f4);
  }
  if (param_2 == 3) {
    if (*(char *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x10) == '\0') {
      uVar1 = 2;
    }
    else {
      uVar1 = DAT_420007f0;
    }
  }
  else if (param_2 == 4) {
    *(byte *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x10) = (byte)(param_3 >> 0xe) & 1;
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x58;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


