// 40379374  FUN_40379374  FUN_40379374  size=375
// strings: gffft>

void FUN_40379374(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined1 auStack_30 [12];
  uint uStack_24;
  
  uVar2 = (int)((longlong)(int)param_1 * (longlong)DAT_403749d8 >> 0x25) - ((int)param_1 >> 0x1f);
  FUN_40379294(auStack_30);
  if (uStack_24 < param_1) {
    if (param_1 == 0xf0) {
      FUN_4037690c(0x6d,1,4,4,0,*PTR_DAT_403749dc);
      FUN_4037690c(0x6d,1,6,4,0,*PTR_DAT_403749e0);
      (*DAT_40374434)(0x28);
    }
    memw();
    memw();
    *DAT_403749e4 = *DAT_403749e4 & DAT_403749e8 | (7 >> (uVar2 & 0x1f) & 0x3fU) << 0xd;
  }
  if (param_1 == 0xa0) {
    memw();
    memw();
    *DAT_40374960 = *DAT_40374960 & 0xfffffffc | 1;
  }
  else if (param_1 == 0xf0) {
    memw();
    memw();
    *DAT_40374960 = *DAT_40374960 & 0xfffffffc | 2;
  }
  else {
    if (param_1 != 0x50) {
                    /* WARNING: Subroutine does not return */
      FUN_40381ce0();
    }
    memw();
    memw();
    *DAT_40374960 = *DAT_40374960 & 0xfffffffc;
  }
  puVar1 = DAT_403749d0;
  memw();
  memw();
  *DAT_403749d0 = *DAT_403749d0 & 0xfffffc00;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_403749ec | 0x400;
  FUN_40379368(DAT_403746c0);
  (*DAT_403749f8)(param_1);
  if (param_1 < uStack_24) {
    if (uStack_24 == 0xf0) {
      FUN_4037690c(0x6d,1,4,4,0,*PTR_DAT_403749f0);
      FUN_4037690c(0x6d,1,6,4,0,*PTR_DAT_403749f4);
      (*DAT_40374434)(0x28);
    }
    memw();
    memw();
    *DAT_403749e4 = *DAT_403749e4 & DAT_403749e8 | (7 >> (uVar2 & 0x1f) & 0x3fU) << 0xd;
  }
  return;
}


