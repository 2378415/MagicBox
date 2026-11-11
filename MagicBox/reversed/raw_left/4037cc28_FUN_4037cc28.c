// 4037cc28  FUN_4037cc28  FUN_4037cc28  size=103

void FUN_4037cc28(int *param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  
  memw();
  if (*param_2 == 0xffffffff) {
    memw();
    piVar1 = (int *)param_1[4];
  }
  else {
    memw();
    piVar1 = param_1 + 2;
    memw();
    uVar2 = *(uint *)param_1[3];
    while (uVar2 <= *param_2) {
      memw();
      piVar1 = (int *)piVar1[1];
      memw();
      memw();
      uVar2 = *(uint *)piVar1[1];
    }
  }
  memw();
  memw();
  param_2[1] = piVar1[1];
  memw();
  memw();
  *(uint **)(param_2[1] + 8) = param_2;
  memw();
  param_2[2] = (uint)piVar1;
  memw();
  piVar1[1] = (int)param_2;
  memw();
  param_2[4] = (uint)param_1;
  memw();
  memw();
  *param_1 = *param_1 + 1;
  return;
}


