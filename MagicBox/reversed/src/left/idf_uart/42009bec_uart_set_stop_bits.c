// strings: uart_set_stop_bits | uart

undefined4 FUN_42009bec(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar4 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    if (param_2 < 4) {
      puVar2 = PTR_DAT_42000a3c + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420004dc)(puVar2,0xffffffff);
      FUN_4202d698(puVar4 + param_1 * 0x18 + 8,param_2);
      (*(code *)PTR_FUN_420004e0)(puVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x135;
    puVar4 = PTR_DAT_42000ac4;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x134;
    puVar4 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar4,uVar1,PTR_DAT_42000a54,PTR_s_uart_set_stop_bits_42000ac0,
             uVar3);
  return 0xffffffff;
}