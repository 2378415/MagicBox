void FUN_4037cf88(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0x19; uVar1 = uVar1 + 1) {
    FUN_4037c8b8(DAT_40374e34 + uVar1 * 0x14);
  }
  FUN_4037c8b8(DAT_40374e80);
  FUN_4037c8b8(DAT_40374e84);
  for (uVar1 = 0; uVar1 < 2; uVar1 = uVar1 + 1) {
    FUN_4037c8b8(DAT_40374e88 + uVar1 * 0x14);
  }
  FUN_4037c8b8(DAT_40374e58);
  FUN_4037c8b8(DAT_40374e6c);
  memw();
  *DAT_40374e1c = DAT_40374e80;
  memw();
  *DAT_40374e70 = DAT_40374e84;
  return;
}