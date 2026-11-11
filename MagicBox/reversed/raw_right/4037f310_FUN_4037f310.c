// 4037f310  FUN_4037f310  FUN_4037f310  size=85

void FUN_4037f310(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_30 [12];
  
  if (((param_2 & 3) == 0) && ((param_3 & 3) == 0)) {
    (*DAT_403744d4)(param_2,param_1 + 0x98,param_3);
  }
  else {
    uVar1 = param_3;
    for (uVar2 = 0; uVar2 < param_3 + 3 >> 2; uVar2 = uVar2 + 1) {
      iVar3 = (uVar1 < 4) * uVar1 + (uint)(uVar1 >= 4) * 4;
      memw();
      local_30[0] = *(undefined4 *)((uVar2 + 0x24) * 4 + param_1 + 8);
      (*DAT_403744d4)(param_2,local_30,iVar3);
      param_2 = param_2 + iVar3;
      uVar1 = uVar1 - iVar3;
    }
  }
  return;
}


