// 42024aa8  FUN_42024aa8  FUN_42024aa8  size=31

void FUN_42024aa8(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xfffffff3 | (param_2 & 3) << 2;
  return;
}


