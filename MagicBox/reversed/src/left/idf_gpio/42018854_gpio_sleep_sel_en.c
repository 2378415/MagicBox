// strings: GPIO number error | gpio_sleep_sel_en

uint FUN_42018854(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (-1 < (int)param_1) {
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
      **(uint **)(PTR_DAT_420015ac + param_1 * 4) = **(uint **)(PTR_DAT_420015ac + param_1 * 4) | 2;
      (*(code *)PTR_FUN_420004e0)(puVar1);
      return uVar3 & 1;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_sleep_sel_en_42001670,0x3ae,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}