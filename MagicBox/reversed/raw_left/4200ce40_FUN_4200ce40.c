// 4200ce40  FUN_4200ce40  FUN_4200ce40  size=59

undefined4 FUN_4200ce40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000cc4)();
  if ((iVar1 == 0) || (*(char *)(DAT_42000cc0 + 8) == '\0')) {
    uVar2 = (*(code *)PTR_FUN_42000ccc)(*DAT_42000cbc,param_2,param_1,param_3);
  }
  else {
    uVar2 = (*(code *)PTR_FUN_42000cc8)(*DAT_42000cbc,param_1,param_2);
  }
  return uVar2;
}


