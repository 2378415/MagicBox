// 4201bd2c  FUN_4201bd2c  FUN_4201bd2c  size=247

int FUN_4201bd2c(int param_1,undefined1 param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_70 [3];
  byte bStack_6d;
  uint uStack_58;
  byte bStack_54;
  byte bStack_53;
  int aiStack_50 [4];
  uint uStack_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uStack_2c = param_5;
  iStack_38 = param_4;
  while( true ) {
    if (iVar1 == 0) {
      return DAT_420011bc;
    }
    aiStack_50[0] = 0;
    iVar2 = FUN_4201d244(iVar1,param_2,0x48,param_3,aiStack_50,auStack_70,0xff,0xff);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  if (uStack_58 != uStack_2c) {
    return DAT_42001a68;
  }
  uStack_40 = 0;
  if (bStack_54 == 0) {
    iVar1 = 0;
  }
  else {
    uStack_3c = (uint)bStack_53;
    uStack_30 = bStack_54 + uStack_3c;
    iStack_34 = param_1;
    do {
      uVar3 = uStack_3c & 0xff;
      iVar1 = *(int *)(iStack_34 + 0x10);
      if (iVar1 == 0) {
LAB_4201be14:
        iVar1 = DAT_420011bc;
        break;
      }
      while( true ) {
        aiStack_50[0] = iVar2;
        iVar4 = FUN_4201d244(iVar1,param_2,0x42,param_3,aiStack_50,auStack_70,uVar3,0xff);
        if (iVar4 == 0) break;
        iVar1 = *(int *)(iVar1 + 4);
        if (iVar1 == 0) goto LAB_4201be14;
      }
      iVar1 = FUN_4201d5e0(iVar1,param_2,0x42,param_3,iStack_38 + uStack_40,uStack_58 & 0xffff,uVar3
                           ,0xff);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (bStack_6d != uStack_3c) goto LAB_4201bdf6;
      uStack_3c = uStack_3c + 1;
      uStack_40 = uStack_40 + (uStack_58 & 0xffff);
      iVar1 = 0;
    } while (uStack_3c != uStack_30);
  }
  if (uStack_2c != uStack_40) {
LAB_4201bdf6:
    iVar1 = -1;
  }
  return iVar1;
}


