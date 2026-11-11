undefined4 FUN_42016af0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_40 [4];
  undefined4 auStack_30 [12];
  
  local_40[0] = 0;
  auStack_30[0] = param_2;
  iVar1 = (*(code *)PTR_FUN_420004c8)();
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_42000488)(param_1,auStack_30,0xffffffff,0);
    if (iVar1 == 1) {
      return 0;
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000a90)(param_1,auStack_30,local_40,0);
    if (iVar1 == 1) {
      if (local_40[0] == 1) {
        (*(code *)PTR_FUN_42000a94)();
      }
      return 0;
    }
  }
  return 0xfffffff2;
}