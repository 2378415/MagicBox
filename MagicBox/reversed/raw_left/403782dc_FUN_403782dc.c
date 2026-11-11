// 403782dc  FUN_403782dc  FUN_403782dc  size=100

int FUN_403782dc(int *param_1,int *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int local_30 [12];
  
  iVar2 = FUN_40378fd8(param_1);
  puVar1 = PTR_PTR_403748f8;
  iVar3 = (*(code *)**(undefined4 **)PTR_PTR_403748f8)(param_1);
  if (iVar3 == 0) {
    if ((iVar2 == 0) ||
       (pcVar4 = *(code **)(param_1[1] + 0x60), piVar5 = param_1, pcVar4 == (code *)0x0)) {
      piVar5 = (int *)*param_1;
      pcVar4 = *(code **)(*piVar5 + 8);
    }
    iVar2 = (*pcVar4)(piVar5,param_2);
    if ((((iVar2 == 0) && (param_3 != 0)) && (iVar2 = (*pcVar4)(piVar5,local_30), iVar2 == 0)) &&
       (*param_2 != local_30[0])) {
      iVar2 = DAT_403748fc;
    }
    iVar3 = (**(code **)(*(int *)puVar1 + 4))(param_1,iVar2);
  }
  return iVar3;
}


