int FUN_420133bc(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = param_1[1];
  uVar3 = (uint)(param_2 + param_1[3]) % uVar2;
  iVar1 = *param_1;
  uVar4 = uVar2 - uVar3;
  iVar5 = iVar1 + uVar3;
  if (uVar4 < param_4) {
    iVar5 = (*DAT_42000114)(iVar5,param_3,uVar4);
    if (iVar5 == 0) {
      iVar5 = (*DAT_42000114)(iVar1,param_3 + uVar4,(param_4 - uVar2) + uVar3);
    }
  }
  else {
    iVar5 = (*DAT_42000114)(iVar5,param_3,param_4);
  }
  return iVar5;
}