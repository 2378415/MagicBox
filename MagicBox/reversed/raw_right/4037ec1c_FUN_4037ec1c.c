// 4037ec1c  FUN_4037ec1c  FUN_4037ec1c  size=75

uint FUN_4037ec1c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    memw();
    uVar1 = *DAT_40375004 & 1;
  }
  else if (param_2 == 1) {
    memw();
    uVar1 = *DAT_40375008 & 1;
  }
  else {
    memw();
    if ((*DAT_40375004 & 1) == 0) {
      uVar1 = 0;
    }
    else {
      memw();
      if ((*DAT_40375008 & 1) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


