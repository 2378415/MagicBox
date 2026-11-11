// strings: usb_new_phy | usb_phy | usb_phy_install | (j7@ | usb_dwc_info.controllers[otg11_index].internal_p | phy_external_iopins_configure | /IDF/components/usb/usb_phy.c | phy_external_iopins_configure(phy_context->iopin | phy_otg_iopins_configure | phy_otg_iopins_configure(config->otg_io_conf, ot

uint * FUN_420170c4(uint *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  uint uVar22;
  undefined4 *puVar23;
  undefined4 uVar24;
  undefined4 *puVar25;
  undefined *puVar26;
  
  puVar26 = PTR_DAT_42001534;
  uVar22 = param_1[1];
  if (2 < uVar22) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar24 = 0x13d;
    puVar26 = PTR_DAT_4200154c;
LAB_420170f8:
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,puVar26,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_new_phy_42001548,uVar24);
    return (uint *)0x102;
  }
  if (1 < *param_1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar24 = 0x13e;
    puVar26 = PTR_DAT_42001550;
    goto LAB_420170f8;
  }
  if (uVar22 == 2) {
    if (param_1[4] == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar24 = 0x13f;
      puVar26 = PTR_DAT_42001554;
      goto LAB_420170f8;
    }
  }
  else if (uVar22 == 1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001558,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_new_phy_42001548,0x144);
    return (uint *)0x106;
  }
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001534,0xffffffff);
  piVar21 = DAT_42001538;
  if (*DAT_42001538 == 0) {
    (*(code *)PTR_FUN_420004e0)(puVar26);
    iVar3 = (*(code *)PTR_FUN_42000910)(1,0x10);
    if (iVar3 == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      puVar26 = PTR_s_usb_phy_420014ec;
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001560,uVar1,PTR_s_usb_phy_420014ec,
                 PTR_s_usb_phy_install_4200155c,0x117);
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,puVar26,PTR_DAT_42001564,uVar1,puVar26,PTR_s_usb_new_phy_42001548,0x147);
      return (uint *)0x101;
    }
    (*(code *)PTR_FUN_420004dc)(puVar26,0xffffffff);
    if (*piVar21 == 0) {
      *piVar21 = iVar3;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      goto LAB_420171e2;
    }
    (*(code *)PTR_FUN_420004e0)(puVar26);
    (*(code *)PTR_FUN_42000570)(iVar3);
  }
  else {
LAB_420171e2:
    (*(code *)PTR_FUN_420004e0)();
  }
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000910)(1,0x1c);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001568,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_new_phy_42001548,0x14b);
    param_1 = (uint *)0x101;
    goto LAB_42017540;
  }
  (*(code *)PTR_FUN_420004dc)(puVar26,0xffffffff);
  FUN_42017038(uVar22,puVar2 + 2);
  if (puVar2[2] == 0) {
    puVar25 = (undefined4 *)*piVar21;
    puVar25[3] = puVar25[3] + 1;
    if (uVar22 == 2) {
      puVar25[2] = puVar2;
      (*(code *)PTR_FUN_420004e0)(puVar26);
      puVar2[1] = *param_1;
      *puVar2 = 2;
      puVar2[2] = 1;
      (*(code *)PTR_FUN_42000aa8)();
      FUN_4201aa84(puVar2 + 6);
      (*(code *)PTR_FUN_42000aac)();
      if (*param_1 == 0) {
        FUN_4201aad8(puVar2 + 6,1);
      }
      *param_2 = puVar2;
      iVar3 = (*(code *)PTR_FUN_42000910)(1,0x20);
      puVar2[5] = iVar3;
      if (iVar3 == 0) {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001578,uVar1,PTR_s_usb_phy_420014ec,
                   PTR_s_usb_new_phy_42001548,0x17d);
        param_1 = (uint *)0x101;
        goto LAB_42017530;
      }
      (*DAT_42000064)(iVar3,param_1[4],0x20);
      piVar21 = (int *)PTR_PTR_42001510;
      puVar25 = (undefined4 *)puVar2[5];
      puVar23 = *(undefined4 **)PTR_PTR_42001510;
      if ((puVar25 == (undefined4 *)0x0) ||
         (puVar23 == (undefined4 *)0x0 || puVar25 == (undefined4 *)0x0)) {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001540,uVar1,PTR_s_usb_phy_420014ec,
                   PTR_s_phy_external_iopins_configure_4200157c,0x5a);
      }
      else {
        iVar3 = FUN_42016bb0(*puVar25,*puVar23);
        iVar4 = FUN_42016bb0(puVar25[1],puVar23[1]);
        iVar5 = FUN_42016bb0(puVar25[2],puVar23[2]);
        iVar6 = FUN_42016c40(puVar25[3],puVar23[3]);
        iVar7 = FUN_42016c40(puVar25[4],puVar23[4]);
        iVar8 = FUN_42016c40(puVar25[5],puVar23[5]);
        iVar9 = FUN_42016c40(puVar25[6],puVar23[6]);
        iVar10 = FUN_42016c40(puVar25[7],puVar23[7]);
        if (((((((iVar3 == 0 && iVar4 == 0) && iVar5 == 0) && iVar6 == 0) && iVar7 == 0) &&
             iVar8 == 0) && iVar9 == 0) && iVar10 == 0) goto LAB_42017424;
      }
      (*(code *)PTR_FUN_42000a1c)
                (0x102,PTR_s__IDF_components_usb_usb_phy_c_42001584,0x180,PTR_s_usb_new_phy_42001574
                 ,PTR_s_phy_external_iopins_configure_ph_42001580);
    }
    else {
      *puVar25 = puVar2;
      (*(code *)PTR_FUN_420004e0)(puVar26);
      uVar22 = *param_1;
      *puVar2 = 0;
      puVar2[1] = uVar22;
      puVar2[2] = 1;
      (*(code *)PTR_FUN_42000aa8)();
      FUN_4201aa84(puVar2 + 6);
      (*(code *)PTR_FUN_42000aac)();
      if (*param_1 == 0) {
        FUN_4201aad8(puVar2 + 6);
      }
      piVar21 = (int *)PTR_PTR_42001510;
      puVar25 = *(undefined4 **)(PTR_PTR_42001510 + 8);
      if (puVar25 == (undefined4 *)0x0) {
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_usb_phy_c_3c039470_0x15_4200151c,0x175,PTR_s_usb_new_phy_42001574,
                   PTR_s_usb_dwc_info_controllers_otg11_i_42001570);
      }
      FUN_4201846c(puVar25[1],3);
      FUN_4201846c(*puVar25,3);
      *param_2 = puVar2;
    }
