// 4200b62c  FUN_4200b62c  FUN_4200b62c  size=113

int FUN_4200b62c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  (*DAT_42000240)(auStack_40,0,0xc);
  (*DAT_42000240)(&local_34,0,8);
  FUN_4200ac28();
  iVar1 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  while( true ) {
    do {
      iVar2 = FUN_42026404(&uStack_2c);
      if (iVar2 == -1) {
        return iVar1;
      }
      iVar2 = FUN_4200ac9c(uStack_24,auStack_40,&local_34);
    } while (iVar2 == 0);
    iVar2 = FUN_4200b604(param_1,auStack_40);
    if (iVar2 < 1) break;
    iVar1 = iVar1 + iVar2;
    if (iStack_30 != 0) {
      iVar2 = FUN_4200b27c(param_1,1,local_34,local_34);
      if (iVar2 < 1) {
        return iVar2;
      }
      iVar1 = iVar1 + iVar2;
    }
  }
  return iVar2;
}


