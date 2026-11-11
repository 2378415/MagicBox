// 420290a4  FUN_420290a4  FUN_420290a4  size=135

void FUN_420290a4(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int local_30;
  int aiStack_2c [11];
  
  if ((*(ushort *)(param_2 + 3) & 2) == 0) {
    uVar2 = FUN_42029038(param_1,param_2,aiStack_2c,&local_30);
    iVar3 = (*(code *)PTR_FUN_42001c78)(param_1,aiStack_2c[0]);
    uVar1 = *(ushort *)(param_2 + 3);
    if (iVar3 != 0) {
      *(ushort *)(param_2 + 3) = uVar1 | 0x80;
      *param_2 = iVar3;
      param_2[4] = iVar3;
      param_2[5] = aiStack_2c[0];
      if ((local_30 != 0) &&
         (iVar3 = FUN_4202cfac(param_1,(int)*(short *)((int)param_2 + 0xe)), iVar3 != 0)) {
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfffc | 1;
      }
      *(ushort *)(param_2 + 3) = uVar2 | *(ushort *)(param_2 + 3);
      return;
    }
    if ((uVar1 & 0x200) != 0) {
      return;
    }
    *(ushort *)(param_2 + 3) = uVar1 & 0xfffc | 2;
  }
  *param_2 = (int)param_2 + 0x47;
  param_2[4] = (int)param_2 + 0x47;
  param_2[5] = 1;
  return;
}


