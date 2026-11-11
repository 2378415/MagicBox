undefined4 FUN_420272f8(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_3 + 8) != 0) {
    uVar1 = FUN_42020214(param_1,param_2,param_3);
    *(undefined4 *)(param_3 + 8) = 0;
  }
  *(undefined4 *)(param_3 + 4) = 0;
  return uVar1;
}