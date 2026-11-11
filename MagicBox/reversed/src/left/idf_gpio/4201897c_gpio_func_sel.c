// strings: GPIO number error | gpio_func_sel

uint FUN_4201897c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      if ((param_1 - 0x13 & 0xff) < 2) {
        memw();
        memw();
        *DAT_420015cc = *DAT_420015cc & DAT_42000294;
      }
      puVar2 = (uint *)((param_1 & 0xff) * 4 + DAT_420015c0);
      memw();
      memw();
      *puVar2 = (param_2 & 7) << 0xc | *puVar2 & DAT_42000784;
      return uVar3 & 1;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,PTR_s_gpio_func_sel_42001678
             ,0x428,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}