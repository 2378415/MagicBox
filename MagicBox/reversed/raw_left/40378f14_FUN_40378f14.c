// 40378f14  FUN_40378f14  FUN_40378f14  size=107

void FUN_40378f14(uint *param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  
  iVar1 = DAT_403749b4;
  uVar4 = *(byte *)((int)param_1 + 0xf) & 1;
  puVar2 = (uint *)(uVar4 * 4 + DAT_403749b4);
  if ((uint *)*puVar2 == (uint *)0x0) {
    param_1[6] = 0;
    *puVar2 = (uint)param_1;
    param_1[7] = (uint)puVar2;
    if (param_2 != 0) {
      return;
    }
  }
  else {
    puVar2 = (uint *)*puVar2;
    while ((puVar2[1] <= param_1[1] && ((puVar2[1] != param_1[1] || (*puVar2 <= *param_1))))) {
      if ((uint *)puVar2[6] == (uint *)0x0) {
        param_1[6] = 0;
        puVar2[6] = (uint)param_1;
        param_1[7] = (uint)(puVar2 + 6);
        goto LAB_40378f77;
      }
      puVar2 = (uint *)puVar2[6];
    }
    puVar3 = (uint *)puVar2[7];
    param_1[6] = (uint)puVar2;
    param_1[7] = (uint)puVar3;
    *puVar3 = (uint)param_1;
    puVar2[7] = (uint)(param_1 + 6);
LAB_40378f77:
    if (param_2 != 0) {
      return;
    }
    if (param_1 != *(uint **)(iVar1 + uVar4 * 4)) {
      return;
    }
  }
  FUN_40377028(*param_1,param_1[1]);
  return;
}


