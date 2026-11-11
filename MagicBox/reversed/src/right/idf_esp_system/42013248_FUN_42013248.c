uint FUN_42013248(void)

{
  uint uVar1;
  
  memw();
  memw();
  uVar1 = (*DAT_42000ff8 & 0x3ffff) << 0xc | *DAT_42000ff4 >> 0x14;
  if (uVar1 == 0 || uVar1 == DAT_42000214) {
    uVar1 = 0;
  }
  return uVar1;
}