// 4200475c  FUN_4200475c  FUN_4200475c  size=56

undefined4 FUN_4200475c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_4200059c = *DAT_4200059c & 0xfffffffe;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    memw();
    *DAT_420005a0 = *DAT_420005a0 & 0xfffffffe;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


