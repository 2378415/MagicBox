// 4037e154  FUN_4037e154  FUN_4037e154  size=71

undefined4 FUN_4037e154(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  if (*(int *)(uVar2 * 4 + DAT_40374d64) != 0) {
    memw();
    iVar3 = *(int *)(uVar2 * 4 + DAT_40374d64);
    *(int *)(iVar3 + 0x50) = *(int *)(iVar3 + 0x50) + 1;
  }
  memw();
  uVar1 = *(undefined4 *)(uVar2 * 4 + DAT_40374d64);
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar1;
}


