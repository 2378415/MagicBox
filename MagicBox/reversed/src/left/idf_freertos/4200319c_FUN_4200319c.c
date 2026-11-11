undefined4 FUN_4200319c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  memw();
  if ((*DAT_42000270 & 0x1f) == 0) {
    uVar1 = 1;
    memw();
    if ((*DAT_42000274 & 0x1f) == 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}