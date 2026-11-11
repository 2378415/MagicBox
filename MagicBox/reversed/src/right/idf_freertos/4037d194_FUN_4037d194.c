void FUN_4037d194(void)

{
  uint uVar1;
  int *piVar2;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar1 = rsr(in_PRID);
  piVar2 = (int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374e18);
  memw();
  memw();
  *piVar2 = *piVar2 + 1;
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}