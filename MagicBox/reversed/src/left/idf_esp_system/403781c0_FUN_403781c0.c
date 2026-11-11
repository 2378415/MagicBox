int FUN_403781c0(undefined4 *param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  
  puVar1 = PTR_PTR_403748f8;
  if ((param_3 == '\0') &&
     (iVar2 = (*(code *)**(undefined4 **)PTR_PTR_403748f8)(param_1), iVar2 != 0)) {
    if (param_2 != 0) {
      iVar2 = param_2;
    }
  }
  else {
    pcVar3 = *(code **)(*(int *)*param_1 + 0x44);
    if ((pcVar3 == (code *)0x0) ||
       (iVar2 = (*pcVar3)((int *)*param_1,param_4,param_5), param_2 != 0)) {
      iVar2 = param_2;
    }
    iVar2 = (**(code **)(*(int *)puVar1 + 4))(param_1,iVar2);
  }
  return iVar2;
}