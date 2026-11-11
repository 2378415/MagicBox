// 4201780c  gpio_pullup_en  FUN_4201780c  size=152
// strings: GPIO number error | gpio_pullup_en

uint FUN_4201780c(uint param_1)

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
      FUN_42018a24(param_1);
      (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
      puVar1 = PTR_DAT_420015a8;
      memw();
      memw();
      **(uint **)(PTR_DAT_420015ac + param_1 * 4) =
           **(uint **)(PTR_DAT_420015ac + param_1 * 4) | 0x100;
      (*(code *)PTR_FUN_420004e0)(puVar1);
      return uVar3 & 1;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_pullup_en_420015c4,0x4e,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}


