// 4202d6cc  FUN_4202d6cc  FUN_4202d6cc  size=31

void FUN_4202d6cc(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xfffffff3 | (param_2 & 3) << 2;
  return;
}


