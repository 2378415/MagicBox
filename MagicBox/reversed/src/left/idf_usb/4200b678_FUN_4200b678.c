uint FUN_4200b678(void)

{
  uint uVar1;
  
  memw();
  if ((DAT_420002b0[1] & 4) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    memw();
    uVar1 = *DAT_420002b0 & 0xff;
  }
  return uVar1;
}