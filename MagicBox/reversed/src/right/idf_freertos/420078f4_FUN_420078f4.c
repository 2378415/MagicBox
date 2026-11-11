// strings: 0ptp | GekpW | 7eH| | 'eG|

void FUN_420078f4(uint *param_1)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  uint local_50;
  int iStack_4c;
  int iStack_48;
  uint uStack_44;
  byte bStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined *puStack_30;
  undefined *puStack_2c;
  
  uVar3 = *param_1;
  bVar1 = false;
  local_50 = 0;
  iStack_4c = 0;
LAB_42007900:
  uVar8 = uVar3 & 0xff;
  iVar4 = *(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8);
  memw();
  uVar6 = *(uint *)(iVar4 + 8);
  if (uVar6 == 0) {
    if (bVar1) {
      (*(code *)PTR_FUN_420008ac)();
    }
    return;
  }
  (*DAT_42000240)(&iStack_48,0,0xc);
  puVar7 = PTR_DAT_42000848;
  iStack_48 = 9;
  if ((uVar6 & 2) != 0) goto LAB_4200792f;
  if ((uVar6 & DAT_42000880) == 0) {
    if ((uVar6 & 0x10) == 0) {
      if ((uVar6 & 0x80) == 0) {
        if ((uVar6 & 8) == 0) {
          if ((uVar6 & 4) == 0) {
            if ((uVar6 & 0x1000) == 0) {
              if ((uVar6 & 0x2000) == 0) {
                if ((uVar6 & 0x40000) == 0) {
                  if ((uVar6 >> 0xf & 7) == 0) {
                    if ((uVar6 & 0x4000) == 0) {
                      if ((uVar6 & 0x80000) == 0) {
                        memw();
                        *(uint *)(iVar4 + 0x10) = uVar6;
                      }
                      else {
                        memw();
                        *(undefined4 *)(iVar4 + 0x10) = DAT_42000894;
                        iStack_48 = 8;
                      }
                    }
                    else if ((*(int *)(*(int *)(uVar8 * 4 + DAT_42000844) + 0xc) != 1) ||
                            ((memw(), (*(uint *)(iVar4 + 0x1c) >> 0x10 & 0x3ff) == 0 &&
                             (memw(), (*(uint *)(iVar4 + 0x6c) >> 4 & 0xf) == 0)))) {
                      memw();
                      *(undefined4 *)(iVar4 + 0x10) = DAT_42000874;
                      puVar7 = PTR_DAT_42000848;
                      puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
                      (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
                      memw();
                      memw();
                      *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) =
                           *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) & DAT_4200016c;
                      puVar7 = PTR_DAT_42000848;
                      if (*(int *)(*(int *)(uVar8 * 4 + DAT_42000844) + 0xc) == 1) {
                        FUN_42002b78(PTR_DAT_42000848 + uVar8 * 0x18 + 8);
                        memw();
                        memw();
                        *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0x20) =
                             *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0x20) | 0x40;
                      }
                      (*(code *)PTR_FUN_420003ac)(puVar5);
                      (*(code *)PTR_FUN_42000898)
                                (*(undefined4 *)(*(int *)(uVar8 * 4 + DAT_42000844) + 0x74),
                                 &iStack_4c);
                      bVar1 = (bool)(iStack_4c == 1 | bVar1);
                    }
                  }
                  else {
                    puStack_30 = (undefined *)(uVar8 * 2);
                    puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
                    (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
                    FUN_42002b78(puVar7 + uVar8 * 0x18 + 8);
                    *(undefined1 *)(*(int *)(uVar8 * 4 + DAT_42000844) + 0x10) = 1;
                    (*(code *)PTR_FUN_420003ac)(puVar5);
                    memw();
                    *(undefined4 *)
                     (*(int *)(PTR_DAT_42000848 + (int)(puStack_30 + uVar8) * 8 + 8) + 0x10) =
                         DAT_42000890;
                    iStack_48 = 9;
                  }
                }
                else {
                  memw();
                  *(uint *)(iVar4 + 0x10) = DAT_420003b4;
                  iStack_48 = 7;
                }
              }
              else {
                puStack_30 = (undefined *)(uVar8 * 2);
                puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
                (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
                memw();
                memw();
                *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) =
                     *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) & DAT_4200088c;
                (*(code *)PTR_FUN_420003ac)(puVar5);
                memw();
                *(undefined4 *)
                 (*(int *)(PTR_DAT_42000848 + (int)(puStack_30 + uVar8) * 8 + 8) + 0x10) =
                     DAT_42000804;
              }
            }
            else {
              puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
              (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
              FUN_42024484(puVar7 + uVar8 * 0x18 + 8,0);
              memw();
              memw();
              *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) =
                   *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) & DAT_42000888;
              if ((char)param_1[0x15] == '\x01') {
                memw();
                memw();
                *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0xc) =
                     *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0xc) | 2;
              }
              (*(code *)PTR_FUN_420003ac)(puVar5);
              memw();
              *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = DAT_4200077c;
              if ((char)param_1[0x15] == '\x01') {
                *(undefined1 *)(param_1 + 0x15) = 0;
                *(undefined1 *)((int)param_1 + 0x56) = 0;
              }
              else {
                (*(code *)PTR_FUN_42000898)(param_1[0x1e],&iStack_4c);
                bVar1 = (bool)(iStack_4c == 1 | bVar1);
              }
            }
          }
          else {
            (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200087c,0xffffffff);
            if ((code *)param_1[0x16] != (code *)0x0) {
              (*(code *)param_1[0x16])(uVar8,2,&iStack_4c);
              bVar1 = (bool)(iStack_4c == 1 | bVar1);
            }
            (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200087c);
            memw();
            *(undefined4 *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = 4;
            iStack_48 = 5;
          }
        }
        else {
          (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200087c,0xffffffff);
          if ((code *)param_1[0x16] != (code *)0x0) {
            (*(code *)param_1[0x16])(uVar8,2,&iStack_4c);
            bVar1 = (bool)(iStack_4c == 1 | bVar1);
          }
          (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200087c);
          memw();
          *(undefined4 *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = 8;
          iStack_48 = 4;
        }
      }
      else {
        memw();
        *(undefined4 *)(iVar4 + 0x10) = 0x80;
        iStack_48 = 1;
      }
    }
    else {
      puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
      FUN_42002b78(puVar7 + uVar8 * 0x18 + 8);
      (*(code *)PTR_FUN_420003ac)(puVar5);
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200087c,0xffffffff);
      if ((code *)param_1[0x16] != (code *)0x0) {
        (*(code *)param_1[0x16])(uVar8,2,&iStack_4c);
        bVar1 = (bool)(iStack_4c == 1 | bVar1);
      }
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200087c);
      memw();
      *(undefined4 *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = 0x10;
      iStack_48 = 3;
    }
  }
  else {
    if (*DAT_42000884 == '\x01') {
      uVar6 = uVar6 | DAT_420003b4;
      *DAT_42000884 = '\0';
    }
    puVar7 = PTR_DAT_42000848;
    if ((char)param_1[7] == '\0') {
      memw();
      local_50 = *(uint *)(iVar4 + 0x1c) & 0x3ff;
      if ((*(char *)(*(int *)(uVar8 * 4 + DAT_42000844) + 0x11) != '\0') && ((uVar6 & 0x100) == 0))
      {
        local_50 = local_50 - 1;
      }
      FUN_4202451c(PTR_DAT_42000848 + uVar8 * 0x18 + 8,param_1[8],&local_50);
      iVar4 = *(int *)(puVar7 + uVar8 * 0x18 + 8);
      memw();
      uStack_38 = *(uint *)(iVar4 + 0x5c);
      memw();
      memw();
      memw();
      uStack_3c = *(uint *)(iVar4 + 0x5c);
      memw();
      memw();
      puStack_30 = (undefined *)(uStack_3c >> 8 & 0xff);
      if ((uVar6 & 0x40000) == 0) {
        memw();
        *(undefined4 *)(iVar4 + 0x10) = 0x101;
        iStack_48 = 0;
        uStack_44 = local_50;
        bStack_40 = (byte)(uVar6 >> 8) & 1;
        puStack_2c = (undefined *)0xffffffff;
      }
      else {
        memw();
        *(uint *)(iVar4 + 0x10) = DAT_420003b4;
        iStack_48 = 7;
        uStack_44 = local_50;
        puStack_2c = (undefined *)FUN_42024640(param_1[8],local_50 - 1,uStack_38 & 0xff);
      }
      *(char *)(param_1 + 9) = (char)local_50;
      iVar4 = (*(code *)PTR_FUN_420008a4)(param_1[0x18],param_1[8],local_50 & 0xff,&iStack_4c);
      bVar1 = (bool)(iStack_4c == 1 | bVar1);
      if (iVar4 == 0) {
        *(undefined1 *)(param_1 + 7) = 1;
        puVar7 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
        (*(code *)PTR_FUN_420003a8)(puVar7,0xffffffff);
        memw();
        memw();
        *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0xc) =
             *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0xc) & 0xfffffefe;
        (*(code *)PTR_FUN_420003ac)(puVar7);
        if (iStack_48 == 7) {
          (*(code *)PTR_FUN_420003a8)(puVar7,0xffffffff);
          if ((int)local_50 < (int)puStack_30) {
            FUN_42007428(uVar8,param_1[5] - ((int)puStack_30 - local_50));
          }
          else {
            if ((int)puStack_2c < 0) {
              puVar5 = (undefined *)(param_1[5] + (uint)(byte)param_1[9]);
            }
            else {
              puVar5 = puStack_2c + param_1[5];
            }
            FUN_42007428(uVar8,puVar5);
          }
          (*(code *)PTR_FUN_420003ac)(puVar7);
          (*(code *)PTR_FUN_420008a8)(param_1[0x17],&iStack_48,&iStack_4c,0);
          bVar1 = (bool)(iStack_4c == 1 | bVar1);
        }
        iStack_48 = 2;
      }
      else {
        puVar7 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
        (*(code *)PTR_FUN_420003a8)(puVar7,0xffffffff);
        if ((uVar6 >> 0x12 & 1) != 0) {
          if ((int)local_50 < (int)puStack_30) {
            FUN_42007428(uVar8,param_1[5] - ((int)puStack_30 - local_50));
          }
          else if (-1 < (int)puStack_2c) {
            FUN_42007428(uVar8,puStack_2c + param_1[5]);
          }
        }
        param_1[5] = param_1[5] + (uint)(byte)param_1[9];
        (*(code *)PTR_FUN_420003ac)(puVar7);
      }
      if (iStack_48 == 0) {
        (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200087c,0xffffffff);
        if ((code *)param_1[0x16] != (code *)0x0) {
          (*(code *)param_1[0x16])(uVar8,0,&iStack_4c);
          bVar1 = (bool)(iStack_4c == 1 | bVar1);
        }
        (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200087c);
      }
    }
    else {
      puStack_30 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puStack_30,0xffffffff);
      memw();
      memw();
      *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) =
           *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) & 0xfffffefe;
      (*(code *)PTR_FUN_420003ac)(puStack_30);
      memw();
      *(undefined4 *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0x10) = 0x101;
      if ((uVar6 & 0x40000) != 0) {
        memw();
        *(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = DAT_420003b4;
        iStack_48 = 7;
        uStack_44 = local_50;
        *DAT_42000884 = '\x01';
      }
    }
  }
  goto LAB_42008142;
