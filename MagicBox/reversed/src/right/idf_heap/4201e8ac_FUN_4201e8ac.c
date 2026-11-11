// strings: Hl7@ | @@`, | 0123456789abcdef | 0123456789ABCDEF |                  | 0000000000000000                

int FUN_4201e8ac(int param_1,int param_2,byte *param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  bool bVar6;
  byte bVar7;
  bool bVar8;
  byte bVar9;
  bool bVar10;
  byte bVar11;
  bool bVar12;
  byte bVar13;
  char cVar14;
  int iVar15;
  byte *pbVar16;
  short *psVar17;
  ushort *puVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  char *pcVar23;
  char *pcVar24;
  uint *puVar25;
  byte *pbVar26;
  uint *puVar27;
  uint uVar28;
  undefined4 *puVar29;
  byte *pbVar30;
  undefined2 *puVar31;
  undefined1 *puVar32;
  int *piVar33;
  undefined4 *puVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  undefined8 uVar38;
  uint local_2b0 [64];
  undefined4 auStack_1b0 [32];
  char acStack_130 [98];
  char local_ce [2];
  undefined4 local_cc [16];
  undefined4 *puStack_8c;
  int iStack_88;
  int iStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined1 uStack_78;
  undefined1 uStack_77;
  char acStack_76 [6];
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  undefined4 *puStack_64;
  int iStack_60;
  byte *pbStack_5c;
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  int iStack_4c;
  uint uStack_48;
  byte *pbStack_44;
  int iStack_40;
  undefined *puStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 *puStack_30;
  
  iStack_54 = param_1;
  iStack_60 = param_2;
  iStack_70 = param_4;
  iStack_6c = param_5;
  iStack_68 = param_6;
  pbStack_5c = param_3;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
    FUN_42017694(param_1);
  }
  if (((*(uint *)(iStack_60 + 100) & 1) == 0) && ((*(ushort *)(iStack_60 + 0xc) & 0x200) == 0)) {
    (*(code *)PTR_FUN_42001154)(*(undefined4 *)(iStack_60 + 0x58));
  }
  if ((((*(ushort *)(iStack_60 + 0xc) & 8) == 0) || (*(int *)(iStack_60 + 0x10) == 0)) &&
     (iVar15 = FUN_42017c98(iStack_54,iStack_60), iVar15 != 0)) {
    if (((*(uint *)(iStack_60 + 100) & 1) == 0) && ((*(ushort *)(iStack_60 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001158)(*(undefined4 *)(iStack_60 + 0x58));
    }
    return -1;
  }
  if (((*(ushort *)(iStack_60 + 0xc) & 0x1a) == 10) && (-1 < *(short *)(iStack_60 + 0xe))) {
    if (((*(uint *)(iStack_60 + 100) & 1) == 0) && ((*(ushort *)(iStack_60 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001158)(*(undefined4 *)(iStack_60 + 0x58));
    }
    iVar15 = FUN_42020534(iStack_54,iStack_60,pbStack_5c,iStack_70,iStack_6c,iStack_68);
    return iVar15;
  }
  puStack_8c = local_cc;
  puStack_64 = local_cc;
  iStack_84 = 0;
  iStack_88 = 0;
  uStack_80 = 0;
  iStack_7c = 0;
  puStack_3c = (undefined *)0x0;
  pbStack_44 = (byte *)0x0;
  iStack_40 = 0;
  uStack_38 = 0;
  iStack_4c = 0;
  auStack_1b0[0] = 0xffffffff;
  iVar15 = 0;
  puStack_30 = local_cc;
LAB_4201e9c8:
  puVar29 = puStack_64;
  for (pbVar26 = pbStack_5c; (*pbVar26 != 0 && (*pbVar26 != 0x25)); pbVar26 = pbVar26 + 1) {
  }
  iVar22 = (int)pbVar26 - (int)pbStack_5c;
  if (iVar22 != 0) {
    *puStack_64 = pbStack_5c;
    puVar29[1] = iVar22;
    iStack_84 = iStack_84 + iVar22;
    iStack_88 = iStack_88 + 1;
    if (iStack_88 < 8) {
      puStack_64 = puStack_64 + 2;
    }
    else {
      iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
      if (iVar35 != 0) {
LAB_420204d1:
        if (((*(uint *)(iStack_60 + 100) & 1) == 0) && ((*(ushort *)(iStack_60 + 0xc) & 0x200) == 0)
           ) {
          (*(code *)PTR_FUN_42001158)(*(undefined4 *)(iStack_60 + 0x58));
        }
        if ((*(ushort *)(iStack_60 + 0xc) & 0x40) == 0) {
          return iStack_4c;
        }
        return -1;
      }
      puStack_64 = local_cc;
    }
    iStack_4c = iStack_4c + iVar22;
  }
  if (*pbVar26 != 0) {
    acStack_76[0] = '\0';
    uStack_58 = 0xffffffff;
    pbStack_5c = pbVar26 + 1;
    uStack_50 = 0;
    bVar2 = false;
    uVar20 = 0;
    bVar4 = false;
    bVar3 = false;
    bVar12 = false;
    bVar10 = false;
    bVar8 = false;
    bVar6 = false;
    iVar22 = iVar15;
    do {
      iVar37 = iStack_68;
      iVar35 = iStack_7c;
      bVar1 = *pbStack_5c;
      pbStack_5c = pbStack_5c + 1;
      uStack_48 = (uint)bVar1;
LAB_4201ea7c:
      iVar36 = iVar15;
      switch(uStack_48) {
      case 0x20:
        if (acStack_76[0] == '\0') {
          acStack_76[0] = ' ';
LAB_4201ec09:
        }
        break;
      default:
        if (uStack_48 != 0) {
          acStack_130[0] = (char)uStack_48;
          goto LAB_4202012f;
        }
        goto LAB_420204ac;
      case 0x23:
        uVar21 = 0;
        bVar5 = 0;
        bVar1 = 1;
        bVar13 = 0;
        bVar11 = 0;
        bVar9 = 0;
        bVar7 = 0;
        goto LAB_4201ede3;
      case 0x27:
        iVar35 = FUN_420207dc(iStack_54);
        uStack_38 = *(undefined4 *)(iVar35 + 4);
        iStack_40 = (*DAT_420001e4)(uStack_38);
        iVar35 = FUN_420207dc(iStack_54);
        pbStack_44 = *(byte **)(iVar35 + 8);
        if (((iStack_40 == 0) || (pbStack_44 == (byte *)0x0)) || (*pbStack_44 == 0)) break;
        uVar21 = 0;
        bVar5 = 1;
        bVar1 = 0;
        bVar13 = 0;
        bVar11 = 0;
        bVar9 = 0;
        bVar7 = 0;
        goto LAB_4201ede3;
      case 0x2a:
        uVar21 = (uint)*pbStack_5c;
        if (uVar21 - 0x30 < 10) {
          iVar35 = 0;
          pbVar30 = pbStack_5c + 1;
          do {
            iVar35 = iVar35 * 10 + (uVar21 - 0x30);
            uVar21 = (uint)*pbVar30;
            pbVar30 = pbVar30 + 1;
          } while (uVar21 - 0x30 < 10);
          if (uVar21 != 0x24) {
LAB_4201ea64:
            bVar2 = false;
            break;
          }
          if (0x20 < iVar35) goto LAB_420204d1;
          iVar35 = iVar35 + -1;
          if (iVar35 < iStack_7c) {
            uStack_50 = local_2b0[iVar35 * 2];
          }
          else {
            puVar25 = (uint *)FUN_4201e3b8(iVar35,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                           auStack_1b0,&uStack_80);
            uStack_50 = *puVar25;
          }
          pbStack_5c = pbVar30;
        }
        else {
          if (iVar15 < iStack_7c) {
            puVar25 = local_2b0 + iVar22 * 2;
          }
          else {
            iStack_68 = iStack_68 + 4;
            if (iStack_7c < 0x20) {
              iStack_7c = iStack_7c + 1;
              if (iStack_68 < 0x19) {
                iVar37 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar37 = iStack_70;
              }
              uStack_50 = *(uint *)(iVar37 + iStack_68 + -4);
              local_2b0[iVar35 * 2] = uStack_50;
              iVar15 = iVar15 + 1;
              goto LAB_4201ebee;
            }
            if (iStack_68 < 0x19) {
              iVar35 = iStack_6c;
            }
            else {
              if (iVar37 < 0x19) {
                iStack_68 = 0x24;
              }
              iVar35 = iStack_70;
            }
            puVar25 = (uint *)(iVar35 + iStack_68 + -4);
          }
          uStack_50 = *puVar25;
          iVar15 = iVar15 + 1;
        }
LAB_4201ebee:
        if ((int)uStack_50 < 0) {
          uStack_50 = -uStack_50;
switchD_4201ea90_caseD_2d:
          uVar21 = 4;
          bVar5 = 0;
          bVar1 = 0;
          bVar13 = 0;
          bVar11 = 0;
          bVar9 = 0;
          bVar7 = 0;
LAB_4201ede3:
          uVar20 = uVar20 | uVar21;
          bVar4 = (bool)(bVar4 | bVar5);
          bVar3 = (bool)(bVar3 | bVar1);
          bVar12 = (bool)(bVar12 | bVar13);
          bVar10 = (bool)(bVar10 | bVar11);
          bVar8 = (bool)(bVar8 | bVar9);
          bVar6 = (bool)(bVar6 | bVar7);
        }
        break;
      case 0x2b:
        acStack_76[0] = '+';
        goto LAB_4201ec09;
      case 0x2d:
        goto switchD_4201ea90_caseD_2d;
      case 0x2e:
        pbVar30 = pbStack_5c + 1;
        uStack_48 = (uint)*pbStack_5c;
        if (*pbStack_5c != 0x2a) {
          iVar36 = 0;
          while( true ) {
            pbStack_5c = pbVar30;
            if (9 < uStack_48 - 0x30) break;
            iVar36 = iVar36 * 10 + (uStack_48 - 0x30);
            bVar1 = *pbVar30;
            pbVar30 = pbVar30 + 1;
            uStack_48 = (uint)bVar1;
          }
          uStack_58 = (uint)(iVar36 >= -1) * iVar36 - (uint)(iVar36 < -1);
          uVar21 = uStack_50;
          goto LAB_4201ea79;
        }
        uVar21 = (uint)pbStack_5c[1];
        if (uVar21 - 0x30 < 10) {
          pbVar16 = pbStack_5c + 2;
          iVar35 = 0;
          do {
            iVar35 = iVar35 * 10 + (uVar21 - 0x30);
            uVar21 = (uint)*pbVar16;
            pbVar16 = pbVar16 + 1;
          } while (uVar21 - 0x30 < 10);
          if (uVar21 != 0x24) {
            pbStack_5c = pbVar30;
            goto LAB_4201ea64;
          }
          if (0x20 < iVar35) goto LAB_420204d1;
          iVar35 = iVar35 + -1;
          if (iVar35 < iStack_7c) {
            uVar21 = local_2b0[iVar35 * 2];
          }
          else {
            puVar25 = (uint *)FUN_4201e3b8(iVar35,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                           auStack_1b0,&uStack_80);
            uVar21 = *puVar25;
          }
          pbVar30 = pbVar16;
        }
        else {
          if (iVar15 < iStack_7c) {
            puVar25 = local_2b0 + iVar22 * 2;
          }
          else {
            if (iStack_7c < 0x20) {
              iStack_7c = iStack_7c + 1;
              iStack_68 = iStack_68 + 4;
              if (iStack_68 < 0x19) {
                iVar37 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar37 = iStack_70;
              }
              uVar21 = *(uint *)(iVar37 + iStack_68 + -4);
              local_2b0[iVar35 * 2] = uVar21;
              iVar15 = iVar15 + 1;
              goto LAB_4201ed1f;
            }
            iStack_68 = iStack_68 + 4;
            if (iStack_68 < 0x19) {
              iVar35 = iStack_6c;
            }
            else {
              if (iVar37 < 0x19) {
                iStack_68 = 0x24;
              }
              iVar35 = iStack_70;
            }
            puVar25 = (uint *)(iVar35 + iStack_68 + -4);
          }
          uVar21 = *puVar25;
          iVar15 = iVar15 + 1;
        }
LAB_4201ed1f:
        uStack_58 = ((int)uVar21 >= -1) * uVar21 - (uint)((int)uVar21 < -1);
        pbStack_5c = pbVar30;
        break;
      case 0x30:
        uVar21 = 0x80;
        bVar5 = 0;
        bVar1 = 0;
        bVar13 = 0;
        bVar11 = 0;
        bVar9 = 0;
        bVar7 = 0;
        goto LAB_4201ede3;
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
        uVar21 = 0;
        do {
          uVar21 = uVar21 * 10 + (uStack_48 - 0x30);
          uStack_48 = (uint)*pbStack_5c;
          pbStack_5c = pbStack_5c + 1;
        } while (uStack_48 - 0x30 < 10);
        if (uStack_48 != 0x24) goto LAB_4201ea79;
        if (0x20 < (int)uVar21) goto LAB_420204d1;
        iVar22 = uVar21 - 1;
        bVar2 = true;
        break;
      case 0x43:
      case 99:
        if (bVar2) {
          if (iVar22 < iStack_7c) {
            acStack_130[0] = (char)local_2b0[iVar22 * 2];
          }
          else {
            pcVar24 = (char *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                           auStack_1b0,&uStack_80);
            acStack_130[0] = *pcVar24;
          }
        }
        else {
          iVar36 = iVar15 + 1;
          if (iVar15 < iStack_7c) {
            acStack_130[0] = (char)local_2b0[iVar22 * 2];
          }
          else {
            iStack_68 = iStack_68 + 4;
            if (iStack_7c < 0x20) {
              iStack_7c = iStack_7c + 1;
              if (iStack_68 < 0x19) {
                iVar15 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar15 = iStack_70;
              }
              uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
              local_2b0[iVar35 * 2] = uVar21;
              acStack_130[0] = (char)uVar21;
            }
            else {
              if (iStack_68 < 0x19) {
                iVar15 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar15 = iStack_70;
              }
              acStack_130[0] = *(char *)(iVar15 + iStack_68 + -4);
            }
          }
        }
        iVar15 = iVar36;
LAB_4202012f:
        acStack_76[0] = '\0';
        uStack_58 = 1;
        uVar21 = 0;
        pcVar24 = acStack_130;
        goto LAB_4202013b;
      case 0x44:
        bVar8 = true;
      case 100:
      case 0x69:
        if (bVar6) {
          if (bVar2) {
            if (iVar22 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              uVar21 = *puVar25;
              uVar19 = puVar25[1];
            }
          }
          else {
            iVar36 = iVar15 + 1;
            if (iVar15 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              uVar21 = iStack_68 + 7U & 0xfffffff8;
              iStack_68 = uVar21 + 8;
              if (iStack_7c < 0x20) {
                iStack_7c = iStack_7c + 1;
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
                local_2b0[iVar35 * 2] = uVar21;
                local_2b0[iVar35 * 2 + 1] = uVar19;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
              }
            }
          }
        }
        else {
          if (bVar8) {
LAB_4201f0f8:
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = *puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else if (bVar10) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(short)local_2b0[iVar22 * 2];
              }
              else {
                psVar17 = (short *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                                auStack_1b0,&uStack_80);
                uVar21 = (uint)*psVar17;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(short)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = (uint)(short)uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(short *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else {
            if (!bVar12) goto LAB_4201f0f8;
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                cVar14 = (char)local_2b0[iVar22 * 2];
              }
              else {
                pcVar24 = (char *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                cVar14 = *pcVar24;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                cVar14 = (char)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  cVar14 = (char)uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  cVar14 = *(char *)(iVar15 + iStack_68 + -4);
                }
              }
            }
            uVar21 = (uint)cVar14;
          }
          uVar19 = (int)uVar21 >> 0x1f;
        }
        if (-1 < (int)uVar19) {
          iVar22 = 1;
          iVar15 = iVar36;
          if ((int)uStack_58 < 0) goto LAB_4201ffe6;
LAB_4201ff85:
          uVar20 = uVar20 & 0xffffff7f;
          if ((uVar21 != 0 || uVar19 != 0) || (uStack_58 != 0)) goto LAB_4201ffa0;
          uStack_58 = 0;
          pcVar24 = (char *)local_cc;
          if (iVar22 == 0) {
            uStack_58 = (uint)bVar3;
            pcVar24 = (char *)local_cc;
            if (uStack_58 != 0) {
              local_ce[1] = '0';
              uStack_58 = 0;
              puVar25 = (uint *)0x1e3;
              puVar27 = local_2b0;
LAB_42020102:
              pcVar24 = (char *)((int)puVar27 + (int)puVar25);
            }
          }
          goto LAB_42020104;
        }
        uVar19 = -uVar19;
        if (uVar21 != 0) {
          uVar19 = uVar19 - 1;
        }
        uVar21 = -uVar21;
        acStack_76[0] = '-';
        iVar22 = 1;
LAB_4201ff73:
        iVar15 = iVar36;
        if (-1 < (int)uStack_58) goto LAB_4201ff85;
LAB_4201ffa0:
        if (iVar22 != 1) {
          if (iVar22 == 2) {
            pcVar24 = (char *)local_cc;
            do {
              uVar28 = uVar21 & 0xf;
              uVar21 = (uint)(CONCAT44(uVar19,uVar21) >> 4);
              pcVar24 = pcVar24 + -1;
              uVar19 = uVar19 >> 4;
              *pcVar24 = puStack_3c[uVar28];
            } while (uVar21 != 0 || uVar19 != 0);
          }
          else {
            pcVar24 = (char *)local_cc;
            do {
              pcVar23 = pcVar24;
              uVar28 = uVar21 & 7;
              uVar21 = (uint)(CONCAT44(uVar19,uVar21) >> 3);
              pcVar24 = pcVar23 + -1;
              uVar19 = uVar19 >> 3;
              *pcVar24 = (char)uVar28 + '0';
            } while (uVar21 != 0 || uVar19 != 0);
            if ((uVar28 != 0) && (bVar3 != false)) {
              pcVar23[-2] = '0';
              pcVar24 = pcVar23 + -2;
            }
          }
          goto LAB_42020104;
        }
LAB_4201ffe6:
        uVar38 = CONCAT44(uVar19,uVar21);
        if ((uVar19 == 0) && (uVar21 < 10)) {
          puVar25 = local_2b0;
          local_ce[1] = (char)uVar21 + '0';
          puVar27 = (uint *)0x1e3;
          goto LAB_42020102;
        }
        uStack_48 = 0;
        pcVar24 = (char *)local_cc;
        goto LAB_4202000e;
      case 0x4f:
        bVar8 = true;
      case 0x6f:
        if (bVar6) {
          if (bVar2) {
            if (iVar22 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              uVar21 = *puVar25;
              uVar19 = puVar25[1];
            }
          }
          else {
            iVar36 = iVar15 + 1;
            if (iVar15 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              uVar21 = iStack_68 + 7U & 0xfffffff8;
              iStack_68 = uVar21 + 8;
              if (iStack_7c < 0x20) {
                iStack_7c = iStack_7c + 1;
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
                local_2b0[iVar35 * 2] = uVar21;
                local_2b0[iVar35 * 2 + 1] = uVar19;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
              }
            }
          }
        }
        else {
          if (bVar8) {
LAB_4201f705:
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = *puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else if (bVar10) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                puVar18 = (ushort *)
                          FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,auStack_1b0,
                                       &uStack_80);
                uVar21 = (uint)*puVar18;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xffff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(ushort *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else {
            if (!bVar12) goto LAB_4201f705;
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                pbVar26 = (byte *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = (uint)*pbVar26;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(byte *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          uVar19 = 0;
        }
        bVar4 = false;
        iVar22 = 0;
LAB_4201ff71:
        acStack_76[0] = '\0';
        goto LAB_4201ff73;
      case 0x53:
      case 0x73:
        if (bVar2) {
          if (iVar22 < iStack_7c) {
            pcVar24 = (char *)local_2b0[iVar22 * 2];
          }
          else {
            puVar29 = (undefined4 *)
                      FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,auStack_1b0,
                                   &uStack_80);
            pcVar24 = (char *)*puVar29;
          }
        }
        else {
          iVar35 = iVar15 + 1;
          if (iVar15 < iStack_7c) {
            pcVar24 = (char *)local_2b0[iVar22 * 2];
            iVar15 = iVar35;
          }
          else {
            iVar15 = iStack_68 + 4;
            if (iStack_7c < 0x20) {
              if (iVar15 < 0x19) {
                iVar22 = iStack_6c;
                iStack_68 = iVar15;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = 0x24;
                }
                iVar22 = iStack_70;
                iStack_68 = iVar15;
              }
              pcVar24 = *(char **)(iVar22 + iStack_68 + -4);
              iVar15 = iStack_7c * 2;
              iStack_7c = iStack_7c + 1;
              local_2b0[iVar15] = (uint)pcVar24;
              iVar15 = iVar35;
            }
            else {
              if (iVar15 < 0x19) {
                iVar22 = iStack_6c;
                iStack_68 = iVar15;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = 0x24;
                }
                iVar22 = iStack_70;
                iStack_68 = iVar15;
              }
              pcVar24 = *(char **)(iVar22 + iStack_68 + -4);
              iVar15 = iVar35;
            }
          }
        }
        acStack_76[0] = '\0';
        if ((int)uStack_58 < 0) {
          uStack_58 = (*DAT_420001e4)(pcVar24);
          uVar21 = 0;
          goto LAB_4202013b;
        }
        iVar22 = (*DAT_420011b8)(pcVar24,0,uStack_58);
        uVar21 = 0;
        uVar19 = iVar22 - (int)pcVar24;
        if (iVar22 != 0) goto LAB_4202010d;
        goto LAB_4202013b;
      case 0x55:
        bVar8 = true;
      case 0x75:
        if (bVar6) {
          if (bVar2) {
            if (iVar22 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              uVar21 = *puVar25;
              uVar19 = puVar25[1];
            }
          }
          else {
            iVar36 = iVar15 + 1;
            if (iVar15 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              uVar21 = iStack_68 + 7U & 0xfffffff8;
              iStack_68 = uVar21 + 8;
              if (iStack_7c < 0x20) {
                iStack_7c = iStack_7c + 1;
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
                local_2b0[iVar35 * 2] = uVar21;
                local_2b0[iVar35 * 2 + 1] = uVar19;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
              }
            }
          }
        }
        else {
          if (bVar8) {
LAB_4201fba9:
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = *puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else if (bVar10) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                puVar18 = (ushort *)
                          FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,auStack_1b0,
                                       &uStack_80);
                uVar21 = (uint)*puVar18;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xffff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(ushort *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else {
            if (!bVar12) goto LAB_4201fba9;
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                pbVar26 = (byte *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = (uint)*pbVar26;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(byte *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          uVar19 = 0;
        }
        iVar22 = 1;
        goto LAB_4201ff71;
      case 0x58:
        puStack_3c = PTR_s_0123456789ABCDEF_42001288;
        goto LAB_4201fc57;
      case 0x68:
        if (*pbStack_5c == 0x68) {
          pbStack_5c = pbStack_5c + 1;
          uVar21 = 0;
          bVar5 = 0;
          bVar1 = 0;
          bVar13 = 1;
          bVar11 = 0;
          bVar9 = 0;
          bVar7 = 0;
        }
        else {
          uVar21 = 0;
          bVar5 = 0;
          bVar1 = 0;
          bVar13 = 0;
          bVar11 = 1;
          bVar9 = 0;
          bVar7 = 0;
        }
        goto LAB_4201ede3;
      case 0x6a:
      case 0x71:
        goto switchD_4201ea90_caseD_6a;
      case 0x6c:
        if (*pbStack_5c == 0x6c) {
          pbStack_5c = pbStack_5c + 1;
switchD_4201ea90_caseD_6a:
          uVar21 = 0;
          bVar5 = 0;
          bVar1 = 0;
          bVar13 = 0;
          bVar11 = 0;
          bVar9 = 0;
          bVar7 = 1;
        }
        else {
          uVar21 = 0;
          bVar5 = 0;
          bVar1 = 0;
          bVar13 = 0;
          bVar11 = 0;
          bVar9 = 1;
          bVar7 = 0;
        }
        goto LAB_4201ede3;
      case 0x6e:
        if (bVar6) {
          if (bVar2) {
            if (iVar22 < iStack_7c) {
              piVar33 = (int *)local_2b0[iVar22 * 2];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              piVar33 = (int *)*puVar25;
            }
          }
          else {
            iVar36 = iVar15 + 1;
            if (iVar15 < iStack_7c) {
              piVar33 = (int *)local_2b0[iVar22 * 2];
              iVar15 = iVar36;
            }
            else {
              iStack_68 = iStack_68 + 4;
              if (iStack_7c < 0x20) {
                iStack_7c = iStack_7c + 1;
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if (iVar37 < 0x19) {
                    iStack_68 = 0x24;
                  }
                  iVar15 = iStack_70;
                }
                piVar33 = *(int **)(iVar15 + iStack_68 + -4);
                local_2b0[iVar35 * 2] = (uint)piVar33;
                iVar15 = iVar36;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if (iVar37 < 0x19) {
                    iStack_68 = 0x24;
                  }
                  iVar15 = iStack_70;
                }
                piVar33 = *(int **)(iVar15 + iStack_68 + -4);
                iVar15 = iVar36;
              }
            }
          }
          *piVar33 = iStack_4c;
          piVar33[1] = iStack_4c >> 0x1f;
          goto LAB_4201e9c8;
        }
        if (bVar8) {
          if (bVar2) {
LAB_4201f42a:
            if (iVar22 < iStack_7c) {
              piVar33 = (int *)local_2b0[iVar22 * 2];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              piVar33 = (int *)*puVar25;
            }
          }
          else if (iVar15 < iStack_7c) {
LAB_4201f45d:
            iVar15 = iVar15 + 1;
            piVar33 = (int *)local_2b0[iVar22 * 2];
          }
          else {
            iStack_68 = iStack_68 + 4;
            if (iStack_7c < 0x20) {
              iStack_7c = iStack_7c + 1;
              if (iStack_68 < 0x19) {
                iVar22 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar22 = iStack_70;
              }
              piVar33 = *(int **)(iVar22 + iStack_68 + -4);
              goto LAB_4201f497;
            }
            if (iStack_68 < 0x19) {
              iVar22 = iStack_6c;
            }
            else {
              if (iVar37 < 0x19) {
                iStack_68 = 0x24;
              }
              iVar22 = iStack_70;
            }
            iVar22 = iVar22 + iStack_68;
LAB_4201f4ba:
            iVar15 = iVar15 + 1;
            piVar33 = *(int **)(iVar22 + -4);
          }
        }
        else {
          if (bVar10) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                puVar31 = (undefined2 *)local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                puVar31 = (undefined2 *)*puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                puVar31 = (undefined2 *)local_2b0[iVar22 * 2];
                iVar15 = iVar36;
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  puVar31 = *(undefined2 **)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = (uint)puVar31;
                  iVar15 = iVar36;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  puVar31 = *(undefined2 **)(iVar15 + iStack_68 + -4);
                  iVar15 = iVar36;
                }
              }
            }
            *puVar31 = (short)iStack_4c;
            goto LAB_4201e9c8;
          }
          if (bVar12) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                puVar32 = (undefined1 *)local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                puVar32 = (undefined1 *)*puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                puVar32 = (undefined1 *)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  puVar32 = *(undefined1 **)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = (uint)puVar32;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  puVar32 = *(undefined1 **)(iVar15 + iStack_68 + -4);
                }
              }
            }
            *puVar32 = (char)iStack_4c;
            iVar15 = iVar36;
            goto LAB_4201e9c8;
          }
          if (bVar2) goto LAB_4201f42a;
          if (iVar15 < iStack_7c) goto LAB_4201f45d;
          iStack_68 = iStack_68 + 4;
          if (0x1f < iStack_7c) {
            if (iStack_68 < 0x19) {
              iVar22 = iStack_6c;
            }
            else {
              if (iVar37 < 0x19) {
                iStack_68 = 0x24;
              }
              iVar22 = iStack_70;
            }
            iVar22 = iVar22 + iStack_68;
            goto LAB_4201f4ba;
          }
          iStack_7c = iStack_7c + 1;
          if (iStack_68 < 0x19) {
            iVar22 = iStack_6c;
          }
          else {
            if (iVar37 < 0x19) {
              iStack_68 = 0x24;
            }
            iVar22 = iStack_70;
          }
          piVar33 = *(int **)(iVar22 + iStack_68 + -4);
LAB_4201f497:
          iVar15 = iVar15 + 1;
          local_2b0[iVar35 * 2] = (uint)piVar33;
        }
        *piVar33 = iStack_4c;
        goto LAB_4201e9c8;
      case 0x70:
        if (bVar2) {
          if (iVar22 < iStack_7c) {
            uVar21 = local_2b0[iVar22 * 2];
          }
          else {
            puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                           auStack_1b0,&uStack_80);
            uVar21 = *puVar25;
          }
        }
        else {
          iVar36 = iVar15 + 1;
          if (iVar15 < iStack_7c) {
            uVar21 = local_2b0[iVar22 * 2];
          }
          else {
            iStack_68 = iStack_68 + 4;
            if (iStack_7c < 0x20) {
              iStack_7c = iStack_7c + 1;
              if (iStack_68 < 0x19) {
                iVar15 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar15 = iStack_70;
              }
              uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
              local_2b0[iVar35 * 2] = uVar21;
            }
            else {
              if (iStack_68 < 0x19) {
                iVar15 = iStack_6c;
              }
              else {
                if (iVar37 < 0x19) {
                  iStack_68 = 0x24;
                }
                iVar15 = iStack_70;
              }
              uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
            }
          }
        }
        uVar20 = uVar20 | 2;
        uStack_78 = 0x30;
        uStack_77 = 0x78;
        uVar19 = 0;
        puStack_3c = PTR_s_0123456789abcdef_4200128c;
        goto LAB_4201ff6f;
      case 0x74:
      case 0x7a:
        break;
      case 0x78:
        puStack_3c = PTR_s_0123456789abcdef_4200128c;
LAB_4201fc57:
        if (bVar6) {
          if (bVar2) {
            if (iVar22 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                             auStack_1b0,&uStack_80);
              uVar21 = *puVar25;
              uVar19 = puVar25[1];
            }
          }
          else {
            iVar36 = iVar15 + 1;
            if (iVar15 < iStack_7c) {
              uVar21 = local_2b0[iVar22 * 2];
              uVar19 = local_2b0[iVar22 * 2 + 1];
            }
            else {
              uVar21 = iStack_68 + 7U & 0xfffffff8;
              iStack_68 = uVar21 + 8;
              if (iStack_7c < 0x20) {
                iStack_7c = iStack_7c + 1;
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
                local_2b0[iVar35 * 2] = uVar21;
                local_2b0[iVar35 * 2 + 1] = uVar19;
              }
              else {
                if (iStack_68 < 0x19) {
                  iVar15 = iStack_6c;
                }
                else {
                  if ((int)uVar21 < 0x19) {
                    iStack_68 = 0x28;
                  }
                  iVar15 = iStack_70;
                }
                uVar21 = *(uint *)(iVar15 + iStack_68 + -8);
                uVar19 = *(uint *)(iVar15 + iStack_68 + -4);
              }
            }
          }
        }
        else {
          if (bVar8) {
            if (bVar2) {
LAB_4201fea6:
              if (iVar22 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
                puVar25 = (uint *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = *puVar25;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = local_2b0[iVar22 * 2];
              }
              else {
LAB_4201fee1:
                iVar36 = iVar15 + 1;
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else if (bVar10) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                puVar18 = (ushort *)
                          FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,auStack_1b0,
                                       &uStack_80);
                uVar21 = (uint)*puVar18;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(ushort)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xffff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(ushort *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else if (bVar12) {
            if (bVar2) {
              if (iVar22 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                pbVar26 = (byte *)FUN_4201e3b8(iVar22,pbVar26,&iStack_70,&iStack_7c,local_2b0,
                                               auStack_1b0,&uStack_80);
                uVar21 = (uint)*pbVar26;
              }
            }
            else {
              iVar36 = iVar15 + 1;
              if (iVar15 < iStack_7c) {
                uVar21 = (uint)(byte)local_2b0[iVar22 * 2];
              }
              else {
                iStack_68 = iStack_68 + 4;
                if (iStack_7c < 0x20) {
                  iStack_7c = iStack_7c + 1;
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = *(uint *)(iVar15 + iStack_68 + -4);
                  local_2b0[iVar35 * 2] = uVar21;
                  uVar21 = uVar21 & 0xff;
                }
                else {
                  if (iStack_68 < 0x19) {
                    iVar15 = iStack_6c;
                  }
                  else {
                    if (iVar37 < 0x19) {
                      iStack_68 = 0x24;
                    }
                    iVar15 = iStack_70;
                  }
                  uVar21 = (uint)*(byte *)(iVar15 + iStack_68 + -4);
                }
              }
            }
          }
          else {
            if (bVar2) goto LAB_4201fea6;
            iVar36 = iVar15 + 1;
            if (iStack_7c <= iVar15) goto LAB_4201fee1;
            uVar21 = local_2b0[iVar22 * 2];
          }
          uVar19 = 0;
        }
        if ((uVar21 != 0 || uVar19 != 0) && (bVar3)) {
          uStack_78 = 0x30;
          uStack_77 = (char)uStack_48;
          uVar20 = uVar20 | 2;
        }
        bVar4 = false;
LAB_4201ff6f:
        iVar22 = 2;
        goto LAB_4201ff71;
      }
    } while( true );
  }
LAB_420204ac:
  if ((iStack_84 == 0) || (iVar15 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c), iVar15 == 0)) {
    iStack_88 = 0;
  }
  goto LAB_420204d1;
  while( true ) {
    uStack_48 = uVar21 + 1;
    uVar38 = (*DAT_420000d0)(uVar19,iVar22,10,0);
    if ((iVar22 == 0) && (uVar19 < 10)) break;
LAB_4202000e:
    iVar22 = (int)((ulonglong)uVar38 >> 0x20);
    uVar19 = (uint)uVar38;
    cVar14 = (*DAT_4200123c)(uVar19,iVar22,10,0);
    uVar21 = uStack_48;
    pcVar24 = pcVar24 + -1;
    *pcVar24 = cVar14 + '0';
    if (((bVar4) && (*pbStack_44 != 0xff)) && ((uint)*pbStack_44 == uVar21 + 1)) {
      if ((iVar22 == 0) && (uVar19 < 10)) break;
      pcVar24 = pcVar24 + -iStack_40;
      (*DAT_42000cfc)(pcVar24,uStack_38,iStack_40);
      if (pbStack_44[1] != 0) {
        pbStack_44 = pbStack_44 + 1;
      }
      uVar38 = (*DAT_420000d0)(uVar19,iVar22,10,0);
      uStack_48 = 0;
      goto LAB_4202000e;
    }
  }
