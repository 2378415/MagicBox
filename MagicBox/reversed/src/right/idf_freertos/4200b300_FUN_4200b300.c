undefined4 FUN_4200b300(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xfffffffd;
  }
  else {
    uVar1 = FUN_4200b27c(param_1,1,*param_2,*param_2,0x154);
  }
  return uVar1;
}