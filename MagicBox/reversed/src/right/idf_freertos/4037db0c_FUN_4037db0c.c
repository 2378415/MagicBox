undefined4 FUN_4037db0c(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsil(3);
  memw();
  if (*DAT_40374e8c == 0) {
    uVar1 = 1;
  }
  else {
    uVar2 = rsr(in_PRID);
    memw();
    if (*(int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374e18) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0;
    }
  }
  (*DAT_40374d10)(uVar3);
  return uVar1;
}