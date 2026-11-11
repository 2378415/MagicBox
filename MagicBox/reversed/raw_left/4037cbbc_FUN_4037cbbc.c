// 4037cbbc  FUN_4037cbbc  FUN_4037cbbc  size=36

void FUN_4037cbbc(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 2;
  memw();
  param_1[1] = puVar1;
  memw();
  param_1[2] = 0xffffffff;
  memw();
  param_1[3] = puVar1;
  memw();
  param_1[4] = puVar1;
  memw();
  *param_1 = 0;
  return;
}


