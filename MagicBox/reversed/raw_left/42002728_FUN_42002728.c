// 42002728  FUN_42002728  FUN_42002728  size=171

undefined4
FUN_42002728(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
            uint *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = FUN_420026dc(param_2,param_1);
  uVar2 = *param_6;
  iVar7 = (int)uVar2 % 8;
  uVar1 = uVar1 >> (param_3 & 0x1f);
  if (param_4 == 0x20) {
    if ((uVar2 & 7) == 0) goto LAB_42002799;
LAB_42002769:
    uVar6 = uVar2 + 7;
    if (-1 < (int)uVar2) {
      uVar6 = uVar2;
    }
    pbVar4 = (byte *)(param_5 + ((int)uVar6 >> 3));
    *pbVar4 = (byte)(uVar1 << 0x20 - (0x20 - (uVar2 & 7))) | *pbVar4;
    iVar7 = -(iVar7 + -8);
    iVar7 = (uint)(iVar7 < (int)param_4) * iVar7 + (iVar7 >= (int)param_4) * param_4;
    uVar2 = *param_6 + iVar7;
    *param_6 = uVar2;
    param_4 = param_4 - iVar7;
  }
  else {
    uVar1 = (1 << 0x20 - (0x20 - (param_4 & 0x1f))) - 1U & uVar1;
    if ((uVar2 & 7) != 0) goto LAB_42002769;
  }
  if ((int)param_4 < 1) {
    return 0;
  }
LAB_42002799:
  uVar6 = 0;
  do {
    uVar3 = uVar2 + 7;
    if (-1 < (int)uVar2) {
      uVar3 = uVar2;
    }
    uVar6 = uVar6 + iVar7;
    pbVar4 = (byte *)(param_5 + ((int)uVar3 >> 3));
    bVar5 = (byte)(uVar1 >> (uVar6 & 0x1f));
    if ((uVar6 & 0x20) != 0) {
      bVar5 = 0;
    }
    *pbVar4 = bVar5 | *pbVar4;
    iVar7 = ((int)param_4 < 8) * param_4 + (uint)((int)param_4 >= 8) * 8;
    uVar2 = iVar7 + *param_6;
    *param_6 = uVar2;
    param_4 = param_4 - iVar7;
  } while (0 < (int)param_4);
  return 0;
}


