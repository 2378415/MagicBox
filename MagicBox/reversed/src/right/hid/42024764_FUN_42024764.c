undefined4 FUN_42024764(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  memw();
  memw();
  memw();
  memw();
  uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0x440) >> 0x11 & 3;
  if (uVar2 == 0) {
    uVar1 = 3;
  }
  else if (uVar2 == 1) {
    uVar1 = 2;
  }
  else if (uVar2 == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}