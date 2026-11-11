// 4037acd4  FUN_4037acd4  FUN_4037acd4  size=63

uint FUN_4037acd4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((*(uint *)(param_1 + 8) & 4) == 0) {
    uVar3 = *(uint *)(param_1 + 0x20);
    uVar2 = *(uint *)(param_1 + 0x2c);
    if (uVar3 < uVar2) {
      iVar1 = uVar2 - uVar3;
    }
    else {
      uVar3 = *(int *)(param_1 + 0x34) - uVar3;
      uVar2 = uVar2 - *(int *)(param_1 + 0x30);
      iVar1 = (uVar3 < uVar2) * uVar2 + (uVar3 >= uVar2) * uVar3;
    }
    uVar3 = iVar1 - 8;
    if ((int)uVar3 < 0) {
      uVar3 = 0;
    }
    else if (*(uint *)(param_1 + 4) < uVar3) {
      uVar3 = *(uint *)(param_1 + 4);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


