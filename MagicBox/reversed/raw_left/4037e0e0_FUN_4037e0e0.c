// 4037e0e0  FUN_4037e0e0  FUN_4037e0e0  size=52

char FUN_4037e0e0(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsil(3);
  cVar1 = '\x01';
  memw();
  if (*DAT_40374f10 != 0) {
    uVar2 = rsr(in_PRID);
    memw();
    cVar1 = (*(int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374ed8) == 0) * '\x02';
  }
  (*DAT_40374db8)(uVar3);
  return cVar1;
}


