undefined4 FUN_42012a4c(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(DAT_42000f2c + 0xec) & 3;
  if (uVar1 != 2) {
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        return 0x50;
      }
      if (uVar1 == 1) {
        return 0x78;
      }
    }
    else if (uVar1 == 3) {
      return 0xf0;
    }
    (*(code *)PTR_FUN_4200006c)();
  }
  return 0xa0;
}