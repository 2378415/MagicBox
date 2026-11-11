// strings: ,b7@('

int FUN_4200d628(void)

{
  int iVar1;
  undefined4 local_d0 [18];
  undefined2 uStack_88;
  int iStack_84;
  ushort uStack_80;
  undefined1 auStack_7c [52];
  int local_48;
  undefined4 uStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  int aiStack_30 [12];
  
  local_d0[0] = 0;
  local_48 = 0;
  aiStack_30[0] = 0x18;
  iVar1 = FUN_4200ce7c();
  if (iVar1 == 0) {
    uStack_88 = 0;
    iVar1 = FUN_4200d2a4(local_d0);
    if (-1 < iVar1) {
      aiStack_30[0] = aiStack_30[0] + iVar1;
      iVar1 = FUN_4200cf50(auStack_7c,aiStack_30);
      if ((iVar1 == 0) && (iVar1 = FUN_4200cfb8(auStack_7c), iVar1 == 0)) {
        local_48 = aiStack_30[0];
        uStack_44 = FUN_4200d700();
        iStack_40 = iVar1;
        iStack_3c = iVar1;
        iStack_38 = iVar1;
        uStack_34 = (*DAT_42000088)();
        iVar1 = FUN_4200ceb4(auStack_7c,&local_48,0x18);
        if (iVar1 == 0) {
          iStack_84 = (uint)uStack_80 * 0x20 + 0x34;
          uStack_88 = 1;
          iVar1 = FUN_4200d2a4(local_d0);
          if (-1 < iVar1) {
            iStack_84 = (uint)uStack_80 * 0x20 + 0x34;
            uStack_88 = 2;
            iVar1 = FUN_4200d2a4(local_d0);
            if (-1 < iVar1) {
              iVar1 = FUN_4200cfc8(auStack_7c);
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