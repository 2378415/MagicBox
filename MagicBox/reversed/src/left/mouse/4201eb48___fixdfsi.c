int __fixdfsi(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = 1;
  if ((int)param_2 < 0) {
    iVar1 = -1;
  }
  uVar4 = param_2 >> 0x14 & 0x7ff;
  uVar5 = param_2 & 0xfffff | 0x100000;
  uVar2 = uVar4 - 0x3ff;
  if ((int)uVar2 < 0x14) {
    if ((int)uVar2 < 0) {
      if (uVar2 == 0xffffffff) {
        return iVar1;
      }
      return 0;
    }
    uVar3 = (0x80000 >> (uVar2 & 0x1f)) + uVar5 >> (-(uVar4 - 0x413) & 0x1f);
  }
  else {
    if (0x1e < uVar2) {
      iVar1 = (*DAT_42001b40)(param_1,param_2);
      return iVar1;
    }
    uVar2 = (0x80000000U >> (uVar4 - 0x413 & 0x1f)) + param_1;
    if (uVar2 < param_1) {
      uVar5 = uVar5 + 1;
    }
    uVar3 = 0;
    if (-(uVar4 - 0x433) != 0x20) {
      uVar3 = uVar2 >> (-(uVar4 - 0x433) & 0x1f);
    }
    uVar3 = uVar3 | uVar5 << 0x20 - (0x20 - (uVar4 - 0x413 & 0x1f));
  }
  return iVar1 * uVar3;
}