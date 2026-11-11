// 4037695c  FUN_4037695c  FUN_4037695c  size=84

void FUN_4037695c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_INTENABLE;
  undefined1 in_PRID;
  
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374708,0xffffffff);
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  uVar3 = *(uint *)(uVar2 * 4 + DAT_40374718);
  if (*(char *)(DAT_4037471c + uVar2) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_40381c60();
  }
  *(char *)(DAT_4037471c + uVar2) = '\x01';
  uVar1 = rsr(in_INTENABLE);
  FUN_40383bfc(uVar3);
  FUN_40376a88(uVar2);
  *(uint *)(DAT_40374720 + uVar2 * 4) = uVar3 & uVar1;
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_40374708);
  return;
}


