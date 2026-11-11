int FUN_420022a4(int *param_1)

{
  int iVar1;
  undefined1 local_30;
  char acStack_2f [47];
  
  acStack_2f[0] = '\0';
  local_30 = 1;
  if (param_1 == (int *)0x0) {
    iVar1 = 0x102;
  }
  else {
    iVar1 = 0x102;
    if (((*(short *)(*param_1 + 2) == 1) && (iVar1 = FUN_42002190(param_1,acStack_2f,1), iVar1 == 0)
        ) && (acStack_2f[0] == '\0')) {
      iVar1 = FUN_42002238(param_1,&local_30,1);
    }
  }
  return iVar1;
}