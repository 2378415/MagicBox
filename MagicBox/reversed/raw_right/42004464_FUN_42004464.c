// 42004464  FUN_42004464  FUN_42004464  size=56

undefined4 FUN_42004464(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_42000580 = *DAT_42000580 & 0xfffffffe;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    memw();
    *DAT_42000584 = *DAT_42000584 & 0xfffffffe;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


