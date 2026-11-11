// 420181f4  gpio_isr_handler_add  FUN_420181f4  size=206
// strings: GPIO isr service is not installed, call gpio_ins | gpio_isr_handler_add | GPIO number error

uint FUN_420181f4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = PTR_PTR_420015e0;
  if (*(int *)(PTR_PTR_420015e0 + 0x10) == 0) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
               PTR_s_gpio_isr_handler_add_42001614,0x211,
               PTR_s_GPIO_isr_service_is_not_installe_42001618);
    uVar3 = 0x103;
  }
  else {
    if (-1 < (int)param_1) {
      uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
              DAT_42000b10 >> (param_1 & 0x1f);
      if ((param_1 >> 5 & 1) != 0) {
        uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
      }
      if ((uVar3 & 1) == 0) {
        (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
        FUN_42017c20(param_1);
        if (*(int *)(puVar1 + 0x10) != 0) {
          puVar4 = (undefined4 *)(param_1 * 8 + *(int *)(puVar1 + 0x10));
          *puVar4 = param_2;
          puVar4[1] = param_3;
        }
        uVar2 = FUN_4202cf74(*(undefined4 *)(puVar1 + 0x14));
        FUN_4202eadc(*(undefined4 *)puVar1,param_1,uVar2);
        (*(code *)PTR_FUN_420004e0)(PTR_DAT_420015a8);
        return uVar3 & 1;
      }
    }
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
               PTR_s_gpio_isr_handler_add_42001614,0x212,PTR_s_GPIO_number_error_420015a4);
    uVar3 = 0x102;
  }
  return uVar3;
}


