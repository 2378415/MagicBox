// strings: usb_dwc_info.controllers[otg11_index].internal_p | usb_new_phy | phy_external_iopins_configure(phy_context->iopin | usb_phy_otg_set_mode(*handle_ret, config->otg_mo | usb_phy_otg_dev_set_speed(*handle_ret, config->o | phy_otg_iopins_configure(config->otg_io_conf, ot

int FUN_420108e8(uint *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  
  uVar5 = param_1[1];
  if (2 < uVar5) {
    return 0x102;
  }
  if (1 < *param_1) {
    return 0x102;
  }
  if ((uVar5 == 2) && (param_1[4] == 0)) {
    return 0x102;
  }
  if (uVar5 == 1) {
    return 0x106;
  }
  iVar2 = FUN_420103e4();
  if (iVar2 != 0) {
    return iVar2;
  }
  puVar3 = (uint *)(*(code *)PTR_FUN_42000738)(1,0x1c);
  if (puVar3 == (uint *)0x0) {
    iVar2 = 0x101;
    goto LAB_42010a9b;
  }
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000da8,0xffffffff);
  FUN_42010898(uVar5,puVar3 + 2);
  if (puVar3[2] == 0) {
    piVar6 = (int *)*DAT_42000dac;
    piVar6[3] = piVar6[3] + 1;
    if (uVar5 == 2) {
      piVar6[2] = (int)puVar3;
      bVar1 = true;
    }
    else if (uVar5 == 0) {
      *piVar6 = (int)puVar3;
      bVar1 = true;
    }
    else {
      piVar6[1] = (int)puVar3;
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000da8);
  if (bVar1) {
    *puVar3 = uVar5;
    puVar3[1] = *param_1;
    puVar3[2] = 1;
    for (iVar2 = 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      (*(code *)PTR_FUN_4200086c)();
      FUN_42013808(puVar3 + 6);
      (*(code *)PTR_FUN_42000870)();
    }
    if (*param_1 == 0) {
      FUN_42013844(puVar3 + 6,uVar5 == 2);
    }
    if (uVar5 == 0) {
      puVar4 = *(undefined4 **)(PTR_PTR_42000db8 + 8);
      if (puVar4 == (undefined4 *)0x0) {
        (*(code *)PTR_FUN_42000044)
                  (PTR_s_usb_phy_c_3c033cb0_0x15_42000dc4,0x175,PTR_s_usb_new_phy_42000dd0,
                   PTR_s_usb_dwc_info_controllers_otg11_i_42000dcc);
      }
      FUN_42011748(puVar4[1],3);
      FUN_42011748(*puVar4,3);
    }
    *param_2 = (int)puVar3;
    if (uVar5 != 2) {
LAB_42010a16:
      if ((param_1[2] != 0) && (iVar2 = FUN_42010650(*param_2), iVar2 != 0)) {
        (*(code *)PTR_FUN_42000840)
                  (iVar2,PTR_s__IDF_components_usb_usb_phy_c_42000dd8,0x183,
                   PTR_s_usb_new_phy_42000dd0,PTR_s_usb_phy_otg_set_mode__handle_ret_42000ddc);
      }
      if ((param_1[3] != 0) && (iVar2 = FUN_420107a8(*param_2), iVar2 != 0)) {
        (*(code *)PTR_FUN_42000840)
                  (iVar2,PTR_s__IDF_components_usb_usb_phy_c_42000dd8,0x186,
                   PTR_s_usb_new_phy_42000dd0,PTR_s_usb_phy_otg_dev_set_speed__handl_42000de0);
      }
      if (param_1[5] == 0) {
        return 0;
      }
      if (puVar3[1] != 0) {
        return 0;
      }
      iVar2 = FUN_420105c0(param_1[5],*(undefined4 *)(PTR_PTR_42000db8 + 4));
      if (iVar2 == 0) {
        return 0;
      }
      (*(code *)PTR_FUN_42000840)
                (iVar2,PTR_s__IDF_components_usb_usb_phy_c_42000dd8,0x18a,PTR_s_usb_new_phy_42000dd0
                 ,PTR_s_phy_otg_iopins_configure_config__42000de4);
      goto LAB_42010a79;
    }
    uVar5 = (*(code *)PTR_FUN_42000738)(1,0x20);
    puVar3[5] = uVar5;
    if (uVar5 != 0) {
      (*DAT_420002fc)(uVar5,param_1[4],0x20);
      iVar2 = FUN_4201054c(puVar3[5],*(undefined4 *)PTR_PTR_42000db8);
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_42000840)
                  (iVar2,PTR_s__IDF_components_usb_usb_phy_c_42000dd8,0x180,
                   PTR_s_usb_new_phy_42000dd0,PTR_s_phy_external_iopins_configure_ph_42000dd4);
      }
      goto LAB_42010a16;
    }
    iVar2 = 0x101;
  }
  else {
LAB_42010a79:
    iVar2 = 0x103;
  }
  (*(code *)PTR_FUN_420004c0)(puVar3[5]);
  (*(code *)PTR_FUN_420004c0)(puVar3);
LAB_42010a9b:
  if (*(int *)(*DAT_42000dac + 0xc) == 0) {
    (*(code *)PTR_FUN_420004c0)();
    *DAT_42000dac = 0;
  }
  return iVar2;
}