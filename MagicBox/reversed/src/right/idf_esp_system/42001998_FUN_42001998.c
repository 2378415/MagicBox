/* WARNING: Control flow encountered bad instruction data */
/* (2 unreachable decompiler blocks omitted) */

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