// 4200b5d8  FUN_4200b5d8  FUN_4200b5d8  size=42

undefined4 FUN_4200b5d8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  auStack_2c[0] = 0;
  if (param_2 == 0) {
    uVar1 = 0xfffffffd;
  }
  else {
    uVar1 = FUN_4200bd34(param_2,&local_30,auStack_2c);
    uVar1 = FUN_4200b27c(param_1,1,local_30,auStack_2c[0],uVar1);
  }
  return uVar1;
}


