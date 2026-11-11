void FUN_40376598(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_INTENABLE;
  undefined1 in_PRID;
  
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
  }
  uVar3 = rsr(in_PRID);
  uVar4 = uVar3 >> 0xd & 1;
  uVar3 = *(uint *)(uVar4 * 4 + DAT_403746cc);
  if (*(char *)(DAT_403746d0 + uVar4) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_40381ce0();
  }
  *(undefined1 *)(DAT_403746d0 + uVar4) = 1;
  uVar2 = rsr(in_INTENABLE);
  FUN_40383d28(uVar3);
  FUN_40376810(uVar4);
  *(uint *)(uVar4 * 4 + DAT_403746d4) = uVar3 & uVar2;
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bd38(PTR_DAT_403746c8);
  }
  else {
    FUN_4037bd38(PTR_DAT_403746c8);
  }
  return;
}