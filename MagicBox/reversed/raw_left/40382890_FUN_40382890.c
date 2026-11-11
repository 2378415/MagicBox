// 40382890  FUN_40382890  FUN_40382890  size=92

int FUN_40382890(undefined4 *param_1)

{
  int iVar1;
  int local_40 [5];
  undefined2 uStack_2c;
  
  local_40[0] = 0;
  uStack_2c = 0x66;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  if (iVar1 == 0) {
    uStack_2c = 0x99;
    local_40[0] = iVar1;
    iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
    }
  }
  return iVar1;
}


