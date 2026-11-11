int FUN_4202efd4(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    param_3 = param_2;
  }
  iVar1 = FUN_4202eeb4(param_1,param_3);
  if (iVar1 != 0) {
    FUN_4202ed54(iVar1,param_1 + *(int *)(iVar1 + 0x14),param_2 - *(int *)(iVar1 + 0x14));
  }
  return iVar1;
}