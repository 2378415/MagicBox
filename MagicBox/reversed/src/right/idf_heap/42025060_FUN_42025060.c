void FUN_42025060(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 == 0) {
    *param_1 = piVar2;
  }
  else {
    *(int **)(iVar1 + 4) = piVar2;
  }
  if (piVar2 == (int *)0x0) {
    param_1[1] = iVar1;
  }
  else {
    *piVar2 = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  return;
}