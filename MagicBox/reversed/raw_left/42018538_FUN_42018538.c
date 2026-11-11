// 42018538  FUN_42018538  FUN_42018538  size=56

void FUN_42018538(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = (param_2 + 0x54) * 4 + **(int **)PTR_PTR_420015e0;
  memw();
  memw();
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xffffff7f;
  puVar1 = (uint *)(param_1 * 4 + DAT_420015c0);
  memw();
  memw();
  *puVar1 = *puVar1 | 0x200;
  return;
}


