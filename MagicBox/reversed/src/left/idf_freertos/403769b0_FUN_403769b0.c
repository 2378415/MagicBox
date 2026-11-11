void FUN_403769b0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374708,0xffffffff);
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  uVar2 = *(undefined4 *)(uVar1 * 4 + DAT_40374720);
  if (*(char *)(DAT_4037471c + uVar1) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_40381c60();
  }
  *(char *)(DAT_4037471c + uVar1) = '\0';
  FUN_40383be4(uVar2);
  FUN_40376abc(uVar1);
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_40374708);
  return;
}