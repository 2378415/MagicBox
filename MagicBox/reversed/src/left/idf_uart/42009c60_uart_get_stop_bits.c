// strings: uart_get_stop_bits

undefined4 FUN_42009c60(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    puVar3 = PTR_DAT_42000a3c + param_1 * 0x18 + 0xc;
    (*(code *)PTR_FUN_420004dc)(puVar3,0xffffffff);
    FUN_4202d6b8(puVar1 + param_1 * 0x18 + 8,param_2);
    (*(code *)PTR_FUN_420004e0)(puVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar2,PTR_DAT_42000a54,
               PTR_s_uart_get_stop_bits_42000ac8,0x13e);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}