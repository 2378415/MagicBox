undefined4 FUN_4200b9bc(void)

{
  int iVar1;
  undefined *puVar2;
  int unaff_retaddr;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  puVar2 = PTR_DAT_42000bf0;
  iVar1 = DAT_420002b0;
  memw();
  memw();
  *(uint *)(DAT_420002b0 + 4) = *(uint *)(DAT_420002b0 + 4) | 1;
  while( true ) {
    uVar5 = (*(code *)PTR_FUN_4200092c)();
    iVar4 = (int)((ulonglong)uVar5 >> 0x20) + *(int *)(puVar2 + 0x2c) * -2;
    if ((0 < iVar4) ||
       ((iVar4 == 0 && (DAT_42000c10 < (uint)((int)uVar5 - *(int *)(puVar2 + 0x28)))))) break;
    if ((*(uint *)(unaff_retaddr + 4) & 2) != 0) {
      uVar5 = (*(code *)PTR_FUN_4200092c)();
      memw();
      uVar3 = *(uint *)(iVar1 + 4);
      *(undefined8 *)(puVar2 + 0x28) = uVar5;
      memw();
      *(uint *)(iVar1 + 4) = uVar3 | 1;
      return 0;
    }
  }
  return 5;
}