uint FUN_40379d38(uint param_1,uint param_2)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 uVar11;
  uint uVar12;
  
  if (param_1 == 0) {
    iVar6 = FUN_403794d4();
    if (iVar6 == 1) {
      param_1 = 2;
      uVar7 = 1;
      goto LAB_40379de6;
    }
    if (iVar6 != 2) {
      memw();
      memw();
      memw();
      uVar8 = *DAT_40374a48 >> 6 & 1 ^ 1;
      uVar9 = *DAT_40374a48 >> 7 & 1 ^ 1;
      uVar7 = 0;
      uVar12 = 0;
      puVar10 = DAT_40374a48;
      goto LAB_40379e7a;
    }
    memw();
    memw();
    memw();
    uVar8 = *DAT_40374a48 >> 6 & 1 ^ 1;
    uVar9 = *DAT_40374a48 >> 7 & 1 ^ 1;
  }
  else {
    if (param_1 == 3) {
      memw();
      memw();
      memw();
      uVar7 = 0;
      uVar8 = *DAT_40374a48 >> 6 & 1 ^ 1;
      uVar9 = *DAT_40374a48 >> 7 & 1 ^ 1;
      param_1 = 0;
      uVar12 = 0;
      puVar10 = DAT_40374a48;
      goto LAB_40379e7a;
    }
    uVar7 = (uint)(param_1 == 2);
LAB_40379de6:
    puVar10 = DAT_40374a48;
    memw();
    uVar9 = *DAT_40374a48 >> 8 & 1 ^ 1;
    uVar12 = uVar7 & uVar9;
    if ((uVar7 & uVar9) != 0) {
      memw();
      memw();
      *DAT_40374a48 = *DAT_40374a48 | 0x100;
      memw();
      memw();
      uVar8 = *puVar10 >> 6 & 1 ^ 1;
      uVar9 = *puVar10 >> 7 & 1 ^ 1;
      param_1 = 2;
      uVar7 = DAT_40374460;
      goto LAB_40379e7a;
    }
    memw();
    memw();
    uVar8 = *DAT_40374a48 >> 6 & 1 ^ 1;
    uVar9 = *DAT_40374a48 >> 7 & 1 ^ 1;
    uVar7 = (param_1 & 3) << 0xd;
    if (param_1 != 1) goto LAB_40379e7a;
  }
  puVar10 = DAT_40374a48;
  FUN_40379370(1);
  uVar7 = DAT_40374944;
  memw();
  param_1 = 1;
  memw();
  *puVar10 = *puVar10 | 0x200;
  uVar12 = 0;
LAB_40379e7a:
  puVar5 = DAT_40374b00;
  puVar4 = DAT_40374af0;
  memw();
  if ((*DAT_40374af0 & 0x1000) != 0) {
    memw();
    memw();
    *DAT_40374b00 = *DAT_40374b00 & 0xff | 0x80;
    do {
      memw();
      if ((*puVar4 & 0x8000) != 0) break;
      memw();
    } while ((*puVar5 & 1) == 0);
  }
  memw();
  memw();
  *puVar4 = *puVar4 & DAT_40374af4 | uVar7;
  uVar7 = DAT_40374afc;
  memw();
  memw();
  *puVar4 = *puVar4 & DAT_40374af8;
  memw();
  memw();
  *puVar4 = (param_2 & 0x7fff) << 0x10 | *puVar4 & uVar7;
  uVar3 = DAT_40374a5c;
  uVar11 = DAT_40374a58;
  uVar2 = DAT_40374464;
  if (param_1 == 2) {
    memw();
    memw();
    *puVar5 = *puVar5 & 0x7f | param_2 << 0x13;
    uVar11 = uVar2;
  }
  else {
    memw();
    if (param_1 == 1) {
      memw();
      *puVar5 = *puVar5 & 0x7f | param_2 << 0x13;
      uVar11 = uVar3;
    }
    else {
      memw();
      *puVar5 = *puVar5 & 0x7f | param_2 << 0x11;
    }
  }
  memw();
  memw();
  *puVar4 = *puVar4 & 0x7fffffff;
  memw();
  uVar1 = (ulonglong)DAT_403746f8;
  iVar6 = param_2 * DAT_403746f8;
  memw();
  *puVar4 = *puVar4 | DAT_40374550;
  (*DAT_40374500)(iVar6,(int)(param_2 * uVar1 >> 0x20),uVar11,0);
  (*DAT_40374444)();
  do {
    memw();
    uVar7 = (*puVar4 >> 0xf & 1) << 0xf;
    if ((*puVar4 & 0x8000) != 0) {
      memw();
      uVar7 = *DAT_40374b04 >> 7;
      break;
    }
    memw();
  } while ((*puVar5 & 1) == 0);
  memw();
  memw();
  *puVar4 = *puVar4 & 0x7fffffff;
  if (uVar12 == 0) {
    if (param_1 == 1) {
      memw();
      memw();
      *puVar10 = *puVar10 & 0xfffffdff;
      FUN_40379370(uVar8,uVar9);
    }
  }
  else {
    memw();
    memw();
    *puVar10 = *puVar10 & 0xfffffeff;
  }
  return uVar7;
}