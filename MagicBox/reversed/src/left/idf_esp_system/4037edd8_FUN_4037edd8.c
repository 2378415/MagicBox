void FUN_4037edd8(void)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  
  FUN_4037ed9c();
  bVar1 = DAT_403750a4[1];
  (*DAT_403750ac)((uint)*DAT_403750a4 << 2);
  (*DAT_403750b0)((uint)bVar1 << 2);
  puVar3 = DAT_4037444c;
  puVar2 = DAT_40374448;
  memw();
  memw();
  *DAT_40374448 = *DAT_40374448;
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffffffd;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffe;
  memw();
  memw();
  *puVar3 = *puVar3;
  memw();
  memw();
  *puVar2 = *puVar2;
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffffffe;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffd;
  memw();
  memw();
  *puVar3 = *puVar3;
  return;
}