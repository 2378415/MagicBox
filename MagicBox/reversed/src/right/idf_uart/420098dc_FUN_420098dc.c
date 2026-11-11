// strings: Lk7@

undefined4 FUN_420098dc(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  (*(code *)PTR_FUN_42000818)(PTR_DAT_42000938);
  iVar1 = (**(code **)(PTR_DAT_42000920 + 0x20))(param_1);
  (*(code *)PTR_FUN_4200081c)(PTR_DAT_42000938);
  uVar3 = 0;
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_420180e4();
    *piVar2 = iVar1;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}