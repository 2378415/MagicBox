void FUN_4037951c(int param_1)

{
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_40374a48 = *DAT_40374a48 & DAT_40374864;
  }
  else {
    if (param_1 != 1) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    memw();
    memw();
    *DAT_40374a48 = *DAT_40374a48 | DAT_40374a60;
  }
  (*DAT_40374444)(3);
  return;
}