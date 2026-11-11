// 40377d54  FUN_40377d54  FUN_40377d54  size=106

int FUN_40377d54(int *param_1,int *param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  int local_30 [12];
  
  iVar1 = FUN_403788ec(param_1);
  iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(param_1);
  if (iVar2 == 0) {
    if ((iVar1 == 0) || (pcVar3 = *(code **)(param_1[1] + 0x60), pcVar3 == (code *)0x0)) {
      pcVar3 = *(code **)(*(int *)*param_1 + 8);
      piVar4 = (int *)*param_1;
    }
    else {
      piVar4 = param_1;
    }
    iVar1 = (*pcVar3)(piVar4,param_2);
    if ((((iVar1 == 0 & param_3) != 0) && (iVar1 = (*pcVar3)(piVar4,local_30), iVar1 == 0)) &&
       (*param_2 != local_30[0])) {
      iVar1 = DAT_40374880;
    }
    iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(param_1,iVar1);
  }
  return iVar2;
}


