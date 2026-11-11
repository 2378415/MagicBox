// 4037f2d0  FUN_4037f2d0  FUN_4037f2d0  size=61

void FUN_4037f2d0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30 [12];
  
  uVar1 = param_3 + 3;
  for (iVar2 = 0; iVar2 < (int)(uVar1 >> 2); iVar2 = iVar2 + 1) {
    local_30[0] = 0;
    iVar3 = (param_3 < 4) * param_3 + (uint)(param_3 >= 4) * 4;
    (*DAT_403744d4)(local_30,param_2,iVar3);
    memw();
    *(undefined4 *)((iVar2 + 0x24) * 4 + param_1 + 8) = local_30[0];
    param_3 = param_3 - iVar3;
    param_2 = param_2 + iVar3;
  }
  return;
}


