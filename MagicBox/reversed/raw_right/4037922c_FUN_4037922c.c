// 4037922c  FUN_4037922c  FUN_4037922c  size=101

undefined4 FUN_4037922c(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = FUN_403791f8();
  if (param_1 - 1 < uVar1) {
    uVar4 = uVar1 / param_1;
    uVar2 = ((uVar4 >> 1) + uVar1) / uVar4;
    if (param_1 != uVar2) {
      return 0;
    }
    uVar3 = 0;
    param_1 = uVar2;
  }
  else if (param_1 == 0x50) {
    uVar4 = 6;
    uVar3 = 1;
    uVar1 = 0x1e0;
  }
  else if (param_1 == 0xa0) {
    uVar4 = 3;
    uVar3 = 1;
    uVar1 = 0x1e0;
  }
  else {
    if (param_1 != 0xf0) {
      return 0;
    }
    uVar4 = 2;
    uVar3 = 1;
    uVar1 = 0x1e0;
  }
  *param_2 = uVar3;
  param_2[1] = uVar1;
  param_2[2] = uVar4;
  param_2[3] = param_1;
  return 1;
}


