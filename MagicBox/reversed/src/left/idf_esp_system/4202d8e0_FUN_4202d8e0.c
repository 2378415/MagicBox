int FUN_4202d8e0(int param_1,uint param_2)

{
  param_1 = param_1 << 0x1d;
  if (param_2 == 2) {
    witlb(param_1,3);
    isync();
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      witlb(param_1,0xf);
      isync();
      wdtlb(param_1,0xf);
      dsync();
    }
    else {
      wdtlb(param_1,0);
      dsync();
    }
  }
  else if (param_2 == 3) {
    wdtlb(param_1,2);
    dsync();
  }
  return param_1;
}