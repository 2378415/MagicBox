// 42016b44  FUN_42016b44  FUN_42016b44  size=108

undefined4 FUN_42016b44(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar1 = (*(code *)PTR_FUN_420004c8)();
  if (iVar1 == 0) {
    if (param_3 == -1) {
      iVar1 = (*(code *)PTR_FUN_420010f8)(param_1,param_2,0xffffffff);
    }
    else {
      iVar1 = (*(code *)PTR_FUN_420010f8)
                        (param_1,param_2,
                         (uint)((ulonglong)(uint)(param_3 * 1000) * (ulonglong)DAT_420002d0 >> 0x26)
                        );
    }
    if (iVar1 != 1) {
      return 0xfffffff2;
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_420014e4)(param_1,param_2,local_30);
    if (iVar1 != 1) {
      return 0xfffffff2;
    }
    if (local_30[0] == 1) {
      (*(code *)PTR_FUN_42000a94)();
    }
  }
  return 0;
}


