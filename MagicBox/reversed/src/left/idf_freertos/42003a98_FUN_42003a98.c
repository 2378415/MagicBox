void FUN_42003a98(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  FUN_42003ab8(uVar1);
  if (uVar1 != 0) {
    memw();
    *DAT_4200038c = 1;
  }
  return;
}