int FUN_4200b834(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4200b350(param_1,*(undefined2 *)(param_1 + 0x50));
  if (*(short *)(param_1 + 0x48) == 2) {
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else if (iVar1 < 1) {
    return iVar1;
  }
  iVar2 = FUN_4200b6a0(param_1);
  if (0 < iVar2) {
    iVar1 = iVar1 + iVar2;
    iVar2 = FUN_4200b6c0(param_1);
    if (-1 < iVar2) {
      iVar1 = iVar1 + iVar2;
      iVar2 = FUN_4200b79c(param_1);
      if (0 < iVar2) {
        iVar2 = iVar2 + iVar1;
      }
    }
  }
  return iVar2;
}