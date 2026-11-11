// 4037e0c0  FUN_4037e0c0  FUN_4037e0c0  size=31

undefined4 FUN_4037e0c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsil(3);
  uVar2 = rsr(in_PRID);
  memw();
  uVar1 = *(undefined4 *)((uVar2 >> 0xd & 1) * 4 + DAT_40374e18);
  (*DAT_40374db8)(uVar3);
  return uVar1;
}


