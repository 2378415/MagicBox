undefined4 FUN_42009494(void)

{
  int iVar1;
  undefined8 uVar2;
  
  memw();
  memw();
  *(uint *)(DAT_42000190 + 4) = *(uint *)(DAT_42000190 + 4) | 1;
  while( true ) {
    uVar2 = (*(code *)PTR_FUN_4200074c)();
    iVar1 = (int)((ulonglong)uVar2 >> 0x20) - *(int *)(PTR_DAT_42000920 + 0x2c);
    if ((uint)uVar2 < *(uint *)(PTR_DAT_42000920 + 0x28)) {
      iVar1 = iVar1 + -1;
    }
    if ((0 < iVar1) ||
       ((iVar1 == 0 && (DAT_42000924 < (uint)uVar2 - *(uint *)(PTR_DAT_42000920 + 0x28))))) break;
    memw();
    if ((*(uint *)(DAT_42000190 + 4) & 2) != 0) {
      uVar2 = (*(code *)PTR_FUN_4200074c)();
      *(undefined8 *)(PTR_DAT_42000920 + 0x28) = uVar2;
      memw();
      memw();
      *(uint *)(DAT_42000190 + 4) = *(uint *)(DAT_42000190 + 4) | 1;
      return 0;
    }
  }
  return 5;
}