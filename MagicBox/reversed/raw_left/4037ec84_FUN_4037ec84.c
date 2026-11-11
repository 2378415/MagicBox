// 4037ec84  FUN_4037ec84  FUN_4037ec84  size=37

undefined4 FUN_4037ec84(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    uVar2 = rsil(3);
    uVar1 = rsr(in_PRID);
    memw();
    param_1 = *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374e18);
    (*DAT_40374db8)(uVar2);
  }
  return *(undefined4 *)(param_1 + 0x44);
}


