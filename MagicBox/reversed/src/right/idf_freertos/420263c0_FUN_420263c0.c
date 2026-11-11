int FUN_420263c0(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x19) {
    iVar1 = (param_1 - 0x18) * -0x14 + DAT_42001498;
  }
  else {
    if (0x1e < param_1) {
      return 0;
    }
    iVar1 = *(int *)(PTR_DAT_4200149c + (param_1 - 0x19) * 4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar2 = (*(code *)PTR_FUN_420014a0)(iVar1);
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}