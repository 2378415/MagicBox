// 42009bac  uart_get_word_length  FUN_42009bac  size=61
// strings: uart_get_word_length

undefined4 FUN_42009bac(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    FUN_4202d6ec(PTR_DAT_42000abc + param_1 * 0x18,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar1,PTR_DAT_42000a54,
               PTR_s_uart_get_word_length_42000ab8,0x12d);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


