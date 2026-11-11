// 4037c8e8  FUN_4037c8e8  FUN_4037c8e8  size=57

void FUN_4037c8e8(int *param_1,int param_2)

{
  int iVar1;
  
  memw();
  iVar1 = param_1[1];
  memw();
  *(int *)(param_2 + 4) = iVar1;
  memw();
  memw();
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 8);
  memw();
  memw();
  *(int *)(*(int *)(iVar1 + 8) + 4) = param_2;
  memw();
  *(int *)(iVar1 + 8) = param_2;
  memw();
  *(int **)(param_2 + 0x10) = param_1;
  memw();
  memw();
  *param_1 = *param_1 + 1;
  return;
}


