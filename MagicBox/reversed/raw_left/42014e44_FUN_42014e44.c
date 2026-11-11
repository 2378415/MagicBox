// 42014e44  FUN_42014e44  FUN_42014e44  size=805

void FUN_42014e44(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 *local_40;
  int local_3c [3];
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  undefined4 *puStack_24;
  
  uVar5 = param_1 & 0xff;
  iVar8 = (param_1 & 0xff) * (DAT_42001360 & 0xffff);
  pbVar7 = (byte *)(DAT_4200135c + uVar5 * DAT_42001360);
  iVar2 = DAT_4200135c + iVar8;
  iStack_30 = DAT_4200135c + iVar8 + 8;
  puVar4 = (undefined4 *)(DAT_4200135c + iVar8 + 0x1c);
  iVar8 = DAT_4200135c + iVar8 + 0x10;
  pbVar6 = pbVar7 + DAT_4200137c;
LAB_42014e72:
  do {
    while( true ) {
      do {
        iVar3 = FUN_42016b44(*(undefined4 *)pbVar6,local_3c,0xffffffff);
      } while (iVar3 < 0);
      if (local_3c[0] == 0) break;
      if (local_3c[0] == 2) {
        *(undefined4 **)(pbVar7 + 8) = puVar4;
        iVar3 = FUN_42014900(uVar5,iVar2,iStack_30,iVar8);
        if (iVar3 == 0) {
LAB_4201514f:
          FUN_42015cf8(uVar5,0x80);
        }
        else {
          FUN_42015ec8(uVar5,0x80,0);
        }
      }
    }
    uVar13 = (uint)*(ushort *)(pbVar7 + 6);
    if (DAT_420006dc < uVar13) {
      if ((*pbVar7 & 0x80) != 0) {
        *(undefined4 **)(pbVar7 + 8) = puVar4;
        *(uint *)(pbVar7 + 0xc) = uVar13;
        *(uint *)(pbVar7 + 0x10) = uVar13;
        pbVar7[0x14] = 0;
        goto LAB_42014ecc;
      }
    }
    else {
      *(undefined4 **)(pbVar7 + 8) = puVar4;
      *(uint *)(pbVar7 + 0xc) = uVar13;
      *(uint *)(pbVar7 + 0x10) = uVar13;
      pbVar7[0x14] = 0;
      if ((uVar13 != 0) && ((*pbVar7 & 0x80) == 0)) {
        local_40 = puVar4;
        FUN_42016068(uVar5,0,puVar4);
        goto LAB_42014e72;
      }
LAB_42014ecc:
      local_40 = puVar4;
      iVar3 = FUN_42014900(uVar5,iVar2,&local_40,iVar8);
      uVar13 = DAT_420006dc;
      if (iVar3 == 0) goto LAB_4201514f;
      uVar9 = *(uint *)(pbVar7 + 0x10);
      uVar14 = (uint)*(ushort *)(pbVar7 + 6);
      uVar9 = (uVar14 < uVar9) * uVar14 + (uVar14 >= uVar9) * uVar9;
      *(uint *)(pbVar7 + 0xc) = uVar9;
      if (uVar9 <= uVar13) {
        puVar10 = *(undefined4 **)(pbVar7 + 8);
        puVar12 = local_40;
        if (puVar10 != local_40) {
          if ((((uint)local_40 ^ (uint)puVar10) & 3) == 0) {
            puVar16 = puVar10;
            if (((uint)puVar10 & 3) != 0) {
              do {
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                if (uVar9 == 0) goto LAB_420150f2;
                uVar9 = uVar9 - 1;
                *(undefined1 *)puVar16 = *(undefined1 *)puVar12;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              } while (((uint)puVar10 & 3) != 0);
            }
            if (0xf < uVar9) {
              uVar13 = uVar9 - 0x10;
              *puVar10 = *puVar12;
              puVar10[1] = puVar12[1];
              puVar10[2] = puVar12[2];
              puVar16 = puVar12 + 3;
              puVar12 = puVar12 + 4;
              puVar10[3] = *puVar16;
              uVar9 = uVar9 & 0xf;
              puVar10 = puVar10 + (uVar13 >> 4 & 0xffff) * 4 + 4;
            }
            puVar16 = puVar12;
            if (3 < uVar9) {
              uVar13 = uVar9 - 4 >> 2 & 0xffff;
              puVar16 = puVar12 + uVar13 + 1;
              puVar11 = puVar10;
              do {
                uVar17 = *puVar12;
                puVar12 = puVar12 + 1;
                *puVar11 = uVar17;
                puVar11 = puVar11 + 1;
              } while (puVar16 != puVar12);
              uVar9 = uVar9 & 3;
              puVar10 = puVar10 + uVar13 + 1;
            }
            puVar12 = (undefined4 *)((int)puVar16 + uVar9);
            if (uVar9 != 0) {
              do {
                uVar1 = *(undefined1 *)puVar16;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
                *(undefined1 *)puVar10 = uVar1;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              } while (puVar16 != puVar12);
LAB_42015115:
              uVar9 = *(uint *)(pbVar7 + 0xc);
              puVar12 = *(undefined4 **)(pbVar7 + 8);
              goto LAB_42015119;
            }
          }
          else {
            uVar13 = uVar9;
            if (uVar9 != 0) {
LAB_42014ff4:
              if (((uint)puVar12 & 3) != 0) break;
              if (uVar13 < 0x10) {
                if (uVar13 < 4) goto LAB_42015106;
              }
              else {
                uVar17 = *puVar12;
                *(char *)((int)puVar10 + 1) = (char)((uint)uVar17 >> 8);
                *(char *)((int)puVar10 + 2) = (char)((uint)uVar17 >> 0x10);
                *(char *)((int)puVar10 + 3) = (char)((uint)uVar17 >> 0x18);
                *(char *)puVar10 = (char)uVar17;
                uVar17 = puVar12[1];
                *(char *)((int)puVar10 + 5) = (char)((uint)uVar17 >> 8);
                *(char *)((int)puVar10 + 6) = (char)((uint)uVar17 >> 0x10);
                *(char *)((int)puVar10 + 7) = (char)((uint)uVar17 >> 0x18);
                *(char *)(puVar10 + 1) = (char)uVar17;
                uVar17 = puVar12[2];
                *(char *)((int)puVar10 + 9) = (char)((uint)uVar17 >> 8);
                *(char *)((int)puVar10 + 10) = (char)((uint)uVar17 >> 0x10);
                *(char *)((int)puVar10 + 0xb) = (char)((uint)uVar17 >> 0x18);
                *(char *)(puVar10 + 2) = (char)uVar17;
                uVar17 = puVar12[3];
                *(char *)(puVar10 + 3) = (char)uVar17;
                *(char *)((int)puVar10 + 0xd) = (char)((uint)uVar17 >> 8);
                *(char *)((int)puVar10 + 0xe) = (char)((uint)uVar17 >> 0x10);
                *(char *)((int)puVar10 + 0xf) = (char)((uint)uVar17 >> 0x18);
                uVar9 = uVar13 - 0x10 & 0xfffffff0;
                uVar15 = uVar13 & 0xf;
                uVar14 = uVar13 & 0xc;
                puVar10 = (undefined4 *)((int)puVar10 + uVar9 + 0x10);
                puVar12 = (undefined4 *)((int)puVar12 + uVar9 + 0x10);
                uVar13 = uVar15;
                if (uVar14 == 0) goto LAB_420150f0;
              }
              puVar16 = puVar10;
              puVar11 = puVar12;
              do {
                uVar17 = *puVar11;
                puVar11 = puVar11 + 1;
                *(char *)puVar16 = (char)uVar17;
                *(char *)((int)puVar16 + 1) = (char)((uint)uVar17 >> 8);
                *(char *)((int)puVar16 + 2) = (char)((uint)uVar17 >> 0x10);
                *(char *)((int)puVar16 + 3) = (char)((uint)uVar17 >> 0x18);
                puVar16 = puVar16 + 1;
              } while (puVar16 != (undefined4 *)((uVar13 & 0xfffffffc) + (int)puVar10));
              uVar9 = uVar13 - 4 & 0xfffffffc;
              uVar15 = uVar13 & 3;
              puVar10 = (undefined4 *)((int)puVar10 + uVar9 + 4);
              puVar12 = (undefined4 *)((int)puVar12 + uVar9 + 4);
LAB_420150f0:
              uVar13 = uVar15;
              iStack_2c = iVar2;
              uStack_28 = uVar5;
              puStack_24 = puVar4;
              if (uVar15 == 0) goto LAB_420150f2;
LAB_42015106:
              puVar16 = (undefined4 *)((int)puVar12 + uVar13);
              do {
                uVar1 = *(undefined1 *)puVar12;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
                *(undefined1 *)puVar10 = uVar1;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              } while (puVar12 != puVar16);
              goto LAB_42015115;
            }
          }
LAB_420150f2:
          iVar3 = DAT_4200135c + uVar5 * DAT_42001360;
          uVar9 = *(uint *)(iVar3 + 0xc);
          puVar12 = *(undefined4 **)(iVar3 + 8);
        }
LAB_42015119:
        FUN_42015ec8(uVar5,0x80,puVar12,uVar9);
        if ((*(uint *)(pbVar7 + 0x10) < (uint)*(ushort *)(pbVar7 + 6)) &&
           ((*(uint *)(pbVar7 + 0x10) & 0x3f) == 0)) {
          pbVar7[0x14] = 1;
        }
        goto LAB_42014e72;
      }
    }
    (*DAT_42000060)(PTR_DAT_420013a0);
    (*DAT_42000060)(PTR_s_Request_buffer_too_small_420013b4);
    (*DAT_42000060)(PTR_DAT_420013a8);
    FUN_42015cf8(uVar5,0x80);
  } while( true );
  uVar1 = *(undefined1 *)puVar12;
  puVar12 = (undefined4 *)((int)puVar12 + 1);
  *(undefined1 *)puVar10 = uVar1;
  puVar10 = (undefined4 *)((int)puVar10 + 1);
  uVar13 = uVar13 - 1;
  uVar9 = uVar9 - 1;
  if (uVar9 == 0) goto LAB_420150f2;
  goto LAB_42014ff4;
}


