// 42014900  FUN_42014900  FUN_42014900  size=1322
// strings: ep:%02x clear halt | ep:%02x set halt

undefined4 FUN_42014900(uint param_1,byte *param_2,int *param_3,uint *param_4)

{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  code *pcVar17;
  uint uVar18;
  byte *pbVar19;
  uint *puVar20;
  byte *pbVar21;
  uint *puVar22;
  byte bVar23;
  byte *pbVar24;
  char local_50 [16];
  uint *puStack_40;
  uint *puStack_3c;
  byte *pbStack_38;
  uint uStack_34;
  byte *pbStack_30;
  uint uStack_2c;
  
  uVar7 = DAT_42001360;
  pbVar5 = DAT_4200135c;
  bVar23 = *param_2;
  if ((bVar23 & 0x60) == 0) {
    bVar1 = param_2[1];
    if (bVar1 == 6) {
      if (*(short *)(param_2 + 2) != 0x600) goto LAB_42014912;
    }
    else {
      uVar12 = bVar23 & 3;
      if (uVar12 == 1) {
        puStack_3c = (uint *)(DAT_4200135c + param_1 * DAT_42001360);
        pbVar10 = (byte *)((int)puStack_3c + DAT_42001394);
        uStack_34 = DAT_42001360;
        uStack_2c = (uint)*(ushort *)(param_2 + 2);
        uVar2 = *(ushort *)(param_2 + 4);
        pbStack_30 = DAT_4200135c;
        puStack_40 = (uint *)param_2;
        pbStack_38 = (byte *)(bVar23 & 0x60);
        pbVar5 = (byte *)(**(code **)(puStack_3c[6] + 4))(*pbVar10);
        puVar3 = puStack_3c;
        bVar23 = *(byte *)((int)puStack_40 + 1);
        if (*(byte *)((int)puStack_3c + DAT_42001390) == 0) {
LAB_42014e15:
          if (bVar23 == 6) {
LAB_42014c2e:
            if (*(short *)((int)puStack_40 + 2) == 0x600) goto LAB_42014e1e;
          }
        }
        else {
          uVar7 = uVar2 & 0xff;
          if (bVar23 == 10) {
            *(byte *)*param_3 = *(byte *)((int)puStack_3c + DAT_4200139c + uVar7);
            *param_4 = 1;
            return 1;
          }
          if (bVar23 < 0xb) {
            if (bVar23 == 0) {
              *(undefined1 *)*param_3 = 0;
              *(undefined1 *)(*param_3 + 1) = 0;
              *param_4 = 2;
              return 1;
            }
            if (bVar23 == 6) {
              if (uStack_2c >> 8 == 0x21) {
                uVar12 = 0xff;
                pbVar10 = pbStack_38;
                pbVar21 = pbStack_38;
                do {
                  uVar18 = (uint)*pbVar5;
                  if (uVar18 == 0) break;
                  bVar23 = pbVar5[1];
                  if (bVar23 == 4) {
                    uVar12 = (uint)pbVar5[2];
                  }
                  else if (bVar23 == 0x21) {
                    if (uVar7 == uVar12) {
                      *param_3 = (int)pbVar5;
                      *param_4 = (uint)*pbVar5;
                      return 1;
                    }
                  }
                  else if (bVar23 == 2) {
                    pbVar21 = (byte *)(uint)*(ushort *)(pbVar5 + 2);
                    pbVar10 = (byte *)0x0;
                  }
                  pbVar10 = pbVar10 + uVar18;
                  pbVar5 = pbVar5 + uVar18;
                } while (pbVar10 <= pbVar21 + -1);
              }
              else if ((uStack_2c >> 8 == 0x22) &&
                      (pbStack_30[DAT_42001364 + param_1 * uStack_34] != 0)) {
                pbVar5 = pbStack_30 + (param_1 & 0xffff) * (uStack_34 & 0xffff) + DAT_42001368;
                do {
                  iVar16 = *(int *)pbVar5;
                  pbVar5 = pbVar5 + 4;
                  if ((iVar16 != 0) && (*(byte *)(iVar16 + 0x18) == uVar7)) {
                    uVar7 = *(uint *)(iVar16 + 0x14);
                    *param_3 = *(int *)(iVar16 + 0x10);
                    *param_4 = uVar7;
                    return 1;
                  }
                } while (pbStack_30 +
                         ((param_1 & 0xffff) * 0x24b +
                         (uint)pbStack_30[DAT_42001364 + param_1 * uStack_34]) * 4 + DAT_42001368 !=
                         pbVar5);
              }
              goto LAB_42014c2e;
            }
          }
          else if (bVar23 == 0xb) {
            uVar12 = puStack_3c[6];
            puStack_3c = (uint *)pbStack_38;
            bVar23 = *(byte *)((int)puStack_40 + 2);
            *(byte *)((int)puVar3 + DAT_4200139c + uVar7) = bVar23;
            pbStack_38 = (byte *)(uint)*(byte *)((int)puStack_40 + 4);
            puStack_40 = (uint *)(uint)bVar23;
            pbVar21 = (byte *)(**(code **)(uVar12 + 4))(*pbVar10);
            pbVar5 = pbStack_38;
            puVar3 = puStack_40;
            pbVar10 = (byte *)0xff;
            uVar7 = 0xff;
            puVar8 = puStack_3c;
            puVar11 = puStack_3c;
            puVar20 = puStack_3c;
            puVar22 = puStack_3c;
            puStack_40 = param_4;
            puStack_3c = (uint *)param_1;
            do {
              puVar6 = puStack_3c;
              param_4 = puStack_40;
              uVar12 = (uint)*pbVar21;
              if (uVar12 == 0) break;
              bVar23 = pbVar21[1];
              if (bVar23 == 4) {
                uVar7 = (uint)pbVar21[3];
                pbVar10 = (byte *)(uint)pbVar21[2];
                pbVar9 = (byte *)puVar22;
                if (puVar3 == (uint *)uVar7) {
                  pbVar9 = (byte *)0x1;
                }
                pbVar19 = (byte *)puVar22;
                if (pbVar5 == pbVar10) {
                  pbVar19 = (byte *)0x1;
                }
                pbVar24 = pbVar21;
                if (pbVar9 == (byte *)0x0) {
                  pbVar24 = (byte *)puVar20;
                }
                if (pbVar19 != (byte *)0x0) {
                  puVar20 = (uint *)pbVar24;
                }
              }
              else if (bVar23 == 5) {
                if (pbVar5 == pbVar10) {
                  if (puVar3 == (uint *)0x0) {
                    pbStack_38 = (byte *)puVar20;
                    FUN_42015bd8(puStack_3c,pbVar21[2]);
                    puVar20 = (uint *)pbStack_38;
                    goto LAB_42014d5a;
                  }
                  if (puVar3 == (uint *)uVar7) {
                    pbStack_38 = pbVar10;
                    uStack_34 = uVar7;
                    pbStack_30 = (byte *)puVar20;
                    FUN_420147fc(puStack_3c,pbVar21);
                    uVar12 = (uint)*pbVar21;
                    puVar22 = (uint *)0x0;
                    pbVar10 = pbStack_38;
                    puVar20 = (uint *)pbStack_30;
                    uVar7 = uStack_34;
                  }
                }
              }
              else if (bVar23 == 2) {
                puVar8 = (uint *)(uint)*(ushort *)(pbVar21 + 2);
                puVar11 = (uint *)0x0;
              }
              puVar11 = (uint *)((int)puVar11 + uVar12);
              pbVar21 = pbVar21 + uVar12;
            } while (puVar11 <= (byte *)((int)puVar8 + -1));
            puVar6 = puStack_3c;
            param_4 = puStack_40;
LAB_42014d5a:
            FUN_42014770(puVar6,8,puVar20);
LAB_42014d62:
            *param_4 = 0;
            return 1;
          }
        }
      }
      else if (uVar12 == 2) {
        if (DAT_4200135c[DAT_42001390 + param_1 * DAT_42001360] != 0) {
          bVar23 = param_2[4];
          if (bVar1 == 1) {
            if (*(short *)(param_2 + 2) == 0) {
              (*DAT_42000060)(PTR_DAT_420013a0);
              (*DAT_42000060)(PTR_s_ep__02x_clear_halt_420013a4,bVar23);
              (*DAT_42000060)(PTR_DAT_420013a8);
              FUN_42015dec(param_1,bVar23);
              return 1;
            }
          }
          else {
            if (bVar1 != 3) {
              if (bVar1 == 0) {
                FUN_42015e8c(param_1,bVar23,local_50);
                *(bool *)*param_3 = local_50[0] != '\0';
                *(undefined1 *)(*param_3 + 1) = 0;
                *param_4 = 2;
                return 1;
              }
              goto LAB_42014e24;
            }
            if (*(short *)(param_2 + 2) == 0) {
              (*DAT_42000060)(PTR_DAT_420013a0);
              (*DAT_42000060)(PTR_s_ep__02x_set_halt_420013ac,bVar23);
              (*DAT_42000060)(PTR_DAT_420013a8);
              FUN_42015cf8(param_1,bVar23);
              *param_4 = 0;
              return 1;
            }
          }
          *param_4 = 0;
        }
      }
      else if ((bVar23 & 3) == 0) {
        uVar2 = *(ushort *)(param_2 + 2);
        if (bVar1 == 5) {
          DAT_4200135c[DAT_4200138c + param_1 * DAT_42001360] = (byte)uVar2;
          FUN_420159e4(param_1);
          *param_4 = uVar12;
          return 1;
        }
        if (bVar1 < 6) {
          if ((bVar1 & 0xfd) == 1) {
            if (uVar2 == 1) {
              pcVar17 = *(code **)(DAT_4200135c + DAT_42001388 + param_1 * DAT_42001360);
              if (bVar1 == 3) {
                DAT_4200135c[DAT_42001384 + param_1 * DAT_42001360] = 1;
                (*pcVar17)(param_1,9);
              }
              else {
                DAT_4200135c[DAT_42001384 + param_1 * DAT_42001360] = 0;
                (*pcVar17)(param_1,10);
              }
            }
            goto LAB_42014d62;
          }
          if (bVar1 == 0) {
            iVar16 = param_1 * DAT_42001360;
            *(undefined1 *)*param_3 = 0;
            if (pbVar5[DAT_42001380 + iVar16] != 0) {
              *(byte *)*param_3 = *(byte *)*param_3 | 1;
            }
            if (pbVar5[DAT_42001384 + param_1 * uVar7] != 0) {
              *(byte *)*param_3 = *(byte *)*param_3 | 2;
            }
            *(undefined1 *)(*param_3 + 1) = 0;
            *param_4 = 2;
            return 1;
          }
        }
        else {
          if (bVar1 == 8) {
            *(byte *)*param_3 = DAT_4200135c[DAT_42001390 + param_1 * DAT_42001360];
            *param_4 = 1;
            return 1;
          }
          if (bVar1 == 9) {
            if ((uVar2 & 0xff) == 0) {
              DAT_4200135c[DAT_42001390 + param_1 * DAT_42001360] = 0;
              *param_4 = 0;
              return 1;
            }
            uStack_34 = DAT_42001360;
            pbStack_38 = DAT_4200135c;
            pbVar9 = (byte *)(uVar2 & 0xff);
            puStack_40 = (uint *)param_2;
            pbVar21 = (byte *)(**(code **)(*(int *)(DAT_4200135c + param_1 * DAT_42001360 + 0x18) +
                                          4))(DAT_4200135c[DAT_42001394 + param_1 * DAT_42001360]);
            uVar18 = 0;
            pbVar5 = (byte *)0xff;
            iVar16 = 0;
            uVar7 = 0xff;
            uVar13 = 0;
            pbVar10 = pbStack_38;
            puStack_3c = param_4;
            do {
              uVar15 = (uint)*pbVar21;
              if (uVar15 == 0) break;
              bVar23 = pbVar21[1];
              if (bVar23 == 4) {
                uVar7 = (uint)pbVar21[3];
              }
              else if (bVar23 == 5) {
                if ((pbVar9 == pbVar5) && (uVar7 == 0)) {
                  pbStack_38 = pbVar5;
                  pbStack_30 = pbVar10;
                  iVar16 = FUN_420147fc(param_1,pbVar21);
                  uVar15 = (uint)*pbVar21;
                  pbVar5 = pbStack_38;
                  pbVar10 = pbStack_30;
                  uVar7 = uVar12;
                }
              }
              else if ((bVar23 == 2) && (pbVar5 = (byte *)(uint)pbVar21[5], pbVar9 == pbVar5)) {
                uVar13 = (uint)*(ushort *)(pbVar21 + 2);
                uVar18 = 0;
                iVar16 = 1;
              }
              uVar18 = uVar18 + uVar15;
              pbVar21 = pbVar21 + uVar15;
            } while (uVar18 <= uVar13 - 1);
            puVar3 = puStack_3c;
            if (iVar16 != 0) {
              iVar14 = param_1 * uStack_34;
              iVar16 = DAT_42001398 + iVar14;
              pbVar10[DAT_42001390 + iVar14] = (byte)uVar2;
              pbVar10[iVar16] = 0;
              FUN_42014770(param_1,7,0);
              (**(code **)(pbVar10 + DAT_42001388 + iVar14))(param_1,7);
              *puVar3 = 0;
              return 1;
            }
            *puStack_3c = 0;
            bVar23 = *(byte *)((int)puStack_40 + 1);
            goto LAB_42014e15;
          }
        }
      }
LAB_42014e24:
      (*DAT_42000060)(PTR_DAT_420013a0);
      (*DAT_42000060)(PTR_s_standard_request_error_420013b0);
      (*DAT_42000060)(PTR_DAT_420013a8);
    }
LAB_42014e1e:
    uVar4 = 0;
  }
  else {
LAB_42014912:
    uVar4 = FUN_42013dd0(param_1,param_2,param_3,param_4);
  }
  return uVar4;
}


