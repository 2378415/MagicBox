// strings: GPIO number error | GPIO interrupt type error | gpio_set_intr_type | gpio

uint FUN_42017a94(uint param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  
  if (-1 < (int)param_1) {
    uVar5 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar5 = DAT_42000b14 >> (param_1 & 0x1f);
    }
    uVar2 = uVar5 & 1;
    if ((uVar5 & 1) == 0) {
      if (param_2 < 6) {
        (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
        puVar1 = PTR_PTR_420015e0;
        iVar6 = param_1 * 4 + **(int **)PTR_PTR_420015e0;
        memw();
        memw();
        *(uint *)(iVar6 + 0x74) = *(uint *)(iVar6 + 0x74) & 0xfffffc7f | (param_2 & 7) << 7;
        puVar10 = PTR_DAT_420015a8;
        uVar5 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        uVar8 = *(uint *)(puVar1 + 0x18);
        uVar7 = *(uint *)(puVar1 + 0x1c);
        if ((param_1 & 0x20) == 0) {
          uVar9 = uVar5;
          uVar5 = uVar2;
        }
        else {
          uVar9 = uVar2;
        }
        if (param_2 - 1 < 3) {
          uVar9 = uVar9 | uVar8;
          uVar5 = uVar5 | uVar7;
        }
        else {
          uVar9 = uVar9 & uVar8 ^ uVar8;
          uVar5 = uVar5 & uVar7 ^ uVar7;
        }
        *(uint *)(puVar1 + 0x18) = uVar9;
        *(uint *)(puVar1 + 0x1c) = uVar5;
        (*(code *)PTR_FUN_420004e0)(puVar10);
        return uVar2;
      }
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = 0x9b;
      puVar10 = PTR_s_GPIO_interrupt_type_error_420015dc;
      goto LAB_42017b02;
    }
  }
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  uVar4 = 0x9a;
  puVar10 = PTR_s_GPIO_number_error_420015a4;
LAB_42017b02:
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar3,PTR_DAT_4200159c,
             PTR_s_gpio_set_intr_type_420015d8,uVar4,puVar10);
  return 0x102;
}