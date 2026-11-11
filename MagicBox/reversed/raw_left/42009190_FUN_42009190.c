// 42009190  FUN_42009190  FUN_42009190  size=2138
// strings: Gfah

void FUN_42009190(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined *puVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int *piVar16;
  uint uVar17;
  int local_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  uint local_44;
  undefined *puStack_40;
  uint uStack_3c;
  undefined *puStack_38;
  undefined *puStack_34;
  int *piStack_30;
  int iStack_2c;
  int iStack_28;
  
  puVar3 = PTR_DAT_42000a3c;
  uVar17 = (uint)*param_1;
  iVar13 = *(int *)(PTR_DAT_42000a3c + uVar17 * 0x18 + 8);
  memw();
  uVar9 = *(uint *)(iVar13 + 8);
  local_44 = 0;
  iStack_48 = 0;
  iStack_2c = uVar17 * 2;
  if (uVar9 != 0) {
    puStack_40 = PTR_DAT_42000a3c + uVar17 * 0x18 + 0xc;
    puStack_34 = PTR_DAT_42000a3c + uVar17 * 0x18 + 8;
    uVar6 = 0;
    uStack_3c = uVar17;
    do {
      puVar12 = puStack_40;
      puVar11 = PTR_DAT_42000a64;
      uVar8 = DAT_42000528;
      uStack_5c = 0;
      uStack_58 = 0;
      local_60 = 9;
      bVar2 = (byte)uVar9;
      uVar7 = uVar6;
      if ((uVar9 & 2) == 0) {
        if ((uVar9 & DAT_42000a68) == 0) {
          if ((uVar9 & 0x10) == 0) {
            if ((uVar9 & 0x80) == 0) {
              if ((uVar9 & 8) == 0) {
                if ((uVar9 & 4) == 0) {
                  if ((uVar9 & 0x1000) == 0) {
                    if ((uVar9 & 0x2000) == 0) {
                      if ((uVar9 >> 0xf & 7) == 0) {
                        if ((uVar9 & 0x4000) == 0) {
                          if ((uVar9 & 0x80000) != 0) {
                            memw();
                            *(undefined4 *)(iVar13 + 0x10) = DAT_42000a7c;
                            local_60 = 8;
                            goto LAB_420099b4;
                          }
                          memw();
                          *(uint *)(iVar13 + 0x10) = uVar9;
                          iVar13 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8);
                        }
                        else {
                          iVar10 = uStack_3c * 4;
                          if (*(int *)(*(int *)(uStack_3c * 4 + DAT_42000a40) + 0xc) != 1) {
LAB_420098fc:
                            memw();
                            *(undefined4 *)(iVar13 + 0x10) = DAT_42000a44;
                            (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
                            puVar11 = PTR_DAT_42000a3c;
                            iVar13 = iStack_2c + uStack_3c;
                            memw();
                            iVar14 = *(int *)(*(int *)(DAT_42000a40 + iVar10) + 0xc);
                            memw();
                            *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar13 * 8 + 8) + 0xc) =
                                 *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar13 * 8 + 8) + 0xc) &
                                 DAT_42000294;
                            if (iVar14 == 1) {
                              FUN_42004478(puStack_34);
                              memw();
                              memw();
                              *(uint *)(*(int *)(puVar11 + iVar13 * 8 + 8) + 0x20) =
                                   *(uint *)(*(int *)(puVar11 + iVar13 * 8 + 8) + 0x20) | 0x40;
                            }
                            (*(code *)PTR_FUN_420004e0)(puStack_40);
                            uVar15 = *(undefined4 *)(*(int *)(DAT_42000a40 + iVar10) + 0x74);
                            goto LAB_42009966;
                          }
                          memw();
                          if ((*(uint *)(iVar13 + 0x1c) >> 0x10 & 0x3ff) == 0) {
                            memw();
                            if ((*(uint *)(iVar13 + 0x6c) >> 4 & 0xf) == 0) goto LAB_420098fc;
                            iVar13 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8);
                          }
                          else {
                            iVar13 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8);
                          }
                        }
                      }
                      else {
                        (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
                        FUN_42004478(puStack_34);
                        uVar9 = uStack_3c;
                        *(undefined1 *)(*(int *)(uStack_3c * 4 + DAT_42000a40) + 0x10) = 1;
                        (*(code *)PTR_FUN_420004e0)(puVar12);
                        iVar13 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + uVar9) * 8 + 8);
                        memw();
                        *(undefined4 *)(iVar13 + 0x10) = DAT_42000a78;
                      }
                      goto LAB_420091d9;
                    }
                    (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
                    puVar11 = PTR_DAT_42000a3c;
                    iVar13 = iStack_2c + uStack_3c;
                    memw();
                    memw();
                    *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar13 * 8 + 8) + 0xc) =
                         *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar13 * 8 + 8) + 0xc) & DAT_42000a74
                    ;
                    (*(code *)PTR_FUN_420004e0)(puVar12);
                    memw();
                    *(undefined4 *)(*(int *)(puVar11 + iVar13 * 8 + 8) + 0x10) = DAT_420009f8;
                  }
                  else {
                    puStack_38 = (undefined *)(uVar9 & 4);
                    (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
                    FUN_4202ce68(puStack_34,puStack_38);
                    iVar13 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8);
                    memw();
                    memw();
                    *(uint *)(iVar13 + 0xc) = *(uint *)(iVar13 + 0xc) & DAT_42000a70;
                    if (param_1[0x54] == 1) {
                      memw();
                      memw();
                      *(uint *)(iVar13 + 0xc) = *(uint *)(iVar13 + 0xc) | 2;
                    }
                    (*(code *)PTR_FUN_420004e0)(puStack_40);
                    memw();
                    *(uint *)(*(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8) + 0x10) =
                         DAT_42000988;
                    if (param_1[0x54] == 1) {
                      param_1[0x54] = 0;
                      param_1[0x56] = 0;
                    }
                    else {
                      uVar15 = *(undefined4 *)(param_1 + 0x78);
LAB_42009966:
                      (*(code *)PTR_FUN_42000a80)(uVar15,&iStack_48);
                      uVar7 = uVar6 | iStack_48 == 1;
                    }
                  }
                  goto LAB_420099aa;
                }
                puStack_38 = (undefined *)(uVar9 & 8);
                (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000a64,0xffffffff);
                if (*(code **)(param_1 + 0x58) != (code *)0x0) {
                  (**(code **)(param_1 + 0x58))(uStack_3c,2,&iStack_48);
                  puVar12 = (undefined *)0x1;
                  if (iStack_48 != 1) {
                    puVar12 = puStack_38;
                  }
                  uVar6 = uVar6 | (uint)puVar12;
                }
                (*(code *)PTR_FUN_420004e0)(puVar11);
                memw();
                *(undefined4 *)(*(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8) + 0x10)
                     = 4;
                local_60 = 5;
              }
              else {
                puStack_38 = (undefined *)(uVar9 & 0x80);
                (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000a64,0xffffffff);
                if (*(code **)(param_1 + 0x58) != (code *)0x0) {
                  (**(code **)(param_1 + 0x58))(uStack_3c,2,&iStack_48);
                  puVar12 = puStack_38;
                  if (iStack_48 == 1) {
                    puVar12 = (undefined *)0x1;
                  }
                  uVar6 = uVar6 | (uint)puVar12;
                }
                (*(code *)PTR_FUN_420004e0)(puVar11);
                memw();
                *(undefined4 *)(*(int *)(PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8 + 8) + 0x10)
                     = 8;
                local_60 = 4;
              }
            }
            else {
              memw();
              *(undefined4 *)(iVar13 + 0x10) = 0x80;
              local_60 = 1;
            }
          }
          else {
            puStack_38 = (undefined *)(uVar9 & DAT_42000a68);
            (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
            FUN_42004478(puStack_34);
            (*(code *)PTR_FUN_420004e0)(puVar12);
            puVar11 = PTR_DAT_42000a64;
            (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000a64,0xffffffff);
            if (*(code **)(param_1 + 0x58) != (code *)0x0) {
              (**(code **)(param_1 + 0x58))(uStack_3c,2,&iStack_48);
              puVar12 = puStack_38;
              if (iStack_48 == 1) {
                puVar12 = (undefined *)0x1;
              }
              uVar6 = (uVar6 | (uint)puVar12) & 0xff;
            }
            (*(code *)PTR_FUN_420004e0)(puVar11);
            memw();
            *(undefined4 *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0x10) = 0x10;
            local_60 = 3;
          }
        }
        else {
          if (*DAT_42000a6c == 1) {
            uVar9 = uVar9 | DAT_42000528;
            *DAT_42000a6c = bVar2 & 2;
          }
          else {
            uVar8 = (uVar9 >> 0x12 & 1) << 0x12;
          }
          if (param_1[0x1c] == 0) {
            memw();
            local_44 = *(uint *)(iVar13 + 0x1c) & 0x3ff;
            if ((*(char *)(*(int *)(uStack_3c * 4 + DAT_42000a40) + 0x11) != '\0') &&
               ((uVar9 & 0x100) == 0)) {
              local_44 = local_44 - 1;
            }
            FUN_4202cf08(puStack_34,*(undefined4 *)(param_1 + 0x20),&local_44);
            iVar13 = *(int *)(puVar3 + uVar17 * 0x18 + 8);
            iVar10 = *(int *)(param_1 + 0x20);
            memw();
            uStack_50 = *(uint *)(iVar13 + 0x5c);
            memw();
            memw();
            memw();
            uStack_54 = *(uint *)(iVar13 + 0x5c);
            memw();
            memw();
            puStack_38 = (undefined *)(uStack_54 >> 8 & 0xff);
            if (uVar8 == 0) {
              memw();
              *(undefined4 *)(iVar13 + 0x10) = 0x101;
              uStack_58 = CONCAT31(uStack_58._1_3_,(char)(uVar9 >> 8)) & 0xffffff01;
              local_60 = 0;
LAB_420094f2:
              uVar9 = 0xffffffff;
            }
            else {
              memw();
              *(uint *)(iVar13 + 0x10) = DAT_42000528;
              local_60 = 7;
              uVar9 = local_44 - 1;
              if (-1 < (int)uVar9) {
                iVar13 = 0;
                if ((uint)*(byte *)(iVar10 + uVar9) != (uStack_50 & 0xff)) goto LAB_420094c8;
                while( true ) {
                  iVar13 = iVar13 + 1;
LAB_420094c8:
                  if ((int)puStack_38 <= iVar13) break;
                  while( true ) {
                    uVar9 = uVar9 - 1;
                    if (uVar9 == 0xffffffff) goto LAB_420094f2;
                    if ((uint)*(byte *)(iVar10 + uVar9) == (uStack_50 & 0xff)) break;
                    iVar13 = 0;
                  }
                }
              }
            }
            uStack_5c = local_44;
            piStack_30 = &iStack_48;
            param_1[0x24] = (byte)local_44;
            iVar13 = (*(code *)PTR_FUN_42000a8c)
                               (*(undefined4 *)(param_1 + 0x60),iVar10,local_44 & 0xff,piStack_30);
            puVar11 = puStack_40;
            bVar1 = iStack_48 == 1;
            uVar7 = uVar6 | bVar1;
            if (iVar13 != 0) {
              (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
              if (uVar8 == 0) {
LAB_420095e0:
                iVar13 = *(int *)(param_1 + 0x14);
              }
              else {
                iVar13 = *(int *)(param_1 + 0x14);
                if ((int)local_44 < (int)puStack_38) {
                  FUN_42009144(uStack_3c,iVar13 - ((int)puStack_38 - local_44));
                  iVar13 = *(int *)(param_1 + 0x14);
                }
                else if (-1 < (int)uVar9) {
                  FUN_42009144(uStack_3c,uVar9 + iVar13);
                  goto LAB_420095e0;
                }
              }
              *(uint *)(param_1 + 0x14) = iVar13 + (uint)param_1[0x24];
              (*(code *)PTR_FUN_420004e0)(puStack_40);
              puVar11 = PTR_DAT_42000a64;
              if (local_60 == 0) {
                (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000a64,0xffffffff);
                if (*(code **)(param_1 + 0x58) != (code *)0x0) {
                  (**(code **)(param_1 + 0x58))(uStack_3c,0,piStack_30);
                  uVar7 = uVar6 & 0xff | (uint)bVar1 | (uint)(iStack_48 == 1);
                }
                (*(code *)PTR_FUN_420004e0)(puVar11);
              }
              goto LAB_420099aa;
            }
            param_1[0x1c] = 1;
            (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
            memw();
            memw();
            *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) =
                 *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) & 0xfffffefe;
            (*(code *)PTR_FUN_420004e0)(puVar11);
            if (local_60 == 7) {
              (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
              if ((int)local_44 < (int)puStack_38) {
                FUN_42009144(uStack_3c,*(int *)(param_1 + 0x14) - ((int)puStack_38 - local_44));
              }
              else {
                if ((int)uVar9 < 0) {
                  uVar9 = (uint)param_1[0x24];
                }
                FUN_42009144(uStack_3c,uVar9 + *(int *)(param_1 + 0x14));
              }
              (*(code *)PTR_FUN_420004e0)(puStack_40);
              (*(code *)PTR_FUN_42000a90)(*(undefined4 *)(param_1 + 0x5c),&local_60,piStack_30,0);
              uVar7 = uVar7 | iStack_48 == 1;
            }
            local_60 = 2;
            uVar6 = uVar7;
          }
          else {
            (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
            memw();
            memw();
            *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) =
                 *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) & 0xfffffefe;
            (*(code *)PTR_FUN_420004e0)(puVar12);
            iVar13 = *(int *)(puVar3 + uVar17 * 0x18 + 8);
            memw();
            *(undefined4 *)(iVar13 + 0x10) = 0x101;
            pbVar4 = DAT_42000a6c;
            if (uVar8 == 0) goto LAB_420099aa;
            memw();
            *(uint *)(iVar13 + 0x10) = DAT_42000528;
            local_60 = 7;
            uStack_5c = local_44;
            *pbVar4 = 1;
          }
        }
