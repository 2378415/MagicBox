// 42024ee4  FUN_42024ee4  FUN_42024ee4  size=111

int * FUN_42024ee4(int *param_1,int *param_2)

{
  int iVar1;
  
  for (iVar1 = (int)param_2 - (int)param_1 >> 4; 0 < iVar1; iVar1 = iVar1 + -1) {
    if (*param_1 != -1) {
      return param_1;
    }
    if (param_1[1] != -1) {
      return param_1 + 1;
    }
    if (param_1[2] != -1) {
      return param_1 + 2;
    }
    if (param_1[3] != -1) {
      return param_1 + 3;
    }
    param_1 = param_1 + 4;
  }
  iVar1 = (int)param_2 - (int)param_1 >> 2;
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      if (iVar1 != 1) {
        return param_2;
      }
      goto LAB_42024f38;
    }
    if (*param_1 != -1) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  if (*param_1 != -1) {
    return param_1;
  }
  param_1 = param_1 + 1;
LAB_42024f38:
  if (*param_1 == -1) {
    param_1 = param_2;
  }
  return param_1;
}


