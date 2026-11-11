// 4037c898  FUN_4037c898  FUN_4037c898  size=30

int FUN_4037c898(int param_1)

{
  int iVar1;
  
  memw();
  iVar1 = 0;
  if (*(int *)(param_1 + 0x24) != 0) {
    memw();
    memw();
    iVar1 = -(**(int **)(param_1 + 0x30) + -0x19);
  }
  return iVar1;
}


