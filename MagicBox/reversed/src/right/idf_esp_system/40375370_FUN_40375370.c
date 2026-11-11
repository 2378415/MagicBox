void FUN_40375370(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar1 = (uint)((*DAT_40374438 & 1) == 0);
  memw();
  if ((*DAT_4037443c & 2) == 0) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0;
  }
  FUN_4037ead0(1,2);
  for (uVar3 = 1; uVar3 < 2; uVar3 = uVar3 + 1) {
    if (uVar3 == 0) {
      uVar4 = uVar1;
    }
    else {
      uVar4 = uVar1 * 2;
    }
    memw();
    memw();
    *DAT_40374438 = uVar4 & *DAT_40374438 ^ *DAT_40374438;
    if (uVar3 == 1) {
      uVar4 = uVar2 >> 3;
    }
    else {
      uVar4 = uVar2 >> 2;
    }
    memw();
    memw();
    *DAT_4037443c = uVar4 & *DAT_4037443c ^ *DAT_4037443c;
  }
  FUN_4037eb0c(1,2);
  return;
}