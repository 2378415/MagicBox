// 40376968  FUN_40376968  FUN_40376968  size=24

bool FUN_40376968(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  return *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374718) != 0;
}


