// 4038080c  FUN_4038080c  FUN_4038080c  size=30

void FUN_4038080c(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 100) = 1 << 0x20 - (0x20 - (param_2 & 0x1f)) | *(uint *)(*param_1 + 100);
  return;
}


