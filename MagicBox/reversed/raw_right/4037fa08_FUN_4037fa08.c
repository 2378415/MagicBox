// 4037fa08  FUN_4037fa08  FUN_4037fa08  size=57

undefined4 FUN_4037fa08(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *(uint *)(DAT_403747f8 + 0xec) & 3;
  if (uVar2 == 2) {
    uVar1 = 0xa0;
  }
  else if (uVar2 < 3) {
    if (uVar2 == 0) {
      uVar1 = 0x50;
    }
    else {
      if (uVar2 != 1) goto LAB_4037fa28;
      uVar1 = 0x78;
    }
  }
  else {
    if (uVar2 != 3) {
LAB_4037fa28:
                    /* WARNING: Subroutine does not return */
      FUN_40381ce0();
    }
    uVar1 = 0xf0;
  }
  return uVar1;
}


