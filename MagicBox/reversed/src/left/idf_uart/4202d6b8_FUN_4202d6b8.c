void FUN_4202d6b8(int *param_1,uint *param_2)

{
  memw();
  *param_2 = *(uint *)(*param_1 + 0x20) >> 4 & 3;
  return;
}