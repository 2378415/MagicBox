// 4200327c  FUN_4200327c  FUN_4200327c  size=52

void FUN_4200327c(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  FUN_4200409c(PTR_LAB_420002ac,uVar1 >> 0xd & 1);
  (*(code *)PTR_FUN_42000264)(0x18);
  uVar1 = rsr(in_PRID);
  (*DAT_42000268)(uVar1 >> 0xd & 1,0x37,0x18);
  (*(code *)PTR_FUN_4200026c)(0x18);
  return;
}


