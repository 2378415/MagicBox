int FUN_420048a8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_420005b8;
  if (param_1 == 2) {
    if (param_2 == 8) {
      FUN_4200453c(param_3,DAT_420005c8);
      iVar1 = FUN_42005ab0();
    }
    else if (param_2 == 0x10) {
      FUN_4200453c(param_3,DAT_420005cc);
      iVar1 = FUN_42005ab0();
    }
  }
  else if (param_1 == 4) {
    if (param_2 == 1) {
      iVar1 = FUN_42004798(param_4);
      if (iVar1 == 0) {
        FUN_42004134(param_4,param_3,1);
        iVar1 = FUN_42005ab0();
      }
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 2) {
      FUN_42003e7c(param_3,DAT_420005c0);
      iVar1 = FUN_42005ab0();
    }
    else if (param_2 == 4) {
      FUN_42003e7c(param_3,DAT_420005c4);
      iVar1 = FUN_42005ab0();
    }
    else if (param_2 == 1) {
      FUN_42003e7c(param_3,DAT_420005bc);
      iVar1 = FUN_42005ab0();
    }
  }
  else {
    iVar1 = DAT_420005b4;
  }
  return iVar1;
}