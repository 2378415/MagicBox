// 4202e730  FUN_4202e730  FUN_4202e730  size=42

void FUN_4202e730(void)

{
  int iVar1;
  
  iVar1 = DAT_420019dc;
  memw();
  memw();
  *(uint *)(DAT_420019dc + 0x104) = *(uint *)(DAT_420019dc + 0x104) | DAT_4200034c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & DAT_4200140c;
  return;
}


