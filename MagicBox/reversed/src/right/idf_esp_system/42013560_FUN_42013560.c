uint FUN_42013560(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  memw();
  uVar3 = *DAT_42001030 >> 10 & 3;
  if (uVar3 == 1) {
    memw();
    if ((*DAT_42001024 & 4) == 0) {
      iVar2 = 0x140;
    }
    else if ((*DAT_42001024 >> 2 & 1) == 1) {
      iVar2 = 0x1e0;
    }
    else {
      iVar2 = 0;
    }
    memw();
    uVar3 = *DAT_42001024 & 3;
    if (uVar3 == 1) {
      iVar1 = 0xa0;
    }
    else if (uVar3 == 2) {
      iVar1 = 0xf0;
    }
    else if (uVar3 == 0) {
      iVar1 = 0x50;
    }
    else {
      iVar1 = 0;
    }
    if (iVar2 == 0x140 && iVar1 == 0xf0) {
      uVar3 = 0;
    }
    else {
      uVar3 = iVar1 * DAT_42000698;
    }
  }
  else {
    if ((uVar3 != 2) && (uVar3 != 0)) {
      uVar3 = 3;
    }
    iVar2 = FUN_42013510(uVar3);
    memw();
    uVar3 = (uint)(iVar2 * DAT_42000698) / ((*DAT_42001030 & 0x3ff) + 1);
  }
  return uVar3;
}