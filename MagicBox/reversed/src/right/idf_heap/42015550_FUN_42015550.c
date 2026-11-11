void FUN_42015550(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_42024e9c(param_1,iVar2);
    (*(code *)PTR_FUN_420004c0)(iVar2);
    iVar2 = iVar1;
  }
  return;
}