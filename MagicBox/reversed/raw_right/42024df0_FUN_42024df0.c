// 42024df0  FUN_42024df0  FUN_42024df0  size=33

void FUN_42024df0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(param_2 + 8);
  if (iVar1 == 0) {
    *param_1 = iVar2;
  }
  else {
    *(int *)(iVar1 + 8) = iVar2;
  }
  if (iVar2 == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(iVar2 + 4) = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  return;
}


