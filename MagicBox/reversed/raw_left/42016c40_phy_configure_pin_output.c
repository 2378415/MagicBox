// 42016c40  phy_configure_pin_output  FUN_42016c40  size=133
// strings: phy_configure_pin_output

undefined4 FUN_42016c40(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0xffffffff) {
LAB_42016c46:
    uVar1 = 0;
  }
  else {
    if (-1 < (int)param_1) {
      uVar2 = DAT_42000b0c << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
              DAT_42000b10 >> (param_1 & 0x1f);
      if ((param_1 >> 5 & 1) != 0) {
        uVar2 = DAT_42000b14 >> (param_1 & 0x1f);
      }
      if ((uVar2 & 1) == 0) {
        (*DAT_420014f4)(param_1);
        (*DAT_42000b34)(param_1,param_2,uVar2 & 1,uVar2 & 1);
        (*DAT_420014f8)(param_1);
        goto LAB_42016c46;
      }
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_420014f0,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_phy_configure_pin_output_420014fc,0x4f);
    uVar1 = 0x102;
  }
  return uVar1;
}


