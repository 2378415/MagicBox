// 42002b78  FUN_42002b78  FUN_42002b78  size=39

void FUN_42002b78(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_420003bc;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_420003c0;
  return;
}


