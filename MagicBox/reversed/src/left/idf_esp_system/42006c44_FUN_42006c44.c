// strings: Fatal error: IRAM0 I_0 split line configuration  | Fatal error: IRAM0 I_1 split line configuration  | Fatal error: DRAM0 D_1 split line configuration 

int FUN_42006c44(char *param_1)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  char *extraout_a3;
  uint *puVar4;
  char *extraout_a3_00;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  uint unaff_a8;
  char *pcVar12;
  int *piVar13;
  int iVar14;
  undefined4 uVar15;
  uint *puVar16;
  char cVar17;
  char *in_t0;
  uint local_80 [7];
  uint local_64 [7];
  char *apcStack_48 [2];
  uint *puStack_40;
  int *piStack_3c;
  char *pcStack_38;
  int *piStack_34;
  int *piStack_30;
  uint uStack_2c;
  
  puVar3 = local_80;
  puVar4 = local_80;
  puVar16 = local_80;
  rer(unaff_a8);
  if ((unaff_a8 & 1) != 0) {
    rer(unaff_a8);
    if ((unaff_a8 & 1) == 0) {
      (*DAT_42000820)();
      do {
        ill();
      } while( true );
    }
    uVar9 = rer(unaff_a8);
    if ((unaff_a8 & 1) == 0) {
      (*DAT_42000820)();
      do {
        ill();
      } while( true );
    }
    uVar10 = rer(uVar9);
    if ((uVar10 & 1) != 0) {
      return 0;
    }
    (*DAT_42000820)();
    do {
      ill();
    } while( true );
  }
  if (param_1 == (char *)0x0) {
    return 0x102;
  }
  uVar10 = *(uint *)(param_1 + 8);
  if (uVar10 == 0) {
    return 0x101;
  }
  piVar11 = *(int **)(param_1 + 0xc);
  if (((char *)0x1 < (char *)((int)piVar11 + -1)) || (*(int *)(PTR_DAT_4200075c + 0xc) == 0)) {
    return DAT_4200072c;
  }
  iVar14 = *(int *)(param_1 + 0x10);
  pcVar6 = param_1 + (int)piVar11 * 4;
  pcVar12 = param_1;
  while( true ) {
    if (*(int *)(PTR_DAT_4200075c + 0x10) != iVar14) {
      pcVar5 = pcVar12;
      if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
        return DAT_4200072c;
      }
      do {
        if (*(int *)(PTR_DAT_4200075c + 0x14) != iVar14) {
          return DAT_4200072c;
        }
        pcVar12 = pcVar5 + 4;
        if (pcVar6 == pcVar12) goto LAB_42006cf8;
        iVar14 = *(int *)(pcVar5 + 0x14);
        pcVar5 = pcVar12;
      } while (iVar14 != *(int *)(PTR_DAT_4200075c + 0x10));
    }
    if (pcVar12 + 4 == pcVar6) break;
    iVar14 = *(int *)(pcVar12 + 0x14);
    pcVar12 = pcVar12 + 4;
  }
