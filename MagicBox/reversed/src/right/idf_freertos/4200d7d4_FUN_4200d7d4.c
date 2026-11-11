undefined4 FUN_4200d7d4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_42000358)(param_1,0,0);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000898)(param_1,local_30);
    if (iVar1 != 1) {
      return 0xfffffff2;
    }
    iVar1 = 1;
    if (local_30[0] == 1) {
      (*(code *)PTR_FUN_420008ac)();
    }
  }
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}