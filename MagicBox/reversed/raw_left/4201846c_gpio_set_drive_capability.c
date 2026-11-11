// 4201846c  gpio_set_drive_capability  FUN_4201846c  size=200
// strings: GPIO number error | GPIO drive capability error | gpio_set_drive_capability | gpio

uint FUN_4201846c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      if (param_2 < 4) {
        FUN_42018a24(param_1);
        (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
        puVar5 = PTR_DAT_420015a8;
        if (param_1 - 0x11 < 2) {
          param_2 = (param_2 & 1) * 2 | param_2 >> 1;
        }
        puVar2 = (uint *)(param_1 * 4 + DAT_420015c0);
        memw();
        memw();
        *puVar2 = *puVar2 & DAT_42001648 | param_2 << 10;
        (*(code *)PTR_FUN_420004e0)(puVar5);
        return uVar3 & 1;
      }
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = 0x2a5;
      puVar5 = PTR_s_GPIO_drive_capability_error_42001644;
      goto LAB_420184da;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  uVar4 = 0x2a4;
  puVar5 = PTR_s_GPIO_number_error_420015a4;
LAB_420184da:
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
             PTR_s_gpio_set_drive_capability_42001640,uVar4,puVar5);
  return 0x102;
}


