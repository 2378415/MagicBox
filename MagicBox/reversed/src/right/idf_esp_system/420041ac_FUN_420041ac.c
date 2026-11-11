undefined4 FUN_420041ac(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (param_1 < 2) {
    if (param_5 == 1) {
      if (param_6 == 1) {
        if (param_2 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 2;
        }
        if (param_3 != 0) {
          uVar2 = uVar2 | 1;
        }
        if (param_4 == 0) {
          uVar4 = 7;
        }
        else {
          uVar2 = uVar2 | 4;
          uVar4 = 7;
        }
      }
      else {
        if (param_6 != 2) {
          return 5;
        }
        uVar2 = 2;
        if (param_2 == 0) {
          uVar2 = 0;
        }
        if (param_3 != 0) {
          uVar2 = uVar2 | 1;
        }
        if (param_4 != 0) {
          uVar2 = uVar2 | 4;
        }
        uVar2 = uVar2 << 3;
        uVar4 = 0x38;
      }
    }
    else {
      if (param_5 != 0x10) {
        return 6;
      }
      if (param_6 == 1) {
        if (param_2 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 2;
        }
        if (param_3 != 0) {
          uVar2 = uVar2 | 1;
        }
        if (param_4 != 0) {
          uVar2 = uVar2 | 4;
        }
        uVar2 = uVar2 << 6;
        uVar4 = 0x1c0;
      }
      else {
        if (param_6 != 2) {
          return 5;
        }
        uVar2 = 2;
        if (param_2 == 0) {
          uVar2 = 0;
        }
        if (param_3 != 0) {
          uVar2 = uVar2 | 1;
        }
        if (param_4 != 0) {
          uVar2 = uVar2 | 4;
        }
        uVar2 = uVar2 << 9;
        uVar4 = DAT_4200056c;
      }
    }
    if (param_1 == 0) {
      puVar3 = DAT_42000570;
    }
    else {
      puVar3 = DAT_42000574;
    }
    memw();
    memw();
    *puVar3 = uVar4 & *puVar3 ^ *puVar3;
    memw();
    memw();
    *puVar3 = (*puVar3 ^ uVar2) & uVar4 ^ *puVar3;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}