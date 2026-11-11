void FUN_40380600(int *param_1)

{
  memw();
  memw();
  *(uint *)(param_1[1] + 0x9c) = *(uint *)(param_1[1] + 0x9c) | 2;
  (**(code **)(*param_1 + 0x40))(param_1);
  return;
}