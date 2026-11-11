// strings: GPIO number error | gpio_sleep_pulldown_en

void FUN_42017604(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
          DAT_42000b10 >> (param_1 & 0x1f);
  if ((param_1 >> 5 & 1) != 0) {
    uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
  }
  if ((uVar3 & 1) == 0) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
    puVar1 = PTR_DAT_420015a8;
    memw();
    memw();
    **(uint **)(PTR_DAT_420015ac + param_1 * 4) = **(uint **)(PTR_DAT_420015ac + param_1 * 4) | 4;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
               PTR_s_gpio_sleep_pulldown_en_420015b0,0x33e,PTR_s_GPIO_number_error_420015a4);
  }
  return;
}