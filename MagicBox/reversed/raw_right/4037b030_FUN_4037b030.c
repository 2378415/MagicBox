// 4037b030  FUN_4037b030  FUN_4037b030  size=35

void FUN_4037b030(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (param_1[0x10] != 0) {
    uVar1 = param_1[3] + param_1[0x10];
    param_1[3] = uVar1;
    if ((uint)param_1[2] <= uVar1) {
      param_1[3] = *param_1;
    }
    (*DAT_403744d4)(param_2,param_1[3]);
  }
  return;
}


