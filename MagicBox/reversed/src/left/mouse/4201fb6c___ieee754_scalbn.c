longlong __ieee754_scalbn(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  
  lVar5 = CONCAT44(param_2,param_1);
  uVar1 = param_2 >> 0x14 & 0x7ff;
  if (uVar1 == 0) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return lVar5;
    }
    lVar5 = (*DAT_42000e30)(param_1,param_2,0,0x43500000);
    uVar1 = ((uint)((ulonglong)lVar5 >> 0x34) & 0x7ff) - 0x36;
    if (param_3 < DAT_42001c18) {
      uVar3 = DAT_42001c20;
      uVar4 = DAT_42001c24;
      goto LAB_4201fc3f;
    }
  }
  else if (uVar1 == 0x7ff) {
    lVar5 = (*DAT_42000e38)(param_1,param_2,param_1,param_2);
    return lVar5;
  }
  uVar2 = (uint)((ulonglong)lVar5 >> 0x20);
  if ((DAT_4200142c < param_3) || (param_3 = param_3 + uVar1, 0x7fe < param_3)) {
    uVar3 = DAT_42001c10;
    if (lVar5 < 0) {
      uVar3 = DAT_42001c2c;
    }
    lVar5 = CONCAT44(uVar3,DAT_42001c0c);
    uVar3 = DAT_42001c0c;
    uVar4 = DAT_42001c10;
  }
  else {
    if (0 < param_3) {
      return CONCAT44(uVar2 & DAT_42001c1c | param_3 * 0x100000,(int)lVar5);
    }
    if (param_3 < -0x35) {
      uVar3 = DAT_42001c24;
      if (lVar5 < 0) {
        uVar3 = DAT_42001c28;
      }
      lVar5 = CONCAT44(uVar3,DAT_42001c20);
      uVar3 = DAT_42001c20;
      uVar4 = DAT_42001c24;
    }
    else {
      lVar5 = CONCAT44((param_3 + 0x36) * 0x100000 | uVar2 & DAT_42001c1c,(int)lVar5);
      uVar3 = 0;
      uVar4 = 0x3c900000;
    }
  }
LAB_4201fc3f:
  lVar5 = (*DAT_42000e30)((int)lVar5,(int)((ulonglong)lVar5 >> 0x20),uVar3,uVar4);
  return lVar5;
}