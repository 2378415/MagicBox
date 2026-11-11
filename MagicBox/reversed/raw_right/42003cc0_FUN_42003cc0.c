// 42003cc0  FUN_42003cc0  FUN_42003cc0  size=123

void FUN_42003cc0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  memw();
  uVar1 = *DAT_42000514 & 0x3fffff;
  memw();
  memw();
  *DAT_42000514 = *DAT_42000514 & 0xffc00000;
  iVar2 = 0;
  while (uVar1 != 0) {
    uVar3 = *(uint *)(PTR_DAT_42000518 + iVar2 * 4);
    if ((uVar1 & 1 << ((byte)uVar3 & 0x1f)) != 0) {
      memw();
      memw();
      *DAT_4200051c =
           *(uint *)(PTR_DAT_42000520 + uVar3 * 0x38 + 0x28) & *DAT_4200051c ^ *DAT_4200051c;
      uVar1 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f)) & uVar1 ^ uVar1;
    }
    iVar2 = iVar2 + 1;
  }
  return;
}


