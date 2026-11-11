// 4200bd80  FUN_4200bd80  FUN_4200bd80  size=47

int FUN_4200bd80(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar1 = FUN_4200ac64(*param_1);
  iVar2 = iVar1;
  if ((iVar1 != 0) && (iVar2 = FUN_4200bc34(param_1), iVar2 == 0)) {
    iVar2 = FUN_4200b9c0(local_30);
    param_1[1] = iVar2;
    param_1[2] = iVar2 + local_30[0];
    iVar2 = iVar1;
  }
  return iVar2;
}


