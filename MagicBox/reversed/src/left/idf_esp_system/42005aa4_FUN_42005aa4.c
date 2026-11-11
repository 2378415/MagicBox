void FUN_42005aa4(void)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  
  puVar9 = (uint *)PTR_DAT_42000710;
  memw();
  memw();
  uVar8 = *DAT_4200070c & 0x3fffff;
  memw();
  *DAT_4200070c = *DAT_4200070c & 0xffc00000;
  puVar4 = PTR_DAT_42000718;
  puVar3 = DAT_42000714;
  iVar2 = 0;
  uVar5 = uVar8;
  do {
    if (uVar5 == 0) {
      return;
    }
    uVar7 = *puVar9;
    uVar5 = 1;
    if ((uVar8 & 1 << ((byte)uVar7 & 0x1f)) != 0) {
      memw();
      uVar6 = *puVar3;
      uVar8 = 1 << 0x20 - (0x20 - (uVar7 & 0x1f)) & uVar8 ^ uVar8;
      uVar5 = 1;
      memw();
      *puVar3 = *(uint *)(puVar4 + uVar7 * 0x38 + 0x28) & uVar6 ^ uVar6;
      if (uVar8 == 0) {
        uVar5 = 0;
      }
    }
    puVar9 = puVar9 + 1;
    bVar1 = iVar2 != 0x30;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return;
}