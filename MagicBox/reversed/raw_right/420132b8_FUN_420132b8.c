// 420132b8  FUN_420132b8  FUN_420132b8  size=45

uint FUN_420132b8(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = DAT_42000afc;
  }
  else {
    uVar1 = param_1 - 1;
    uVar1 = uVar1 | ((int)uVar1 / 2 & 0xffU) << 8 | (uVar1 & 0xff) << 0x10;
  }
  return uVar1;
}


