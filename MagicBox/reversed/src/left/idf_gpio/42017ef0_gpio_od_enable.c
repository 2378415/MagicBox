// strings: GPIO number error | gpio_od_enable

uint FUN_42017ef0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (-1 < (int)param_1) {
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      iVar2 = param_1 * 4 + **(int **)PTR_PTR_420015e0;
      memw();
      memw();
      *(uint *)(iVar2 + 0x74) = *(uint *)(iVar2 + 0x74) | 4;
      return uVar3 & 1;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
             PTR_s_gpio_od_enable_42001604,0xe7,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}