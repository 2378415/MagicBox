// 4200d708  FUN_4200d708  FUN_4200d708  size=27

void FUN_4200d708(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (*DAT_42000cd4)(*param_1,param_2,param_3);
    *param_1 = uVar1;
    param_1[1] = param_1[1] + param_3;
  }
  return;
}


