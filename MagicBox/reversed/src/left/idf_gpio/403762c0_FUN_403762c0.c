int FUN_403762c0(void)

{
  int iVar1;
  uint uVar2;
  
  memw();
  memw();
  uVar2 = *(uint *)(DAT_40374680 + 0x50) >> 0x12 & 7;
  iVar1 = (*(uint *)(DAT_40374680 + 0x58) >> 0x17 & 1) * 8 + uVar2;
  if (((uVar2 == 0) && (memw(), (*(uint *)(DAT_40374680 + 0x6c) & 3) == 1)) &&
     (memw(), (*(uint *)(DAT_40374680 + 0x50) >> 0x18 & 7) == 1)) {
    iVar1 = 0;
  }
  return iVar1;
}