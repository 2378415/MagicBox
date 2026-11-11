void FUN_403794d4(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *DAT_40374a48 >> 0x1e;
  if (((uVar1 != 1) && (uVar1 != 2)) && (uVar1 != 0)) {
    FUN_40379270();
  }
  return;
}