// 4037ef4c  FUN_4037ef4c  FUN_4037ef4c  size=52

uint FUN_4037ef4c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    memw();
    uVar1 = *DAT_403750d0;
  }
  else {
    if (param_2 != 1) {
      memw();
      if ((*DAT_403750d0 & 1) == 0) {
        return *DAT_403750d0 & 1;
      }
    }
    memw();
    uVar1 = *DAT_403750d4;
  }
  return uVar1 & 1;
}


