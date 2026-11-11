// 42009b38  uart_set_word_length  FUN_42009b38  size=115
// strings: uart_set_word_length | uart

undefined4 FUN_42009b38(uint param_1,uint param_2)

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
      FUN_4202d6cc(puVar4 + param_1 * 0x18 + 8,param_2);
      (*(code *)PTR_FUN_420004e0)(puVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x124;
    puVar4 = PTR_DAT_42000ab4;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x123;
    puVar4 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar4,uVar1,PTR_DAT_42000a54,PTR_s_uart_set_word_length_42000ab0,
             uVar3);
  return 0xffffffff;
}


