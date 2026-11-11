void FUN_40380110(int param_1)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = DAT_403747cc;
  bVar1 = *(byte *)(param_1 + 0x2d);
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(DAT_403747cc + 0x98) = *(uint *)(DAT_403747cc + 0x98) & 0xfffffc03 | 0x14;
  memw();
  memw();
  *(uint *)(iVar5 + 0x98) = *(uint *)(iVar5 + 0x98) | 1;
  memw();
  memw();
  *(uint *)(iVar5 + 0x9c) = *(uint *)(iVar5 + 0x9c) | 4;
  memw();
  memw();
  *(uint *)(iVar5 + 0x9c) = *(uint *)(iVar5 + 0x9c) & 0xfffffff7 | ((bVar1 ^ 1) & 1) << 3;
  iVar5 = DAT_403747cc;
  if (*(int *)(param_1 + 0x28) == 0x78) {
    if (*(byte *)(param_1 + 0xc) == 0) {
      memw();
      memw();
      *(uint *)(DAT_403747cc + 0x98) = *(uint *)(DAT_403747cc + 0x98) & 0xfffffffd;
    }
    else {
      memw();
      memw();
      *(uint *)(DAT_403747cc + 0x98) =
           *(uint *)(DAT_403747cc + 0x98) & DAT_403750f4 |
           (*(byte *)(param_1 + 0xc) - 1 & 0x3f) << 10;
      memw();
      memw();
      *(uint *)(iVar5 + 0x98) = *(uint *)(iVar5 + 0x98) | 2;
    }
  }
  iVar5 = DAT_403747cc;
  memw();
  memw();
  *(uint *)(DAT_403747cc + 0xa0) = *(uint *)(DAT_403747cc + 0xa0) | 1;
  memw();
  memw();
  *(uint *)(iVar5 + 0x9c) = *(uint *)(iVar5 + 0x9c) | 0x10;
  iVar3 = DAT_403747cc;
  uVar7 = (uint)*(byte *)(param_1 + 0x2c) * *(int *)(param_1 + 0x28);
  memw();
  if ((*(uint *)(iVar5 + 0xa4) & 0x40) == 0) {
    uVar6 = 4;
  }
  else {
    uVar6 = 0x100;
  }
  memw();
  if ((*(uint *)(DAT_403747cc + 0xa4) & 0x40) == 0) {
    uVar8 = 4;
  }
  else {
    uVar8 = 0x100;
  }
  memw();
  memw();
  *(uint *)(DAT_403747cc + 0xc) =
       *(uint *)(DAT_403747cc + 0xc) & DAT_403750f8 |
       (uVar7 / uVar6 + (uint)(uVar7 % uVar8 != 0) & 0x3ff) << 2;
  memw();
  memw();
  *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) | 0x20;
  memw();
  memw();
  *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) | 0x40;
  iVar4 = FUN_4037fa08();
  iVar3 = DAT_403750fc;
  lVar2 = (longlong)DAT_403750fc;
  iVar5 = FUN_4037fa08();
  iVar5 = iVar5 * 0x1e;
  memw();
  memw();
  *(uint *)(DAT_403747f8 + 0x10) =
       *(uint *)(DAT_403747f8 + 0x10) & DAT_40375100 |
       (((int)((iVar4 * 0x1e) * lVar2 >> 0x26) - (iVar4 * 0x1e >> 0x1f)) +
        (uint)(iVar5 + ((int)((longlong)iVar5 * (longlong)iVar3 >> 0x26) - (iVar5 >> 0x1f)) * -1000
              != 0) & 0x3f) << 0x19;
  return;
}