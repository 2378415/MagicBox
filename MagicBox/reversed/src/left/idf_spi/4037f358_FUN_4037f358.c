void FUN_4037f358(void)

{
  int *piVar1;
  
  piVar1 = DAT_40375178;
  do {
    memw();
  } while (*DAT_40375178 == 1);
  memw();
  *DAT_4037517c = 1;
  do {
    memw();
  } while (*piVar1 != 3);
  return;
}