void FUN_4037c354(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  FUN_40375f3c();
  uVar2 = rsr(in_PRID);
  if ((uVar2 >> 0xd & 1) == 0) {
    iVar1 = FUN_4037d1f4();
  }
  else {
    iVar1 = FUN_4037e608();
  }
  if (iVar1 != 0) {
    FUN_4037be34();
  }
  return;
}