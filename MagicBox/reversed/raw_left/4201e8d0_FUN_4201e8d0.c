// 4201e8d0  FUN_4201e8d0  FUN_4201e8d0  size=42

int FUN_4201e8d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_4201e98c(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))
                      (*(int **)(param_1 + 8),param_2,param_3,param_4);
  }
  return iVar1;
}


