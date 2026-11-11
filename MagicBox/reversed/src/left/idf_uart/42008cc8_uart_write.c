// strings: fd >= 0 && fd < 3 | uart_write | Pm7@L

void FUN_42008cc8(uint param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0xe4,PTR_s_uart_write_42000a04,
               PTR_s_fd_>__0____fd_<_3_420009e8);
  }
  piVar4 = (int *)(PTR_PTR_42000978 + param_1 * 4);
  iVar2 = *piVar4;
  (*(code *)PTR_FUN_420000b8)(iVar2 + 0xc);
  if (param_3 != 0) {
    pcVar3 = param_2 + param_3;
    do {
      cVar1 = *param_2;
      if ((cVar1 == '\n') && (*(int *)(iVar2 + 0x14) != 2)) {
        (**(code **)(iVar2 + 0x1c))(param_1,0xd);
        if (*(int *)(iVar2 + 0x14) != 1) goto LAB_42008d02;
      }
      else {
LAB_42008d02:
        (**(code **)(*piVar4 + 0x1c))(param_1,cVar1);
      }
      param_2 = param_2 + 1;
    } while (param_2 != pcVar3);
  }
  (*(code *)PTR_FUN_420000bc)(iVar2 + 0xc);
  return;
}