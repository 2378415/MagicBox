void FUN_40375aa0(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_40374524;
  memw();
  if (((*DAT_40374524 & 4) == 0) && (memw(), (*DAT_40374528 & 4) != 0)) {
    (*DAT_403744fc)(*DAT_40374524 & 4);
  }
  memw();
  if (((*puVar1 & 0x20) == 0) && (memw(), (*DAT_40374528 & 0x20) != 0)) {
    (*DAT_403744fc)(1);
  }
  memw();
  if (((*puVar1 & 0x200) == 0) && (memw(), (*DAT_40374528 & 0x200) != 0)) {
    (*DAT_403744fc)(2);
  }
  puVar2 = DAT_40374558;
  memw();
  memw();
  *DAT_40374558 = *DAT_40374558 | DAT_4037455c;
  memw();
  *puVar2 = 0;
  puVar2 = DAT_40374564;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_40374560;
  memw();
  *puVar1 = 0;
  memw();
  memw();
  *puVar2 = *puVar2 | 0x40;
  puVar1 = DAT_40374568;
  memw();
  *puVar2 = 0;
  memw();
  memw();
  *puVar1 = *puVar1 | 2;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}