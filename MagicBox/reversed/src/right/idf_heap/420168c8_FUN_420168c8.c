void FUN_420168c8(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    FUN_4202503c(param_1,param_3);
  }
  else {
    iVar1 = *param_2;
    if (iVar1 == 0) {
      FUN_42025084(param_1,param_3);
    }
    else {
      *(int **)(iVar1 + 4) = param_3;
      *param_2 = (int)param_3;
      param_3[1] = (int)param_2;
      *param_3 = iVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
  }
  return;
}