// 42004388  FUN_42004388  FUN_42004388  size=104

undefined4 FUN_42004388(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_42000580 = *DAT_42000580 & 0xfffffffd;
    }
    else {
      memw();
      memw();
      *DAT_42000580 = *DAT_42000580 | 2;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 0) {
      memw();
      memw();
      *DAT_42000584 = *DAT_42000584 & 0xfffffffd;
      uVar1 = 0;
    }
    else {
      memw();
      memw();
      *DAT_42000584 = *DAT_42000584 | 2;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


