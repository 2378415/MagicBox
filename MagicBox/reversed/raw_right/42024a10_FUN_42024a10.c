// 42024a10  FUN_42024a10  FUN_42024a10  size=40

void FUN_42024a10(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(*param_1 + 0x78) >> 0x14 & 3;
  if (uVar1 == 2) {
    *param_2 = 9;
  }
  else if (uVar1 == 3) {
    *param_2 = 0xb;
  }
  else {
    *param_2 = 4;
  }
  return;
}


