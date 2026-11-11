// 40377e80  FUN_40377e80  FUN_40377e80  size=114

void FUN_40377e80(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_30 [12];
  
  uVar4 = *param_3;
  if ((uVar4 & DAT_4037489c) != 0) {
    uVar3 = *param_2;
    uVar2 = *param_1;
    local_30[0] = 0;
    iVar1 = FUN_4037a1d4(uVar4,local_30);
    if (iVar1 == 0) {
      uVar2 = (uVar2 < local_30[0]) * local_30[0] + (uVar2 >= local_30[0]) * uVar2;
      if ((uVar4 >> 0x14 & 1) != 0) {
        uVar2 = (uint)(uVar2 < 0x10) * 0x10 + (uVar2 >= 0x10) * uVar2;
      }
      if ((uVar4 >> 0x11 & 3) != 0) {
        uVar4 = uVar4 & DAT_403748a0 | 8;
      }
      *param_2 = -uVar2 & (uVar3 - 1) + uVar2;
      *param_1 = uVar2;
      if ((uVar4 >> 10 & 1) != 0) {
        uVar4 = uVar4 & 0xfffffff7;
      }
      *param_3 = uVar4 & DAT_403748a4;
    }
    else {
      *param_3 = *param_3 | DAT_40374550;
    }
  }
  return;
}


