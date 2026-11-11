undefined4 FUN_42006634(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x102;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000774,0xffffffff);
    iVar4 = *DAT_42000780;
    iVar2 = (*(code *)PTR_FUN_42000784)(*DAT_42000778,(iVar4 + 1) * 4,DAT_4200077c);
    if (iVar2 == 0) {
      uVar3 = 0x101;
    }
    else {
      *DAT_42000778 = iVar2;
      piVar1 = DAT_42000780;
      *(int *)(*DAT_42000780 * 4 + iVar2) = param_1;
      *piVar1 = iVar4 + 1;
      uVar3 = 0;
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000774);
  }
  return uVar3;
}