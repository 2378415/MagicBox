// strings: Db7@8a7@

int FUN_42026278(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_FUN_42000484)(0x54,param_3);
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_42000484)(param_2 * param_1,param_3);
  }
  if (((iVar1 == 0) || (param_2 != 0 && iVar2 == 0)) ||
     (iVar3 = (*(code *)PTR_FUN_4200037c)(param_1,param_2,iVar2,iVar1,0), iVar3 == 0)) {
    (*(code *)PTR_FUN_420008b4)(iVar2);
    (*(code *)PTR_FUN_420008b4)(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}