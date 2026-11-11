// 40376d2c  FUN_40376d2c  FUN_40376d2c  size=103

void FUN_40376d2c(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(DAT_40374768 + 8) & 2;
  memw();
  *(undefined4 *)(DAT_40374768 + 0x14) = 2;
  memw();
  if ((bool)*DAT_4037476c != (uVar1 != 0)) {
    if (uVar1 == 0) {
      if (*DAT_40374770 == 0) {
        FUN_40378e58();
        memw();
        *DAT_4037476c = '\0';
      }
      else {
        *DAT_40374770 = *DAT_40374770 + -1;
      }
    }
    else {
      FUN_40378e48();
      memw();
      *DAT_4037476c = '\x01';
      *DAT_40374770 = 3;
    }
  }
  return;
}


