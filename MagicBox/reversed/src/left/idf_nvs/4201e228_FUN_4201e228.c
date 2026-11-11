undefined4 FUN_4201e228(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_42018d80(1,2,param_1);
  if (iVar1 == 0) {
    uVar3 = 0x105;
  }
  else {
    uVar3 = DAT_42001ab0;
    if (*(char *)(iVar1 + 0x29) == '\0') {
      iVar2 = (*(code *)PTR_FUN_4200056c)(0x10);
      if (iVar2 == 0) {
        uVar3 = 0x101;
      }
      else {
        FUN_4201c784(iVar2,iVar1);
        *param_2 = iVar2;
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}