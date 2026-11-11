int FUN_4201c48c(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_60 [2];
  byte bStack_5e;
  uint auStack_40 [4];
  uint uStack_30;
  
  iVar3 = *(int *)(param_1 + 100);
  uStack_30 = param_2 & 0xff;
  *param_3 = 0;
  iVar1 = DAT_420011bc;
  iVar2 = DAT_42001a70;
  if (iVar3 == 1) {
    for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      auStack_40[0] = 0;
      do {
        iVar3 = FUN_4201d244(iVar2,uStack_30,0xff,0,auStack_40,auStack_60,0xff,0xff);
        if (iVar3 == iVar1) break;
        if (iVar3 != 0) {
          return iVar3;
        }
        auStack_40[0] = bStack_5e + auStack_40[0];
        *param_3 = *param_3 + (uint)bStack_5e;
      } while (auStack_40[0] < 0x7e);
    }
    iVar2 = 0;
  }
  return iVar2;
}