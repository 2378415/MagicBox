// 4201779c  gpio_input_disable  FUN_4201779c  size=111
// strings: GPIO number error | gpio_input_disable

void FUN_4201779c(uint param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
          DAT_42000b10 >> (param_1 & 0x1f);
  if ((param_1 >> 5 & 1) != 0) {
    uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
  }
  if ((uVar3 & 1) == 0) {
    puVar2 = (uint *)(param_1 * 4 + DAT_420015c0);
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffdff;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
               PTR_s_gpio_input_disable_420015bc,0xc2,PTR_s_GPIO_number_error_420015a4);
  }
  return;
}


