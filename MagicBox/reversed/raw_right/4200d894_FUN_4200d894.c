// 4200d894  FUN_4200d894  FUN_4200d894  size=88

undefined4 FUN_4200d894(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_40 [4];
  undefined4 auStack_30 [12];
  
  local_40[0] = 0;
  auStack_30[0] = param_2;
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_42000358)(param_1,auStack_30,0xffffffff,0);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_420008a8)(param_1,auStack_30,local_40,0);
    if (iVar1 != 1) {
      return 0xfffffff2;
    }
    iVar1 = 1;
    if (local_40[0] == 1) {
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


