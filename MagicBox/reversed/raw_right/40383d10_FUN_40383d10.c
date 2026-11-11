// 40383d10  FUN_40383d10  FUN_40383d10  size=24

uint FUN_40383d10(uint param_1)

{
  uint uVar1;
  undefined1 in_INTENABLE;
  
  uVar1 = xsr(in_INTENABLE,0);
  rsync();
  wsr(in_INTENABLE,uVar1 | param_1);
  rsync();
  return uVar1;
}


