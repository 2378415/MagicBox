undefined4 FUN_4037e090(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar1 = 0;
  if (param_2 < 2) {
    if (param_1 == 0) {
      uVar1 = rsil(3);
      uVar2 = rsr(in_PRID);
      memw();
      param_1 = *(int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374e18);
      (*DAT_40374db8)(uVar1);
    }
    uVar1 = *(undefined4 *)(param_2 * 4 + param_1 + 0x54);
  }
  return uVar1;
}