// 42017dbc  gpio_output_enable  FUN_42017dbc  size=173
// strings: GPIO output gpio_num error | gpio_output_enable

uint FUN_42017dbc(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (-1 < (int)param_1) {
    uVar2 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar2 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar2 & 1) == 0) {
      iVar3 = **(int **)PTR_PTR_420015e0;
      memw();
      *(undefined4 *)(param_1 * 4 + DAT_420015f4) = 0x100;
      if (param_1 < 0x20) {
        memw();
        *(int *)(iVar3 + 0x24) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        return uVar2 & 1;
      }
      memw();
      memw();
      *(int *)(iVar3 + 0x30) =
           (int)(CONCAT44(*(uint *)(iVar3 + 0x30) >> 0x16,
                          (1 << 0x20 - (0x20 - (param_1 & 0x1f))) << 10) >> 10);
      return uVar2 & 1;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
             PTR_s_gpio_output_enable_420015f8,0xd8,PTR_s_GPIO_output_gpio_num_error_420015fc);
  return 0x102;
}


