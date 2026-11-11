// 4037bb00  FUN_4037bb00  FUN_4037bb00  size=40

void FUN_4037bb00(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  rsil(3);
  FUN_40383c64();
  FUN_4037c34c();
  uVar1 = rsr(in_PRID);
  memw();
  *(undefined4 *)((uVar1 >> 0xd & 1) * 4 + DAT_40374ce8) = 1;
  FUN_40383af8();
  FUN_4037bee0();
  return;
}


