// 4202d758  FUN_4202d758  FUN_4202d758  size=29

void FUN_4202d758(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & 0xfffffc00 | param_2 & 0x3ff;
  return;
}


