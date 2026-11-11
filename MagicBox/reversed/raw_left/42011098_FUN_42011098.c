// 42011098  FUN_42011098  FUN_42011098  size=28

void FUN_42011098(undefined4 param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      FUN_42010e70(param_1,*param_2);
      param_2 = param_2 + 1;
    } while (param_3 != iVar1);
  }
  return;
}


