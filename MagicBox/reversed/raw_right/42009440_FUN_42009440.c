// 42009440  FUN_42009440  FUN_42009440  size=49

uint FUN_42009440(void)

{
  bool bVar1;
  uint uVar2;
  byte local_30;
  
  bVar1 = false;
  while ((!bVar1 && (memw(), (DAT_42000190[1] & 4) != 0))) {
    memw();
    local_30 = (byte)*DAT_42000190;
    bVar1 = true;
  }
  if (bVar1) {
    uVar2 = (uint)local_30;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


