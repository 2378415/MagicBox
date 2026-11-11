undefined4 FUN_4037869c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_403748cc)(param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0x10d;
  }
  else if ((*(char *)(param_1 + 4) == '\0') &&
          (iVar1 = (*(code *)PTR_FUN_403748d0)(param_2,param_3), iVar1 == 0)) {
    uVar2 = 0x106;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}