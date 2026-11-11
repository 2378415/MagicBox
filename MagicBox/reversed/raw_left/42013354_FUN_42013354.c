// 42013354  FUN_42013354  FUN_42013354  size=103

undefined4 FUN_42013354(int *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  iVar2 = param_1[1];
  if (uVar3 < uVar4) {
    iVar5 = (iVar2 + uVar3) - uVar4;
  }
  else {
    iVar5 = uVar3 - uVar4;
  }
  uVar1 = 0;
  if (param_3 <= (uint)(iVar2 - iVar5)) {
    uVar4 = iVar2 - uVar3;
    if (uVar4 < param_3) {
      (*DAT_42000064)(*param_1 + uVar3,param_2,uVar4);
      iVar2 = (uVar3 + param_3) - iVar2;
      (*DAT_42000064)(*param_1,param_2 + uVar4,iVar2);
      param_1[2] = iVar2;
    }
    else {
      (*DAT_42000064)(*param_1 + uVar3,param_2,param_3);
      param_1[2] = (param_3 + param_1[2]) % (uint)param_1[1];
    }
    uVar1 = 1;
  }
  return uVar1;
}


