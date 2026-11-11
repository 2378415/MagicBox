// 42011244  FUN_42011244  FUN_42011244  size=124

undefined4 FUN_42011244(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
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
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000dfc,0xffffffff);
      if (*(int *)(PTR_PTR_42000e00 + 0xc) == 3) {
        uVar2 = rsr(in_PRID);
        *(uint *)(PTR_PTR_42000e00 + 0xc) = uVar2 >> 0xd & 1;
      }
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000dfc);
      FUN_4202647c(*(undefined4 *)PTR_PTR_42000e00,param_1,*(undefined4 *)(PTR_PTR_42000e00 + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}


