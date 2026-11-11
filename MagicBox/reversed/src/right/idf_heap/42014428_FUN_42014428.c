int FUN_42014428(int param_1,undefined1 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uStack_50;
  char cStack_4f;
  undefined4 auStack_30 [12];
  
  if (*(int *)(param_1 + 100) == 1) {
    if (param_3 == 'A') {
      iVar1 = FUN_420141a8(param_1,param_2,param_4,0xff);
    }
    else {
      auStack_30[0] = 0;
      iVar1 = FUN_4201408c(param_1,param_2,param_3,param_4,auStack_30,&uStack_50,0xff,0xff);
      if (iVar1 == 0) {
        if (cStack_4f == 'B' || cStack_4f == 'H') {
          iVar1 = FUN_420141a8(param_1,param_2,param_4,0xff);
        }
        else {
          iVar1 = FUN_42016228(auStack_30[0],param_2,param_3,param_4,0xff);
        }
      }
    }
  }
  else {
    iVar1 = DAT_420010a0;
  }
  return iVar1;
}