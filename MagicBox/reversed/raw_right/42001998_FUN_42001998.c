// 42001998  FUN_42001998  FUN_42001998  size=133

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x420019d2) */
/* WARNING: Removing unreachable block (ram,0x42001a1c) */

void FUN_42001998(void)

{
  (*DAT_420000a8)(0);
  (*DAT_420000a8)(1);
  memw();
  memw();
  memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


