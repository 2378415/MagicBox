// 42021fc4  FUN_42021fc4  FUN_42021fc4  size=85

void FUN_42021fc4(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar2 = (undefined4 *)(param_3 + 0x14);
  puVar3 = puVar2 + *(int *)(param_3 + 0x10);
  puVar1 = param_1;
  for (; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
  }
  uVar4 = 0;
  if ((-(param_3 + 0x10) & 0xffU) != 0) {
    uVar4 = (int)puVar3 - (param_3 + 0x11) & 0xfffffffc;
  }
  for (puVar1 = (undefined4 *)((int)param_1 + uVar4); puVar1 < param_1 + (param_2 + -1 >> 5) + 1;
      puVar1 = puVar1 + 1) {
    *puVar1 = 0;
  }
  return;
}


