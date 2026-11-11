// 4200b604  FUN_4200b604  FUN_4200b604  size=38

int FUN_4200b604(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4200b320(param_1,param_2);
  if (0 < iVar1) {
    iVar2 = FUN_4200b5d8(param_1,param_2);
    if (iVar2 == -2) {
      iVar1 = -2;
    }
    else {
      iVar1 = iVar1 + iVar2;
    }
  }
  return iVar1;
}


