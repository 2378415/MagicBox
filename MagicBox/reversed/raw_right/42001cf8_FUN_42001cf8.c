// 42001cf8  FUN_42001cf8  FUN_42001cf8  size=52
// strings: TZ7@ | pf7@

void FUN_42001cf8(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  FUN_42002aa0(PTR_FUN_42000184,uVar1 >> 0xd & 1);
  (*(code *)PTR_FUN_42000140)(0x18);
  uVar1 = rsr(in_PRID);
  (*DAT_4200005c)(uVar1 >> 0xd & 1,0x37,0x18);
  (*(code *)PTR_FUN_42000144)(0x18);
  return;
}


