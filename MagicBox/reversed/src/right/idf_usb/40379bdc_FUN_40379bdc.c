void FUN_40379bdc(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  for (cVar4 = '\x01'; cVar4 != '\0'; cVar4 = cVar4 + -1) {
    iVar3 = (*(code *)PTR_FUN_40374a84)(10);
    iVar2 = DAT_40374a70;
    uVar1 = DAT_403748a8;
    if (iVar3 == 0) {
      memw();
      memw();
      *(uint *)(DAT_40374a70 + 0x18) = *(uint *)(DAT_40374a70 + 0x18) | DAT_403748a8;
      memw();
      memw();
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | uVar1;
      memw();
      memw();
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & DAT_40374a74;
      memw();
      memw();
      *(uint *)(DAT_40374a78 + 0x48) = *(uint *)(DAT_40374a78 + 0x48) & DAT_40374a7c;
    }
    (*(code *)PTR_FUN_40374a80)(10,iVar3);
  }
  return;
}