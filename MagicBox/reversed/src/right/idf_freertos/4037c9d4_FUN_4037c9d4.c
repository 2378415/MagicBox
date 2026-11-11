undefined4 FUN_4037c9d4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x44) == DAT_403747f4) {
    memw();
    if (*DAT_40374e18 == 0) {
      uVar1 = 1;
    }
    else {
      memw();
      if (DAT_40374e18[1] == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else {
    memw();
    if (DAT_40374e18[*(int *)(param_1 + 0x44)] == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}