int FUN_40382974(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  }
  if ((iVar1 == 0) || (iVar1 == 0x106 || iVar1 == 0)) {
    if (*(code **)(param_1[2] + 0x24) != (code *)0x0) {
      (**(code **)(param_1[2] + 0x24))(1);
    }
    (**(code **)(*(int *)*param_1 + 0x10))((int *)*param_1,param_2);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))
                      (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 0xc));
    if (*(code **)(param_1[2] + 0x24) != (code *)0x0) {
      (**(code **)(param_1[2] + 0x24))(0);
    }
    if (iVar1 == 0x106) {
      iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}