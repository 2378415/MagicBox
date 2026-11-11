// 4200bc14  FUN_4200bc14  FUN_4200bc14  size=32

int FUN_4200bc14(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  iVar1 = FUN_4200bc0c();
  uVar2 = rsr(in_PRID);
  return iVar1 + ((uVar2 >> 0xd & 1) + 1) * 0x830;
}


