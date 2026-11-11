// 42017b88  gpio_intr_enable  FUN_42017b88  size=149
// strings: GPIO number error | gpio_intr_enable

uint FUN_42017b88(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
      puVar1 = PTR_PTR_420015e0;
      if (*(int *)(PTR_PTR_420015e0 + 0xc) == 3) {
        uVar4 = rsr(in_PRID);
        *(uint *)(PTR_PTR_420015e0 + 0xc) = uVar4 >> 0xd & 1;
      }
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_420015a8);
      FUN_4202eadc(*(undefined4 *)puVar1,param_1,*(undefined4 *)(puVar1 + 0xc));
      return uVar3 & 1;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
             PTR_s_gpio_intr_enable_420015e4,0xb0,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}


