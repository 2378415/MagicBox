void FUN_42001fcc(void)

{
  byte bVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  
  pcVar2 = DAT_42000024;
  memw();
  bVar1 = (byte)*PTR_DAT_42000020 >> 4;
  cVar4 = bVar1 + 0x30;
  bVar3 = *PTR_DAT_42000020 & 0xf;
  if (9 < bVar1) {
    cVar4 = bVar1 + 0x57;
  }
  *DAT_42000024 = cVar4;
  cVar4 = bVar3 + 0x30;
  if (9 < bVar3) {
    cVar4 = bVar3 + 0x57;
  }
  pcVar2[1] = cVar4;
  pcVar2[9] = '\0';
  return;
}