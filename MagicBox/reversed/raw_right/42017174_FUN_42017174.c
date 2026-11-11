// 42017174  FUN_42017174  FUN_42017174  size=53

undefined4
FUN_42017174(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int *param_8)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  if ((param_5 == param_7) && (iVar2 = FUN_42017124(uVar1,*(undefined4 *)(param_6 + 4)), iVar2 != 0)
     ) {
    param_8[2] = param_3;
  }
  else {
    iVar2 = FUN_42017124(uVar1,*(undefined4 *)(param_4 + 4));
    if (iVar2 != 0) {
      *param_8 = param_5;
      param_8[1] = param_3;
      param_8[3] = 1;
    }
  }
  return 0;
}


