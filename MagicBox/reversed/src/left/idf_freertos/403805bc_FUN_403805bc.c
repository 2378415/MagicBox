uint FUN_403805bc(int param_1)

{
  memw();
  memw();
  return (uint)(**(int **)(param_1 + 4) == 0) | ((*(int **)(param_1 + 4))[0x29] & 1U) * 2;
}