// 403806a8  FUN_403806a8  FUN_403806a8  size=30

void FUN_403806a8(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 100) = *(uint *)(*param_1 + 100) | 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


