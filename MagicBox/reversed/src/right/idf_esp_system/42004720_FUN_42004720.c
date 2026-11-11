undefined4 FUN_42004720(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_4200059c = *DAT_4200059c | 1;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    memw();
    *DAT_420005a0 = *DAT_420005a0 | 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}