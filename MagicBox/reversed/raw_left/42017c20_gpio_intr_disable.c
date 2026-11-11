// 42017c20  gpio_intr_disable  FUN_42017c20  size=109
// strings: GPIO number error | gpio_intr_disable

uint FUN_42017c20(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (-1 < (int)param_1) {
    uVar2 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar2 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar2 & 1) == 0) {
      FUN_4202eb3c(*(undefined4 *)PTR_PTR_420015e0,param_1);
      return uVar2 & 1;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
             PTR_s_gpio_intr_disable_420015e8,0xbb,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}


