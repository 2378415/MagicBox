int FUN_403791f8(void)

{
  uint uVar1;
  int iVar2;
  
  memw();
  uVar1 = *DAT_403749cc;
  if ((uVar1 & 0xffff) == uVar1 >> 0x10) {
    if (uVar1 - 1 < 0xfffffffe) {
      uVar1 = uVar1 >> 1 & 0x7fff;
      iVar2 = uVar1 * 2;
      if (uVar1 == 0) {
        iVar2 = 0x28;
      }
    }
    else {
      iVar2 = 0x28;
    }
  }
  else {
    iVar2 = 0x28;
  }
  return iVar2;
}