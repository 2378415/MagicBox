// 420140dc  FUN_420140dc  FUN_420140dc  size=199

int FUN_420140dc(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,uint param_5)

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
  uint uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  
  auStack_40[0] = 0;
  uStack_2c = param_1;
  iStack_28 = param_4;
  iVar1 = FUN_4201408c(param_1,param_2 & 0xff,0x48,param_3,auStack_40,auStack_60,0xff,0xff);
  if (iVar1 == 0) {
    if (uStack_48 == param_5) {
      uVar2 = 0;
      uStack_30 = param_2 & 0xff;
      uStack_24 = param_5;
      for (uVar4 = 0; uVar4 < bStack_44; uVar4 = uVar4 + 1 & 0xff) {
        uVar3 = uVar4 + bStack_43 & 0xff;
        iVar1 = FUN_4201408c(uStack_2c,uStack_30,0x42,param_3,auStack_40,auStack_60,uVar3,0xff);
        if (iVar1 != 0) {
          if (iVar1 != DAT_42000cd4) {
            return iVar1;
          }
          break;
        }
        iVar1 = FUN_4201602c(auStack_40[0],uStack_30,0x42,param_3,iStack_28 + uVar2,
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
      if (uVar2 != uStack_24) {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = DAT_4200109c;
    }
  }
  return iVar1;
}


