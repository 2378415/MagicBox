// 40376280  FUN_40376280  FUN_40376280  size=62

uint FUN_40376280(void)

{
  uint uVar1;
  
  memw();
  memw();
  if ((((*(uint *)(DAT_40374680 + 0x50) >> 0x12 & 7) != 0) ||
      (memw(), (*(uint *)(DAT_40374680 + 0x6c) & 3) != 1)) ||
     (memw(), uVar1 = 0, (*(uint *)(DAT_40374680 + 0x50) >> 0x18 & 7) != 1)) {
    memw();
    uVar1 = *(uint *)(DAT_40374680 + 0x58) >> 0x18 & 3;
  }
  return uVar1;
}


