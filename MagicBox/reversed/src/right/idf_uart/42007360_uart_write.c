// strings: fd >= 0 && fd < 3 | uart_write | Lk7@

void FUN_42007360(uint param_1,int param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0xe4,PTR_s_uart_write_42000828,
               PTR_s_fd_>__0____fd_<_3_420007f4);
  }
  (*(code *)PTR_FUN_42000818)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0xc);
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    cVar1 = *(char *)(param_2 + uVar2);
    if (((cVar1 != '\n') || (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x14) == 2)) ||
       ((**(code **)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x1c))(param_1,0xd),
       *(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x14) != 1)) {
      (**(code **)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x1c))(param_1,cVar1);
    }
  }
  (*(code *)PTR_FUN_4200081c)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0xc);
  return;
}