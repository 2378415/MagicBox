// 42013c70  FUN_42013c70  FUN_42013c70  size=37

int FUN_42013c70(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_30 [4];
  int *apiStack_2c [11];
  
  FUN_420154e8(auStack_30);
  iVar1 = FUN_42013b60(param_1,apiStack_2c);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*apiStack_2c[0] + 0x28))();
  }
  FUN_420154f8(auStack_30);
  return iVar1;
}


