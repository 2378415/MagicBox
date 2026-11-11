// 4037b0d4  FUN_4037b0d4  FUN_4037b0d4  size=54

uint FUN_4037b0d4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 8);
  if (((((uVar2 & 2) == 0) || (uVar1 = 0, *(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c))) &&
      (uVar1 = 0, 0 < *(int *)(param_1 + 0x38))) &&
     (((*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24) || ((uVar2 & 4) != 0)) &&
      (uVar1 = 1, (uVar2 & 3) == 0)))) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x28) + 4) >> 3 & 1;
  }
  return uVar1;
}


