// strings: uart_wait_tx_done | uart | !(is_rs485_mode && disabled && uart_hal_get_intr | uart.c

undefined4 FUN_4200abe0(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int extraout_a3;
  int *piVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  uint in_t0;
  
  if (2 < param_1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar6 = 0x540;
    puVar9 = PTR_DAT_42000a58;
LAB_4200ac1d:
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,puVar9,uVar1,PTR_DAT_42000a54,PTR_s_uart_wait_tx_done_42000b60,
               uVar6);
    return 0xffffffff;
  }
  piVar4 = (int *)(param_1 * 4 + DAT_42000a40);
  if (*piVar4 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar6 = 0x541;
    puVar9 = PTR_DAT_42000af0;
    goto LAB_4200ac1d;
  }
  iVar2 = (*(code *)PTR_FUN_42000b70)();
  iVar3 = (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar4 + 0x6c),param_2);
  if (iVar3 == 0) {
    return 0x107;
  }
  puVar5 = PTR_DAT_42000a3c + param_1 * 0x18 + 0xc;
  (*(code *)PTR_FUN_420004dc)(puVar5,0xffffffff);
  iVar3 = *(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8);
  memw();
  uVar7 = (*(uint *)(iVar3 + 0xc) >> 0xe & 1 ^ 0xffffffff) & 1;
  puVar9 = (undefined *)(uint)(*(int *)(*piVar4 + 0xc) != 1);
  if (((*(uint *)(iVar3 + 0xc) & 0x4000) == 0) && (puVar9 == (undefined *)0x0)) {
    memw();
    if ((*(uint *)(iVar3 + 4) & 0x4000) == 0) goto LAB_4200acba;
    puVar9 = PTR_s___is_rs485_mode____disabled____u_42000b64;
    uVar7 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_c_3c035ef4_0x25_42000b6c,0x551,PTR_s_uart_wait_tx_done_42000b68);
    iVar3 = extraout_a3;
  }
  if ((uVar7 != 0) && (puVar9 != (undefined *)0x0)) {
    memw();
    *(uint *)(iVar3 + 0x10) = DAT_42000a44;
  }
LAB_4200acba:
  (*(code *)PTR_FUN_420004e0)(puVar5);
  piVar4 = (int *)(DAT_42000a40 + param_1 * 4);
  (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar4 + 0x74),0);
  (*DAT_420002b8)(2);
  memw();
  if (((*(uint *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0x1c) >> 0x10 & 0x3ff) == 0) &&
     (memw(), (*(uint *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0x6c) >> 4 & 0xf) == 0))
  {
    (*(code *)PTR_FUN_42000488)(*(undefined4 *)(*piVar4 + 0x6c),0,0,0);
  }
  else {
    (*(code *)PTR_FUN_420004dc)(puVar5,0xffffffff);
    memw();
    memw();
    *(uint *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0xc) =
         *(uint *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0xc) | DAT_42000a44;
    (*(code *)PTR_FUN_420004e0)(puVar5);
    iVar3 = (*(code *)PTR_FUN_42000b70)();
    iVar8 = 0;
    if ((uint)(iVar3 - iVar2) <= param_2) {
      iVar8 = (iVar2 + param_2) - iVar3;
    }
    piVar4 = (int *)(DAT_42000a40 + param_1 * 4);
    iVar2 = (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar4 + 0x74),iVar8);
    (*(code *)PTR_FUN_42000488)(*(undefined4 *)(*piVar4 + 0x6c),0,0);
    if (iVar2 == 0) {
      return 0x107;
    }
  }
  return 0;
}