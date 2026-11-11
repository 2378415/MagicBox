// 4200302c  FUN_4200302c  FUN_4200302c  size=28

uint FUN_4200302c(void)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *DAT_42000244;
  uVar1 = uVar2 & 0x7fff;
  if (((uVar2 >> 0x10 & 0x7fff) != uVar1) || (-1 < (int)uVar2)) {
    uVar1 = 0;
  }
  return uVar1;
}


