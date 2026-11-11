// 40378cec  FUN_40378cec  FUN_40378cec  size=46

undefined4 FUN_40378cec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_4037497c)(param_2,param_3);
  uVar2 = 0x10d;
  if (iVar1 != 0) {
    if ((*(char *)(param_1 + 4) == '\0') &&
       (iVar1 = (*(code *)PTR_FUN_40374980)(param_2,param_3), iVar1 == 0)) {
      return 0x106;
    }
    uVar2 = 0;
  }
  return uVar2;
}


