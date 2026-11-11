// 40383b1c  FUN_40383b1c  FUN_40383b1c  size=47

void FUN_40383b1c(undefined4 *param_1)

{
  undefined1 in_BR;
  undefined1 in_SCOMPARE1;
  undefined1 in_ACCLO;
  undefined1 in_ACCHI;
  undefined1 in_M0;
  undefined1 in_M1;
  undefined1 in_M2;
  undefined1 in_M3;
  undefined1 in_VECBASE;
  
  wur(in_VECBASE,*param_1);
  wsr(in_ACCLO,param_1[1]);
  wsr(in_ACCHI,param_1[2]);
  wsr(in_BR,param_1[3]);
  wsr(in_SCOMPARE1,param_1[4]);
  wsr(in_M0,param_1[5]);
  wsr(in_M1,param_1[6]);
  wsr(in_M2,param_1[7]);
  wsr(in_M3,param_1[8]);
  return;
}


