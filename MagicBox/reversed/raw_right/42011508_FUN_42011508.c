// 42011508  FUN_42011508  FUN_42011508  size=96

undefined4 FUN_42011508(uint param_1)

{
  int iVar1;
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
      iVar1 = (param_1 + 0x1c) * 4 + **(int **)PTR_PTR_42000e00;
      memw();
      memw();
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 4;
      uVar2 = 0;
    }
  }
  return uVar2;
}


