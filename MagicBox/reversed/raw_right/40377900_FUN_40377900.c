// 40377900  FUN_40377900  FUN_40377900  size=109

void FUN_40377900(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_30 [12];
  
  uVar3 = *param_2;
  uVar2 = *param_1;
  uVar4 = *param_3;
  if ((uVar4 & DAT_4037481c) != 0) {
    local_30[0] = 0;
    iVar1 = FUN_40379c74(uVar4,local_30);
    if (iVar1 == 0) {
      if (local_30[0] <= uVar2) {
        local_30[0] = uVar2;
      }
      if ((uVar4 & 0x100000) != 0) {
        local_30[0] = (uint)(local_30[0] < 0x10) * 0x10 + (local_30[0] >= 0x10) * local_30[0];
      }
      if ((uVar4 >> 0x11 & 3) != 0) {
        uVar4 = uVar4 & DAT_40374820 | 8;
      }
      if ((uVar4 & 0x400) != 0) {
        uVar4 = uVar4 & 0xfffffff7;
      }
      uVar4 = uVar4 & DAT_40374824;
      *param_2 = (local_30[0] + uVar3) - 1 & -local_30[0];
      *param_1 = local_30[0];
      *param_3 = uVar4;
    }
    else {
      *param_3 = *param_3 | DAT_4037450c;
    }
  }
  return;
}


