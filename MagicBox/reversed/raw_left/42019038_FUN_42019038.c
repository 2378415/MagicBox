// 42019038  FUN_42019038  FUN_42019038  size=41

/* WARNING: Control flow encountered bad instruction data */

uint FUN_42019038(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (DAT_420016f4 < param_1) {
    iVar2 = FUN_4201e57c();
    if (param_1 < *(uint *)(iVar2 + 0xc)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = -(param_1 - 1) & 0xff;
  }
  return uVar1;
}


