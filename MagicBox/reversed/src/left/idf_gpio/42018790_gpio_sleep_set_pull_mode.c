// strings: GPIO number error | GPIO pull mode error | gpio_sleep_set_pull_mode | gpio

uint FUN_42018790(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    uVar1 = uVar3 & 1;
    if ((uVar3 & 1) == 0) {
      if (param_2 < 4) {
        if (param_2 == 2) {
          FUN_42017604(param_1);
          FUN_42017714(param_1);
          return uVar1;
        }
        if (param_2 == 3) {
          FUN_4201757c();
          FUN_4201768c(param_1);
          return uVar1;
        }
        if (param_2 == 1) {
          FUN_42017604(param_1);
          FUN_4201768c(param_1);
          return uVar1;
        }
        FUN_4201757c();
        FUN_42017714(param_1);
        return uVar1;
      }
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = 0x38b;
      puVar5 = PTR_s_GPIO_pull_mode_error_4200166c;
      goto LAB_420187fe;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  uVar4 = 0x38a;
  puVar5 = PTR_s_GPIO_number_error_420015a4;
LAB_420187fe:
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_sleep_set_pull_mode_42001668,uVar4,puVar5);
  return 0x102;
}