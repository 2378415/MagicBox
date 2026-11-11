// 42013c98  FUN_42013c98  FUN_42013c98  size=43

int FUN_42013c98(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_30 [4];
  int *apiStack_2c [11];
  
  FUN_420154e8(auStack_30);
  iVar1 = FUN_42013b60(param_1,apiStack_2c);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*apiStack_2c[0] + 0xc))(apiStack_2c[0],param_2,param_3,param_4);
  }
  FUN_420154f8(auStack_30);
  return iVar1;
}


