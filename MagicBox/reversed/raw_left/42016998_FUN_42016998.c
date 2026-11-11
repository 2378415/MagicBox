// 42016998  FUN_42016998  FUN_42016998  size=112

void FUN_42016998(void)

{
  int iVar1;
  undefined4 local_40 [2];
  undefined4 uStack_38;
  
  local_40[0] = 0;
  uStack_38 = 2;
  iVar1 = FUN_420170c4(local_40,DAT_420014c4);
  if (iVar1 == 0) {
    iVar1 = FUN_42005720(0x26,0xe,PTR_FUN_420014d8,0,DAT_420014d4);
    if (iVar1 != 0) {
      (*DAT_42000060)(PTR_DAT_420014c8);
      (*DAT_42000060)(PTR_s_USB_Interrupt_Init_Failed__420014dc);
      (*DAT_42000060)(PTR_DAT_420014d0);
    }
  }
  else {
    (*DAT_42000060)(PTR_DAT_420014c8);
    (*DAT_42000060)(PTR_s_USB_Phy_Init_Failed__420014cc);
    (*DAT_42000060)(PTR_DAT_420014d0);
  }
  return;
}


