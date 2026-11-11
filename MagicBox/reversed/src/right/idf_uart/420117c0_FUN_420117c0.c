void FUN_420117c0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = (param_2 + 0x54) * 4 + **(int **)PTR_PTR_42000e00;
  memw();
  memw();
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xffffff7f;
  puVar1 = (uint *)((param_1 + DAT_42000de8) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 | 0x200;
  return;
}