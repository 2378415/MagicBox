// 40383558  FUN_40383558  FUN_40383558  size=56

int FUN_40383558(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x54))
                    (param_1,**(undefined4 **)(*(int *)(param_1 + 4) + 4));
  if ((iVar1 == 0) && (iVar1 = FUN_4038350c(param_1,param_2,param_3,param_4), iVar1 == 0)) {
    iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x54))
                      (param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x10));
  }
  return iVar1;
}


