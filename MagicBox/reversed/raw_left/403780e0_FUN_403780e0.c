// 403780e0  FUN_403780e0  FUN_403780e0  size=69

undefined4 FUN_403780e0(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int local_30;
  uint auStack_2c [11];
  
  *param_2 = 0;
  auStack_2c[0] = 0;
  local_30 = FUN_40377e34(param_1,auStack_2c);
  uVar1 = 0;
  if (local_30 == 0) {
    if ((auStack_2c[0] & 1) == 0) {
      FUN_4037f21c(auStack_2c[0] & 1,param_1,1,1,&local_30);
    }
    else {
      FUN_4037f21c(0,param_1,1,2,&local_30);
    }
    uVar1 = 1;
    *param_2 = local_30;
  }
  return uVar1;
}


