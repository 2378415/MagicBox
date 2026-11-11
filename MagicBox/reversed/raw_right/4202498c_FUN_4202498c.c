// 4202498c  FUN_4202498c  FUN_4202498c  size=26

undefined4 FUN_4202498c(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & 1) == 0) {
    uVar1 = 0;
  }
  else if ((param_1 & 0x14) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


