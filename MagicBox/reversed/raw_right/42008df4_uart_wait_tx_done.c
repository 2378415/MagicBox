// 42008df4  uart_wait_tx_done  FUN_42008df4  size=385
// strings: !(is_rs485_mode && disabled && uart_hal_get_intr | uart.c | uart_wait_tx_done

undefined4 FUN_42008df4(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  ulonglong uVar10;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      iVar2 = (*(code *)PTR_FUN_420008f8)();
      iVar3 = (*(code *)PTR_FUN_42000350)
                        (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x6c),param_2);
      puVar9 = PTR_DAT_42000848;
      if (iVar3 == 0) {
        uVar5 = 0x107;
      }
      else {
        puVar6 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
        (*(code *)PTR_FUN_420003a8)(puVar6,0xffffffff);
        puVar9 = *(undefined **)(puVar9 + param_1 * 0x18 + 8);
        memw();
        uVar7 = *(uint *)(puVar9 + 0xc) >> 0xe & 1;
        uVar8 = (uint)(uVar7 == 0);
        bVar1 = *(int *)(*(int *)(param_1 * 4 + DAT_42000844) + 0xc) != 1;
        uVar10 = (ulonglong)CONCAT14(bVar1,uVar8);
        if ((!bVar1 && uVar7 == 0) &&
           (memw(), uVar10 = (ulonglong)CONCAT14(bVar1,uVar8), (*(uint *)(puVar9 + 4) & 0x4000) != 0
           )) {
          puVar9 = PTR_s_uart_wait_tx_done_420008f0;
          uVar10 = (*(code *)PTR_FUN_42000044)
                             (PTR_s_uart_c_3c033104_0x25_420008f4,0x551,
                              PTR_s_uart_wait_tx_done_420008f0,
                              PTR_s___is_rs485_mode____disabled____u_420008ec);
        }
        if (((uint)uVar10 & (uint)(uVar10 >> 0x20)) != 0) {
          memw();
          *(uint *)(puVar9 + 0x10) = DAT_42000874;
        }
        (*(code *)PTR_FUN_420003ac)(puVar6);
        (*(code *)PTR_FUN_42000350)(*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x74),0);
        (*DAT_42000078)(2);
        memw();
        if (((*(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x1c) >> 0x10 & 0x3ff) ==
             0) && (memw(), (*(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x6c) >> 4
                            & 0xf) == 0)) {
          (*(code *)PTR_FUN_42000358)
                    (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x6c),0,0);
          uVar5 = 0;
        }
        else {
          (*(code *)PTR_FUN_420003a8)(puVar6,0xffffffff);
          memw();
          memw();
          *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) =
               *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) | DAT_42000874;
          (*(code *)PTR_FUN_420003ac)(puVar6);
          iVar3 = (*(code *)PTR_FUN_420008f8)();
          if (param_2 < (uint)(iVar3 - iVar2)) {
            iVar2 = 0;
          }
          else {
            iVar2 = param_2 + (iVar2 - iVar3);
          }
          piVar4 = (int *)(param_1 * 4 + DAT_42000844);
          iVar2 = (*(code *)PTR_FUN_42000350)(*(undefined4 *)(*piVar4 + 0x74),iVar2);
          (*(code *)PTR_FUN_42000358)(*(undefined4 *)(*piVar4 + 0x6c),0,0);
          if (iVar2 == 0) {
            uVar5 = 0x107;
          }
          else {
            uVar5 = 0;
          }
        }
      }
    }
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


