// 40379294  FUN_40379294  FUN_40379294  size=204

void FUN_40379294(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar2 = *DAT_403749d0 >> 10 & 3;
  if (uVar2 == 1) {
    memw();
    uVar4 = *DAT_40374960 & 3;
    if (uVar4 == 1) {
      uVar4 = 0xa0;
    }
    else if (uVar4 == 2) {
      uVar4 = 0xf0;
    }
    else if (uVar4 == 0) {
      uVar4 = 0x50;
    }
    else {
      uVar4 = 0;
    }
    memw();
    if ((*DAT_40374960 & 4) == 0) {
      uVar3 = 0x140;
    }
    else if ((*DAT_40374960 >> 2 & 1) == 1) {
      uVar3 = 0x1e0;
    }
    else {
      uVar3 = 0;
    }
    if (uVar4 == 0x50) {
      if (uVar3 == 0x1e0) {
        uVar1 = 6;
      }
      else {
        uVar1 = 4;
      }
    }
    else if (uVar4 == 0xa0) {
      if (uVar3 == 0x1e0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      if (uVar4 != 0xf0 || uVar3 != 0x1e0) {
        return;
      }
      uVar1 = 2;
    }
  }
  else if (uVar2 == 2) {
    uVar4 = 0x14;
    uVar1 = 1;
    uVar3 = 0x14;
  }
  else {
    if (uVar2 != 0) {
      return;
    }
    memw();
    uVar1 = (*DAT_403749d0 & 0x3ff) + 1;
    uVar3 = FUN_403791f8();
    uVar4 = uVar3 / uVar1;
  }
  *param_1 = uVar2;
  param_1[1] = uVar3;
  param_1[2] = uVar1;
  param_1[3] = uVar4;
  return;
}


