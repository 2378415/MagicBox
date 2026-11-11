bool FUN_42017124(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = true;
  if ((param_1 != param_2) && (bVar1 = false, *param_1 != '*')) {
    if (*param_2 == '*') {
      param_2 = param_2 + 1;
    }
    iVar2 = (*DAT_420007e8)(param_1,param_2);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}