LAB_42006cf8:
  piStack_3c = (int *)(uVar10 & 1);
  puStack_40 = (uint *)(uVar10 & 4);
  uVar7 = uVar10 & 2;
  pcStack_38 = param_1;
  if ((uVar10 & 1) == 0) {
    if (uVar7 == 0) {
      if (puStack_40 == (uint *)0x0) goto LAB_420076ad;
LAB_42006d1d:
      pcVar12 = param_1;
      do {
        iVar14 = FUN_42006710(4,0,*(undefined4 *)(pcVar12 + 0x10));
        if (iVar14 != 0) {
          return iVar14;
        }
        pcVar12 = pcVar12 + 4;
      } while (pcVar6 != pcVar12);
      if (*param_1 != '\0') {
        if (piStack_3c != (int *)0x0) goto LAB_42006d48;
        if (uVar7 != 0) goto LAB_42006d7a;
        goto LAB_42006dfa;
      }
      goto LAB_42006e9e;
    }
LAB_42006d10:
    pcVar12 = param_1;
    do {
      iVar14 = FUN_42006710(2,0,*(undefined4 *)(pcVar12 + 0x10));
      if (iVar14 != 0) {
        return iVar14;
      }
      pcVar12 = pcVar12 + 4;
    } while (pcVar6 != pcVar12);
    if (puStack_40 != (uint *)0x0) goto LAB_42006d1d;
    if (*param_1 != '\0') {
      if (piStack_3c != (int *)0x0) goto LAB_42006d48;
      goto LAB_42006d7a;
    }
LAB_420076e4:
    uVar10 = *(uint *)(param_1 + 4);
    if (*(uint *)(param_1 + 4) == 0) {
      uVar10 = DAT_420007c0;
    }
    uVar9 = 2;
    if ((uVar10 + DAT_42000730 <= DAT_42000734) && (uVar9 = 3, (uVar10 & 0xff) == 0)) {
      (*DAT_42000064)(local_64,PTR_DAT_42000738);
      puVar8 = local_64;
      piStack_34 = (int *)PTR_DAT_4200073c;
      iVar14 = 0;
      piStack_30 = piVar11;
      uStack_2c = uVar7;
      do {
        (*DAT_42000064)(local_80,piStack_34,0x1c);
        uVar7 = uStack_2c;
        piVar11 = piStack_30;
        if (uVar10 <= *puVar3) {
          local_64[iVar14] = 2;
          goto LAB_42006f23;
        }
        *puVar8 = 0;
        iVar14 = iVar14 + 1;
        puVar3 = puVar3 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar14 != 7);
      uVar7 = uStack_2c;
      piVar11 = piStack_30;
LAB_42006f23:
      memw();
      *DAT_42000748 =
           (local_64[1] & 3) << 2 | local_64[0] & 3 | (local_64[2] & 3) << 4 |
           (local_64[3] & 3) << 6 | (local_64[4] & 3) << 8 | (local_64[5] & 3) << 10 |
           (local_64[6] & 3) << 0xc | ((uVar10 & 0x3ffffff) >> 8 & 0xff) << 0xe;
      uVar9 = 0;
    }
    iVar14 = FUN_4200775c(uVar9);
    if (iVar14 != 0) {
      return iVar14;
    }
    iVar14 = FUN_42005b3c(1,2,uVar10,0xffffffff);
    if (iVar14 != 0) {
      return iVar14;
    }
    iVar14 = FUN_42005b3c(1,1,uVar10,0xffffffff);
    if (iVar14 != 0) {
      return iVar14;
    }
    iVar2 = uVar10 + DAT_42000750;
    iVar14 = FUN_42005b3c(2,8,iVar2,0xffffffff);
    if (iVar14 != 0) {
      return iVar14;
    }
    iVar14 = FUN_42005b3c(2,0x10,iVar2,0xffffffff);
    puVar8 = DAT_42000780;
    puVar3 = DAT_42000778;
    if (iVar14 != 0) {
      return iVar14;
    }
    if (piStack_3c != (int *)0x0) {
      memw();
      memw();
      *DAT_42000778 = *DAT_42000778 & DAT_42000784;
      memw();
      memw();
      *puVar3 = *puVar3 & DAT_42000788 | DAT_420007c4;
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffffff8 | 5;
      memw();
      memw();
      *puVar3 = *puVar3 & 0xffffffc7 | 0x28;
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffffe3f | 0x140;
      memw();
      memw();
      *puVar3 = *puVar3 & DAT_4200077c;
      puVar3 = DAT_42000780;
      if (uVar7 != 0) {
        memw();
        memw();
        *DAT_42000780 = *DAT_42000780 & 0xfffffffc | 1;
        memw();
        memw();
        *puVar3 = *puVar3 | 0xc;
        memw();
        memw();
        *puVar3 = *puVar3 | 0x30;
        memw();
        memw();
        *puVar3 = *puVar3 | 0xc0;
      }
      if (puStack_40 != (uint *)0x0) goto LAB_420070bc;
      piStack_34 = piStack_3c;
      goto LAB_42007107;
    }
    if (uVar7 != 0) {
      memw();
      memw();
      *DAT_42000780 = *DAT_42000780 & 0xfffffffc | 1;
      memw();
      memw();
      *puVar8 = *puVar8 | 0xc;
      memw();
      memw();
      *puVar8 = *puVar8 | 0x30;
      memw();
      memw();
      *puVar8 = *puVar8 | 0xc0;
      if (puStack_40 != (uint *)0x0) goto LAB_420070bc;
      piStack_34 = (int *)0x1;
      goto LAB_4200712a;
    }
    if (puStack_40 != (uint *)0x0) {
LAB_420070bc:
      piStack_34 = (int *)0x1;
      goto LAB_420070c1;
    }
  }
  else {
    pcVar12 = param_1;
    do {
      iVar14 = FUN_42006710(1,0,*(undefined4 *)(pcVar12 + 0x10));
      if (iVar14 != 0) {
        return iVar14;
      }
      pcVar12 = pcVar12 + 4;
    } while (pcVar6 != pcVar12);
    if (uVar7 != 0) goto LAB_42006d10;
    if (puStack_40 != (uint *)0x0) goto LAB_42006d1d;
    if (*param_1 == '\0') goto LAB_420076e4;
LAB_42006d48:
    pcVar12 = param_1;
    piStack_34 = piVar11;
    do {
      iVar14 = *(int *)(pcVar12 + 0x10);
      (*(code *)PTR_FUN_42000264)(0x19);
      if (iVar14 == 0) {
        uVar15 = 0;
        uVar9 = 0x55;
      }
      else if (iVar14 == 1) {
        uVar9 = 0x59;
        uVar15 = 0;
      }
      else {
        uVar9 = 99;
        uVar15 = 0xffffffff;
      }
      iVar2 = FUN_4200775c(uVar15);
      if (iVar2 != 0) {
        return iVar2;
      }
      (*DAT_42000268)(iVar14,uVar9,0x19);
      pcVar12 = pcVar12 + 4;
      (*(code *)PTR_FUN_4200026c)(0x19);
    } while (pcVar6 != pcVar12);
    piVar11 = piStack_34;
    if (uVar7 != 0) {
LAB_42006d7a:
      pcVar12 = param_1;
      piStack_34 = piVar11;
      do {
        iVar14 = *(int *)(pcVar12 + 0x10);
        (*(code *)PTR_FUN_42000264)(0x19);
        if (iVar14 == 0) {
          uVar15 = 0;
          uVar9 = 0x56;
        }
        else if (iVar14 == 1) {
          uVar9 = 0x5a;
          uVar15 = 0;
        }
        else {
          uVar9 = 99;
          uVar15 = 7;
        }
        iVar2 = FUN_4200775c(uVar15);
        if (iVar2 != 0) {
          return iVar2;
        }
        (*DAT_42000268)(iVar14,uVar9,0x19);
        pcVar12 = pcVar12 + 4;
        (*(code *)PTR_FUN_4200026c)(0x19);
        piVar11 = piStack_34;
      } while (pcVar6 != pcVar12);
    }
    piStack_34 = piVar11;
    if (puStack_40 == (uint *)0x0) goto LAB_420076e4;
LAB_42006dfa:
    pcVar12 = param_1;
    piStack_34 = piVar11;
    do {
      iVar14 = *(int *)(pcVar12 + 0x10);
      (*(code *)PTR_FUN_42000264)(0x19);
      if (iVar14 == 0) {
        uVar15 = 0;
        uVar9 = 0x57;
      }
      else if (iVar14 == 1) {
        uVar9 = 0x5b;
        uVar15 = 0;
      }
      else {
        uVar9 = 99;
        uVar15 = 7;
      }
      iVar2 = FUN_4200775c(uVar15);
      if (iVar2 != 0) {
        return iVar2;
      }
      (*DAT_42000268)(iVar14,uVar9,0x19);
      pcVar12 = pcVar12 + 4;
      (*(code *)PTR_FUN_4200026c)(0x19);
    } while (pcVar12 != pcVar6);
    piVar11 = piStack_34;
LAB_42006e9e:
    piStack_34 = (int *)(uVar7 >> 1 | (uint)piStack_3c);
    if (piStack_34 != (int *)0x0) goto LAB_420076e4;
    uVar10 = 0;
LAB_420070c1:
    pcVar12 = param_1;
    do {
      iVar14 = FUN_42005b3c(4,1,PTR_DAT_420007c8,*(undefined4 *)(pcVar12 + 0x10));
      if (iVar14 != 0) {
        return iVar14;
      }
      iVar14 = FUN_42006058(0x100,5,*(undefined4 *)(pcVar12 + 0x10));
      if (iVar14 != 0) {
        return iVar14;
      }
      iVar14 = FUN_42006058(0x200,3,*(undefined4 *)(pcVar12 + 0x10));
      if (iVar14 != 0) {
        return iVar14;
      }
      pcVar12 = pcVar12 + 4;
    } while (pcVar6 != pcVar12);
    if (piStack_3c == (int *)0x0) {
      if (uVar7 != 0) goto LAB_4200712a;
LAB_42007160:
      pcVar12 = param_1;
      do {
        iVar14 = FUN_420068ec(4,*(undefined4 *)(pcVar12 + 0x10));
        if (iVar14 != 0) {
          return iVar14;
        }
        iVar14 = FUN_42006710(4,1,*(undefined4 *)(pcVar12 + 0x10));
        if (iVar14 != 0) {
          return iVar14;
        }
        pcVar12 = pcVar12 + 4;
      } while (pcVar12 != pcVar6);
      if (param_1[1] != '\0') {
        if (piStack_3c != (int *)0x0) goto LAB_4200719d;
        if (uVar7 != 0) goto LAB_420076d7;
        goto LAB_420071fd;
      }
    }
    else {
LAB_42007107:
      pcVar12 = param_1;
      do {
        iVar14 = FUN_420068ec(1,*(undefined4 *)(pcVar12 + 0x10));
        if (iVar14 != 0) {
          return iVar14;
        }
        iVar14 = FUN_42006710(1,1,*(undefined4 *)(pcVar12 + 0x10));
        if (iVar14 != 0) {
          return iVar14;
        }
        pcVar12 = pcVar12 + 4;
      } while (pcVar6 != pcVar12);
      if (uVar7 == 0) {
        if (puStack_40 != (uint *)0x0) goto LAB_42007160;
        if (param_1[1] == '\0') goto LAB_42007219;
LAB_4200719d:
        piStack_30 = DAT_420007bc;
        piVar13 = DAT_42000760;
        memw();
        *DAT_420007bc = 1;
        uVar9 = *(undefined4 *)(param_1 + 0x10);
        memw();
        *piVar13 = 1;
        iVar14 = FUN_42006580(1,uVar9);
        if (iVar14 != 0) {
          return iVar14;
        }
        if ((piVar11 == (int *)0x2) &&
           (iVar14 = FUN_42006580(1,*(undefined4 *)(param_1 + 0x14)), iVar14 != 0)) {
          return iVar14;
        }
        piVar13 = piStack_30;
        if (uVar7 != 0) goto LAB_420071d2;
      }
      else {
LAB_4200712a:
        pcVar12 = param_1;
        do {
          iVar14 = FUN_420068ec(2,*(undefined4 *)(pcVar12 + 0x10));
          if (iVar14 != 0) {
            return iVar14;
          }
          iVar14 = FUN_42006710(2,1,*(undefined4 *)(pcVar12 + 0x10));
          if (iVar14 != 0) {
            return iVar14;
          }
          pcVar12 = pcVar12 + 4;
        } while (pcVar12 != pcVar6);
        if (puStack_40 != (uint *)0x0) goto LAB_42007160;
        if (param_1[1] == '\0') goto LAB_42007219;
        if (piStack_3c != (int *)0x0) goto LAB_4200719d;
LAB_420076d7:
        piVar13 = DAT_420007bc;
LAB_420071d2:
        memw();
        *piVar13 = 1;
        uVar9 = *(undefined4 *)(param_1 + 0x10);
        memw();
        *DAT_42000764 = 1;
        iVar14 = FUN_42006580(2,uVar9);
        if (iVar14 != 0) {
          return iVar14;
        }
        if ((piVar11 == (int *)0x2) &&
           (iVar14 = FUN_42006580(2,*(undefined4 *)(param_1 + 0x14)), iVar14 != 0)) {
          return iVar14;
        }
      }
      if (puStack_40 != (uint *)0x0) {
LAB_420071fd:
        pcVar12 = pcStack_38;
        do {
          iVar14 = FUN_42005fd8(4,*(undefined4 *)(pcVar12 + 0x10));
          if (iVar14 != 0) {
            return iVar14;
          }
          iVar14 = FUN_42006580(4,*(undefined4 *)(pcVar12 + 0x10));
          if (iVar14 != 0) {
            return iVar14;
          }
          pcVar12 = pcVar12 + 4;
        } while (pcVar12 != pcVar6);
      }
    }
LAB_42007219:
    if (piStack_34 == (int *)0x0) goto LAB_420076ad;
  }
  (*DAT_42000064)(local_64,PTR_DAT_42000738);
  iVar14 = 0;
  piStack_34 = (int *)PTR_DAT_4200073c;
  puVar3 = local_64;
  do {
    puStack_40 = puVar4;
    (*DAT_42000064)(local_80,piStack_34,0x1c);
    puVar4 = puStack_40;
    if (uVar10 <= *puStack_40) {
      local_64[iVar14] = 2;
      break;
    }
    *puVar3 = 0;
    iVar14 = iVar14 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar14 != 7);
  apcStack_48[0] =
       (char *)((local_64[1] & 3) << 2 | local_64[0] & 3 | (local_64[2] & 3) << 4 |
                (local_64[3] & 3) << 6 | (local_64[4] & 3) << 8 | (local_64[5] & 3) << 10 |
                (local_64[6] & 3) << 0xc | ((uVar10 & 0x3ffffff) >> 8 & 0xff) << 0xe);
  memw();
  pcVar12 = (char *)*DAT_42000740;
  if (pcVar12 != apcStack_48[0]) {
    memw();
    (*DAT_42000060)(PTR_s_Fatal_error__Main_I_D_split_line_420007cc,apcStack_48[0],*DAT_42000740);
    (*(code *)PTR_FUN_42000330)();
    pcVar12 = extraout_a3;
  }
  memw();
  pcVar6 = (char *)*DAT_42000744;
  if (pcVar6 != pcVar12) {
    memw();
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_I_0_split_lin_420007d0,pcVar12,*DAT_42000744);
    pcVar6 = in_t0;
    (*(code *)PTR_FUN_42000330)();
    in_t0 = pcVar6;
  }
  memw();
  if ((char *)*DAT_42000748 != pcVar6) {
    memw();
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_I_1_split_lin_420007d4,pcVar6,*DAT_42000748);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = DAT_42000750;
  (*DAT_42000064)(local_64,PTR_DAT_42000738);
  uVar10 = uVar10 + iVar14;
  pcVar12 = (char *)0x0;
  puVar4 = local_64;
  do {
    puStack_40 = puVar16;
    pcStack_38 = pcVar12;
    (*DAT_42000064)(local_80,piStack_34,0x1c);
    pcVar12 = pcStack_38;
    puVar16 = puStack_40;
    if (uVar10 <= *puStack_40 + iVar14) {
      local_64[(int)pcStack_38] = 2;
      break;
    }
    *puVar4 = 0;
    pcVar12 = pcVar12 + 1;
    puVar16 = puVar16 + 1;
    puVar4 = puVar4 + 1;
  } while (pcVar12 != (char *)0x7);
  apcStack_48[0] =
       (char *)((local_64[1] & 3) << 2 | local_64[0] & 3 | (local_64[2] & 3) << 4 |
                (local_64[3] & 3) << 6 | (local_64[4] & 3) << 8 | (local_64[5] & 3) << 10 |
                (local_64[6] & 3) << 0xc | ((uVar10 & 0x3ffffff) >> 8 & 0xff) << 0xe);
  memw();
  pcVar12 = (char *)*DAT_42000754;
  if (pcVar12 != apcStack_48[0]) {
    memw();
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_D_0_split_lin_420007d8,apcStack_48[0],*DAT_42000754);
    (*(code *)PTR_FUN_42000330)();
    pcVar12 = extraout_a3_00;
  }
  memw();
  if ((char *)*DAT_42000758 != pcVar12) {
    memw();
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_D_1_split_lin_420007dc,pcVar12,*DAT_42000758);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(1,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x5) {
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_AREA_0_co_420007e0,5);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(2,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x5) {
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_AREA_1_co_420007e4,5);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(4,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x5) {
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_AREA_2_co_420007e8,5);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(8,apcStack_48,0xffffffff);
  pcVar12 = apcStack_48[0];
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x0) {
    (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_AREA_3_co_420007ec,0,apcStack_48[0]);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(0x10,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x1) {
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_AREA_0_co_420007f0,1);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(0x20,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x3) {
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_AREA_1_co_420007f4,3);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(0x40,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x3) {
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_AREA_2_co_420007f8,3);
    (*(code *)PTR_FUN_42000330)();
  }
  iVar14 = FUN_4200634c(0x80,apcStack_48,0xffffffff);
  if (iVar14 != 0) {
    return iVar14;
  }
  if (apcStack_48[0] != (char *)0x3) {
    (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_AREA_3_co_420007fc,3);
    (*(code *)PTR_FUN_42000330)();
  }
  if (piStack_3c != (int *)0x0) {
    pcVar6 = param_1 + 0x10;
    pcVar5 = (char *)0x0;
    while( true ) {
      iVar14 = FUN_42006820(1,local_64,*(undefined4 *)pcVar6);
      if (iVar14 != 0) {
        return iVar14;
      }
      if ((char)local_64[0] == '\0') {
        pcVar5 = param_1 + (int)pcVar5 * 4;
        (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000800,
                        *(undefined4 *)(pcVar5 + 0x10));
        (*(code *)PTR_FUN_42000330)();
      }
      pcVar6 = pcVar6 + 4;
      if (piVar11 <= pcVar5 + 1) break;
      pcVar5 = (char *)0x1;
    }
  }
  if (uVar7 != 0) {
    pcVar6 = param_1 + 0x10;
    pcVar5 = (char *)0x0;
    while( true ) {
      iVar14 = FUN_42006820(2,local_64,*(undefined4 *)pcVar6);
      if (iVar14 != 0) {
        return iVar14;
      }
      if ((char)local_64[0] == '\0') {
        pcVar5 = param_1 + (int)pcVar5 * 4;
        (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000804,
                        *(undefined4 *)(pcVar5 + 0x10));
        (*(code *)PTR_FUN_42000330)();
      }
      pcVar6 = pcVar6 + 4;
      if (piVar11 <= pcVar5 + 1) break;
      pcVar5 = (char *)0x1;
    }
  }
  cVar17 = (char)in_t0;
  if (param_1[1] != '\0') {
    if (piStack_3c != (int *)0x0) {
      memw();
      local_80[0]._0_1_ = '\x01';
      if (*DAT_420007bc != 1) {
        (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000808);
        (*(code *)PTR_FUN_42000330)();
        local_80[0]._0_1_ = (char)in_t0;
      }
      memw();
      pcVar6 = param_1 + 0x10;
      if (*DAT_42000760 != 1) {
        local_80[0]._0_1_ = '\0';
      }
      pcVar5 = (char *)0x0;
      if (*DAT_42000760 == 1) goto LAB_4200760c;
      (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_configura_4200080c);
      (*(code *)PTR_FUN_42000330)();
      do {
        pcVar5 = (char *)0x1;
LAB_4200760c:
        iVar14 = FUN_42006628(1,local_80,*(undefined4 *)pcVar6);
        if (iVar14 != 0) {
          return iVar14;
        }
        if ((char)local_80[0] == '\0') {
          pcVar5 = param_1 + (int)pcVar5 * 4;
          (*DAT_42000060)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000810,
                          *(undefined4 *)(pcVar5 + 0x10));
          (*(code *)PTR_FUN_42000330)();
        }
        cVar17 = (char)in_t0;
        pcVar6 = pcVar6 + 4;
      } while (pcVar5 + 1 < piVar11);
    }
    if (uVar7 != 0) {
      memw();
      cVar1 = '\x01';
      if (*DAT_420007bc != 1) {
        (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000814);
        (*(code *)PTR_FUN_42000330)();
        cVar1 = cVar17;
      }
      local_80[0]._0_1_ = cVar1;
      memw();
      pcVar6 = param_1 + 0x10;
      if (*DAT_42000764 != 1) {
        local_80[0]._0_1_ = '\0';
        (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000818);
        (*(code *)PTR_FUN_42000330)();
        goto LAB_4200767e;
      }
      while( true ) {
        iVar14 = FUN_42006628(2,local_80,*(undefined4 *)pcVar6);
        if (iVar14 != 0) {
          return iVar14;
        }
        if ((char)local_80[0] == '\0') {
          pcVar12 = param_1 + (int)pcVar12 * 4;
          (*DAT_42000060)(PTR_s_Fatal_error__DRAM0_PMS_configura_4200081c,
                          *(undefined4 *)(pcVar12 + 0x10));
          (*(code *)PTR_FUN_42000330)();
        }
        pcVar6 = pcVar6 + 4;
        if (piVar11 <= pcVar12 + 1) break;
LAB_4200767e:
        pcVar12 = (char *)0x1;
      }
    }
  }
LAB_420076ad:
  (*DAT_42000064)(PTR_DAT_4200075c,param_1,0x18);
  return 0;
}