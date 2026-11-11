// 40375f64  FUN_40375f64  FUN_40375f64  size=72

uint FUN_40375f64(void)

{
  uint uVar1;
  
  memw();
  memw();
  if ((((*(uint *)(DAT_40374640 + 0x50) >> 0x12 & 7) == 0) &&
      (memw(), (*(uint *)(DAT_40374640 + 0x6c) & 3) == 1)) &&
     (memw(), (*(uint *)(DAT_40374640 + 0x50) >> 0x18 & 7) == 1)) {
    uVar1 = 0;
  }
  else {
    memw();
    uVar1 = *(uint *)(DAT_40374640 + 0x58) >> 0x18 & 3;
  }
  return uVar1;
}


