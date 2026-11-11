// 4200420c  FUN_4200420c  FUN_4200420c  size=156

void FUN_4200420c(void)

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
  memw();
  memw();
  *(uint *)(iVar1 + 0x1cc) = *(uint *)(iVar1 + 0x1cc) & 0xffff0000 | DAT_42000500;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1d4) = *(uint *)(iVar1 + 0x1d4) | 1;
  do {
    memw();
  } while ((*(uint *)(iVar1 + 0x1d4) & 1) != 0);
  do {
    memw();
  } while ((*(uint *)(iVar1 + 0x1d4) & 1) != 0);
  return;
}


