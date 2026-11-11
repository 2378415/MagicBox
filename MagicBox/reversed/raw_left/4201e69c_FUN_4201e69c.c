// 4201e69c  FUN_4201e69c  FUN_4201e69c  size=36

void FUN_4201e69c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      FUN_4201ea1c(iVar2 + 0x30);
      iVar2 = iVar1;
    }
    (*(code *)PTR_FUN_42000570)(param_1);
  }
  return;
}


