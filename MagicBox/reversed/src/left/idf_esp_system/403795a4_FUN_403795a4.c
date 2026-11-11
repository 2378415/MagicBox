undefined4 FUN_403795a4(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = FUN_40379564();
  if (param_1 - 1 < uVar1) {
    uVar3 = uVar1 / param_1;
    uVar2 = 0;
    if (param_1 != ((uVar3 >> 1) + uVar1) / uVar3) {
      return 0;
    }
  }
  else if (param_1 == 0x50) {
    uVar3 = 6;
    uVar2 = 1;
    uVar1 = 0x1e0;
  }
  else if (param_1 == 0xa0) {
    uVar3 = 3;
    uVar2 = 1;
    uVar1 = 0x1e0;
  }
  else {
    if (param_1 != 0xf0) {
      return 0;
    }
    uVar3 = 2;
    uVar2 = 1;
    uVar1 = 0x1e0;
  }
  *param_2 = uVar2;
  param_2[1] = uVar1;
  param_2[2] = uVar3;
  param_2[3] = param_1;
  return 1;
}