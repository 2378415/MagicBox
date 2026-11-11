int FUN_4037cc94(int param_1)

{
  int *piVar1;
  
  memw();
  piVar1 = *(int **)(param_1 + 0x10);
  memw();
  memw();
  memw();
  *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 8);
  memw();
  memw();
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 4) = *(undefined4 *)(param_1 + 4);
  memw();
  if (piVar1[1] == param_1) {
    memw();
    memw();
    piVar1[1] = *(int *)(param_1 + 8);
  }
  memw();
  *(undefined4 *)(param_1 + 0x10) = 0;
  memw();
  memw();
  *piVar1 = *piVar1 + -1;
  memw();
  return *piVar1;
}