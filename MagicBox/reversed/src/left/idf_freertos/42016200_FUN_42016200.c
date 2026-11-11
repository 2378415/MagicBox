// strings: 8axQ

void FUN_42016200(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  char cVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint local_60;
  uint uStack_5c;
  
  param_1 = param_1 & 0xff;
  iVar9 = *(int *)(param_1 * 8 + DAT_420013e0 + 4);
  memw();
  iVar21 = param_1 * 8;
  memw();
  memw();
  uVar6 = *(uint *)(iVar9 + 0x14) & *(uint *)(iVar9 + 0x18);
  if (((*(uint *)(iVar9 + 0x14) & *(uint *)(iVar9 + 0x18)) != 0) &&
     (uVar1 = *(uint *)(iVar9 + 0x14) & 1, (*(uint *)(iVar9 + 0x14) & 1) == 0)) {
    if ((uVar6 & 0x80000) != 0) {
      memw();
      memw();
      uVar2 = (*(uint *)(iVar9 + 0x818) & *(uint *)(iVar9 + 0x81c)) >> 0x10;
      if (uVar2 != 0) {
        iVar10 = DAT_420013f8 + param_1 * 0x100;
        iVar9 = iVar10;
        do {
          for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
            uVar1 = uVar1 + 1;
            iVar9 = iVar9 + 0x10;
          }
          iVar3 = *(int *)(DAT_420013e0 + iVar21 + 4);
          uVar20 = uVar1 & 0xffff;
          puVar8 = (uint *)(iVar3 + 0xb00);
          memw();
          uVar14 = puVar8[uVar20 * 8 + 2];
          memw();
          puVar8[uVar20 * 8 + 2] = uVar14;
          memw();
          uVar14 = uVar14 & *(uint *)(iVar3 + 0x814);
          if ((uVar14 & 1) != 0) {
            if (uVar1 == 0) {
              iVar7 = *(int *)(iVar10 + 0x80);
              if (iVar7 == 0) {
                memw();
                *(undefined4 *)(iVar3 + 0xb10) = 0;
                memw();
                memw();
                *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | DAT_42000a7c;
                memw();
                memw();
                *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | 0x18;
                memw();
                memw();
                *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | DAT_42001430;
                uVar20 = DAT_42001434;
                memw();
                *(int *)(iVar3 + 0xb14) = iVar10;
                memw();
                memw();
                *puVar8 = *puVar8 | uVar20;
              }
              else {
                memw();
                *(uint *)(iVar10 + 0x84) = iVar7 - (*(uint *)(iVar3 + 0xb10) & 0x7ffff);
                *(int *)(iVar10 + 0x80) = 0;
                FUN_4201529c(param_1,0);
              }
            }
            else {
              memw();
              *(uint *)(iVar9 + 0x84) = *(int *)(iVar9 + 0x80) - (puVar8[uVar20 * 8 + 4] & 0x7ffff);
              *(undefined4 *)(iVar9 + 0x80) = 0;
              FUN_4201529c(param_1,uVar1);
            }
          }
          if ((uVar14 & 8) != 0) {
            FUN_42015238(param_1,iVar10);
          }
          uVar2 = uVar2 >> 1;
          uVar1 = uVar1 + 1;
          iVar9 = iVar9 + 0x10;
        } while (uVar2 != 0);
      }
    }
    iVar9 = DAT_420013f8;
    if ((uVar6 & 0x40000) != 0) {
      iVar10 = DAT_420013e0 + iVar21;
      memw();
      memw();
      uVar1 = *(uint *)(*(int *)(iVar10 + 4) + 0x818) & *(uint *)(*(int *)(iVar10 + 4) + 0x81c) &
              0xffff;
      if (uVar1 != 0) {
        iVar3 = DAT_420013f8 + param_1 * 0x100;
        uVar2 = 0;
        do {
          if ((uVar1 & 1) != 0) {
            iVar16 = *(int *)(iVar10 + 4);
            memw();
            uVar15 = *(uint *)(iVar16 + 0x810);
            memw();
            uVar14 = *(uint *)(iVar16 + 0x834);
            iVar7 = (uVar2 & 0xffff) * 0x20;
            iVar18 = iVar7 + iVar16 + 0x900;
            memw();
            uVar20 = *(uint *)(iVar18 + 8);
            memw();
            *(uint *)(iVar18 + 8) = uVar20;
            uVar20 = ((uVar14 >> (uVar2 & 0xf) & 1) << 7 | uVar15) & uVar20;
            if ((uVar20 & 1) != 0) {
              if (uVar2 == 0) {
                memw();
                pbVar5 = (byte *)(iVar9 + param_1 * 0x100);
                *(uint *)(pbVar5 + 0x14) =
                     *(int *)(pbVar5 + 0x10) - (*(uint *)(iVar16 + 0x910) & 0x7ffff);
                pbVar5[0x10] = 0;
                pbVar5[0x11] = 0;
                pbVar5[0x12] = 0;
                pbVar5[0x13] = 0;
                FUN_4201526c(param_1,0x80);
                uVar14 = DAT_42000a7c;
                if ((*(short *)(pbVar5 + 6) == 0) || ((*pbVar5 & 0x80) == 0)) {
                  iVar16 = *(int *)(iVar10 + 4);
                  memw();
                  *(undefined4 *)(iVar16 + 0xb10) = 0;
                  memw();
                  memw();
                  *(uint *)(iVar16 + 0xb10) = *(uint *)(iVar16 + 0xb10) | uVar14;
                  memw();
                  memw();
                  *(uint *)(iVar16 + 0xb10) = *(uint *)(iVar16 + 0xb10) | 0x18;
                  memw();
                  memw();
                  *(uint *)(iVar16 + 0xb10) = *(uint *)(iVar16 + 0xb10) | DAT_42001430;
                  memw();
                  *(uint *)(iVar16 + 0xb14) = iVar9 + param_1 * 0x100;
                  memw();
                  memw();
                  *(uint *)(iVar16 + 0xb00) = *(uint *)(iVar16 + 0xb00) | DAT_42001434;
                }
              }
              else {
                memw();
                uVar14 = *(uint *)(iVar18 + 0x10);
                iVar16 = *(int *)(iVar3 + 0x10);
                *(undefined4 *)(iVar3 + 0x10) = 0;
                *(uint *)(iVar3 + 0x14) = iVar16 - (uVar14 & 0x7ffff);
                FUN_4201526c(param_1,uVar2 & 0xff | 0x80);
              }
            }
            if ((uVar20 & 0x80) != 0) {
              uVar19 = *(uint *)(iVar3 + 0x10);
              iVar16 = *(int *)(DAT_420013e0 + iVar21 + 4);
              uVar15 = *(uint *)(iVar3 + 0x14);
              uVar20 = (uint)*(ushort *)(iVar3 + 8);
              puVar8 = (uint *)(iVar16 + 0x900 + iVar7);
              uVar14 = uVar19 - uVar15;
              memw();
              uVar14 = (uVar14 < uVar20) * uVar14 + (uVar14 >= uVar20) * uVar20 + 3 >> 2;
              if (uVar14 <= (puVar8[6] & 0xffff)) {
                do {
                  uVar11 = DAT_42000540;
                  if (uVar19 <= uVar15) goto LAB_420165f7;
                  uVar19 = uVar19 - uVar15;
                  iVar7 = (uVar19 < uVar20) * uVar19 + (uVar19 >= uVar20) * uVar20;
                  if (*(char *)(iVar3 + 10) == '\x01') {
                    memw();
                    if ((*(uint *)(iVar16 + 0x808) & 0x100) == 0) {
                      memw();
                      memw();
                      *puVar8 = *puVar8 & DAT_42000538;
                      memw();
                      memw();
                      *puVar8 = *puVar8 | uVar11;
                    }
                    else {
                      memw();
                      memw();
                      *puVar8 = *puVar8 & DAT_42000544;
                      memw();
                      memw();
                      *puVar8 = *puVar8 | DAT_4200143c;
                    }
                    memw();
                    memw();
                    puVar8[4] = puVar8[4] & DAT_4200140c;
                    memw();
                    memw();
                    puVar8[4] = puVar8[4] | uVar11;
                  }
                  puVar4 = *(undefined4 **)(iVar3 + 0xc);
                  if (iVar7 + 3U >> 2 != 0) {
                    memw();
                    *(undefined4 *)((uVar2 & 0xffff) * 0x1000 + iVar16 + 0x1000) = *puVar4;
                    uVar15 = *(uint *)(iVar3 + 0x14);
                  }
                  uVar15 = uVar15 + iVar7;
                  *(uint *)(iVar3 + 0x14) = uVar15;
                  memw();
                  uVar11 = puVar8[6];
                  *(int *)(iVar3 + 0xc) = (int)puVar4 + iVar7;
                  uVar19 = *(uint *)(iVar3 + 0x10);
                } while (uVar14 <= (uVar11 & 0xffff));
              }
              if (uVar19 <= uVar15) {
LAB_420165f7:
                memw();
                memw();
                *(uint *)(iVar16 + 0x834) =
                     (uint)(0xfffffffefffffffe >> 0x20 - (uVar2 & 0xf)) & *(uint *)(iVar16 + 0x834);
              }
            }
            if (uVar1 >> 1 == 0) break;
          }
          uVar1 = uVar1 >> 1;
          uVar2 = uVar2 + 1;
          iVar3 = iVar3 + 0x10;
        } while( true );
      }
    }
    if ((uVar6 & 0x1000) != 0) {
      iVar9 = *(int *)(DAT_420013e0 + iVar21 + 4);
      memw();
      *(undefined4 *)(iVar9 + 0x14) = DAT_42000988;
      memw();
      memw();
      *(uint *)(iVar9 + 0x804) = *(uint *)(iVar9 + 0x804) & 0xfffffffe;
      uVar1 = DAT_42001408;
      memw();
      local_60 = 0;
      do {
        memw();
        local_60 = local_60 + 1;
        memw();
        if (DAT_42001408 < local_60) goto LAB_42016654;
        memw();
      } while (-1 < *(int *)(iVar9 + 0x10));
      memw();
      local_60 = 0;
      memw();
      *(undefined4 *)(iVar9 + 0x10) = 0x420;
      do {
        memw();
        local_60 = local_60 + 1;
        memw();
        if (uVar1 < local_60) break;
        memw();
      } while ((*(uint *)(iVar9 + 0x10) & 0x20) != 0);
LAB_42016654:
      memw();
      uStack_5c = 0;
      do {
        memw();
        uStack_5c = uStack_5c + 1;
        memw();
        if (uVar1 < uStack_5c) goto LAB_420166a4;
        memw();
      } while (-1 < *(int *)(iVar9 + 0x10));
      memw();
      uStack_5c = 0;
      memw();
      *(undefined4 *)(iVar9 + 0x10) = 0x10;
      do {
        memw();
        uStack_5c = uStack_5c + 1;
        memw();
        if (uVar1 < uStack_5c) break;
        memw();
      } while ((*(uint *)(iVar9 + 0x10) & 0x10) != 0);
LAB_420166a4:
      iVar10 = DAT_42000550;
      memw();
      *(int *)(iVar9 + 0x900) = DAT_42000550;
      piVar12 = (int *)(iVar9 + 0xb00);
      cVar13 = '\0';
      memw();
      *piVar12 = iVar10;
      iVar3 = DAT_4200146c;
      iVar10 = DAT_42001468;
      piVar17 = (int *)(iVar9 + 0x900);
      while( true ) {
        memw();
        piVar17[4] = 0;
        memw();
        piVar17[2] = iVar3;
        memw();
        piVar12[4] = 0;
        cVar13 = cVar13 + '\x01';
        memw();
        piVar12[2] = iVar3;
        if (cVar13 == '\a') break;
        memw();
        if (piVar17[8] < 0) {
          memw();
          piVar17[8] = iVar10;
        }
        else {
          memw();
          piVar17[8] = 0;
        }
        piVar12 = piVar17 + 0x88;
        memw();
        if (*piVar12 < 0) {
          memw();
          *piVar12 = iVar10;
        }
        else {
          memw();
          *piVar12 = 0;
        }
        piVar17 = piVar17 + 8;
      }
      memw();
      memw();
      *(uint *)(iVar9 + 0x81c) = *(uint *)(iVar9 + 0x81c) | DAT_42001470;
      memw();
      *(undefined4 *)(iVar9 + 0x814) = 9;
      iVar10 = param_1 * 0x100 + DAT_420013f8;
      memw();
      *(undefined4 *)(iVar9 + 0x810) = 1;
      (*DAT_42000094)(iVar10,0,0x100);
      FUN_420151d0(param_1);
      uVar1 = DAT_42000a7c;
      iVar9 = *(int *)(DAT_420013e0 + iVar21 + 4);
      memw();
      *(undefined4 *)(iVar9 + 0xb10) = 0;
      memw();
      memw();
      *(uint *)(iVar9 + 0xb10) = *(uint *)(iVar9 + 0xb10) | uVar1;
      memw();
      memw();
      *(uint *)(iVar9 + 0xb10) = *(uint *)(iVar9 + 0xb10) | 0x18;
      memw();
      memw();
      *(uint *)(iVar9 + 0xb10) = *(uint *)(iVar9 + 0xb10) | DAT_42001430;
      memw();
      *(int *)(iVar9 + 0xb14) = iVar10;
      memw();
      memw();
      *(uint *)(iVar9 + 0xb00) = *(uint *)(iVar9 + 0xb00) | DAT_42001434;
    }
    uVar1 = DAT_42001448;
    if ((uVar6 & 0x2000) != 0) {
      iVar9 = *(int *)(DAT_420013e0 + iVar21 + 4);
      memw();
      *(uint *)(iVar9 + 0x14) = DAT_420009f8;
      memw();
      if ((*(uint *)(iVar9 + 0x808) & 2) != 0) {
        iVar10 = *(int *)PTR_DAT_42001474;
        uVar1 = DAT_4200144c;
        if ((((DAT_4200147c < (uint)(iVar10 + DAT_42001478)) &&
             (uVar1 = DAT_42001450, DAT_420012d8 < (uint)(iVar10 + DAT_42001480))) &&
            (uVar1 = DAT_42001454, DAT_42001488 < (uint)(iVar10 + DAT_42001484))) &&
           ((uVar1 = DAT_42001458, DAT_42001490 < (uint)(iVar10 + DAT_4200148c) &&
            (uVar1 = DAT_4200145c, DAT_42001498 < (uint)(iVar10 + DAT_42001494))))) {
          if (DAT_420014a0 < (uint)(iVar10 + DAT_4200149c)) {
            if (DAT_420014a8 < (uint)(iVar10 + DAT_420014a4)) {
              if (DAT_420014b0 < (uint)(iVar10 + DAT_420014ac)) {
                if (DAT_420014b8 < (uint)(iVar10 + DAT_420014b4)) {
                  uVar1 = DAT_420012f4;
                }
                else {
                  uVar1 = DAT_42001464;
                }
              }
              else {
                uVar1 = DAT_420009f8;
              }
            }
            else {
              uVar1 = DAT_42001448;
            }
          }
          else {
            uVar1 = DAT_42001460;
          }
        }
      }
      memw();
      memw();
      *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) | 7;
      memw();
      memw();
      *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & DAT_420014bc;
      memw();
      memw();
      *(uint *)(iVar9 + 0xc) = uVar1 | *(uint *)(iVar9 + 0xc);
      memw();
      memw();
      *(uint *)(iVar9 + 0x804) = *(uint *)(iVar9 + 0x804) | 0x100;
    }
    if ((uVar6 & 0x200000) != 0) {
      memw();
      *(undefined4 *)(*(int *)(DAT_420013e0 + iVar21 + 4) + 0x14) = DAT_42000b54;
    }
    if ((uVar6 & 0x100000) != 0) {
      memw();
      *(undefined4 *)(*(int *)(DAT_420013e0 + iVar21 + 4) + 0x14) = DAT_42000b50;
    }
    if ((uVar6 & 8) != 0) {
      memw();
      *(undefined4 *)(*(int *)(DAT_420013e0 + iVar21 + 4) + 0x14) = 8;
    }
    if ((uVar6 & 0x800) != 0) {
      memw();
      *(undefined4 *)(*(int *)(DAT_420013e0 + iVar21 + 4) + 0x14) = DAT_420006dc;
      FUN_4201519c(param_1);
    }
    if ((int)uVar6 < 0) {
      memw();
      *(undefined4 *)(*(int *)(DAT_420013e0 + iVar21 + 4) + 0x14) = DAT_420014c0;
      FUN_42015170(param_1);
    }
    if ((uVar6 & 4) != 0) {
      iVar9 = *(int *)(DAT_420013e0 + iVar21 + 4);
      memw();
      memw();
      memw();
      *(uint *)(iVar9 + 4) = *(uint *)(iVar9 + 4) | *(uint *)(iVar9 + 4);
    }
  }
  return;
}