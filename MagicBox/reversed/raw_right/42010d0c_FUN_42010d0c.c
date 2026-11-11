// 42010d0c  FUN_42010d0c  FUN_42010d0c  size=91

undefined4 FUN_42010d0c(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((int)param_1 < 0) {
    uVar1 = 0x102;
  }
  else {
    uVar2 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar2 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar2 & 1) == 0) {
      uVar1 = 0x102;
    }
    else {
      memw();
      memw();
      **(uint **)(PTR_DAT_42000df8 + param_1 * 4) = **(uint **)(PTR_DAT_42000df8 + param_1 * 4) | 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}


