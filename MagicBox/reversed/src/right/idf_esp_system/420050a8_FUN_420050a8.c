int FUN_420050a8(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_42004798(param_2);
  if (iVar1 == 0) {
    if (param_1 == 2) {
      FUN_42004720(param_2);
      iVar1 = FUN_42005ab0();
      if (iVar1 == 0) {
        FUN_4200475c(param_2);
        iVar1 = FUN_42005ab0();
      }
    }
    else if (param_1 == 4) {
      FUN_42004428(param_2);
      iVar1 = FUN_42005ab0();
      if (iVar1 == 0) {
        FUN_42004464(param_2);
        iVar1 = FUN_42005ab0();
      }
    }
    else if (param_1 == 1) {
      FUN_42004080(param_2);
      iVar1 = FUN_42005ab0();
      if (iVar1 == 0) {
        FUN_420040bc(param_2);
        iVar1 = FUN_42005ab0();
      }
    }
    else {
      iVar1 = DAT_420005b4;
    }
  }
  return iVar1;
}