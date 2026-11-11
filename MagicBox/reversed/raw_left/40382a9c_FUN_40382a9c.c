// 40382a9c  FUN_40382a9c  FUN_40382a9c  size=82

int FUN_40382a9c(undefined4 *param_1,char param_2)

{
  int iVar1;
  char local_30 [48];
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  if ((iVar1 == 0) || (iVar1 == 0x106 || iVar1 == 0)) {
    (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,param_2);
  }
  iVar1 = (**(code **)(param_1[1] + 0x28))(param_1,local_30);
  if ((iVar1 == 0) && (local_30[0] != param_2)) {
    iVar1 = 0x105;
  }
  return iVar1;
}


