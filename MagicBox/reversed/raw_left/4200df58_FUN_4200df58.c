// 4200df58  FUN_4200df58  FUN_4200df58  size=82

void FUN_4200df58(undefined4 param_1,undefined4 param_2,int param_3,int param_4,char *param_5,
                 int param_6)

{
  if (param_6 != 0) {
    if ((*(int *)(*(int *)(param_4 + 0xc) * 4 + *(int *)(param_3 + 0x210) + 0x54) == 0) ||
       (1 < (byte)(*param_5 - 0x30U))) {
      FUN_420143e8(param_1,param_2,0);
    }
    else {
      FUN_4202d1ac(param_3,*(int *)(param_4 + 0xc),*param_5 == '1');
      *DAT_42000dac = 1;
      FUN_420143e8(param_1,param_2,0);
    }
  }
  return;
}


