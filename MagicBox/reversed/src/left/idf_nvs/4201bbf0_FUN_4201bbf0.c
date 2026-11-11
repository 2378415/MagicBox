int FUN_4201bbf0(int param_1,undefined1 param_2,undefined4 param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_70 [3];
  byte bStack_6d;
  uint uStack_58;
  byte bStack_54;
  byte bStack_53;
  int aiStack_50 [4];
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iStack_34 = param_1;
  iStack_30 = param_4;
  uStack_38 = param_5;
  while( true ) {
    if (iVar2 == 0) {
      return DAT_420011bc;
    }
    aiStack_50[0] = 0;
    iVar3 = FUN_4201d244(iVar2,param_2,0x48,param_3,aiStack_50,auStack_70,0xff,0xff);
    if (iVar3 == 0) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  uVar5 = (uint)bStack_53;
  if (uStack_58 == uStack_38) {
    uStack_2c = bStack_54 + uVar5;
    uStack_40 = 0;
    if (bStack_54 == 0) {
      uStack_3c = 0;
    }
    else {
      do {
        iVar2 = *(int *)(iStack_34 + 0x10);
        if (iVar2 == 0) {
LAB_4201bd10:
          uStack_3c = DAT_420011bc;
LAB_4201bd1a:
          if (*(int *)(iStack_34 + 100) == 1) {
            FUN_4201b2ec(iStack_34,param_2,param_3,0xff);
          }
          goto LAB_4201bd07;
        }
        uStack_3c = uVar5;
        while( true ) {
          aiStack_50[0] = iVar3;
          iVar4 = FUN_4201d244(iVar2,param_2,0x42,param_3,aiStack_50,auStack_70,uVar5 & 0xff,0xff);
          uVar1 = uStack_40;
          if (iVar4 == 0) break;
          iVar2 = *(int *)(iVar2 + 4);
          if (iVar2 == 0) goto LAB_4201bd10;
        }
        if (uStack_38 - uStack_40 < (uStack_58 & 0xffff)) {
          uStack_3c = DAT_42001a64;
          goto LAB_4201bd1a;
        }
        uStack_40 = uStack_3c;
        uStack_3c = uVar1;
        iVar2 = FUN_4201d4b0(iVar2,param_2,0x42,param_3,iStack_30 + uVar1,uStack_58 & 0xffff,
                             uVar5 & 0xff,0xff);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (bStack_6d != uStack_40) {
          return -1;
        }
        uVar5 = uStack_40 + 1;
        uStack_40 = uStack_3c + (uStack_58 & 0xffff);
      } while (uVar5 != uStack_2c);
      uStack_3c = 0;
    }
LAB_4201bd07:
    if (uStack_38 == uStack_40) {
      return uStack_3c;
    }
  }
  return -1;
}