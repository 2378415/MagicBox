// 4200b88c  FUN_4200b88c  FUN_4200b88c  size=198

int FUN_4200b88c(void)

{
  int iVar1;
  undefined1 auStack_d0 [72];
  undefined2 uStack_88;
  int iStack_84;
  ushort uStack_80;
  undefined1 auStack_7c [52];
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int aiStack_30 [12];
  
  (*DAT_42000240)(auStack_d0,0,0x88);
  (*DAT_42000240)(&iStack_48,0,0x18);
  aiStack_30[0] = 0x18;
  iVar1 = FUN_4200ae8c();
  if (iVar1 == 0) {
    uStack_88 = 0;
    iVar1 = FUN_4200b834(auStack_d0);
    if (-1 < iVar1) {
      aiStack_30[0] = aiStack_30[0] + iVar1;
      iVar1 = FUN_4200af64(auStack_7c,aiStack_30);
      if ((iVar1 == 0) && (iVar1 = FUN_4200afd4(auStack_7c), iVar1 == 0)) {
        iStack_48 = aiStack_30[0];
        uStack_44 = FUN_4200b988();
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        uStack_34 = (*(code *)PTR_FUN_42000524)();
        iVar1 = FUN_4200aed4(auStack_7c,&iStack_48,0x18);
        if (iVar1 == 0) {
          uStack_88 = 1;
          iStack_84 = (uint)uStack_80 * 0x20 + 0x34;
          iVar1 = FUN_4200b834(auStack_d0);
          if (-1 < iVar1) {
            uStack_88 = 2;
            iStack_84 = (uint)uStack_80 * 0x20 + 0x34;
            iVar1 = FUN_4200b834(auStack_d0);
            if (-1 < iVar1) {
              iVar1 = FUN_4200afe4(auStack_7c);
            }
          }
        }
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


