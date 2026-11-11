undefined4 FUN_4200d8f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    uVar2 = 0;
    if (param_3 == -1) {
      iVar1 = (*(code *)PTR_FUN_42000b6c)(param_1,param_2,0xffffffff);
      if (iVar1 != 1) {
        uVar2 = 0xfffffff2;
      }
    }
    else {
      iVar1 = (*(code *)PTR_FUN_42000b6c)
                        (param_1,param_2,
                         (uint)((ulonglong)(uint)(param_3 * 1000) * (ulonglong)DAT_420001a4 >> 0x26)
                        );
      if (iVar1 != 1) {
        uVar2 = 0xfffffff2;
      }
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000b68)(param_1,param_2,local_30);
    if (iVar1 == 1) {
      if (local_30[0] == 1) {
        (*(code *)PTR_FUN_420008ac)();
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xfffffff2;
    }
  }
  return uVar2;
}