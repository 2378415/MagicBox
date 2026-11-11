// 420265f4  FUN_420265f4  FUN_420265f4  size=38

undefined4 FUN_420265f4(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  if (param_3 == 0) {
    *(int *)(param_4 + 0x14) = *(int *)(param_4 + 0x14) + 1;
    if (*(uint *)(param_4 + 8) < param_2) {
      *(uint *)(param_4 + 8) = param_2;
    }
  }
  else {
    *(int *)(param_4 + 0x10) = *(int *)(param_4 + 0x10) + 1;
  }
  *(int *)(param_4 + 0x18) = *(int *)(param_4 + 0x18) + 1;
  return 1;
}


