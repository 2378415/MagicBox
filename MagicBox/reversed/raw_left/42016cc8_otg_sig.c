// 42016cc8  otg_sig  FUN_42016cc8  size=352
// strings: usb_phy_otg_set_mode | usb_phy | otg_sig

undefined4 FUN_42016cc8(int *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined *puVar5;
  
  if (param_1 == (int *)0x0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x85;
    puVar5 = PTR_DAT_42001504;
  }
  else {
    if (param_2 < 3) {
      if (param_1[1] != 0) {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_usb_phy_420014ec,PTR_DAT_4200150c,uVar1,PTR_s_usb_phy_420014ec,
                   PTR_s_usb_phy_otg_set_mode_42001500,0x87);
        return 0xffffffff;
      }
      param_1[3] = param_2;
      if (*param_1 != 1) {
        puVar2 = *(undefined4 **)(PTR_PTR_42001510 + 4);
        if (puVar2 == (undefined4 *)0x0) {
          (*(code *)PTR_FUN_420000a8)
                    (PTR_s_usb_phy_c_3c039470_0x15_4200151c,0x93,PTR_s_usb_phy_otg_set_mode_42001518
                     ,PTR_s_otg_sig_42001514);
        }
        if (param_2 == 1) {
          (*DAT_42000b30)(0x3c,*puVar2,0);
          (*DAT_42000b30)(0x3c,puVar2[2],0);
          (*DAT_42000b30)(0x38,puVar2[3],0);
          (*DAT_42000b30)(0x38,puVar2[1],0);
          if (*param_1 == 0) {
            puVar4 = (uint *)param_1[6];
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_42000a74;
            memw();
            memw();
            *puVar4 = *puVar4 | DAT_42000a44;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_4200028c;
            memw();
            memw();
            *puVar4 = *puVar4 | DAT_42000d30;
            memw();
            memw();
            *puVar4 = *puVar4 | DAT_42000988;
          }
        }
        else if (param_2 == 2) {
          (*DAT_42000b30)(0x38,*puVar2,0);
          (*DAT_42000b30)(0x38,puVar2[2],0);
          (*DAT_42000b30)(0x38,puVar2[3],0);
          (*DAT_42000b30)(0x3c,puVar2[1],0);
        }
      }
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x86;
    puVar5 = PTR_DAT_42001508;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_s_usb_phy_420014ec,puVar5,uVar1,PTR_s_usb_phy_420014ec,
             PTR_s_usb_phy_otg_set_mode_42001500,uVar3);
  return 0x102;
}


