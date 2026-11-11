// 42024b5c  FUN_42024b5c  FUN_42024b5c  size=76

int FUN_42024b5c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  memw();
  memw();
  memw();
  if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
    uVar3 = 0;
  }
  else {
    memw();
    uVar3 = *(uint *)(iVar1 + 0x20) & 1 | 2;
  }
  if ((*(uint *)(iVar1 + 0x20) >> 4 & 3) < 2) {
    iVar2 = 1;
  }
  else {
    iVar2 = 2;
  }
  return (uint)(uVar3 != 0) + iVar2 + (*(uint *)(iVar1 + 0x20) >> 2 & 3) + 6;
}


