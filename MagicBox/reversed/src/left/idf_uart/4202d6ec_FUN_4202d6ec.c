void FUN_4202d6ec(int *param_1,uint *param_2)

{
  memw();
  *param_2 = *(uint *)(*param_1 + 0x20) >> 2 & 3;
  return;
}