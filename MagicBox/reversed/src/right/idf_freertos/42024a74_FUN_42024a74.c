void FUN_42024a74(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xffffffcf | (param_2 & 3) << 4;
  return;
}