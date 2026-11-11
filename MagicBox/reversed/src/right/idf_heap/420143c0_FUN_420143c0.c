int FUN_420143c0(int param_1,undefined1 param_2,char param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined1 auStack_50 [32];
  undefined4 auStack_30 [12];
  
  if (*(int *)(param_1 + 100) == 1) {
    auStack_30[0] = 0;
    if ((param_3 != 'A') ||
       (iVar1 = FUN_420142b4(param_1,param_2,param_4,param_5,param_6), iVar1 == DAT_42000cd4)) {
      iVar1 = FUN_4201408c(param_1,param_2,param_3,param_4,auStack_30,auStack_50,0xff,0xff);
      if (iVar1 == 0) {
        iVar1 = FUN_42016130(auStack_30[0],param_2,param_3,param_4,param_5,param_6,0xff,0xff);
      }
    }
  }
  else {
    iVar1 = DAT_420010a0;
  }
  return iVar1;
}