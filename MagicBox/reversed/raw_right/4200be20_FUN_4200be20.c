// 4200be20  FUN_4200be20  FUN_4200be20  size=86

int FUN_4200be20(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  while( true ) {
    if (7 < uVar3) {
      return 0;
    }
    uVar4 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
    if ((uVar4 & *DAT_42000ad0) == 0) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  *DAT_42000ad0 = uVar4 | *DAT_42000ad0;
  iVar1 = DAT_42000ad4;
  iVar2 = uVar3 * 0x98 + DAT_42000ad4;
  (*DAT_42000240)(iVar2,0,0x98);
  *(char *)(iVar1 + uVar3 * 0x98 + 0x90) = (char)uVar3;
  return iVar2;
}


