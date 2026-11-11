// 4037ff00  FUN_4037ff00  FUN_4037ff00  size=38

void FUN_4037ff00(int *param_1)

{
  memw();
  memw();
  *(uint *)param_1[1] = *(uint *)param_1[1] | DAT_403750e8;
  if ((param_1[6] & 1U) == 0) {
    (**(code **)(*param_1 + 0x40))(param_1);
  }
  return;
}


