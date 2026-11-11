/* WARNING: Control flow encountered bad instruction data */

int FUN_4037b728(int param_1,undefined4 param_2)

{
  int iVar1;
  char unaff_a8;
  
  if ((param_1 == 0) || (unaff_a8 == '\x01')) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = FUN_4037b628(param_1,0,2);
  if (iVar1 != 0) {
    memw();
    *(undefined4 *)(iVar1 + 0x38) = param_2;
  }
  return iVar1;
}