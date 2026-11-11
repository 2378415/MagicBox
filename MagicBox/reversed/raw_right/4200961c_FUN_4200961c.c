// 4200961c  FUN_4200961c  FUN_4200961c  size=103

undefined4 FUN_4200961c(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x102;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000928,0xffffffff);
    iVar4 = *DAT_42000930;
    iVar2 = (*(code *)PTR_FUN_42000784)(*DAT_4200092c,(iVar4 + 1) * 4,DAT_4200077c);
    if (iVar2 == 0) {
      uVar3 = 0x101;
    }
    else {
      if (*DAT_42000930 == 0) {
        FUN_42009aa8(PTR_FUN_42000934);
      }
      *DAT_4200092c = iVar2;
      piVar1 = DAT_42000930;
      *(int *)(*DAT_42000930 * 4 + iVar2) = param_1;
      *piVar1 = iVar4 + 1;
      uVar3 = 0;
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000928);
  }
  return uVar3;
}


