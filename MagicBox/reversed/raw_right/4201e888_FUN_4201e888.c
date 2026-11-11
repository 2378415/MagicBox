// 4201e888  FUN_4201e888  FUN_4201e888  size=34

undefined4 FUN_4201e888(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_3 + 8) != 0) {
    uVar1 = FUN_420177e4(param_1,param_2,param_3);
    *(undefined4 *)(param_3 + 8) = 0;
  }
  *(undefined4 *)(param_3 + 4) = 0;
  return uVar1;
}


