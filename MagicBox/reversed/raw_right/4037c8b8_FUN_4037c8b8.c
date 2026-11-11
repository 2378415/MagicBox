// 4037c8b8  FUN_4037c8b8  FUN_4037c8b8  size=36

void FUN_4037c8b8(undefined4 *param_1)

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


