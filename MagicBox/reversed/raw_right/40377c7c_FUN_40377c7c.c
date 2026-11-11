// 40377c7c  FUN_40377c7c  FUN_40377c7c  size=69

int FUN_40377c7c(undefined4 *param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  code *pcVar2;
  
  if ((param_3 == '\0') &&
     (iVar1 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(param_1), iVar1 != 0)) {
    if (param_2 == 0) {
      param_2 = iVar1;
    }
  }
  else {
    pcVar2 = *(code **)(*(int *)*param_1 + 0x44);
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)((int *)*param_1,param_4,param_5);
      if (param_2 == 0) {
        param_2 = iVar1;
      }
    }
    param_2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(param_1,param_2);
  }
  return param_2;
}


