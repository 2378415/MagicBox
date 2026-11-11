// 42021f38  FUN_42021f38  FUN_42021f38  size=83

undefined1  [12] FUN_42021f38(int param_1,int param_2)

{
  undefined1 auVar1 [12];
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_30;
  int aiStack_2c [11];
  
  uVar5 = FUN_42021df4(param_1,aiStack_2c);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_42021df4(param_2,&local_30);
  iVar4 = (int)((ulonglong)uVar6 >> 0x20);
  iVar3 = (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20 + (aiStack_2c[0] - local_30);
  if (iVar3 < 1) {
    iVar4 = iVar4 + iVar3 * -0x100000;
  }
  else {
    iVar2 = iVar3 * 0x100000 + iVar2;
  }
  auVar1._0_8_ = (*DAT_42001304)((int)uVar5,iVar2,(int)uVar6,iVar4);
  auVar1._8_4_ = (int)uVar5;
  return auVar1;
}


