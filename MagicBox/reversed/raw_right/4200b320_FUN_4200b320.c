// 4200b320  FUN_4200b320  FUN_4200b320  size=25

undefined4 FUN_4200b320(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xfffffffd;
  }
  else {
    uVar1 = FUN_4200b300(param_1,param_2);
  }
  return uVar1;
}