LAB_42020104:
  uVar19 = (int)puStack_30 - (int)pcVar24;
  uVar21 = uStack_58;
LAB_4202010d:
  uStack_58 = uVar19;
LAB_4202013b:
  iVar22 = ((int)uVar21 < (int)uStack_58) * uStack_58 + ((int)uVar21 >= (int)uStack_58) * uVar21;
  if (acStack_76[0] != '\0') {
    iVar22 = iVar22 + 1;
  }
  uStack_48 = uVar20 & 2;
  if (uStack_48 != 0) {
    iVar22 = iVar22 + 2;
  }
  uStack_34 = uVar20 & 0x84;
  if ((uVar20 & 0x84) == 0) {
    puVar29 = (undefined4 *)(uStack_50 - iVar22);
    if (0 < (int)puVar29) {
      while( true ) {
        *puStack_64 = PTR_DAT_42001294;
        iStack_88 = iStack_88 + 1;
        puVar34 = puStack_64 + 2;
        if ((int)puVar29 < 0x11) break;
        iVar35 = iStack_84 + 0x10;
        puStack_64[1] = 0x10;
        puStack_64 = puVar29;
        iStack_84 = iVar35;
        if (7 < iStack_88) {
          iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
          if (iVar35 != 0) goto LAB_420204d1;
          puVar34 = local_cc;
        }
        puVar29 = puStack_64 + -4;
        puStack_64 = puVar34;
      }
      puStack_64[1] = puVar29;
      iStack_84 = (int)puVar29 + iStack_84;
      puStack_64 = puVar34;
      if (7 < iStack_88) {
        iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
        if (iVar35 != 0) goto LAB_420204d1;
        puStack_64 = local_cc;
      }
    }
  }
  puVar29 = puStack_64;
  if (acStack_76[0] != '\0') {
    iVar35 = iStack_88 + 1;
    *puStack_64 = acStack_76;
    iStack_84 = iStack_84 + 1;
    puVar29[1] = 1;
    puVar29 = puVar29 + 2;
    iStack_88 = iVar35;
    if (7 < iVar35) {
      iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
      if (iVar35 != 0) goto LAB_420204d1;
      puVar29 = local_cc;
    }
    puStack_64 = puVar29;
  }
  puVar29 = puStack_64;
  if (uStack_48 != 0) {
    iVar35 = iStack_88 + 1;
    *puStack_64 = &uStack_78;
    iStack_84 = iStack_84 + 2;
    puVar29[1] = 2;
    puVar29 = puVar29 + 2;
    iStack_88 = iVar35;
    if (7 < iVar35) {
      iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
      if (iVar35 != 0) goto LAB_420204d1;
      puVar29 = local_cc;
    }
    puStack_64 = puVar29;
  }
  if (uStack_34 == 0x80) {
    puVar29 = (undefined4 *)(uStack_50 - iVar22);
    if (0 < (int)puVar29) {
      while( true ) {
        iVar35 = iStack_88 + 1;
        puVar34 = puStack_64 + 2;
        iStack_88 = iVar35;
        if ((int)puVar29 < 0x11) break;
        iVar37 = iStack_84 + 0x10;
        *puStack_64 = PTR_DAT_42001298;
        puStack_64[1] = 0x10;
        puStack_64 = puVar29;
        iStack_84 = iVar37;
        if (7 < iVar35) {
          iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
          if (iVar35 != 0) goto LAB_420204d1;
          puVar34 = local_cc;
        }
        puVar29 = puStack_64 + -4;
        puStack_64 = puVar34;
      }
      iVar37 = (int)puVar29 + iStack_84;
      *puStack_64 = PTR_DAT_42001298;
      puStack_64[1] = puVar29;
      iStack_84 = iVar37;
      puStack_64 = puVar34;
      if (7 < iVar35) {
        iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
        if (iVar35 != 0) goto LAB_420204d1;
        puStack_64 = local_cc;
      }
    }
  }
  iVar35 = uVar21 - uStack_58;
  if (0 < iVar35) {
    while( true ) {
      puVar29 = puStack_64;
      iVar37 = iStack_88 + 1;
      puVar34 = puStack_64 + 2;
      iStack_88 = iVar37;
      if (iVar35 < 0x11) break;
      iVar36 = iStack_84 + 0x10;
      *puStack_64 = PTR_DAT_42001298;
      puVar29[1] = 0x10;
      iStack_84 = iVar36;
      if (7 < iVar37) {
        iVar37 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
        if (iVar37 != 0) goto LAB_420204d1;
        puVar34 = local_cc;
      }
      iVar35 = iVar35 + -0x10;
      puStack_64 = puVar34;
    }
    puStack_64[1] = iVar35;
    iVar35 = iVar35 + iStack_84;
    *puStack_64 = PTR_DAT_42001298;
    iStack_84 = iVar35;
    puStack_64 = puVar34;
    if (7 < iVar37) {
      iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
      if (iVar35 != 0) goto LAB_420204d1;
      puStack_64 = local_cc;
    }
  }
  uVar21 = uStack_58;
  puVar29 = puStack_64;
  puStack_64[1] = uStack_58;
  *puVar29 = pcVar24;
  iStack_84 = iStack_84 + uVar21;
  iStack_88 = iStack_88 + 1;
  if (iStack_88 < 8) {
    puVar29 = puStack_64 + 2;
  }
  else {
    iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
    if (iVar35 != 0) goto LAB_420204d1;
    puVar29 = local_cc;
  }
  if (((uVar20 & 4) != 0) && (iVar35 = uStack_50 - iVar22, 0 < iVar35)) {
    while( true ) {
      *puVar29 = PTR_DAT_42001294;
      iStack_88 = iStack_88 + 1;
      if (iVar35 < 0x11) break;
      iVar37 = iStack_84 + 0x10;
      puVar29[1] = 0x10;
      puVar29 = puVar29 + 2;
      iStack_84 = iVar37;
      if (7 < iStack_88) {
        iVar37 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c);
        if (iVar37 != 0) goto LAB_420204d1;
        puVar29 = local_cc;
      }
      iVar35 = iVar35 + -0x10;
    }
    puVar29[1] = iVar35;
    iStack_84 = iVar35 + iStack_84;
    if ((7 < iStack_88) && (iVar35 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c), iVar35 != 0))
    goto LAB_420204d1;
  }
  iStack_4c = iStack_4c +
              (uint)((int)uStack_50 < iVar22) * iVar22 + ((int)uStack_50 >= iVar22) * uStack_50;
  if ((iStack_84 != 0) && (iVar22 = FUN_4201e888(iStack_54,iStack_60,&puStack_8c), iVar22 != 0))
  goto LAB_420204d1;
  iStack_88 = 0;
  puStack_64 = local_cc;
  goto LAB_4201e9c8;
LAB_4201ea79:
  uStack_50 = uVar21;
  goto LAB_4201ea7c;
}