uint FUN_4037b10c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(param_1 + 8) & 4;
  if ((*(uint *)(param_1 + 8) & 4) == 0) {
    uVar4 = *(uint *)(param_1 + 0x20);
    uVar3 = *(uint *)(param_1 + 0x2c);
    iVar2 = uVar3 - uVar4;
    if (uVar3 <= uVar4) {
      uVar4 = *(int *)(param_1 + 0x34) - uVar4;
      uVar3 = uVar3 - *(int *)(param_1 + 0x30);
      iVar2 = (uVar4 < uVar3) * uVar3 + (uVar4 >= uVar3) * uVar4;
    }
    uVar4 = iVar2 - 8;
    if (-1 < (int)uVar4) {
      uVar1 = *(uint *)(param_1 + 4);
      uVar1 = (uVar4 < uVar1) * uVar4 + (uVar4 >= uVar1) * uVar1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}