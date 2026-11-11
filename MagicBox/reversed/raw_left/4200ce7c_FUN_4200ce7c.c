// 4200ce7c  FUN_4200ce7c  FUN_4200ce7c  size=55

undefined4 FUN_4200ce7c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_42000cc0;
  iVar2 = (*DAT_42000cd4)(0,DAT_42000cc0,0xc);
  if (((piVar1[3] == iVar2) && (*piVar1 != 0)) && (3 < (uint)piVar1[1])) {
    (*(code *)PTR_FUN_42000cd8)(PTR_PTR_42000cd0);
    FUN_42019a5c(1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


