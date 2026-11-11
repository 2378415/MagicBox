void FUN_420041a8(void)

{
  int iVar1;
  
  iVar1 = DAT_420004f0;
  memw();
  memw();
  *(uint *)(DAT_420004f0 + 0x1e8) = *(uint *)(DAT_420004f0 + 0x1e8) | DAT_420004f4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1e8) = *(uint *)(iVar1 + 0x1e8) & 0xffffff00 | 0x28;
  memw();
  memw();
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & DAT_420004f8 | DAT_420004fc;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1f8) = *(uint *)(iVar1 + 0x1f8) & 0xffff0000 | 400;
  return;
}