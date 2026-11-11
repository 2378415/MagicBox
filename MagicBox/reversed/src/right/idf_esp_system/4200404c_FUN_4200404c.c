undefined4 FUN_4200404c(int param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    *param_2 = (byte)(*DAT_42000550 >> 1) & 1;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    *param_2 = (byte)(*DAT_42000554 >> 1) & 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}