void FUN_42013408(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)(param_2 + param_1[3]) % (uint)param_1[1];
  uVar3 = param_1[1] - uVar1;
  iVar2 = (uVar3 < param_4) * uVar3 + (uVar3 >= param_4) * param_4;
  (*DAT_42000064)(param_3,*param_1 + uVar1,iVar2);
  if (uVar3 < param_4) {
    (*DAT_42000064)(param_3 + iVar2,*param_1,param_4 - iVar2);
  }
  return;
}