// 420244e0  FUN_420244e0  FUN_420244e0  size=58

void FUN_420244e0(int *param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  memw();
  uVar1 = -((*(uint *)(*param_1 + 0x1c) >> 0x10 & 0x3ff) - 0x80);
  if (param_3 < (uVar1 & 0xffff)) {
    uVar1 = param_3;
  }
  *param_4 = uVar1 & 0xffff;
  puVar3 = (uint *)*param_1;
  for (iVar2 = 0; iVar2 < (int)(uVar1 & 0xffff); iVar2 = iVar2 + 1) {
    memw();
    *puVar3 = (uint)*(byte *)(param_2 + iVar2);
  }
  return;
}


