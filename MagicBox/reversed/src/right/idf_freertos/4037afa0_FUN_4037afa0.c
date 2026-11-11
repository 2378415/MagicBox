undefined4 FUN_4037afa0(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar2 = param_1[0xe];
  if (param_1[0x10] == 0) {
    if (*param_1 == 0) {
      uVar1 = FUN_4037df74(param_1[2]);
      param_1[2] = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_3 == 0) {
    (*DAT_403744d4)(param_1[1]);
    uVar3 = param_1[1];
    param_1[1] = uVar3 + param_1[0x10];
    uVar1 = 0;
    if (param_1[2] <= uVar3 + param_1[0x10]) {
      param_1[1] = *param_1;
    }
  }
  else {
    (*DAT_403744d4)(param_1[3],param_2);
    uVar3 = param_1[3] - param_1[0x10];
    param_1[3] = uVar3;
    if (uVar3 < *param_1) {
      param_1[3] = param_1[2] - param_1[0x10];
    }
    if (param_3 == 2) {
      if (uVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar2 = uVar2 - 1;
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  memw();
  param_1[0xe] = uVar2 + 1;
  return uVar1;
}