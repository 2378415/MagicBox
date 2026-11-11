// 42010650  usb_phy_otg_set_mode  FUN_42010650  size=340
// strings: otg_sig

undefined4 FUN_42010650(int *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x102;
  }
  else if (param_2 < 3) {
    if (param_1[1] == 0) {
      param_1[3] = param_2;
      if (*param_1 == 1) {
        uVar1 = 0;
      }
      else {
        puVar2 = *(undefined4 **)(PTR_PTR_42000db8 + 4);
        if (puVar2 == (undefined4 *)0x0) {
          (*(code *)PTR_FUN_42000044)
                    (PTR_s_usb_phy_c_3c033cb0_0x15_42000dc4,0x93,PTR_s_usb_phy_otg_set_mode_42000dc0
                     ,PTR_s_otg_sig_42000dbc);
        }
        if (param_2 == 1) {
          (*DAT_420008d4)(0x3c,*puVar2,0);
          (*DAT_420008d4)(0x3c,puVar2[2],0);
          (*DAT_420008d4)(0x38,puVar2[3],0);
          (*DAT_420008d4)(0x38,puVar2[1],0);
          if (*param_1 == 0) {
            uVar3 = *(uint *)PTR_DAT_42000dc8;
            puVar4 = (uint *)param_1[6];
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_4200088c | (uVar3 & 1) << 0xd;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_4200016c | (uVar3 >> 0x10 & 1) << 0xe;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_42000164 | (uVar3 >> 8 & 1) << 0xf;
            memw();
            memw();
            *puVar4 = *puVar4 & DAT_42000480 | (uVar3 >> 0x18 & 1) << 0x10;
            memw();
            memw();
            *puVar4 = *puVar4 | DAT_4200077c;
            uVar1 = 0;
          }
          else {
            uVar1 = 0;
          }
        }
        else if (param_2 == 2) {
          (*DAT_420008d4)(0x38,*puVar2,0);
          (*DAT_420008d4)(0x38,puVar2[2],0);
          (*DAT_420008d4)(0x38,puVar2[3],0);
          (*DAT_420008d4)(0x3c,puVar2[1],0);
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


