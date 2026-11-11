// 4201b2ec  FUN_4201b2ec  FUN_4201b2ec  size=326

int FUN_4201b2ec(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_60 [2];
  byte bStack_5e;
  byte bStack_5d;
  uint auStack_40 [4];
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  
  iVar5 = *(int *)(param_1 + 0x10);
  iStack_30 = param_1;
  while( true ) {
    if (iVar5 == 0) {
      return DAT_420011bc;
    }
    auStack_40[0] = 0;
    iVar1 = FUN_4201d244(iVar5,param_2,0x48,param_3,auStack_40,auStack_60,0xff,param_4);
    if (iVar1 == 0) break;
    iVar5 = *(int *)(iVar5 + 4);
  }
  uVar2 = FUN_4201d70c(iVar5,param_2,0x48,param_3,0xff,param_4);
  if (uVar2 != 0) {
    return uVar2;
  }
  iStack_28 = 0;
  if (param_4 == 0xff) {
    iVar5 = *(int *)(iStack_30 + 0x10);
    if (iVar5 == 0) {
      return 0;
    }
    uStack_2c = iStack_28;
    do {
      auStack_40[0] = uVar2;
      iVar1 = FUN_4201d244(iVar5,param_2,0x48,param_3,auStack_40,auStack_60,0xff,0xff);
      if (iVar1 == 0) {
        iVar5 = FUN_4201d70c(iVar5,param_2,0x48,param_3,0xff);
        if (iVar5 != 0) {
          return iVar5;
        }
        break;
      }
      iVar5 = *(int *)(iVar5 + 4);
    } while (iVar5 != 0);
    uVar4 = 0;
    uVar2 = 0xff;
    iStack_28 = uStack_2c;
  }
  else {
    uVar2 = 0x80;
    uVar4 = 0;
    if (param_4 != 0) {
      uVar4 = (uint)(param_4 == 0x80) << 7;
      uVar2 = 0xff;
    }
  }
  iVar5 = DAT_420011bc;
  iVar1 = *(int *)(iStack_30 + 0x10);
  if (iVar1 != 0) {
    iStack_30 = param_3;
    uStack_2c = uVar2;
    do {
      auStack_40[0] = 0;
      do {
        iVar3 = FUN_4201d244(iVar1,param_2,0x42,iStack_30,auStack_40,auStack_60,0xff,0xff);
        if (iVar3 == iVar5) break;
        if (iVar3 != 0) {
          return iVar3;
        }
        if ((bStack_5d < uVar4) || (uStack_2c <= bStack_5d)) {
          auStack_40[0] = bStack_5e + auStack_40[0];
        }
        else {
          iVar3 = FUN_4201d0e8(iVar1);
          auStack_40[0] = bStack_5e + auStack_40[0];
          if (iVar3 != 0) {
            return iVar3;
          }
        }
      } while (auStack_40[0] < 0x7e);
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != 0);
  }
  return iStack_28;
}


