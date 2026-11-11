undefined4 FUN_4201c2b4(int param_1,uint param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_60;
  char cStack_5f;
  undefined4 auStack_40 [4];
  uint uStack_30;
  
  uStack_30 = param_2 & 0xff;
  if (*(int *)(param_1 + 100) == 1) {
    if (param_3 == 'A') {
LAB_4201c32b:
      uVar2 = FUN_4201b2ec(param_1,uStack_30,param_4,0xff);
    }
    else {
      uVar2 = DAT_420011bc;
      for (iVar3 = *(int *)(param_1 + 0x10); DAT_420011bc = uVar2, iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 4)) {
        auStack_40[0] = 0;
        iVar1 = FUN_4201d244(iVar3,uStack_30,param_3,param_4,auStack_40,&uStack_60,0xff,0xff);
        if (iVar1 == 0) {
          if ((cStack_5f != 'B') && (cStack_5f != 'H' && cStack_5f != 'B')) {
            uVar2 = FUN_4201d70c(iVar3,uStack_30,param_3,param_4,0xff);
            return uVar2;
          }
          if (*(int *)(param_1 + 100) == 1) goto LAB_4201c32b;
          goto LAB_4201c2c6;
        }
        uVar2 = DAT_420011bc;
      }
    }
  }
  else {
LAB_4201c2c6:
    uVar2 = DAT_42001a70;
  }
  return uVar2;
}