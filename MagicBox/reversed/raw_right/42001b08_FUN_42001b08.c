// 42001b08  FUN_42001b08  FUN_42001b08  size=39

uint FUN_42001b08(void)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *DAT_42000120;
  uVar1 = uVar2 & 0x7fff;
  if (-1 < (int)uVar2 || (uVar2 >> 0x10 & 0x7fff) != uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}


