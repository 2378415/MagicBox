undefined4 FUN_42010fb4(uint param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((int)param_1 < 0) {
    uVar2 = 0x102;
  }
  else {
    uVar3 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar3 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      uVar2 = 0x102;
    }
    else {
      FUN_42011b5c(param_1);
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000dfc,0xffffffff);
      puVar1 = DAT_42000df4;
      if (param_1 == 0x14) {
        memw();
        memw();
        *DAT_42000df4 = *DAT_42000df4 | 0x100;
        memw();
        memw();
        *puVar1 = *puVar1 & 0xfffffdff;
      }
      puVar1 = (uint *)((param_1 + DAT_42000de8) * 4);
      memw();
      memw();
      *puVar1 = *puVar1 & 0xfffffeff;
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000dfc);
      uVar2 = 0;
    }
  }
  return uVar2;
}