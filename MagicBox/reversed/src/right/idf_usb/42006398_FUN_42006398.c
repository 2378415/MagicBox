void FUN_42006398(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_420031ec();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20) - DAT_42000740[1];
  if ((uint)uVar4 < *DAT_42000740) {
    iVar2 = iVar2 + -1;
  }
  uVar3 = (uint)uVar4 - *DAT_42000740;
  uVar4 = (*(code *)PTR_FUN_4200074c)();
  piVar1 = DAT_42000744;
  iVar2 = iVar2 - (int)((ulonglong)uVar4 >> 0x20);
  if (uVar3 < (uint)uVar4) {
    iVar2 = iVar2 + -1;
  }
  *DAT_42000744 = uVar3 - (uint)uVar4;
  piVar1[1] = iVar2;
  FUN_420015d4(PTR_FUN_42000748);
  return;
}