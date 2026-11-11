// strings: uart_get_buffered_data_len | uart

undefined4 FUN_4200af20(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 uVar4;
  
  if (param_1 < 3) {
    piVar3 = (int *)(param_1 * 4 + DAT_42000a40);
    if (*piVar3 != 0) {
      puVar2 = PTR_DAT_42000af4 + param_1 * 0x18;
      (*(code *)PTR_FUN_420004dc)(puVar2,0xffffffff);
      *param_2 = *(undefined4 *)(*piVar3 + 0x14);
      (*(code *)PTR_FUN_420004e0)(puVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar4 = 0x61a;
    puVar2 = PTR_DAT_42000af0;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar4 = 0x619;
    puVar2 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar2,uVar1,PTR_DAT_42000a54,
             PTR_s_uart_get_buffered_data_len_42000b8c,uVar4);
  return 0xffffffff;
}