// 42011748  FUN_42011748  FUN_42011748  size=116

undefined4 FUN_42011748(uint param_1,uint param_2)

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
    else if (param_2 < 4) {
      FUN_42011b5c(param_1);
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000dfc,0xffffffff);
      FUN_42010ad4(**(undefined4 **)PTR_PTR_42000e00,param_1,param_2);
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000dfc);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x102;
    }
  }
  return uVar1;
}


