int FUN_42012d50(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 3;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_420004dc)(param_1);
    if (uVar1 < 2) {
      iVar2 = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    }
    else {
      iVar2 = 3;
    }
  }
  return iVar2;
}