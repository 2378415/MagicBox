// 4037ed9c  FUN_4037ed9c  FUN_4037ed9c  size=58

void FUN_4037ed9c(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  
  puVar3 = DAT_403750a8;
  pbVar2 = DAT_403750a4;
  puVar1 = DAT_403750a0;
  memw();
  DAT_403750a4[1] = (byte)(*DAT_403750a0 >> 2) & 1;
  memw();
  *pbVar2 = (byte)(*puVar3 >> 2) & 1;
  memw();
  pbVar2[3] = (byte)(*puVar1 >> 2) & 1;
  memw();
  pbVar2[2] = (byte)(*puVar3 >> 2) & 1;
  return;
}


