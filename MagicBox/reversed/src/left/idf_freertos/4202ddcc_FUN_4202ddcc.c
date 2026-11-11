// strings: periph < PERIPH_MODULE_MAX | periph_module_enable

void FUN_4202ddcc(uint param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  if (0x28 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_periph_ctrl_c_3c033dac_0x20_42001e14,0x3d,PTR_s_periph_module_enable_42001e10,
               PTR_s_periph_<_PERIPH_MODULE_MAX_42001e0c);
  }
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001dfc,0xffffffff);
  puVar5 = DAT_42001e1c;
  uVar6 = DAT_42001e18;
  iVar4 = DAT_42001e00;
  puVar3 = DAT_4200021c;
  puVar2 = DAT_42000218;
  puVar8 = DAT_42000214;
  cVar1 = *(char *)(DAT_42001e00 + param_1);
  if (cVar1 != '\0') goto LAB_4202df10;
  if (param_1 == 3) {
    memw();
    uVar9 = *DAT_42000218;
    uVar6 = FUN_4202da6c(3);
    memw();
    *puVar2 = uVar9 | uVar6;
LAB_4202dee2:
    puVar8 = DAT_4200022c;
  }
  else {
    uVar9 = param_1 - 9;
    if (uVar9 < 0x1e) {
      uVar10 = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
      if ((uVar10 & DAT_42001e18) == 0) {
        if ((uVar10 >> 0x10 & 0x3f) == 0) {
          if (uVar9 != 0x1d) {
            memw();
            uVar7 = *DAT_42000214;
            uVar10 = FUN_4202da6c(param_1);
            memw();
            *DAT_42000214 = uVar7 | uVar10;
            goto LAB_4202ded7;
          }
          memw();
          uVar9 = *DAT_42001e1c;
          uVar6 = FUN_4202da6c(0x26);
          memw();
          *puVar5 = uVar6 | uVar9;
LAB_4202def4:
          puVar8 = DAT_42001e04;
        }
        else {
          memw();
          uVar9 = *DAT_4200021c;
          uVar6 = FUN_4202da6c(param_1);
          memw();
          *puVar3 = uVar9 | uVar6;
LAB_4202de58:
          puVar8 = DAT_42001e08;
        }
        goto LAB_4202def7;
      }
      memw();
      uVar7 = *DAT_42000218;
      uVar10 = FUN_4202da6c(param_1);
      memw();
      *DAT_42000218 = uVar7 | uVar10;
LAB_4202ded7:
      uVar10 = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
      if ((uVar10 & uVar6) != 0) goto LAB_4202dee2;
      if ((uVar10 >> 0x10 & 0x3f) != 0) goto LAB_4202de58;
      if (uVar9 == 0x1d) goto LAB_4202def4;
    }
    else {
      memw();
      uVar9 = *DAT_42000214;
      uVar6 = FUN_4202da6c(param_1);
      memw();
      *puVar8 = uVar9 | uVar6;
    }
    puVar8 = DAT_42000228;
  }
LAB_4202def7:
  memw();
  uVar9 = *puVar8;
  uVar6 = FUN_4202dc00(param_1,1);
  memw();
  *puVar8 = uVar6 & uVar9 ^ uVar9;
LAB_4202df10:
  *(char *)(iVar4 + param_1) = cVar1 + '\x01';
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42001dfc);
  return;
}