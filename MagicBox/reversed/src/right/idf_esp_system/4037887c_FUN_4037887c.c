uint FUN_4037887c(void)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar1 = 0;
  for (uVar2 = *(uint *)(DAT_40374640 + 0x34) >> 0x12 & 7; uVar2 != 0; uVar2 = uVar2 >> 1) {
    if ((uVar2 & 1) != 0) {
      uVar1 = uVar1 ^ 1;
    }
  }
  return uVar1;
}