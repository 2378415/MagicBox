// 42006074  FUN_42006074  FUN_42006074  size=48
// strings: <k7@

void FUN_42006074(void)

{
  int *piVar1;
  
  (*(code *)PTR_FUN_42000700)(DAT_420006fc);
  if (*DAT_420006f4 != 0 || DAT_420006f4[1] != 0) {
    FUN_42005f3c();
    piVar1 = DAT_420006f4;
    *DAT_420006f4 = 0;
    piVar1[1] = 0;
  }
  (*(code *)PTR_FUN_42000704)(DAT_420006fc);
  return;
}


