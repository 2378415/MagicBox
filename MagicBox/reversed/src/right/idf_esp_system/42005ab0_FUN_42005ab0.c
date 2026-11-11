// strings: &R$fb'!

undefined4 FUN_42005ab0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 4) {
    uVar1 = DAT_42000640;
  }
  else if (param_1 < 5) {
    if (param_1 == 2) {
      uVar1 = DAT_42000638;
    }
    else if (param_1 == 3) {
      uVar1 = DAT_4200063c;
    }
    else if (param_1 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else if (param_1 == 5) {
    uVar1 = DAT_42000648;
  }
  else if (param_1 == 6) {
    uVar1 = DAT_42000644;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}