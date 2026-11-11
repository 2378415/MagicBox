void FUN_4037c924(int *param_1,uint *param_2)

{
  int *piVar1;
  
  memw();
  if (*param_2 == 0xffffffff) {
    memw();
    piVar1 = (int *)param_1[4];
  }
  else {
    piVar1 = param_1 + 2;
    while( true ) {
      memw();
      memw();
      if (*param_2 < *(uint *)piVar1[1]) break;
      memw();
      piVar1 = (int *)piVar1[1];
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