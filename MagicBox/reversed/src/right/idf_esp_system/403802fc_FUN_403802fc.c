void FUN_403802fc(void)

{
  int iVar1;
  
  iVar1 = DAT_403747cc;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(DAT_403747cc + 0x98) = *(uint *)(DAT_403747cc + 0x98) & 0xfffffc03 | 0x14;
  memw();
  memw();
  *(uint *)(iVar1 + 0x98) = *(uint *)(iVar1 + 0x98) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(iVar1 + 0x9c) = *(uint *)(iVar1 + 0x9c) & 0xfffffffb;
  memw();
  memw();
  *(uint *)(iVar1 + 0x9c) = *(uint *)(iVar1 + 0x9c) & 0xfffffff7;
  memw();
  memw();
  *(uint *)(iVar1 + 0xa0) = *(uint *)(iVar1 + 0xa0) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(iVar1 + 0x9c) = *(uint *)(iVar1 + 0x9c) & 0xffffffef;
  return;
}