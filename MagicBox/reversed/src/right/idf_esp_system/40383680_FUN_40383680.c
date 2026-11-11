int FUN_40383680(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if (((iVar1 == 0) &&
      (iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4)),
      iVar1 == 0)) && (iVar1 = FUN_40383634(param_1,param_2), iVar1 == 0)) {
    pcVar2 = *(code **)(*(int *)*param_1 + 0x44);
    if ((pcVar2 == (code *)0x0) ||
       (iVar1 = (*pcVar2)((int *)*param_1,param_2,*(undefined4 *)(param_1[1] + 0x24)), iVar1 == 0))
    {
      iVar1 = (**(code **)(param_1[1] + 0x54))
                        (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 8));
    }
  }
  return iVar1;
}