// 4200d6c8  FUN_4200d6c8  FUN_4200d6c8  size=111

void FUN_4200d6c8(void)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 1;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  iVar1 = FUN_420108e8(&local_40,DAT_42000b38);
  if (iVar1 == 0) {
    iVar1 = FUN_42003938(0x26,0xe,PTR_FUN_42000b4c,0,DAT_42000b48);
    if (iVar1 != 0) {
      (*DAT_42000634)(PTR_DAT_42000b3c);
      (*DAT_42000634)(PTR_s_USB_Interrupt_Init_Failed__42000b50);
      (*DAT_42000634)(PTR_DAT_42000b44);
    }
  }
  else {
    (*DAT_42000634)(PTR_DAT_42000b3c);
    (*DAT_42000634)(PTR_s_USB_Phy_Init_Failed__42000b40);
    (*DAT_42000634)(PTR_DAT_42000b44);
  }
  return;
}


