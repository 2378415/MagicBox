void FUN_40375808(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar2 = 0; puVar1 = DAT_40374514, (int)uVar2 < 3; uVar2 = uVar2 + 1) {
    if (uVar2 == 0) {
      uVar3 = 4;
      uVar4 = 4;
    }
    else if (uVar2 == 1) {
      uVar3 = 0x20;
      uVar4 = 0x20;
    }
    else if (uVar2 == 2) {
      uVar3 = 0x200;
      uVar4 = 0x200;
    }
    else {
      uVar3 = 0;
      uVar4 = 0;
    }
    memw();
    if (((*DAT_403744e0 & uVar3) == 0) && (memw(), (*DAT_403744e4 & uVar4) != 0)) {
      (*DAT_403744c4)(uVar2 & 0xff);
    }
  }
  memw();
  memw();
  *DAT_40374514 = *DAT_40374514 | DAT_40374518;
  memw();
  *puVar1 = 0;
  puVar1 = DAT_403744e0;
  memw();
  memw();
  *DAT_403744e0 = *DAT_403744e0 | DAT_4037451c;
  memw();
  *puVar1 = 0;
  puVar1 = DAT_40374520;
  memw();
  memw();
  *DAT_40374520 = *DAT_40374520 | 0x40;
  memw();
  *puVar1 = 0;
  puVar1 = DAT_40374524;
  memw();
  memw();
  *DAT_40374524 = *DAT_40374524 | 2;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}