LAB_42017424:
    if ((param_1[2] != 0) && (iVar3 = FUN_42016cc8(*param_2), iVar3 != 0)) {
      (*(code *)PTR_FUN_42000a1c)
                (iVar3,PTR_s__IDF_components_usb_usb_phy_c_42001584,0x183,PTR_s_usb_new_phy_42001574
                 ,PTR_s_usb_phy_otg_set_mode__handle_ret_42001588);
    }
    if ((param_1[3] != 0) && (iVar3 = FUN_42016e2c(*param_2), iVar3 != 0)) {
      (*(code *)PTR_FUN_42000a1c)
                (iVar3,PTR_s__IDF_components_usb_usb_phy_c_42001584,0x186,PTR_s_usb_new_phy_42001574
                 ,PTR_s_usb_phy_otg_dev_set_speed__handl_4200158c);
    }
    puVar25 = (undefined4 *)param_1[5];
    if ((puVar25 == (undefined4 *)0x0) || (puVar2[1] != 0)) {
      return (uint *)0x0;
    }
    puVar23 = (undefined4 *)piVar21[1];
    if (puVar23 == (undefined4 *)0x0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001540,uVar1,PTR_s_usb_phy_420014ec,
                 PTR_s_phy_otg_iopins_configure_42001590,0x6e);
    }
    else {
      uVar22 = FUN_42016bb0(*puVar25,*puVar23);
      uVar11 = FUN_42016bb0(puVar25[1],puVar23[1]);
      uVar12 = FUN_42016bb0(puVar25[2],puVar23[3]);
      uVar13 = FUN_42016bb0(puVar25[7],puVar23[2]);
      uVar14 = FUN_42016bb0(puVar25[8],puVar23[4]);
      uVar15 = FUN_42016c40(puVar25[3],puVar23[5]);
      uVar16 = FUN_42016c40(puVar25[4],puVar23[6]);
      uVar17 = FUN_42016c40(puVar25[5],puVar23[7]);
      uVar18 = FUN_42016c40(puVar25[6],puVar23[8]);
      uVar19 = FUN_42016c40(puVar25[9],puVar23[9]);
      uVar20 = FUN_42016c40(puVar25[10],puVar23[10]);
      puVar2 = (undefined4 *)
               (uVar22 | uVar11 | uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 |
                uVar19 | uVar20);
      if (puVar2 == (undefined4 *)0x0) {
        return (uint *)0x0;
      }
    }
    (*(code *)PTR_FUN_42000a1c)
              (0x102,PTR_s__IDF_components_usb_usb_phy_c_42001584,0x18a,PTR_s_usb_new_phy_42001574,
               PTR_s_phy_otg_iopins_configure_config__42001594);
  }
  else {
    (*(code *)PTR_FUN_420004e0)(puVar26);
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_4200156c,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_new_phy_42001548,0x15b);
    param_1 = (uint *)0x103;
  }
LAB_42017530:
  (*(code *)PTR_FUN_42000570)(puVar2[5]);
  (*(code *)PTR_FUN_42000570)(puVar2);
LAB_42017540:
  if (*(int *)(*piVar21 + 0xc) == 0) {
    (*(code *)PTR_FUN_42000570)();
    *piVar21 = 0;
    return param_1;
  }
  return param_1;
}