LAB_4200792f:
  puVar5 = PTR_DAT_42000848 + uVar8 * 0x18 + 0xc;
  (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
  memw();
  memw();
  *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) =
       *(uint *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0xc) & 0xfffffffd;
  (*(code *)PTR_FUN_420003ac)(puVar5);
  memw();
  *(undefined4 *)(*(int *)(puVar7 + uVar8 * 0x18 + 8) + 0x10) = 2;
  if (*(char *)((int)param_1 + 0x56) == '\0') {
    if (((char)param_1[0x10] == '\0') || (param_1[0xf] != 0)) {
      if (param_1[0xf] == 0) goto LAB_42007900;
      memw();
      uVar6 = -((*(uint *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x1c) >> 0x10 & 0x3ff) -
               0x80);
      puStack_30 = (undefined *)0x0;
      while (uVar6 != 0) {
        if (((param_1[0x13] == 0) || (param_1[0x11] == 0)) || (param_1[0x14] == 0)) {
          piVar2 = (int *)(*(code *)PTR_FUN_4200089c)(param_1[0x19],&uStack_34);
          param_1[0x12] = (uint)piVar2;
          if (piVar2 == (int *)0x0) break;
          if (param_1[0x13] == 0) {
            param_1[0x11] = 0;
            param_1[0x13] = piVar2[2];
            if (*piVar2 == 6) {
              *(undefined1 *)(param_1 + 0x15) = 1;
              *(char *)((int)param_1 + 0x55) = (char)piVar2[1];
            }
            (*(code *)PTR_FUN_420008a0)(param_1[0x19],piVar2,&iStack_4c);
            bVar1 = (bool)(iStack_4c == 1 | bVar1);
          }
          else if (param_1[0x11] == 0) {
            param_1[0x11] = (uint)piVar2;
            param_1[0x14] = uStack_34;
            puStack_30 = (undefined *)0x1;
          }
        }
        if (((param_1[0x13] != 0) && (param_1[0x11] != 0)) && (uVar9 = param_1[0x14], uVar9 != 0)) {
          iVar4 = FUN_420077e0(uVar8,param_1[0x11],
                               (uVar9 < uVar6) * uVar9 + (uVar9 >= uVar6) * uVar6);
          param_1[0x11] = param_1[0x11] + iVar4;
          param_1[0x13] = param_1[0x13] - iVar4;
          uVar9 = param_1[0x14];
          param_1[0x14] = uVar9 - iVar4;
          uVar6 = uVar6 - iVar4;
          if (uVar9 - iVar4 == 0) {
            (*(code *)PTR_FUN_420008a0)(param_1[0x19],param_1[0x12],&iStack_4c);
            bVar1 = (bool)(iStack_4c == 1 | bVar1);
            param_1[0x12] = 0;
            param_1[0x11] = 0;
            if (param_1[0x13] == 0) {
              if ((char)param_1[0x15] == '\x01') {
                puStack_30 = PTR_DAT_42000848 + uVar8 * 0x18;
                puStack_2c = puStack_30 + 8;
                memw();
                *(uint *)(*(int *)(puStack_30 + 8) + 0x10) = DAT_4200077c;
                (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
                FUN_42024484(puStack_2c,*(undefined1 *)((int)param_1 + 0x55));
                memw();
                memw();
                *(uint *)(*(int *)(puStack_30 + 8) + 0xc) =
                     *(uint *)(*(int *)(puStack_30 + 8) + 0xc) | DAT_4200077c;
                (*(code *)PTR_FUN_420003ac)(puVar5);
                *(undefined1 *)((int)param_1 + 0x56) = 1;
                puStack_30 = (undefined *)0x0;
              }
              else {
                puStack_30 = (undefined *)0x1;
              }
            }
            else {
              puStack_30 = (undefined *)0x1;
            }
            (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200087c,0xffffffff);
            if ((code *)param_1[0x16] != (code *)0x0) {
              (*(code *)param_1[0x16])(uVar8,1,&iStack_4c);
              bVar1 = (bool)(iStack_4c == 1 | bVar1);
            }
            (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200087c);
          }
          else {
            puStack_30 = (undefined *)0x1;
          }
        }
      }
      if (puStack_30 != (undefined *)0x0) {
        puStack_30 = (undefined *)(uVar8 * 2);
        memw();
        *(undefined4 *)(*(int *)(PTR_DAT_42000848 + uVar8 * 0x18 + 8) + 0x10) = 2;
        (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
        memw();
        memw();
        *(uint *)(*(int *)(PTR_DAT_42000848 + (int)(puStack_30 + uVar8) * 8 + 8) + 0xc) =
             *(uint *)(*(int *)(PTR_DAT_42000848 + (int)(puStack_30 + uVar8) * 8 + 8) + 0xc) | 2;
        (*(code *)PTR_FUN_420003ac)(puVar5);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x10) = 0;
      (*(code *)PTR_FUN_42000898)(param_1[0x1c],&iStack_4c);
      bVar1 = (bool)(iStack_4c == 1 | bVar1);
    }
LAB_42008142:
    if ((iStack_48 != 9) && (param_1[0x17] != 0)) {
      (*(code *)PTR_FUN_420008a8)(param_1[0x17],&iStack_48,&iStack_4c,0);
      bVar1 = (bool)(iStack_4c == 1 | bVar1);
    }
  }
  goto LAB_42007900;
}