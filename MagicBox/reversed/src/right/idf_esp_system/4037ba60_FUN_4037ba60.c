void FUN_4037ba60(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = 0;
  do {
    if (0 < iVar1) {
      return;
    }
    pcVar2 = *(code **)(iVar1 * 4 + param_1 + 0x58);
    if (pcVar2 != (code *)0x0) {
      if ((((-(DAT_403745e8 + -1) & 0xffU) == 0 && (-(DAT_403745f0 + -1) & 0xffU) == 0) &&
          (DAT_403745f8 < pcVar2 + DAT_4037477c)) && (DAT_403745dc < pcVar2 + DAT_403745d8)) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0(pcVar2 + DAT_40374ce4);
      }
      (*pcVar2)(iVar1,*(undefined4 *)((iVar1 + 0x14) * 4 + param_1 + 4));
    }
    iVar1 = iVar1 + 1;
  } while( true );
}