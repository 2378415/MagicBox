// 40377a50  FUN_40377a50  FUN_40377a50  size=38

void FUN_40377a50(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  iVar1 = DAT_4037484c;
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  FUN_40377970((uint)(uVar2 == 0),(uint)(uVar2 == 0) * 4 + DAT_4037484c);
  FUN_40376598();
  FUN_40377970(uVar2,uVar2 * 4 + iVar1);
  return;
}


