// 40375c1c  FUN_40375c1c  FUN_40375c1c  size=157

undefined4 FUN_40375c1c(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[2];
  *param_1 = uVar3;
  param_1[2] = *(uint *)(param_1[1] - 0x10);
  uVar2 = *(uint *)(param_1[1] - 0xc);
  param_1[1] = uVar2;
  if (((DAT_403745d4 < uVar2 + DAT_403745d0) || ((uVar2 & 0xf) != 0)) &&
     (DAT_403745dc < uVar2 + DAT_403745d8)) {
    uVar1 = 0;
  }
  else {
    if ((int)uVar3 < 0) {
      uVar3 = uVar3 & 0x3fffffff | DAT_403745e0;
    }
    if ((-(DAT_403745e8 + -1) & 0xffU) == 0 && (-(DAT_403745f0 + -1) & 0xffU) == 0) {
      if (DAT_403745f8 < uVar3 + DAT_403745f4) {
        if (DAT_403745dc < uVar3 + DAT_403745fc) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


