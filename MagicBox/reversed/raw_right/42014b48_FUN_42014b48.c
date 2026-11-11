// 42014b48  FUN_42014b48  FUN_42014b48  size=585

int FUN_42014b48(int param_1,undefined1 param_2,char param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_60;
  undefined1 uStack_5c;
  char cStack_5b;
  byte bStack_3f;
  undefined4 uStack_30;
  uint uStack_2c;
  
  if (*(int *)(param_1 + 100) == 1) {
    iStack_60 = 0;
    uStack_30 = param_5;
    if (param_3 == 'A') {
      iVar2 = FUN_4201408c(param_1,param_2,0x48,param_4,&iStack_60,&uStack_5c,0xff,0xff);
      if (iVar2 == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      iVar2 = FUN_4201408c(param_1,param_2,0xff,param_4,&iStack_60,&uStack_5c,0xff,0xff);
      if (iVar2 == 0) {
        if (cStack_5b == param_3) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
    }
    if (iVar2 == 0 || iVar2 == DAT_42000cd4) {
      if (param_3 == 'A') {
        if (bVar1) {
          iVar2 = FUN_420140dc(param_1,param_2,param_4,uStack_30,param_6);
          if (iVar2 == 0) {
            return 0;
          }
          if (((*(int *)(iStack_60 + 0xc) == -1) || (*(int *)(iStack_60 + 0xc) == 0)) &&
             (iVar2 = FUN_4201408c(param_1,param_2,0x41,param_4,&iStack_60,&uStack_5c,0xff,0xff),
             iVar2 != 0)) {
            return iVar2;
          }
          uStack_2c = (uint)bStack_3f;
          if (uStack_2c != 0 && uStack_2c != 0x80) {
            return -1;
          }
          if (uStack_2c == 0x80) {
            uVar4 = 0;
          }
          else {
            uVar4 = 0x80;
          }
        }
        else {
          uVar4 = 0;
          uStack_2c = 0;
        }
        iVar2 = FUN_42014970(param_1,param_2,param_4,uStack_30,param_6,uVar4);
        if (iVar2 == DAT_420010ac) {
          return DAT_420010a4;
        }
        if (iVar2 != 0) {
          return iVar2;
        }
        if (bVar1) {
          iVar2 = FUN_420141a8(param_1,param_2,param_4,uStack_2c);
          if (iVar2 == DAT_420010b4) {
            return DAT_420010b0;
          }
          if (iVar2 != 0) {
            return iVar2;
          }
          iStack_60 = 0;
        }
        else {
          iVar2 = FUN_4201408c(param_1,param_2,0x41,param_4,&iStack_60,&uStack_5c,0xff,0xff);
          if (iVar2 != 0 && iVar2 != DAT_42000cd4) {
            return iVar2;
          }
        }
      }
      else {
        if ((bVar1) &&
           (iVar2 = FUN_4201602c(iStack_60,param_2,param_3,param_4,uStack_30,param_6,0xff,0xff),
           iVar2 == 0)) {
          return 0;
        }
        iVar3 = *(int *)(param_1 + 0x14);
        iVar2 = FUN_42015ac8(iVar3,param_2,param_3,param_4,uStack_30,param_6,0xff);
        if (iVar2 == DAT_420010ac) {
          if ((*(int *)(iVar3 + 0xc) != -4) && (iVar2 = FUN_42015820(iVar3), iVar2 != 0)) {
            return iVar2;
          }
          iVar2 = FUN_42016820(param_1 + 0x10);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar2 = FUN_42015ac8(*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,uStack_30,
                               param_6,0xff);
          if (iVar2 == DAT_420010ac) {
            return DAT_420010a4;
          }
        }
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      if (iStack_60 == 0) {
        iVar2 = 0;
      }
      else if ((((*(int *)(iStack_60 + 0xc) != -1) && (*(int *)(iStack_60 + 0xc) != 0)) ||
               (iVar2 = FUN_4201408c(param_1,param_2,0xff,param_4,&iStack_60,&uStack_5c,0xff,0xff),
               iVar2 == 0)) &&
              (iVar2 = FUN_42016228(iStack_60,param_2,0xff,param_4,0xff), iVar2 == DAT_420010b4)) {
        iVar2 = DAT_420010b0;
      }
    }
  }
  else {
    iVar2 = DAT_420010a0;
  }
  return iVar2;
}


