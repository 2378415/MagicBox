// 4037ca1c  FUN_4037ca1c  FUN_4037ca1c  size=59

void FUN_4037ca1c(void)

{
  memw();
  memw();
  if (*(int *)*DAT_40374e1c == 0) {
    memw();
    *DAT_40374e20 = 0xffffffff;
  }
  else {
    memw();
    memw();
    memw();
    memw();
    *DAT_40374e20 = **(undefined4 **)(*DAT_40374e1c + 0xc);
  }
  return;
}


