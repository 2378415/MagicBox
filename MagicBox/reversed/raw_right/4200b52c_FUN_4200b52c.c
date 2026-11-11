// 4200b52c  FUN_4200b52c  FUN_4200b52c  size=165

int FUN_4200b52c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined1 auStack_40 [12];
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  (*DAT_42000240)(auStack_40,0,0xc);
  FUN_4200ac28();
  uVar5 = rsr(in_PRID);
  uVar1 = (*(code *)PTR_FUN_420009dc)(uVar5 >> 0xd & 1);
  iVar2 = FUN_4200ac9c(uVar1,auStack_40,0);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_4200b504(param_1,auStack_40);
    if (*(short *)(param_1 + 0x48) == 1) {
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    else if (iVar2 < 1) {
      return iVar2;
    }
  }
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  do {
    do {
      do {
        iVar4 = FUN_42026404(&uStack_34);
        iVar3 = iStack_2c;
        if (iVar4 == -1) {
          iVar2 = FUN_4200b220(param_1,iVar2);
          return iVar2;
        }
      } while (iStack_2c == 0);
      uVar5 = rsr(in_PRID);
      iVar4 = (*(code *)PTR_FUN_420009dc)(uVar5 >> 0xd & 1);
    } while ((iVar3 == iVar4) || (iVar3 = FUN_4200ac9c(iVar3,auStack_40,0), iVar3 == 0));
    iVar3 = FUN_4200b504(param_1,auStack_40);
    if (*(short *)(param_1 + 0x48) == 1) {
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    else if (iVar3 < 1) {
      return iVar3;
    }
    iVar2 = iVar2 + iVar3;
  } while( true );
}


