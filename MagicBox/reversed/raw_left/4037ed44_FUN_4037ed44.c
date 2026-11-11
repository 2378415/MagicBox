// 4037ed44  FUN_4037ed44  FUN_4037ed44  size=40

undefined * FUN_4037ed44(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 in_PRID;
  
  uVar4 = rsil(3);
  uVar3 = rsr(in_PRID);
  memw();
  iVar2 = *(int *)((uVar3 >> 0xd & 1) * 4 + DAT_40374e18);
  (*DAT_40374db8)(uVar4);
  puVar1 = (undefined *)(iVar2 + 0x5c);
  if (iVar2 == 0) {
    puVar1 = PTR_DAT_4037478c;
  }
  return puVar1;
}


