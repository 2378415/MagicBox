// 40378c8c  FUN_40378c8c  FUN_40378c8c  size=66

int FUN_40378c8c(undefined4 param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_40374974;
  iVar4 = 5;
  do {
    uVar2 = (*(code *)PTR_FUN_40374978)(uVar1);
    if (uVar2 <= param_2) {
      param_2 = (*(code *)PTR_FUN_40374978)(uVar1);
    }
    param_2 = param_2 + 3 & 0xfffffffc;
    iVar3 = FUN_40376314(param_2,uVar1);
    iVar4 = iVar4 + -1;
    if (iVar3 != 0) goto LAB_40378cc8;
  } while (iVar4 != 0);
  param_2 = 0;
LAB_40378cc8:
  *param_3 = param_2;
  return iVar3;
}


