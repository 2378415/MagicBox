void FUN_403791b4(int param_1)

{
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & DAT_403747e0;
  }
  else {
    if (param_1 != 1) {
                    /* WARNING: Subroutine does not return */
      FUN_40381ce0();
    }
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | DAT_403749c8;
  }
  (*DAT_40374434)(3);
  return;
}