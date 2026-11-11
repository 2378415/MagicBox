void FUN_40380290(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = DAT_40374850;
  memw();
  memw();
  memw();
  memw();
  memw();
  bVar1 = *(byte *)(param_1 + 0x2d);
  memw();
  *(uint *)(DAT_40374850 + 0x98) = *(uint *)(DAT_40374850 + 0x98) & 0xfffffc03 | 0x14;
  memw();
  memw();
  *(uint *)(iVar2 + 0x98) = *(uint *)(iVar2 + 0x98) | 1;
  memw();
  memw();
  *(uint *)(iVar2 + 0x9c) = *(uint *)(iVar2 + 0x9c) | 4;
  memw();
  memw();
  *(uint *)(iVar2 + 0x9c) = *(uint *)(iVar2 + 0x9c) & 0xfffffff7 | ((bVar1 ^ 0xffffffff) & 1) << 3;
  iVar4 = *(int *)(param_1 + 0x28);
  if (iVar4 == 0x78) {
    if (*(byte *)(param_1 + 0xc) == 0) {
      memw();
      memw();
      *(uint *)(iVar2 + 0x98) = *(uint *)(iVar2 + 0x98) & 0xfffffffd;
    }
    else {
      memw();
      memw();
      *(uint *)(iVar2 + 0x98) =
           *(uint *)(iVar2 + 0x98) & DAT_403751b4 | (*(byte *)(param_1 + 0xc) - 1 & 0x3f) << 10;
      memw();
      memw();
      *(uint *)(iVar2 + 0x98) = *(uint *)(iVar2 + 0x98) | 2;
    }
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0xa0) = *(uint *)(iVar2 + 0xa0) | 1;
  memw();
  memw();
  *(uint *)(iVar2 + 0x9c) = *(uint *)(iVar2 + 0x9c) | 0x10;
  memw();
  memw();
  uVar3 = (uint)*(byte *)(param_1 + 0x2c) * iVar4;
  uVar5 = 0x100;
  uVar7 = 4;
  if ((*(uint *)(iVar2 + 0xa4) >> 6 & 1) != 0) {
    uVar7 = 0x100;
  }
  if ((*(uint *)(iVar2 + 0xa4) >> 6 & 1) == 0) {
    uVar5 = 4;
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0xc) =
       *(uint *)(iVar2 + 0xc) & DAT_403751b8 |
       ((uint)(uVar3 % uVar7 != 0) + uVar3 / uVar5 & 0x3ff) << 2;
  memw();
  memw();
  *(uint *)(iVar2 + 0xa4) = *(uint *)(iVar2 + 0xa4) | 0x20;
  iVar4 = DAT_40374878;
  memw();
  memw();
  *(uint *)(iVar2 + 0xa4) = *(uint *)(iVar2 + 0xa4) | 0x40;
  memw();
  uVar3 = *(uint *)(iVar4 + 0xec) & 3;
  iVar2 = 5;
  if (uVar3 != 2) {
    iVar6 = 3;
    if (uVar3 != 0) {
      iVar6 = 4;
    }
    iVar2 = 8;
    if (uVar3 != 3) {
      iVar2 = iVar6;
    }
  }
  memw();
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & DAT_403751bc | iVar2 << 0x19;
  return;
}