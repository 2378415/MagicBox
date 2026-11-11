// 42016ff4  FUN_42016ff4  FUN_42016ff4  size=119

undefined4
FUN_42016ff4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  iVar1 = FUN_42016fc4(uVar2,*(undefined4 *)(param_4 + 4));
  if (iVar1 == 0) {
    if ((param_5 != param_7) ||
       (iVar1 = FUN_42016fc4(uVar2,*(undefined4 *)(param_6 + 4)), iVar1 == 0)) {
      uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x1c))
                        (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,param_7,
                         param_8);
      return uVar2;
    }
    param_8[2] = param_3;
  }
  else {
    *param_8 = param_5;
    param_8[1] = param_3;
    if (param_2 < 0) {
      if (param_2 != -2) {
        return 0;
      }
      iVar1 = 1;
    }
    else {
      iVar1 = 1;
      if (param_7 == param_5 + param_2) {
        iVar1 = 6;
      }
    }
    param_8[3] = iVar1;
  }
  return 0;
}


