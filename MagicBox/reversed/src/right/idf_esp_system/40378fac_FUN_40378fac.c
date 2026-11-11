void FUN_40378fac(char param_1,char param_2)

{
  if (param_1 == '\0') {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | 0x40;
    memw();
    memw();
    *DAT_403749a8 = *DAT_403749a8 & DAT_403749ac | 0x500;
  }
  else {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0xffffffbf;
    memw();
    memw();
    *DAT_403749a8 = *DAT_403749a8 & DAT_403749ac | 0x140;
    (*DAT_40374434)(0x32);
  }
  if (param_2 == '\0') {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 | 0x80;
  }
  else {
    memw();
    memw();
    *DAT_403749a4 = *DAT_403749a4 & 0xffffff7f;
  }
  return;
}