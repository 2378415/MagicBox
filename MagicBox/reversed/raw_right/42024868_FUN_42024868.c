// 42024868  FUN_42024868  FUN_42024868  size=43

undefined4 FUN_42024868(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 < 2) {
      if (param_1 == 1) {
        uVar1 = 8;
      }
      else {
        uVar1 = 0x40;
      }
    }
    else {
      uVar1 = 0x40;
    }
  }
  else if (param_1 - 5U < 2) {
    uVar1 = 0x200;
  }
  else {
    uVar1 = 0x40;
  }
  return uVar1;
}


