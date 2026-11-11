// 42024d84  FUN_42024d84  FUN_42024d84  size=33

void FUN_42024d84(int *param_1,int param_2)

{
  if (param_1[1] != 0) {
    *(int *)(param_1[1] + 8) = param_2;
  }
  *(int *)(param_2 + 4) = param_1[1];
  *(undefined4 *)(param_2 + 8) = 0;
  param_1[1] = param_2;
  if (*param_1 == 0) {
    *param_1 = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}


