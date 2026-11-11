uint FUN_40379820(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    iVar2 = FUN_40379160();
    if (iVar2 == 1) {
      param_1 = 2;
    }
    else if (iVar2 == 2) {
      param_1 = 1;
    }
  }
  else if (param_1 == 3) {
    param_1 = 0;
  }
  memw();
  uVar6 = *DAT_403749a4 >> 8 & 1 ^ 1;
  if ((uVar6 & param_1 == 2) != 0) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | 0x100;
  }
  memw();
  uVar5 = *DAT_403749a4;
  memw();
  uVar4 = *DAT_403749a4;
  if (param_1 == 1) {
    FUN_40378fac(1);
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | 0x200;
  }
  memw();
  if ((*DAT_40374a34 & 0x1000) != 0) {
    memw();
    memw();
    *DAT_40374a38 = *DAT_40374a38 & 0xff | 0x80;
    do {
      memw();
      if ((*DAT_40374a34 & 0x8000) != 0) break;
      memw();
    } while ((*DAT_40374a38 & 1) == 0);
  }
  puVar1 = DAT_40374a34;
  memw();
  memw();
  *DAT_40374a34 = *DAT_40374a34 & DAT_40374a3c | (param_1 & 3) << 0xd;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374a40;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374a44 | (param_2 & 0x7fff) << 0x10;
  if (param_1 == 2) {
    memw();
    memw();
    *DAT_40374a38 = *DAT_40374a38 & 0x7f | param_2 << 0x13;
    uVar7 = DAT_40374454;
  }
  else if (param_1 == 1) {
    memw();
    memw();
    *DAT_40374a38 = *DAT_40374a38 & 0x7f | param_2 << 0x13;
    uVar7 = DAT_403749c4;
  }
  else {
    memw();
    memw();
    *DAT_40374a38 = *DAT_40374a38 & 0x7f | param_2 << 0x11;
    uVar7 = DAT_403749c0;
  }
  (*DAT_403744c8)(param_2 * DAT_403746b8,(int)((ulonglong)param_2 * (ulonglong)DAT_403746b8 >> 0x20)
                  ,uVar7,0);
  puVar1 = DAT_40374a34;
  memw();
  memw();
  *DAT_40374a34 = *DAT_40374a34 & 0x7fffffff;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_4037450c;
  (*DAT_40374434)();
  do {
    memw();
    uVar3 = (*DAT_40374a34 >> 0xf & 1) << 0xf;
    if ((*DAT_40374a34 & 0x8000) != 0) {
      memw();
      uVar3 = *DAT_40374a48 >> 7;
      break;
    }
    memw();
  } while ((*DAT_40374a38 & 1) == 0);
  memw();
  memw();
  *DAT_40374a34 = *DAT_40374a34 & 0x7fffffff;
  if ((uVar6 & param_1 == 2) != 0) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0xfffffeff;
  }
  if (param_1 == 1) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0xfffffdff;
    FUN_40378fac((uVar5 & 0x40) == 0,(uVar4 & 0x80) == 0);
  }
  return uVar3;
}