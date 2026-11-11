int FUN_42005044(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x102;
  }
  else {
    iVar1 = FUN_42004798(param_3);
    if (iVar1 == 0) {
      if (param_1 == 2) {
        FUN_420046ec(param_3,param_2);
        iVar1 = FUN_42005ab0();
      }
      else if (param_1 == 4) {
        FUN_420043f4(param_3,param_2);
        iVar1 = FUN_42005ab0();
      }
      else if (param_1 == 1) {
        FUN_4200404c(param_3,param_2);
        iVar1 = FUN_42005ab0();
      }
      else {
        iVar1 = DAT_420005b4;
      }
    }
  }
  return iVar1;
}