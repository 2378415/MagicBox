void FUN_4037f13c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  memw();
  *DAT_403750b0 = param_3 >> 5;
  memw();
  *DAT_403750b4 = param_1;
  FUN_4037f0d0(param_1,param_2,param_3);
  memw();
  *DAT_403750b8 = 1;
  return;
}