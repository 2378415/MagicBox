// 42016e2c  usb_phy_otg_dev_set_speed  FUN_42016e2c  size=316
// strings: usb_phy_otg_dev_set_speed | usb_phy

undefined4 FUN_42016e2c(int *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  undefined *puVar5;
  
  if (param_1 == (int *)0x0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar2 = 0xaf;
    puVar5 = PTR_DAT_42001504;
  }
  else {
    if (param_2 < 4) {
      if (param_1[1] == 0) {
        iVar3 = *param_1;
        if ((iVar3 != 2) && (param_1[3] == 2)) {
          if ((iVar3 == 1) != (param_2 == 3)) {
            uVar1 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (1,PTR_s_usb_phy_420014ec,PTR_DAT_4200152c,uVar1,PTR_s_usb_phy_420014ec,
                       PTR_s_usb_phy_otg_dev_set_speed_42001520,0xb4);
            return 0x106;
          }
          param_1[4] = param_2;
          if (iVar3 != 1) {
            puVar4 = (uint *)param_1[6];
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_42000a74 | (uint)(param_2 != 1) << 0xd;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_42000294;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_4200028c | (uint)(param_2 == 1) << 0xf;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_4200065c;
            memw();
            memw();
            *puVar4 = *puVar4 | DAT_42000988;
          }
          return 0;
        }
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        uVar2 = 0xb2;
        puVar5 = PTR_DAT_42001528;
      }
      else {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        uVar2 = 0xb1;
        puVar5 = PTR_DAT_4200150c;
      }
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_usb_phy_420014ec,puVar5,uVar1,PTR_s_usb_phy_420014ec,
                 PTR_s_usb_phy_otg_dev_set_speed_42001520,uVar2);
      return 0xffffffff;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar2 = 0xb0;
    puVar5 = PTR_DAT_42001524;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_s_usb_phy_420014ec,puVar5,uVar1,PTR_s_usb_phy_420014ec,
             PTR_s_usb_phy_otg_dev_set_speed_42001520,uVar2);
  return 0x102;
}


