void FUN_42024b14(int *param_1,uint *param_2)

{
  memw();
  if ((*(uint *)(*param_1 + 0x20) & 2) == 0) {
    *param_2 = 0;
  }
  else {
    memw();
    *param_2 = *(uint *)(*param_1 + 0x20) & 1 | 2;
  }
  return;
}