// 40381bb0  FUN_40381bb0  FUN_40381bb0  size=101

uint FUN_40381bb0(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_CCOUNT;
  undefined1 in_PRID;
  
  iVar2 = FUN_4037e0e0();
  puVar1 = DAT_40375280;
  if (iVar2 == 1) {
    uVar3 = rsr(in_CCOUNT);
    iVar2 = (*DAT_403746fc)();
    uVar3 = uVar3 / (uint)(iVar2 * 1000);
  }
  else {
    if ((*DAT_40375280 == 0) && (uVar3 = rsr(in_PRID), (uVar3 >> 0xd & 1) == 0)) {
      uVar3 = rsr(in_CCOUNT);
      iVar2 = (*DAT_403746fc)();
      *puVar1 = uVar3 / (uint)(iVar2 * 1000);
    }
    iVar2 = FUN_4037bf20();
    if (iVar2 == 0) {
      iVar2 = FUN_4037d560();
    }
    else {
      iVar2 = FUN_4037d570();
    }
    uVar3 = iVar2 + *puVar1;
  }
  return uVar3;
}


