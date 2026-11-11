int FUN_4202d090(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar2 = param_2 & 7;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    uVar7 = 0;
    pbVar6 = (byte *)(param_1 + (param_2 >> 3));
    uVar5 = 0;
    do {
      uVar4 = param_3 - uVar5;
      uVar3 = -(uVar2 - 8);
      uVar4 = (uVar3 < uVar4) * uVar3 + (uVar3 >= uVar4) * uVar4;
      uVar3 = uVar5 & 0x1f;
      uVar5 = uVar5 + uVar4;
      uVar7 = uVar7 | (-1 << 0x20 - (0x20 - (uVar4 & 0x1f)) & (uint)(*pbVar6 >> uVar2) ^
                      (uint)(*pbVar6 >> uVar2)) << 0x20 - (0x20 - uVar3);
      pbVar6 = pbVar6 + 1;
      uVar2 = 0;
    } while (uVar5 < param_3);
    if ((param_3 < 0x10) && ((uVar7 & 1 << ((char)param_3 - 1U & 0x1f)) != 0)) {
      iVar1 = (int)(short)(-(short)(1 << 0x20 - (0x20 - (param_3 & 0x1f))) | (ushort)uVar7);
    }
    else {
      iVar1 = (int)(short)(ushort)uVar7;
    }
  }
  return iVar1;
}