// 4201aa04  FUN_4201aa04  FUN_4201aa04  size=126

void FUN_4201aa04(int *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  memw();
  memw();
  memw();
  bVar1 = (*(uint *)(iVar3 + 0x20) & 2) != 0;
  if (bVar1) {
    memw();
  }
  iVar4 = 1;
  if (1 < (*(uint *)(iVar3 + 0x20) >> 4 & 3)) {
    iVar4 = 2;
  }
  uVar2 = ((*(uint *)(iVar3 + 0x20) >> 2 & 3) + 6 + (uint)bVar1 + iVar4) * (param_2 & 0xff);
  if (uVar2 == 0) {
    memw();
    memw();
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) & DAT_42000aa0;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar3 + 0x60) = *(uint *)(iVar3 + 0x60) & DAT_4200199c | (uVar2 & 0x3ff) << 0x11;
    memw();
    memw();
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | DAT_42000a9c;
  }
  return;
}


