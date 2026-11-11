// 42005cd0  FUN_42005cd0  FUN_42005cd0  size=59

undefined4 FUN_42005cd0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = FUN_4201349c();
  }
  else if (param_1 == 2) {
    FUN_42005bcc(0x400);
    uVar1 = (*(code *)PTR_FUN_4200068c)();
  }
  else if (param_1 == 0) {
    memw();
    uVar1 = (*(code *)PTR_FUN_4200068c)(*DAT_42000468);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


