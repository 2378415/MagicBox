bool FUN_40376b90(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  return *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374754) != 0;
}