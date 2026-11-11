// 420141a8  FUN_420141a8  FUN_420141a8  size=259

int FUN_420141a8(int param_1,undefined1 param_2,undefined4 param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined1 auStack_50 [2];
  byte bStack_4e;
  byte bStack_4d;
  undefined4 uStack_30;
  uint auStack_2c [11];
  
  if (*(int *)(param_1 + 100) == 1) {
    uStack_30 = 0;
    iVar1 = FUN_4201408c(param_1,param_2,0x48,param_3,&uStack_30,auStack_50,0xff,param_4);
    if ((iVar1 == 0) &&
       (iVar1 = FUN_42016228(uStack_30,param_2,0x48,param_3,0xff,param_4), iVar1 == 0)) {
      if (param_4 == 0xff) {
        iVar2 = FUN_4201408c(param_1,param_2,0x48,param_3,&uStack_30,auStack_50,0xff,0xff);
        if (iVar2 == 0) {
          iVar2 = FUN_42016228(uStack_30,param_2,0x48,param_3,0xff,0xff);
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        else if (iVar2 != DAT_42000cd4) {
          return iVar2;
        }
      }
      if (param_4 == 0) {
        bVar4 = 0x80;
      }
      else if (param_4 == 0x80) {
        bVar4 = 0xff;
      }
      else {
        bVar4 = 0xff;
        param_4 = 0;
      }
      for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        auStack_2c[0] = 0;
        do {
          iVar3 = FUN_42015dbc(iVar2,param_2,0x42,param_3,auStack_2c,auStack_50,0xff,0xff);
          if (iVar3 == DAT_42000cd4) break;
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar3 = 0;
          if ((param_4 <= bStack_4d) && (bStack_4d < bVar4)) {
            iVar3 = FUN_42015c90(iVar2,auStack_2c[0]);
          }
          auStack_2c[0] = bStack_4e + auStack_2c[0];
          if (iVar3 != 0) {
            return iVar3;
          }
        } while (auStack_2c[0] < 0x7e);
      }
    }
  }
  else {
    iVar1 = DAT_420010a0;
  }
  return iVar1;
}


