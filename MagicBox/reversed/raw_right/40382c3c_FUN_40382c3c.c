// 40382c3c  FUN_40382c3c  FUN_40382c3c  size=108

int FUN_40382c3c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  if (iVar1 == 0 || iVar1 == 0x106) {
    (**(code **)(*(int *)*param_1 + 0x20))((int *)*param_1,param_2,param_3,param_4);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))
                      (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 0x10));
    if (iVar1 == 0x106) {
      iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}


