// strings: Pm7@L

undefined4 FUN_4200bbc4(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  (*(code *)PTR_FUN_420000b8)(PTR_DAT_42000c04);
  iVar1 = (**(code **)(PTR_DAT_42000bf0 + 0x20))(param_1);
  (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c04);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_42020b54();
    *piVar2 = iVar1;
  }
  return 0;
}