undefined8 __ieee754_floor(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar6 = param_2 >> 0x14 & 0x7ff;
  uVar3 = uVar6 - 0x3ff;
  uVar2 = param_1;
  uVar4 = param_2;
  if ((int)uVar3 < 0x14) {
    if ((int)uVar3 < 0) {
      uVar7 = (*DAT_42000e38)(param_1,param_2,DAT_42001c0c,DAT_42001c10);
      iVar1 = (*DAT_42001c14)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0);
      if (0 < iVar1) {
        uVar2 = 0;
        uVar4 = 0;
        if (((int)param_2 < 0) && (uVar4 = 0xbff00000, (param_2 & 0x7fffffff) == 0 && param_1 == 0))
        {
          uVar4 = 0x80000000;
        }
      }
    }
    else {
      uVar6 = 0xfffff >> (uVar3 & 0x1f);
      if ((uVar6 & param_2) == 0 && param_1 == 0) {
        return CONCAT44(param_2,param_1);
      }
      uVar7 = (*DAT_42000e38)(param_1,param_2,DAT_42001c0c,DAT_42001c10);
      iVar1 = (*DAT_42001c14)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0);
      if (0 < iVar1) {
        if ((int)param_2 < 0) {
          param_2 = (0x100000 >> (uVar3 & 0x1f)) + param_2;
        }
        uVar2 = 0;
        uVar4 = uVar6 & param_2 ^ param_2;
      }
    }
  }
  else {
    if (0x33 < (int)uVar3) {
      if (uVar3 == 0x400) {
        uVar7 = (*DAT_42000e38)(param_1,param_2,param_1,param_2);
        return uVar7;
      }
      return CONCAT44(param_2,param_1);
    }
    uVar5 = 0xffffffff >> (uVar6 + 0xd & 0x1f);
    if ((param_1 & uVar5) == 0) {
      return CONCAT44(param_2,param_1);
    }
    uVar7 = (*DAT_42000e38)(param_1,param_2,DAT_42001c0c,DAT_42001c10);
    iVar1 = (*DAT_42001c14)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0);
    if (0 < iVar1) {
      if (((int)param_2 < 0) &&
         ((uVar3 == 0x14 ||
          (uVar2 = param_1 + (1 << 0x20 - (0x20 - (-(uVar6 - 0x433) & 0x1f))), uVar2 < param_1)))) {
        param_2 = param_2 + 1;
      }
      uVar2 = uVar5 & uVar2 ^ uVar2;
      uVar4 = param_2;
    }
  }
  return CONCAT44(uVar4,uVar2);
}