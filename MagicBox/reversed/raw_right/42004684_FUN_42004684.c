// 42004684  FUN_42004684  FUN_42004684  size=104

undefined4 FUN_42004684(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_4200059c = *DAT_4200059c & 0xfffffffd;
    }
    else {
      memw();
      memw();
      *DAT_4200059c = *DAT_4200059c | 2;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_420005a0 = *DAT_420005a0 & 0xfffffffd;
      uVar1 = 0;
    }
    else {
      memw();
      memw();
      *DAT_420005a0 = *DAT_420005a0 | 2;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


