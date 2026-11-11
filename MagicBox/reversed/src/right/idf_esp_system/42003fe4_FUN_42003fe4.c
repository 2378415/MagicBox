undefined4 FUN_42003fe4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_42000550 = *DAT_42000550 & 0xfffffffd;
    }
    else {
      memw();
      memw();
      *DAT_42000550 = *DAT_42000550 | 2;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_42000554 = *DAT_42000554 & 0xfffffffd;
      uVar1 = 0;
    }
    else {
      memw();
      memw();
      *DAT_42000554 = *DAT_42000554 | 2;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}