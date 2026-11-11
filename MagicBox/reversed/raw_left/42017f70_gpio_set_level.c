// 42017f70  gpio_set_level  FUN_42017f70  size=179
// strings: GPIO output gpio_num error | gpio_set_level

uint FUN_42017f70(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    uVar1 = uVar3 & 1;
    if ((uVar3 & 1) == 0) {
      iVar4 = **(int **)PTR_PTR_420015e0;
      if (param_2 == 0) {
        if (param_1 < 0x20) {
          memw();
          *(int *)(iVar4 + 0xc) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
          return uVar1;
        }
        memw();
        *(int *)(iVar4 + 0x18) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        return uVar1;
      }
      if (param_1 < 0x20) {
        memw();
        *(int *)(iVar4 + 8) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        return uVar1;
      }
      memw();
      *(int *)(iVar4 + 0x14) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
      return uVar1;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_set_level_42001608,0xee,PTR_s_GPIO_output_gpio_num_error_420015fc);
  return 0x102;
}


