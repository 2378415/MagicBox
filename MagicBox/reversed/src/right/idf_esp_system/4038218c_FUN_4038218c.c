/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4038218c(undefined4 *param_1,int param_2)

{
  if ((((-(DAT_40374d80 + -1) & 0xffU) == 0 && (-((int)param_1 + DAT_40374d84 + -1) & 0xffU) == 0)
      && ((-(DAT_403745dc + -1) & 0xffU) == 0)) && (*(int *)(param_2 + 0x1c) == 0)) {
    return 0x102;
  }
  if (*(int *)(param_2 + 0x1c) == 0) {
    *param_1 = PTR_PTR_40375230;
  }
  else {
    *param_1 = PTR_PTR_40375234;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}