// 4038096c  FUN_4038096c  FUN_4038096c  size=22

uint FUN_4038096c(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + -4) & 0xfffffffc;
  }
  return uVar1;
}


