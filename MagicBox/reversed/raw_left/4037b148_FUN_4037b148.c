// 4037b148  FUN_4037b148  FUN_4037b148  size=75

uint FUN_4037b148(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1[2] & 4;
  if ((param_1[2] & 4U) == 0) {
    uVar3 = param_1[8];
    uVar2 = param_1[0xb];
    if ((uVar3 == param_1[0xc]) && (uVar3 == uVar2)) {
      uVar2 = *param_1 - 8;
    }
    else if (uVar3 < uVar2) {
      uVar2 = (uVar2 - uVar3) - 8;
    }
    else {
      uVar2 = ((param_1[0xd] - uVar3) + (uVar2 - param_1[0xc])) - 0x10;
    }
    if (-1 < (int)uVar2) {
      uVar1 = param_1[1];
      uVar1 = (uVar2 < uVar1) * uVar2 + (uVar2 >= uVar1) * uVar1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


