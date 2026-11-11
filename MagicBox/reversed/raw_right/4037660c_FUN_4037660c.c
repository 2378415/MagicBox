// 4037660c  FUN_4037660c  FUN_4037660c  size=99

void FUN_4037660c(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
  }
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  uVar3 = *(undefined4 *)(uVar2 * 4 + DAT_403746d4);
  if (*(char *)(DAT_403746d0 + uVar2) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_40381ce0();
  }
  *(undefined1 *)(DAT_403746d0 + uVar2) = 0;
  FUN_40383d10(uVar3);
  FUN_40376844(uVar2);
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bd38(PTR_DAT_403746c8);
  }
  else {
    FUN_4037bd38(PTR_DAT_403746c8);
  }
  return;
}


