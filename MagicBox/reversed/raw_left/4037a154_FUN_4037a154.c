// 4037a154  FUN_4037a154  FUN_4037a154  size=96

void FUN_4037a154(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (*(code *)PTR_FUN_40374b3c)(10);
  iVar3 = DAT_40374b34;
  iVar2 = DAT_40374b2c;
  uVar1 = DAT_40374944;
  if (iVar4 == 0) {
    memw();
    memw();
    *(uint *)(DAT_40374b2c + 0x18) = *(uint *)(DAT_40374b2c + 0x18) | DAT_40374944;
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | uVar1;
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & DAT_40374b30;
    memw();
    memw();
    *(uint *)(iVar3 + 0x48) = *(uint *)(iVar3 + 0x48) & DAT_40374b38;
  }
  (*(code *)PTR_FUN_40374b40)(10,iVar4);
  return;
}


