undefined4 FUN_4037d3c4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  if (param_1 == 0) {
    uVar2 = rsil(3);
    uVar1 = rsr(in_PRID);
    memw();
    param_1 = *(int *)((uVar1 >> 0xd & 1) * 4 + DAT_40374e18);
    (*DAT_40374db8)(uVar2);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar2;
}