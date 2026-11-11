// 403794f0  FUN_403794f0  FUN_403794f0  size=40

undefined4 FUN_403794f0(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *DAT_40374a48 >> 0x1e;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      return DAT_40374a5c;
    }
    if (uVar1 == 0) {
      return DAT_40374a58;
    }
    FUN_40379270();
  }
  return DAT_40374464;
}


