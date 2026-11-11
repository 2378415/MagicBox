// 42008be4  uart_fcntl  FUN_42008be4  size=85
// strings: fd >= 0 && fd < 3

undefined4 FUN_42008be4(uint param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0x168,PTR_s_uart_fcntl_420009ec,
               PTR_s_fd_>__0____fd_<_3_420009e8);
  }
  if (param_2 == 3) {
    uVar2 = 2;
    if (*(char *)(*(int *)(PTR_PTR_42000978 + param_1 * 4) + 0x10) != '\0') {
      uVar2 = DAT_420009e4;
    }
  }
  else if (param_2 == 4) {
    *(byte *)(*(int *)(PTR_PTR_42000978 + param_1 * 4) + 0x10) = (byte)(param_3 >> 0xe) & 1;
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x58;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


