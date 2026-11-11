// 40375694  FUN_40375694  FUN_40375694  size=149

void FUN_40375694(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  memw();
  memw();
  *(uint *)(DAT_403744dc + 0x4c) = *(uint *)(DAT_403744dc + 0x4c) | 0x200;
  uVar3 = rsr(in_PRID);
  FUN_40378910((uVar3 >> 0xd & 1) == 0);
  FUN_403757d8(9);
  iVar1 = FUN_40381f90();
  if (iVar1 != 0) {
    FUN_403776bc();
  }
  for (uVar3 = 0; (int)uVar3 < 3; uVar3 = uVar3 + 1) {
    if (uVar3 == 0) {
      uVar2 = 4;
      uVar4 = 4;
    }
    else if (uVar3 == 1) {
      uVar2 = 0x20;
      uVar4 = 0x20;
    }
    else if (uVar3 == 2) {
      uVar2 = 0x200;
      uVar4 = 0x200;
    }
    else {
      uVar2 = 0;
      uVar4 = 0;
    }
    memw();
    if (((*DAT_403744e0 & uVar2) == 0) && (memw(), (*DAT_403744e4 & uVar4) != 0)) {
      (*DAT_403744c4)(uVar3 & 0xff);
    }
  }
  (*DAT_403744e8)();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


