// 4037ad14  FUN_4037ad14  FUN_4037ad14  size=79

uint FUN_4037ad14(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1[2] & 4U) == 0) {
    uVar2 = param_1[8];
    uVar3 = param_1[0xc];
    if ((uVar2 == uVar3) && (uVar3 == param_1[0xb])) {
      uVar2 = *param_1 - 8;
    }
    else {
      uVar1 = param_1[0xb];
      if (uVar2 < uVar1) {
        uVar2 = (uVar1 - uVar2) - 8;
      }
      else {
        uVar2 = ((uVar1 - uVar3) + (param_1[0xd] - uVar2)) - 0x10;
      }
    }
    if ((int)uVar2 < 0) {
      uVar2 = 0;
    }
    else if ((uint)param_1[1] < uVar2) {
      uVar2 = param_1[1];
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


