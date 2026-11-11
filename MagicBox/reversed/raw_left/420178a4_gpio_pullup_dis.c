// 420178a4  gpio_pullup_dis  FUN_420178a4  size=188
// strings: GPIO number error | gpio_pullup_dis

uint FUN_420178a4(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (-1 < (int)param_1) {
    uVar4 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar4 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar4 & 1) == 0) {
      FUN_42018a24(param_1);
      (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
      puVar3 = DAT_420015cc;
      if (param_1 == 0x14) {
        memw();
        memw();
        *DAT_420015cc = *DAT_420015cc | 0x100;
        memw();
        memw();
        *puVar3 = *puVar3 & 0xfffffdff;
      }
      puVar1 = PTR_DAT_420015a8;
      puVar3 = (uint *)(param_1 * 4 + DAT_420015c0);
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffffeff;
      (*(code *)PTR_FUN_420004e0)(puVar1);
      return uVar4 & 1;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_pullup_dis_420015c8,0x61,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}


