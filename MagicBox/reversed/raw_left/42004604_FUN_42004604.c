// 42004604  FUN_42004604  FUN_42004604  size=58

undefined4 FUN_42004604(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30 [12];
  
  local_30[0] = *(undefined4 *)PTR_DAT_42000028;
  uVar2 = local_30[0];
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_FUN_42000560)();
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = FUN_420047a8(param_1,local_30);
      if (iVar1 == 0) {
        FUN_4200469c(param_1,local_30);
        FUN_4200487c(param_1,local_30[0]);
      }
      (*(code *)PTR_FUN_4200055c)();
      uVar2 = local_30[0];
    }
  }
  return uVar2;
}


