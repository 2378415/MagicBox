// 4038379c  FUN_4038379c  FUN_4038379c  size=25

uint FUN_4038379c(int param_1)

{
  uint uVar1;
  
  if (*(byte *)(param_1 + 0x18) < 0x19) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  return uVar1 | 4;
}


