int FUN_420142b4(undefined4 param_1,undefined1 param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_60 [3];
  byte bStack_5d;
  uint uStack_48;
  byte bStack_44;
  byte bStack_43;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  auStack_40[0] = 0;
  uStack_30 = param_3;
  uStack_2c = param_5;
  uStack_28 = param_1;
  iStack_24 = param_4;
  iVar1 = FUN_4201408c(param_1,param_2,0x48,param_3,auStack_40,auStack_60,0xff,0xff);
  if (iVar1 == 0) {
    if (uStack_48 == param_5) {
      uVar2 = 0;
      for (uVar4 = 0; uVar4 < bStack_44; uVar4 = uVar4 + 1 & 0xff) {
        uVar3 = uVar4 + bStack_43 & 0xff;
        iVar1 = FUN_4201408c(uStack_28,param_2,0x42,uStack_30,auStack_40,auStack_60,uVar3,0xff);
        if (iVar1 != 0) {
          if (iVar1 != DAT_42000cd4) {
            return iVar1;
          }
          goto LAB_42014378;
        }
        if (uStack_2c - uVar2 < (uStack_48 & 0xffff)) {
          iVar1 = DAT_42001094;
          goto LAB_42014378;
        }
        iVar1 = FUN_42016130(auStack_40[0],param_2,0x42,uStack_30,iStack_24 + uVar2,
                             uStack_48 & 0xffff,uVar3,0xff);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (bStack_43 + uVar4 != (uint)bStack_5d) {
          return -1;
        }
        uVar2 = uVar2 + (uStack_48 & 0xffff);
        iVar1 = 0;
      }
LAB_42014378:
      if (iVar1 == DAT_42000cd4 || iVar1 == DAT_42001094) {
        FUN_420141a8(uStack_28,param_2,uStack_30,0xff);
      }
      if (uVar2 != uStack_2c) {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}