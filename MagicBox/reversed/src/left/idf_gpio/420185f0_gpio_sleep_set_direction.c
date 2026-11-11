// strings: GPIO number error | gpio_sleep_set_direction | gpio | gpio_sleep_input_enable | gpio_sleep_input_disable | GPIO output gpio_num error | gpio_sleep_output_disable | gpio_sleep_output_enable

/* (2 unreachable decompiler blocks omitted) */

undefined4 FUN_420185f0(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  if (-1 < (int)param_1) {
    uVar4 = DAT_420006f0 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_420006f4 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar4 = DAT_420006f8 >> (param_1 & 0x1f);
    }
    if ((uVar4 & 1) == 1) {
      uVar4 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
              DAT_42000b10 >> (param_1 & 0x1f);
      if ((param_1 >> 5 & 1) != 0) {
        uVar4 = DAT_42000b14 >> (param_1 & 0x1f);
      }
      if ((param_2 & 1) == 0) {
        if ((uVar4 & 1) == 0) {
          puVar6 = *(uint **)(PTR_DAT_420015ac + param_1 * 4);
          memw();
          memw();
          *puVar6 = *puVar6 & 0xffffffef;
          goto joined_r0x42018728;
        }
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar5 = 0x354;
        puVar7 = PTR_s_gpio_sleep_input_disable_4200165c;
      }
      else {
        if ((uVar4 & 1) == 0) {
          puVar6 = *(uint **)(PTR_DAT_420015ac + param_1 * 4);
          memw();
          memw();
          *puVar6 = *puVar6 | 0x10;
joined_r0x42018728:
          if ((param_2 & 2) == 0) {
            memw();
            memw();
            *puVar6 = *puVar6 & 0xfffffffe;
            return 0;
          }
          memw();
          memw();
          *puVar6 = *puVar6 | 1;
          return 0;
        }
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar5 = 0x35b;
        puVar7 = PTR_s_gpio_sleep_input_enable_42001658;
      }
      puVar8 = PTR_s_GPIO_number_error_420015a4;
      puVar2 = PTR_DAT_420015a0;
      puVar1 = PTR_DAT_4200159c;
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar3,PTR_DAT_4200159c,puVar7,uVar5,
                 PTR_s_GPIO_number_error_420015a4);
      if ((param_2 & 2) == 0) {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar5 = 0x362;
        puVar7 = PTR_s_gpio_sleep_output_disable_42001664;
      }
      else {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar5 = 0x369;
        puVar7 = PTR_s_gpio_sleep_output_enable_42001660;
        puVar8 = PTR_s_GPIO_output_gpio_num_error_420015fc;
      }
      (*(code *)PTR_FUN_42000118)(1,puVar1,puVar2,uVar3,puVar1,puVar7,uVar5,puVar8);
      return 0;
    }
  }
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar3,PTR_DAT_4200159c,
             PTR_s_gpio_sleep_set_direction_42001650,0x370,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}