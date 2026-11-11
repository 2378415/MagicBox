// 4037b3b8  FUN_4037b3b8  FUN_4037b3b8  size=135

undefined4 FUN_4037b3b8(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar2 = param_1[0xe];
  if (param_1[0x10] == 0) {
    uVar2 = uVar2 + 1;
    uVar1 = 0;
    if (*param_1 == 0) {
      uVar1 = FUN_4037e1fc(param_1[2]);
      param_1[2] = 0;
    }
  }
  else if (param_3 == 0) {
    uVar2 = uVar2 + 1;
    (*DAT_4037450c)(param_1[1]);
    uVar3 = param_1[1];
    param_1[1] = uVar3 + param_1[0x10];
    if (param_1[2] <= uVar3 + param_1[0x10]) {
      param_1[1] = *param_1;
    }
    uVar1 = 0;
  }
  else {
    (*DAT_4037450c)(param_1[3],param_2);
    uVar3 = param_1[3] - param_1[0x10];
    param_1[3] = uVar3;
    if (uVar3 < *param_1) {
      param_1[3] = param_1[2] - param_1[0x10];
    }
    if (param_3 == 2) {
      uVar2 = (uint)(uVar2 == 0) + (uVar2 != 0) * uVar2;
      uVar1 = 0;
    }
    else {
      uVar2 = uVar2 + 1;
      uVar1 = 0;
    }
  }
  memw();
  param_1[0xe] = uVar2;
  return uVar1;
}


