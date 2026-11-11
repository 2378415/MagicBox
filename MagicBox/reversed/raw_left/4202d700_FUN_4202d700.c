// 4202d700  FUN_4202d700  FUN_4202d700  size=53

void FUN_4202d700(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffe | param_2 & 1;
  }
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffd | (param_2 >> 1 & 1) * 2;
  return;
}


