// 42001c04  FUN_42001c04  FUN_42001c04  size=43

undefined4 FUN_42001c04(void)

{
  undefined4 uVar1;
  
  memw();
  if ((*DAT_42000148 & 0x1f) == 0) {
    memw();
    if ((*DAT_4200014c & 0x1f) == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


