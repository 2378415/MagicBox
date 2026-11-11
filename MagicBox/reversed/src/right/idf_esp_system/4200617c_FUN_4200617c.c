void FUN_4200617c(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_30 [48];
  
  FUN_42018124(auStack_30,0);
  FUN_420060a4(auStack_30,0);
  uVar4 = FUN_420031ec();
  uVar5 = (*(code *)PTR_FUN_4200070c)();
  iVar1 = (int)((ulonglong)uVar4 >> 0x20) - (int)((ulonglong)uVar5 >> 0x20);
  if ((uint)uVar4 < (uint)uVar5) {
    iVar1 = iVar1 + -1;
  }
  uVar2 = (uint)uVar4 - (uint)uVar5;
  uVar4 = FUN_42006130();
  iVar1 = DAT_42000708[1] - iVar1;
  if (*DAT_42000708 < uVar2) {
    iVar1 = iVar1 + -1;
  }
  uVar2 = *DAT_42000708 - uVar2;
  iVar1 = (int)((ulonglong)uVar4 >> 0x20) + iVar1;
  uVar3 = (int)uVar4 + uVar2;
  if (uVar3 < uVar2) {
    iVar1 = iVar1 + 1;
  }
  FUN_42006108(uVar3,iVar1);
  return;
}