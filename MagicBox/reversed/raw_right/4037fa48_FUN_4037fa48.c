// 4037fa48  FUN_4037fa48  FUN_4037fa48  size=93

void FUN_4037fa48(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_30 [12];
  
  memw();
  memw();
  param_1[6] = param_1[6] & DAT_403747e0;
  uVar1 = param_3 + 3;
  for (iVar2 = 0; iVar2 < (int)(uVar1 >> 2); iVar2 = iVar2 + 1) {
    local_30[0] = 0;
    iVar3 = (param_3 < 4) * param_3 + (uint)(param_3 >= 4) * 4;
    (*DAT_403744d4)(local_30,param_2,iVar3);
    memw();
    param_1[iVar2 + 0x16] = local_30[0];
    param_3 = param_3 - iVar3;
    param_2 = iVar3 + param_2;
  }
  memw();
  memw();
  *param_1 = *param_1 | DAT_403746a8;
  return;
}


