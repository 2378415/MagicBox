// 420145b0  FUN_420145b0  FUN_420145b0  size=94

int FUN_420145b0(int param_1,undefined1 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_50 [2];
  byte bStack_4e;
  uint auStack_30 [12];
  
  *param_3 = 0;
  if (*(int *)(param_1 + 100) == 1) {
    for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      auStack_30[0] = 0;
      do {
        iVar1 = FUN_42015dbc(iVar2,param_2,0xff,0,auStack_30,auStack_50,0xff,0xff);
        if (iVar1 == DAT_42000cd4) break;
        if (iVar1 != 0) {
          return iVar1;
        }
        *param_3 = *param_3 + (uint)bStack_4e;
        auStack_30[0] = bStack_4e + auStack_30[0];
      } while (auStack_30[0] < 0x7e);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_420010a0;
  }
  return iVar2;
}


