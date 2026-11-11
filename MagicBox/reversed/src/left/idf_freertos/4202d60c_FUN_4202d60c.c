int FUN_4202d60c(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < *(uint *)(param_1 + 0xc)) {
    uVar1 = uVar1 + *(int *)(param_1 + 4);
  }
  return uVar1 - *(uint *)(param_1 + 0xc);
}