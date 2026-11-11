// 4038300c  FUN_4038300c  FUN_4038300c  size=140

int FUN_4038300c(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  }
  if ((iVar1 == 0) || (iVar1 == 0x106 || iVar1 == 0)) {
    local_40 = 0x20000000;
    uStack_2c = (undefined2)DAT_40375368;
    uStack_3c = param_2;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 8));
    if (iVar1 == 0x106) {
      iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}


