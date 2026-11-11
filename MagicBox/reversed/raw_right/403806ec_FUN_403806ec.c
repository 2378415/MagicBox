// 403806ec  FUN_403806ec  FUN_403806ec  size=33

void FUN_403806ec(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 + 0xc) * 4 + *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0x7fffffff | param_3 << 0x1f;
  return;
}


