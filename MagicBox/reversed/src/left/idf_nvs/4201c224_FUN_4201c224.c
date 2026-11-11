int FUN_4201c224(int param_1,undefined1 param_2,char param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [32];
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar1 = DAT_42001a70;
  if (*(int *)(param_1 + 100) == 1) {
    uStack_30 = param_5;
    uStack_2c = param_6;
    if ((param_3 != 'A') ||
       (iVar1 = FUN_4201bbf0(param_1,param_2,param_4,param_5,param_6), iVar1 == DAT_420011bc)) {
      iVar1 = DAT_420011bc;
      for (iVar2 = *(int *)(param_1 + 0x10); DAT_420011bc = iVar1, iVar2 != 0;
          iVar2 = *(int *)(iVar2 + 4)) {
        auStack_40[0] = 0;
        iVar1 = FUN_4201d244(iVar2,param_2,param_3,param_4,auStack_40,auStack_60,0xff,0xff);
        if (iVar1 == 0) {
          iVar1 = FUN_4201d4b0(iVar2,param_2,param_3,param_4,uStack_30,uStack_2c,0xff,0xff);
          return iVar1;
        }
        iVar1 = DAT_420011bc;
      }
    }
  }
  return iVar1;
}