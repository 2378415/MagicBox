bool FUN_4037bbc4(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsil(3);
  uVar1 = rsr(in_PRID);
  iVar2 = *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374718);
  (*DAT_40374d10)(uVar3);
  return iVar2 != 0;
}