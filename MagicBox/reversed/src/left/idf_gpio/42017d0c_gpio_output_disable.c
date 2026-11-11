// strings: GPIO number error | gpio_output_disable

uint FUN_42017d0c(uint param_1)

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
      if (param_1 < 0x20) {
        memw();
        *(int *)(iVar3 + 0x28) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
      }
      else {
        memw();
        memw();
        *(int *)(iVar3 + 0x34) =
             (int)(CONCAT44(*(uint *)(iVar3 + 0x34) >> 0x16,
                            (1 << 0x20 - (0x20 - (param_1 & 0x1f))) << 10) >> 10);
      }
      memw();
      *(undefined4 *)(param_1 * 4 + DAT_420015f4) = 0x100;
      return uVar2 & 1;
    }
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar1,PTR_DAT_4200159c,
             PTR_s_gpio_output_disable_420015f0,0xd0,PTR_s_GPIO_number_error_420015a4);
  return 0x102;
}