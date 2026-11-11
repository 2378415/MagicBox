undefined4 FUN_42016b24(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_42011e9c(1,2,param_1);
  if (iVar1 == 0) {
    uVar3 = 0x105;
  }
  else if (*(char *)(iVar1 + 0x29) == '\0') {
    iVar2 = (*(code *)PTR_FUN_420006e0)(0x10);
    if (iVar2 == 0) {
      uVar3 = 0x101;
    }
    else {
      FUN_4201517c(iVar2,iVar1);
      *param_2 = iVar2;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = DAT_420010f8;
  }
  return uVar3;
}