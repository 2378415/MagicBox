// 40380704  FUN_40380704  FUN_40380704  size=82

void FUN_40380704(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = FUN_40380640(param_1,param_2);
  uVar4 = (*(code *)param_1[2])(param_3,param_4);
  iVar2 = *param_1;
  iVar1 = param_2 * 8 + iVar2;
  memw();
  memw();
  *(int *)(iVar1 + 0xc) =
       (int)(CONCAT44(*(uint *)(iVar1 + 0xc) >> 0x14,
                      ((int)((ulonglong)uVar3 >> 0x20) + (int)((ulonglong)uVar4 >> 0x20) +
                      (int)uVar4) * 0x1000) >> 0xc);
  memw();
  *(int *)(iVar1 + 0x10) = (int)uVar3 + (int)uVar4;
  memw();
  *(undefined4 *)((param_2 + 0x14) * 4 + iVar2 + 0xc) = 1;
  return;
}


