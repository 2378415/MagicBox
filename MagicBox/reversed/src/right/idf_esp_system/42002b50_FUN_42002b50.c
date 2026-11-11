void FUN_42002b50(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_420003b4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_420003b8;
  return;
}