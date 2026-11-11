void FUN_40381f18(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(PTR_DAT_40375208,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_40375208,0xffffffff);
  }
  memw();
  memw();
  memw();
  *param_1 = *param_1 | param_3;
  memw();
  param_1[1] = param_1[1] | param_4;
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bd38(PTR_DAT_40375208);
  }
  else {
    FUN_4037bd38(PTR_DAT_40375208);
  }
  return;
}