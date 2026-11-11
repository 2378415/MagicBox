// 403785c8  FUN_403785c8  FUN_403785c8  size=47

undefined4 FUN_403785c8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40376cf8();
  if ((uint)(iVar1 - *(int *)(param_1 + 0xc)) < 1000) {
    if (DAT_403748b4 < (uint)(iVar1 - *(int *)(param_1 + 8))) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    *(int *)(param_1 + 8) = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}


