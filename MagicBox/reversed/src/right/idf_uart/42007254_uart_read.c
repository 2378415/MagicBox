// strings: fd >= 0 && fd < 3 | uart_read | c != NONE | Lk7@

uint FUN_42007254(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,0x111,PTR_s_uart_read_42000820,
               PTR_s_fd_>__0____fd_<_3_420007f4);
  }
  iVar5 = *(int *)(PTR_PTR_42000770 + param_1 * 4);
  (*(code *)PTR_FUN_42000818)(iVar5 + 8);
  if (*(char *)(iVar5 + 0x10) == '\0') {
    iVar5 = FUN_42006518(param_1);
  }
  else {
    iVar5 = -1;
  }
  uVar1 = (**(code **)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x24))(param_1);
  if (iVar5 != -1) {
    uVar1 = uVar1 + 1;
  }
  if (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 4) != -1) {
    uVar1 = uVar1 + 1;
  }
  uVar2 = (uVar1 < param_3) * uVar1 + (uVar1 >= param_3) * param_3;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = 0;
    do {
      if ((iVar5 == -1) && (iVar5 = FUN_42006518(param_1), iVar5 == -1)) {
        (*(code *)PTR_FUN_42000044)
                  (PTR_s_uart_vfs_c_3c032fb4_0x25_420007fc,299,PTR_s_uart_read_42000820,
                   PTR_s_c____NONE_42000824);
      }
      if (iVar5 == 0xd) {
        if (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) == 1) {
          iVar5 = 10;
        }
        else if (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) == 0) {
          iVar3 = FUN_42006518(param_1);
          if (iVar3 == -1) {
            FUN_420071e8(param_1,0xd);
            goto LAB_42007341;
          }
          if (iVar3 == 10) {
            iVar5 = 10;
            uVar2 = uVar2 - 1;
          }
          else {
            FUN_420071e8(param_1,iVar3);
          }
        }
      }
      *(char *)(param_2 + uVar1) = (char)iVar5;
      uVar1 = uVar1 + 1;
      iVar5 = -1;
    } while (uVar1 < uVar2);
  }
  if (iVar5 != -1) {
    FUN_420071e8(param_1,iVar5);
  }
LAB_42007341:
  (*(code *)PTR_FUN_4200081c)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 8);
  if (uVar1 == 0) {
    puVar4 = (undefined4 *)FUN_420180e4();
    *puVar4 = 0xb;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}