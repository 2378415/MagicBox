void FUN_403804cc(int *param_1)

{
  memw();
  memw();
  *(uint *)(param_1[1] + 0x9c) = *(uint *)(param_1[1] + 0x9c) | 1;
  (**(code **)(*param_1 + 0x40))(param_1);
  return;
}