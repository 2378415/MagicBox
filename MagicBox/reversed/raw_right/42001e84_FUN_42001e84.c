// 42001e84  FUN_42001e84  FUN_42001e84  size=59
// strings: gfff

void FUN_42001e84(int param_1)

{
  int iVar1;
  
  iVar1 = (int)((longlong)param_1 * (longlong)DAT_420001a0 >> 0x22) - (param_1 >> 0x1f);
  if (iVar1 == 0) {
    FUN_42001e18(0x20);
  }
  else {
    FUN_42001e18(iVar1 + 0x30U & 0xff);
  }
  FUN_42001e18(param_1 + iVar1 * -10 + 0x30U & 0xff);
  return;
}


