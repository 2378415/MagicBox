// 40376258  FUN_40376258  FUN_40376258  size=39

uint FUN_40376258(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar2 = *(uint *)(DAT_40374680 + 0x34) >> 0x12 & 7;
  if (uVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    do {
      uVar3 = uVar2 & 1;
      uVar2 = uVar2 >> 1;
      uVar1 = uVar1 ^ uVar3;
    } while (uVar2 != 0);
  }
  return uVar1;
}


