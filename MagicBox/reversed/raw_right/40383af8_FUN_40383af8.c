// 40383af8  FUN_40383af8  FUN_40383af8  size=35

void FUN_40383af8(void)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_a5;
  undefined1 uVar3;
  
  uVar2 = rsr(0);
  iVar1 = (uVar2 & DAT_40374d78) + 3;
  wsr(0,iVar1);
  rsync();
  uVar3 = 0;
  FUN_403839e4(iVar1);
  wsr(uVar3,extraout_a5);
  rsync();
  return;
}


