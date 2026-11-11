// 42021da8  FUN_42021da8  FUN_42021da8  size=76

undefined8 FUN_42021da8(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = (param_2 >> 0x14 & 0x7ff) * 0x100000 + -0x3400000;
  uVar3 = 0;
  if (iVar1 < 1) {
    uVar2 = -iVar1 >> 0x14;
    if ((int)uVar2 < 0x14) {
      iVar1 = 0x80000 >> (uVar2 & 0x1f);
    }
    else {
      uVar3 = 1;
      if ((int)(uVar2 - 0x14) < 0x1f) {
        uVar3 = 0x80000000 >> (uVar2 - 0x14 & 0x1f);
      }
      iVar1 = 0;
    }
  }
  return CONCAT44(iVar1,uVar3);
}


