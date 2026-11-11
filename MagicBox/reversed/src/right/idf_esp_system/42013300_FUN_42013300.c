int FUN_42013300(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(*(int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30));
  if (*(int *)(param_1 + 0x30) < *(int *)(param_1 + 0x2c)) {
    uVar2 = (*(code *)PTR_FUN_4200006c)();
  }
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  (*DAT_42000ffc)();
  return ((int)uVar2 + iVar1 + -1) / iVar1;
}