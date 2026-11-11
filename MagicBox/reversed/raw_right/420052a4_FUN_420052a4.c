// 420052a4  FUN_420052a4  FUN_420052a4  size=2004
// strings: Fatal error: IRAM0 I_0 split line configuration  | Fatal error: IRAM0 I_1 split line configuration  | Fatal error: DRAM0 D_1 split line configuration 

int FUN_420052a4(char *param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_a3;
  uint extraout_a3_00;
  uint extraout_a3_01;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  undefined4 uStack_3c;
  uint local_38;
  char cStack_34;
  char acStack_33 [3];
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  uVar5 = rer(DAT_420001c0);
  uVar3 = uVar5 & 1;
  if ((uVar5 & 1) == 0) {
    if (param_1 == (char *)0x0) {
      iVar1 = 0x102;
    }
    else {
      uVar5 = *(uint *)(param_1 + 8);
      if (uVar5 == 0) {
        iVar1 = 0x101;
      }
      else {
        uVar4 = *(uint *)(param_1 + 0xc);
        if (uVar4 - 1 < 2) {
          for (uVar2 = uVar3; uVar2 < uVar4; uVar2 = uVar2 + 1) {
            iVar1 = FUN_42004798(*(undefined4 *)(param_1 + (uVar2 + 4) * 4));
            if (iVar1 != 0) {
              return iVar1;
            }
          }
          uStack_2c = uVar5 & 1;
          uVar2 = uVar5 & 2;
          uStack_28 = (uint)(uVar2 != 0);
          uStack_30 = uVar5 & 4;
          if ((uVar5 & 1) != 0) {
            for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
              iVar1 = FUN_42004fec(1,0,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
              if (iVar1 != 0) {
                return iVar1;
              }
            }
          }
          if (uVar2 != 0) {
            for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
              iVar1 = FUN_42004fec(2,0,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
              if (iVar1 != 0) {
                return iVar1;
              }
            }
          }
          if (uStack_30 != 0) {
            for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
              iVar1 = FUN_42004fec(4,0,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
              if (iVar1 != 0) {
                return iVar1;
              }
            }
          }
          if (*param_1 != '\0') {
            if (uStack_2c != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420047e4(1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
              }
            }
            if (uVar2 != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420047e4(2,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
              }
            }
            if (uStack_30 != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420047e4(4,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
              }
            }
          }
          iVar1 = 0;
          local_40 = 0;
          uStack_28 = uStack_2c | uStack_28;
          if (((uStack_28 == 0) ||
              (((((local_40 = *(int *)(param_1 + 4), local_40 != 0 ||
                  (iVar1 = FUN_42004968(1,&local_40), iVar1 == 0)) &&
                 (iVar1 = FUN_420048a8(1,4,local_40,0xffffffff), iVar1 == 0)) &&
                (((iVar1 = FUN_420048a8(1,2,local_40,0xffffffff), iVar1 == 0 &&
                  (iVar1 = FUN_420048a8(1,1,local_40,0xffffffff), iVar1 == 0)) &&
                 ((iVar1 = FUN_420048a8(2,8,local_40 + DAT_42000588,0xffffffff), iVar1 == 0 &&
                  (iVar1 = FUN_420048a8(2,0x10,local_40 + DAT_42000588,0xffffffff), iVar1 == 0))))))
               && ((uStack_2c == 0 ||
                   (((iVar1 = FUN_42004b48(0x400,0,0xffffffff), iVar1 == 0 &&
                     (iVar1 = FUN_42004b48(DAT_420004fc,5,0xffffffff), iVar1 == 0)) &&
                    ((iVar1 = FUN_42004b48(1,5,0xffffffff), iVar1 == 0 &&
                     (((iVar1 = FUN_42004b48(2,5,0xffffffff), iVar1 == 0 &&
                       (iVar1 = FUN_42004b48(4,5,0xffffffff), iVar1 == 0)) &&
                      (iVar1 = FUN_42004b48(8,0,0xffffffff), iVar1 == 0)))))))))))) &&
             ((uVar2 == 0 ||
              (((iVar1 = FUN_42004b48(0x10,1,0xffffffff), iVar1 == 0 &&
                (iVar1 = FUN_42004b48(0x20,3,0xffffffff), iVar1 == 0)) &&
               ((iVar1 = FUN_42004b48(0x40,3,0xffffffff), iVar1 == 0 &&
                (iVar1 = FUN_42004b48(0x80,3,0xffffffff), iVar1 == 0)))))))) {
            uStack_3c = 0;
            if (uStack_30 != 0) {
              iVar1 = FUN_42004968(4,&uStack_3c);
              if (iVar1 != 0) {
                return iVar1;
              }
              for (uVar5 = uVar3; iVar1 = 0, uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420048a8(4,1,uStack_3c,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004b48(0x100,5,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004b48(0x200,3,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
              }
            }
            if (uStack_2c != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420050a8(1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004fec(1,1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = 0;
              }
            }
            if (uVar2 != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420050a8(2,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004fec(2,1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = 0;
              }
            }
            if (uStack_30 != 0) {
              for (uVar5 = uVar3; uVar5 < uVar4; uVar5 = uVar5 + 1) {
                iVar1 = FUN_420050a8(4,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004fec(4,1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = 0;
              }
            }
            if (param_1[1] != '\0') {
              if (uStack_2c != 0) {
                iVar1 = FUN_420049ac(1,0xffffffff);
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004a68(1,0xffffffff);
                if (iVar1 != 0) {
                  return iVar1;
                }
                for (uVar5 = uVar3; iVar1 = 0, uVar5 < uVar4; uVar5 = uVar5 + 1) {
                  iVar1 = FUN_42004ed0(1,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                }
              }
              if (uVar2 != 0) {
                iVar1 = FUN_420049ac(2,0xffffffff);
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = FUN_42004a68(2,0xffffffff);
                if (iVar1 != 0) {
                  return iVar1;
                }
                for (uVar5 = uVar3; iVar1 = 0, uVar5 < uVar4; uVar5 = uVar5 + 1) {
                  iVar1 = FUN_42004ed0(2,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                }
              }
              if (uStack_30 != 0) {
                for (; uVar3 < uVar4; uVar3 = uVar3 + 1) {
                  iVar1 = FUN_42004a68(4,*(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  iVar1 = FUN_42004ed0(4,*(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  iVar1 = 0;
                }
              }
            }
            if (uStack_28 != 0) {
              FUN_42003de8(local_40,&local_38);
              memw();
              uVar5 = local_38;
              if (local_38 != *DAT_420005bc) {
                memw();
                (*DAT_42000634)(PTR_s_Fatal_error__Main_I_D_split_line_420005dc,local_38,
                                *DAT_420005bc);
                (*(code *)PTR_FUN_4200006c)();
                uVar5 = extraout_a3;
              }
              memw();
              if (uVar5 != *DAT_420005c0) {
                memw();
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_I_0_split_lin_420005e0,uVar5,*DAT_420005c0)
                ;
                (*(code *)PTR_FUN_4200006c)();
                uVar5 = extraout_a3_00;
              }
              memw();
              if (uVar5 != *DAT_420005c4) {
                memw();
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_I_1_split_lin_420005e4,uVar5,*DAT_420005c4)
                ;
                (*(code *)PTR_FUN_4200006c)();
              }
              FUN_420044a0(local_40 + DAT_42000588,&local_38);
              memw();
              uVar5 = local_38;
              if (local_38 != *DAT_420005c8) {
                memw();
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_D_0_split_lin_420005e8,local_38,
                                *DAT_420005c8);
                (*(code *)PTR_FUN_4200006c)();
                uVar5 = extraout_a3_01;
              }
              memw();
              if (uVar5 != *DAT_420005cc) {
                memw();
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_D_1_split_lin_420005ec,uVar5,*DAT_420005cc)
                ;
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(1,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 5) {
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_AREA_0_co_420005f0,5);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(2,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 5) {
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_AREA_1_co_420005f4,5);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(4,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 5) {
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_AREA_2_co_420005f8,5);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(8,&local_38,0xffffffff);
              uVar5 = local_38;
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 0) {
                (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_AREA_3_co_420005fc,0,local_38);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(0x10,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 1) {
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_AREA_0_co_42000600,1);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(0x20,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 3) {
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_AREA_1_co_42000604,3);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(0x40,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 3) {
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_AREA_2_co_42000608,3);
                (*(code *)PTR_FUN_4200006c)();
              }
              iVar1 = FUN_42004cb4(0x80,&local_38,0xffffffff);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_38 != 3) {
                (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_AREA_3_co_4200060c,3);
                (*(code *)PTR_FUN_4200006c)();
              }
              if (uStack_2c != 0) {
                for (uVar3 = uVar5; uVar3 < uVar4; uVar3 = uVar3 + 1) {
                  iVar1 = FUN_42005044(1,acStack_33,*(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (acStack_33[0] == '\0') {
                    (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000610,
                                    *(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                    (*(code *)PTR_FUN_4200006c)();
                  }
                }
              }
              if (uVar2 != 0) {
                for (uVar3 = uVar5; uVar3 < uVar4; uVar3 = uVar3 + 1) {
                  iVar1 = FUN_42005044(2,acStack_33,*(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (acStack_33[0] == '\0') {
                    (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000614,
                                    *(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                    (*(code *)PTR_FUN_4200006c)();
                  }
                }
              }
              iVar1 = 0;
              if (param_1[1] != '\0') {
                if (uStack_2c != 0) {
                  iVar1 = FUN_42004a10(1,&cStack_34,0xffffffff);
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (cStack_34 == '\0') {
                    (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000618);
                    (*(code *)PTR_FUN_4200006c)();
                  }
                  iVar1 = FUN_42004adc(1,&cStack_34,0xffffffff);
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (cStack_34 != '\0') {
                    uVar3 = uVar5;
                    goto LAB_42005a02;
                  }
                  (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_configura_4200061c);
                  (*(code *)PTR_FUN_4200006c)();
                  do {
                    iVar1 = FUN_42004f88(1,&cStack_34,*(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                    if (iVar1 != 0) {
                      return iVar1;
                    }
                    if (cStack_34 == '\0') {
                      (*DAT_42000634)(PTR_s_Fatal_error__IRAM0_PMS_configura_42000620,
                                      *(undefined4 *)(param_1 + (uVar3 + 4) * 4));
                      (*(code *)PTR_FUN_4200006c)();
                    }
                    uVar3 = uVar3 + 1;
LAB_42005a02:
                  } while (uVar3 < uVar4);
                }
                iVar1 = 0;
                if (uVar2 != 0) {
                  iVar1 = FUN_42004a10(2,&cStack_34,0xffffffff);
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (cStack_34 == '\0') {
                    (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000624);
                    (*(code *)PTR_FUN_4200006c)();
                  }
                  iVar1 = FUN_42004adc(2,&cStack_34,0xffffffff);
                  if (iVar1 != 0) {
                    return iVar1;
                  }
                  if (cStack_34 != '\0') goto LAB_42005a80;
                  (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_configura_42000628);
                  (*(code *)PTR_FUN_4200006c)();
                  do {
                    iVar1 = FUN_42004f88(2,&cStack_34,*(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                    if (iVar1 != 0) {
                      return iVar1;
                    }
                    if (cStack_34 == '\0') {
                      (*DAT_42000634)(PTR_s_Fatal_error__DRAM0_PMS_configura_4200062c,
                                      *(undefined4 *)(param_1 + (uVar5 + 4) * 4));
                      (*(code *)PTR_FUN_4200006c)();
                    }
                    uVar5 = uVar5 + 1;
LAB_42005a80:
                    iVar1 = 0;
                  } while (uVar5 < uVar4);
                }
              }
            }
            if (iVar1 == 0) {
              (*DAT_420002fc)(PTR_DAT_420005a8,param_1,0x18);
            }
          }
        }
        else {
          iVar1 = DAT_420005a4;
        }
      }
    }
  }
  else {
    uVar3 = rer(DAT_420001c0);
    if ((uVar3 & 1) == 0) {
      (*DAT_42000630)();
      do {
        ill();
      } while( true );
    }
    uVar3 = rer(DAT_420001c0);
    if ((uVar3 & 1) == 0) {
      (*DAT_42000630)();
      do {
        ill();
      } while( true );
    }
    uVar3 = rer(DAT_420001c0);
    if ((uVar3 & 1) == 0) {
      (*DAT_42000630)();
      do {
        ill();
      } while( true );
    }
    iVar1 = 0;
  }
  return iVar1;
}


