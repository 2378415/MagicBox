void FUN_4200241c(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  FUN_4200243c(uVar1);
  if (uVar1 != 0) {
    memw();
    *DAT_42000254 = 1;
  }
  return;
}