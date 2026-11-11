// 40383d28  FUN_40383d28  FUN_40383d28  size=27

undefined8 FUN_40383d28(uint param_1)

{
  uint uVar1;
  undefined1 in_INTENABLE;
  
  uVar1 = xsr(in_INTENABLE,0);
  rsync();
  param_1 = (uVar1 | param_1) ^ param_1;
  wsr(in_INTENABLE,param_1);
  rsync();
  return CONCAT44(param_1,uVar1);
}


