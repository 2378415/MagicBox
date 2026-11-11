void FUN_42004450(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_42000528;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_4200052c;
  return;
}