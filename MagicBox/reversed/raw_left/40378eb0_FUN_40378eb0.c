// 40378eb0  FUN_40378eb0  FUN_40378eb0  size=66

uint FUN_40378eb0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 in_CCOUNT;
  
  iVar2 = FUN_40376788();
  iVar3 = FUN_4037679c();
  puVar1 = DAT_403749ac;
  uVar4 = 0;
  do {
    iVar5 = rsr(in_CCOUNT);
    memw();
    uVar4 = uVar4 ^ *DAT_403749ac;
  } while ((uint)(iVar5 - *DAT_403749a8) < (uint)((iVar2 / iVar3) * 0x6f2));
  *DAT_403749a8 = iVar5;
  memw();
  return *puVar1 ^ uVar4;
}


