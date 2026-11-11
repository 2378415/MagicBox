undefined4 FUN_4200ae14(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000a00)();
  if ((iVar1 == 0) || (*(char *)(DAT_420009f8 + 8) == '\0')) {
    uVar2 = (*(code *)PTR_FUN_42000a08)(*DAT_420009fc,param_2,param_1,param_3);
  }
  else {
    uVar2 = (*(code *)PTR_FUN_42000a04)(*DAT_420009fc,param_1,param_2,param_3);
  }
  return uVar2;
}