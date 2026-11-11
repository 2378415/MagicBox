// 42026a3c  FUN_42026a3c  FUN_42026a3c  size=43

void FUN_42026a3c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == 0) {
    param_3 = param_2;
  }
  iVar1 = FUN_42026a0c(param_1,param_3);
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_FUN_420014bc)();
    FUN_42026878(iVar1,param_1 + iVar2,param_2 - iVar2);
  }
  return;
}


