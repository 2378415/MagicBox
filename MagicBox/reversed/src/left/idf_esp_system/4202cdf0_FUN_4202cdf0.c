int FUN_4202cdf0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      param_1 = param_1 + 1;
      iVar1 = iVar1 + (uint)*(ushort *)(iVar2 + 2);
      iVar2 = *param_1;
    }
  }
  return iVar1;
}