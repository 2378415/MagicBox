int FUN_4200b6c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_30 [12];
  
  iVar1 = 0;
  local_30[0] = 0;
  uVar3 = 0;
  while( true ) {
    if (3 < uVar3) {
      return iVar1;
    }
    iVar2 = FUN_4200ac30(uVar3,local_30);
    if (iVar2 < 0) break;
    if (0 < iVar2) {
      iVar2 = FUN_4200b33c(param_1,local_30[0],iVar2);
      if (iVar2 < 1) {
        return iVar2;
      }
      iVar1 = iVar1 + iVar2;
    }
    uVar3 = uVar3 + 1;
  }
  return -3;
}