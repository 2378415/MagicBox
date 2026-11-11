// 40377b94  FUN_40377b94  FUN_40377b94  size=72

undefined4 FUN_40377b94(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_30;
  undefined4 auStack_2c [11];
  
  *param_2 = 0;
  local_30 = 0;
  iVar1 = FUN_40377890(param_1,&local_30);
  if (iVar1 == 0) {
    auStack_2c[0] = 0;
    if ((local_30 & 1) == 0) {
      FUN_4037eea0(0,param_1,1,1,auStack_2c);
    }
    else {
      FUN_4037eea0(0,param_1,1,2,auStack_2c);
    }
    *param_2 = auStack_2c[0];
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