LAB_420099b4:
        if (*(int *)(param_1 + 0x5c) == 0) {
LAB_420099b9:
          iVar13 = *(int *)(puVar3 + uVar17 * 0x18 + 8);
        }
        else {
          (*(code *)PTR_FUN_42000a90)(*(int *)(param_1 + 0x5c),&local_60,&iStack_48,0);
          iVar13 = *(int *)(puVar3 + uVar17 * 0x18 + 8);
          uVar6 = uVar6 | iStack_48 == 1;
        }
      }
      else {
        (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
        memw();
        memw();
        *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) =
             *(uint *)(*(int *)(puVar3 + uVar17 * 0x18 + 8) + 0xc) & 0xfffffffd;
        (*(code *)PTR_FUN_420004e0)(puVar12);
        iVar13 = *(int *)(puVar3 + uVar17 * 0x18 + 8);
        memw();
        *(undefined4 *)(iVar13 + 0x10) = 2;
        if (param_1[0x56] == 0) {
          if (param_1[0x40] == 0) {
            if (*(int *)(param_1 + 0x3c) == 0) goto LAB_420091d9;
          }
          else if (*(int *)(param_1 + 0x3c) == 0) {
            param_1[0x40] = 0;
            (*(code *)PTR_FUN_42000a80)(*(undefined4 *)(param_1 + 0x70),&iStack_48);
            uVar7 = uVar6 & 0xff | (uint)(iStack_48 == 1);
            goto LAB_420099aa;
          }
          memw();
          uVar6 = *(uint *)(iVar13 + 0x1c) >> 0x10 & 0x3ff;
          uVar9 = -(uVar6 - 0x80);
          if (uVar6 != 0x80) {
            iVar13 = 0;
            do {
              iVar10 = *(int *)(param_1 + 0x4c);
              do {
                do {
                  if (((iVar10 != 0) && (piVar16 = *(int **)(param_1 + 0x44), piVar16 != (int *)0x0)
                      ) && (uVar6 = *(uint *)(param_1 + 0x50), uVar6 != 0)) goto LAB_420092f6;
                  do {
                    piVar5 = (int *)(*(code *)PTR_FUN_42000a84)
                                              (*(undefined4 *)(param_1 + 100),&uStack_4c);
                    *(int **)(param_1 + 0x48) = piVar5;
                    if (piVar5 == (int *)0x0) goto LAB_420093dd;
                    iVar10 = *(int *)(param_1 + 0x4c);
                    if (iVar10 != 0) {
                      piVar16 = *(int **)(param_1 + 0x44);
                      if (*(int **)(param_1 + 0x44) == (int *)0x0) {
                        *(int **)(param_1 + 0x44) = piVar5;
                        *(undefined4 *)(param_1 + 0x50) = uStack_4c;
                        iVar13 = 1;
                        piVar16 = piVar5;
                      }
                      goto LAB_420092f0;
                    }
                    iVar14 = piVar5[2];
                    iVar10 = *piVar5;
                    param_1[0x44] = 0;
                    param_1[0x45] = 0;
                    param_1[0x46] = 0;
                    param_1[0x47] = 0;
                    *(int *)(param_1 + 0x4c) = iVar14;
                    if (iVar10 == 6) {
                      param_1[0x54] = 1;
                      param_1[0x55] = (byte)piVar5[1];
                    }
                    (*(code *)PTR_FUN_42000a88)(*(undefined4 *)(param_1 + 100),piVar5,&iStack_48);
                    iVar10 = *(int *)(param_1 + 0x4c);
                    uVar7 = uVar7 | iStack_48 == 1;
                  } while (iVar10 == 0);
                  piVar16 = *(int **)(param_1 + 0x44);
                } while (*(int **)(param_1 + 0x44) == (int *)0x0);
LAB_420092f0:
                uVar6 = *(uint *)(param_1 + 0x50);
              } while (uVar6 == 0);
LAB_420092f6:
              iVar13 = FUN_42008f48(uStack_3c,piVar16,
                                    (uVar6 < uVar9) * uVar6 + (uVar6 >= uVar9) * uVar9);
              uVar6 = *(int *)(param_1 + 0x50) - iVar13;
              *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + iVar13;
              *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) - iVar13;
              *(uint *)(param_1 + 0x50) = uVar6;
              uVar9 = uVar9 - iVar13;
              iVar13 = 1;
              if (uVar6 == 0) {
                piStack_30 = &iStack_48;
                puStack_38 = (undefined *)uVar6;
                (*(code *)PTR_FUN_42000a88)
                          (*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x48),piStack_30
                          );
                puVar11 = puStack_38;
                if (iStack_48 == 1) {
                  puVar11 = (undefined *)0x1;
                }
                iVar10 = *(int *)(param_1 + 0x4c);
                *(undefined **)(param_1 + 0x48) = puStack_38;
                *(undefined **)(param_1 + 0x44) = puStack_38;
                uVar7 = (uVar7 | (uint)puVar11) & 0xff;
                iVar13 = 1;
                if ((iVar10 == 0) && (param_1[0x54] == 1)) {
                  puStack_38 = PTR_DAT_42000a3c + (iStack_2c + uStack_3c) * 8;
                  memw();
                  *(uint *)(*(int *)(puStack_38 + 8) + 0x10) = DAT_42000988;
                  iStack_28 = iVar10;
                  (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
                  FUN_4202ce68(puStack_34,param_1[0x55]);
                  memw();
                  memw();
                  *(uint *)(*(int *)(puStack_38 + 8) + 0xc) =
                       *(uint *)(*(int *)(puStack_38 + 8) + 0xc) | DAT_42000988;
                  (*(code *)PTR_FUN_420004e0)(puStack_40);
                  param_1[0x56] = 1;
                  iVar13 = iStack_28;
                }
                puStack_38 = PTR_DAT_42000a64;
                (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000a64,0xffffffff);
                if (*(code **)(param_1 + 0x58) != (code *)0x0) {
                  (**(code **)(param_1 + 0x58))(uStack_3c,1,piStack_30);
                  uVar7 = uVar7 | iStack_48 == 1;
                }
                (*(code *)PTR_FUN_420004e0)(puStack_38);
              }
            } while (uVar9 != 0);
LAB_420093dd:
            puVar11 = PTR_DAT_42000a3c;
            if (iVar13 != 0) {
              iVar13 = iStack_2c + uStack_3c;
              memw();
              *(undefined4 *)(*(int *)(PTR_DAT_42000a3c + iVar13 * 8 + 8) + 0x10) = 2;
              (*(code *)PTR_FUN_420004dc)(puStack_40,0xffffffff);
              memw();
              memw();
              *(uint *)(*(int *)(puVar11 + iVar13 * 8 + 8) + 0xc) =
                   *(uint *)(*(int *)(puVar11 + iVar13 * 8 + 8) + 0xc) | 2;
              (*(code *)PTR_FUN_420004e0)(puStack_40);
            }
          }
LAB_420099aa:
          uVar6 = uVar7;
          if (local_60 != 9) goto LAB_420099b4;
          goto LAB_420099b9;
        }
      }
LAB_420091d9:
      memw();
      uVar9 = *(uint *)(iVar13 + 8);
    } while (uVar9 != 0);
    if (uVar6 != 0) {
      (*(code *)PTR_FUN_42000a94)();
    }
  }
  return;
}


