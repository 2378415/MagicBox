// 4037be6c  FUN_4037be6c  FUN_4037be6c  size=40

void FUN_4037be6c(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  rsil(3);
  FUN_40383b38();
  FUN_4037c760();
  uVar1 = rsr(in_PRID);
  memw();
  *(undefined4 *)((uVar1 >> 0xd & 1) * 4 + DAT_40374d90) = 1;
  FUN_403839cc();
  FUN_4037c2bc();
  return;
}


