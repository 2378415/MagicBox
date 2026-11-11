// 40380604  FUN_40380604  FUN_40380604  size=84

void FUN_40380604(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar4 = FUN_40380530(param_1,param_2);
  uVar5 = (*(code *)param_1[2])(param_3,param_4);
  uVar2 = (int)((ulonglong)uVar4 >> 0x20) + (int)((ulonglong)uVar5 >> 0x20);
  uVar3 = (int)uVar4 + (uint)uVar5;
  if (uVar3 < (uint)uVar5) {
    uVar2 = uVar2 + 1;
  }
  iVar1 = param_2 * 8 + *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfff00000 | uVar2 & 0xfffff;
  memw();
  *(uint *)(iVar1 + 0x10) = uVar3;
  memw();
  *(undefined4 *)((param_2 + 0x14) * 4 + *param_1 + 0xc) = 1;
  return;
}


