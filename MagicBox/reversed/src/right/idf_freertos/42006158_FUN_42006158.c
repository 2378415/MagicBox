void FUN_42006158(void)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = FUN_420031ec();
  uVar4 = (*(code *)PTR_FUN_4200070c)();
  piVar1 = DAT_42000708;
  iVar2 = (int)((ulonglong)uVar3 >> 0x20) - (int)((ulonglong)uVar4 >> 0x20);
  if ((uint)uVar3 < (uint)uVar4) {
    iVar2 = iVar2 + -1;
  }
  *DAT_42000708 = (uint)uVar3 - (uint)uVar4;
  piVar1[1] = iVar2;
  return;
}