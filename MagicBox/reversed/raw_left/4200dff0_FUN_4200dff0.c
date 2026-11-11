// 4200dff0  FUN_4200dff0  FUN_4200dff0  size=48

void FUN_4200dff0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0x210) != 0)) {
    iVar1 = param_4[3] * 4 + *(int *)(param_3 + 0x210);
    if (*(int *)(iVar1 + 0x54) == 0) {
      uVar2 = 0;
    }
    else if (*(int *)(iVar1 + 0x168) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (*(int *)(iVar1 + 0x124) != 0) {
        uVar2 = 1;
      }
    }
    FUN_4200dc18(*param_4,param_4[1],uVar2);
  }
  return;
}


