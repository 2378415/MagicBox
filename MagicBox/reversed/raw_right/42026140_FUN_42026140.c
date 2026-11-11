// 42026140  FUN_42026140  FUN_42026140  size=42

void FUN_42026140(void)

{
  int iVar1;
  
  iVar1 = DAT_42001084;
  memw();
  memw();
  *(uint *)(DAT_42001084 + 0x104) = *(uint *)(DAT_42001084 + 0x104) | DAT_420000a0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & DAT_42000b0c;
  return;
}


