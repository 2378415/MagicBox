// 42004adc  FUN_42004adc  FUN_42004adc  size=99

int FUN_42004adc(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x102;
  }
  else if (param_1 == 2) {
    memw();
    *(bool *)param_2 = *DAT_420005d8 == 1;
    iVar1 = 0;
  }
  else if (param_1 == 4) {
    iVar1 = FUN_42004798(param_3);
    if (iVar1 == 0) {
      FUN_420040f8(param_3,param_2);
      iVar1 = FUN_42005ab0();
    }
  }
  else if (param_1 == 1) {
    memw();
    *(bool *)param_2 = *DAT_420005d4 == 1;
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_420005b4;
  }
  return iVar1;
}


