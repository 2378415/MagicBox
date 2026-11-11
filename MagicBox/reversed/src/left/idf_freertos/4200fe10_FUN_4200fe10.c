/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x42010179) overlaps instruction at (ram,0x42010178)
    */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint FUN_4200fe10(byte *param_1,undefined1 *param_2,uint param_3)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  ushort uVar5;
  ushort *puVar6;
  uint *unaff_retaddr;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  byte *pbVar15;
  uint uVar16;
  int unaff_a10;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  byte bVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  undefined4 uVar27;
  uint uVar28;
  int iVar29;
  undefined4 in_f4;
  undefined1 uVar30;
  uint in_SCOMPARE1;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  bVar2 = *param_1;
  uVar8 = (uint)bVar2;
  if (uVar8 == 0) {
    return 0;
  }
  piVar11 = *(int **)(param_1 + 0x210);
  if (piVar11 == (int *)0x0) {
    return 0;
  }
  if (*(byte *)((int)piVar11 + 0x1d6) != param_3) {
    return 0;
  }
  if ((param_1[0x20c] != 0) && (param_3 != 0)) {
    *param_2 = *(undefined1 *)((int)piVar11 + 0x1d5);
  }
  piVar7 = (int *)((int)unaff_retaddr + unaff_a10);
  puVar14 = unaff_retaddr;
  (*(code *)PTR_FUN_420004dc)();
  *(int **)((int)unaff_retaddr + unaff_a10 + 8) = piVar11;
  uVar10 = param_3 * 8;
  *(uint *)((int)unaff_retaddr + unaff_a10 + 0xc) = param_3;
  uVar22 = *(int *)((int)unaff_retaddr + unaff_a10 + 4) + *piVar11;
  pbVar15 = param_2 + (uVar22 >> 3);
  if (uVar22 < uVar10) {
    bVar19 = *pbVar15;
    uVar23 = (int)(uint)bVar19 >> (uVar22 & 7) & 1;
    if (piVar11[0x28] == 0) {
      uVar21 = (uint)(piVar11[0x4a] != 0 && piVar11[0x16] == 0);
      if (uVar23 != uVar21) {
        if (uVar21 != 0) goto LAB_4200fec4;
        *pbVar15 = (byte)(1 << 0x20 - (0x20 - (uVar22 & 7))) & bVar19 ^ bVar19;
      }
    }
    else if (uVar23 == 0) {
LAB_4200fec4:
      *pbVar15 = bVar19 | (byte)(1 << 0x20 - (0x20 - (uVar22 & 7)));
    }
  }
  iVar12 = *(int *)((int)unaff_retaddr + unaff_a10 + 8);
  iVar9 = *(int *)((int)unaff_retaddr + unaff_a10 + 0xc);
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000e50);
  puVar6 = DAT_42000dfc;
  memw();
  memw();
  uVar22 = (uint)*DAT_42000dfc;
  memw();
  memw();
  memw();
  uVar5 = *DAT_42000e00;
  memw();
  uVar30 = (undefined1)in_SCOMPARE1;
  if (uVar22 < uVar5) {
    sVar4 = *(short *)(uVar22 * 4 + DAT_42000df8);
    *(int *)((int)unaff_retaddr + unaff_a10 + 0xc) = (int)*(short *)(uVar22 * 4 + DAT_42000df4);
    uVar22 = DAT_42000d18;
    puVar14 = (uint *)((uint)puVar6 & 0xfffffffc);
    *(int *)((int)unaff_retaddr + unaff_a10 + 8) = (int)sVar4;
    uVar22 = uVar22 << 0x20 - (((uint)puVar6 & 3) * -8 + 0x20);
    memw();
    uVar23 = *puVar14;
    do {
      uVar24 = uVar23 & (uVar22 ^ 0xffffffff) |
               uVar23 + (1 << 0x20 - (((uint)puVar6 & 3) * -8 + 0x20)) & uVar22;
      wsr(uVar30,uVar23);
      uVar21 = *puVar14;
      if (uVar21 == in_SCOMPARE1) {
        *puVar14 = uVar24;
      }
      bVar1 = uVar21 != uVar23;
      uVar23 = uVar21;
    } while (bVar1);
    iVar29 = ((uint)puVar6 & 3) << 3;
    if ((uVar24 >> iVar29 & 0xffff) < (uint)uVar5) {
      cVar3 = *(char *)(iVar12 + 0x9c);
    }
    else {
      memw();
      memw();
      *DAT_42000e00 = 0;
      memw();
      memw();
      memw();
      *DAT_42000dfc = 0;
      memw();
      cVar3 = *(char *)(iVar12 + 0x9c);
    }
    if (cVar3 == '\0') {
      *(undefined4 *)((int)unaff_retaddr + unaff_a10 + 0x10) = 0;
      piVar7 = (int *)((int)unaff_retaddr + unaff_a10);
      uVar22 = uVar8;
      goto LAB_42010429;
    }
    *(undefined4 *)((int)unaff_retaddr + unaff_a10 + 0x10) = 0;
  }
  else {
    uVar24 = (uint)DAT_42000e4c & 3;
    memw();
    puVar13 = (uint *)((uint)DAT_42000e4c & 0xfffffffc);
    uVar25 = uVar24 * 8;
    uVar21 = 0xff << 0x20 - (((uint)DAT_42000e4c & 3) * -8 + 0x20) ^ 0xffffffff;
    uVar23 = (uint)*DAT_42000e4c;
    do {
      memw();
      uVar22 = uVar21 & *puVar13;
      do {
        uVar26 = uVar22;
        uVar22 = (uVar23 & 0xff) << 0x20 - (uVar24 * -8 + 0x20) | uVar26;
        wsr(uVar30,uVar22);
        uVar18 = *puVar13;
        if (uVar18 == in_SCOMPARE1) {
          *puVar13 = uVar26;
        }
        uVar16 = DAT_42000d18;
      } while ((uVar18 != uVar22) && (uVar22 = uVar18 & uVar21, uVar26 != (uVar18 & uVar21)));
      uVar28 = uVar18 >> uVar25;
      uVar22 = uVar23 & 0xff;
      uVar17 = uVar28 & 0xff;
      uVar23 = uVar28;
    } while (uVar17 != uVar22);
    if (uVar22 == 0) {
      piVar11 = (int *)((int)puVar14 + uVar17);
      if (puVar14 != (uint *)0x0) {
        uVar23 = *puVar14;
        puVar14 = _DAT_41ff8294;
        goto code_r0x42010178;
      }
      puVar14 = (uint *)((uint)_DAT_41ff8294 & uVar17);
      uVar21 = ((uint)_DAT_41ff8294 & 3) << 3;
      uVar25 = DAT_42000d18 << 0x20 - (((uint)_DAT_41ff8294 & 3) * -8 + 0x20) ^ 0xffffffff;
      piVar11 = (int *)puRam00000000;
      uVar26 = DAT_42000d18;
      do {
        memw();
        uVar17 = *puVar14;
        *(short *)((int)piVar11 + 0xc) = (short)uVar28;
        uVar23 = (uVar28 & 0xffff) << 0x20 - (0x20 - (uVar21 & 0x1f));
        uVar17 = uVar25 & uVar17;
        *(uint *)((int)piVar11 + 0x10) = uVar21;
        do {
          uVar21 = uVar23 | uVar17;
          wsr(uVar30,uVar21);
          uVar18 = *puVar14;
          if (uVar18 == in_SCOMPARE1) {
            *puVar14 = uVar17;
          }
code_r0x42010178:
          *(uint *)((int)piVar11 + 8) = uVar17;
          uVar17 = uVar18 & uVar25;
        } while ((uVar18 != uVar21) && (*(uint *)((int)piVar11 + 8) != uVar17));
        uVar21 = *(uint *)((int)piVar11 + 0x10);
        uVar28 = uVar18 >> (uVar21 & 0x1f);
      } while ((uVar28 & 0xffff) != (uint)*(ushort *)((int)piVar11 + 0xc));
      uVar24 = (uint)DAT_42000e98 & 3;
      memw();
      uVar21 = (uint)*DAT_42000e98;
      uVar23 = (uint)DAT_42000e98 & 3;
      *(uint *)((int)piVar11 + 8) = (uint)DAT_42000e98 & 0xfffffffc;
      uVar23 = uVar26 << 0x20 - (uVar23 * -8 + 0x20) ^ 0xffffffff;
      uVar27 = 0;
      do {
        memw();
        uVar25 = **(uint **)((int)piVar11 + 8);
        *(undefined4 *)((int)piVar11 + 0x10) = uVar27;
        *(short *)((int)piVar11 + 0x14) = (short)uVar21;
        uVar25 = uVar23 & uVar25;
        do {
          uVar16 = (uVar21 & 0xffff) << 0x20 - (uVar24 * -8 + 0x20) | uVar25;
          wsr(uVar30,uVar16);
          uVar18 = **(uint **)((int)piVar11 + 8);
          if (uVar18 == in_SCOMPARE1) {
            **(uint **)((int)piVar11 + 8) = uVar25;
          }
          puVar6 = DAT_42000e9c;
          uVar28 = uVar18 & uVar23;
        } while ((uVar18 != uVar16) && (bVar1 = uVar25 != uVar28, uVar25 = uVar28, bVar1));
        uVar21 = uVar18 >> uVar24 * 8;
        uVar27 = *(undefined4 *)((int)piVar11 + 0x10);
      } while ((uVar21 & 0xffff) != (uint)*(ushort *)((int)piVar11 + 0x14));
      uVar24 = (uint)DAT_42000e9c & 3;
      memw();
      uVar23 = (uint)*DAT_42000e9c;
      *(int *)((int)piVar11 + 8) = (int)(short)*(ushort *)((int)piVar11 + 0x14);
      puVar14 = (uint *)((uint)puVar6 & 0xfffffffc);
      iVar29 = uVar24 * 8;
      uVar21 = uVar26 << 0x20 - (((uint)puVar6 & 3) * -8 + 0x20) ^ 0xffffffff;
      do {
        memw();
        uVar25 = uVar21 & *puVar14;
        *(short *)((int)piVar11 + 0x14) = (short)uVar23;
        do {
          uVar26 = (uVar23 & 0xffff) << 0x20 - (uVar24 * -8 + 0x20) | uVar25;
          wsr(uVar30,uVar26);
          uVar18 = *puVar14;
          if (uVar18 == in_SCOMPARE1) {
            *puVar14 = uVar25;
          }
          *(uint *)((int)piVar11 + 0x10) = uVar25;
          uVar25 = uVar18 & uVar21;
        } while ((uVar18 != uVar26) && (*(uint *)((int)piVar11 + 0x10) != uVar25));
        uVar23 = uVar18 >> iVar29;
      } while ((uVar23 & 0xffff) != (uint)*(ushort *)((int)piVar11 + 0x14));
      cVar3 = *(char *)(iVar12 + 0x9c);
      *(uint *)((int)piVar11 + 0x10) = *(ushort *)((int)piVar11 + 0x14) & 0xff;
      if (cVar3 != '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      cVar3 = *(char *)(iVar12 + 0x9d);
      *(int *)((int)piVar11 + 0xc) = (int)*(short *)((int)piVar11 + 0xc);
      if (cVar3 == '\0') {
LAB_420103ba:
        uVar23 = (uint)*(byte *)(*piVar11 + 0xc4);
        piVar7 = piVar11;
        if ((uVar23 == 0) || (param_2 == (undefined1 *)0x0)) goto LAB_42010429;
      }
      else {
        piVar11 = (int *)0x0;
        if (*(int *)(param_2 + 0x24) != 0 || (byte)puRam00000000[0xbc] == 0) {
          uRam00000008 = 0;
          goto LAB_420103ba;
        }
        uVar23 = iRam00000004 + *(int *)(iVar12 + 0x1b8);
        if (uVar23 < uVar10) {
          uVar21 = (byte)puRam00000000[0xbc] + uVar23;
          uVar21 = (uVar21 < uVar10) * uVar21 + (uVar21 >= uVar10) * uVar10;
          uVar24 = uVar21 + 7;
          uVar23 = uVar23 >> 3;
          uRam00000008 = uVar24 >> 3;
          if (uVar23 < uRam00000008) {
            uRam00000014 = uVar21;
            uRam00000018 = uVar24;
            uRam0000001c = uVar22;
            (*DAT_42000094)(param_2 + uVar23,0,uRam00000008 - uVar23);
            uVar21 = uRam00000014;
            uVar24 = uRam00000018;
            uVar22 = uRam0000001c;
          }
          if (((uVar24 & 0xfffffff8) != uVar21) && ((-(uVar21 - 1) & 0xff) != 0)) {
            iVar29 = 0x20 - ((uVar24 & 0xfffffff8) - uVar21 & 0x1f);
            param_2[uRam00000008 - 1] = (char)(1 << 0x20 - iVar29) - 1U & param_2[uRam00000008 - 1];
          }
        }
        uVar23 = (uint)(byte)puRam00000000[0xc4];
        if (uVar23 == 0) {
          uRam00000008 = 0;
          piVar7 = piVar11;
          uVar22 = 0;
          goto LAB_42010429;
        }
        uRam00000008 = 0;
      }
      uVar21 = *(int *)((int)piVar11 + 4) + *(int *)(iVar12 + 0x1c0);
      piVar7 = piVar11;
      if (uVar21 < uVar10) {
        uVar23 = uVar23 + uVar21;
        uVar23 = (uVar23 < uVar10) * uVar23 + (uVar23 >= uVar10) * uVar10;
        uVar24 = uVar23 + 7;
        uVar21 = uVar21 >> 3;
        uVar25 = uVar24 >> 3;
        if (uVar21 < uVar25) {
          *(uint *)((int)piVar11 + 0x1c) = uVar22;
          *(uint *)((int)piVar11 + 0x18) = uVar24;
          *(uint *)((int)piVar11 + 0x14) = uVar25;
          (*DAT_42000094)(param_2 + uVar21,0,uVar25 - uVar21);
          uVar22 = *(uint *)((int)piVar11 + 0x1c);
          uVar24 = *(uint *)((int)piVar11 + 0x18);
          uVar25 = *(uint *)((int)piVar11 + 0x14);
        }
        if (((uVar24 & 0xfffffff8) != uVar23) && ((-(iVar9 + -1) & 0xffU) != 0)) {
          iVar29 = 0x20 - ((uVar24 & 0xfffffff8) - uVar23 & 0x1f);
          param_2[uVar25 - 1] = (char)(1 << 0x20 - iVar29) - 1U & param_2[uVar25 - 1];
        }
      }
      goto LAB_42010429;
    }
    memw();
    uVar21 = (uint)DAT_42000e44 & 3;
    puVar14 = (uint *)((uint)DAT_42000e44 & 0xfffffffc);
    uVar24 = DAT_42000d18 << 0x20 - (((uint)DAT_42000e44 & 3) * -8 + 0x20) ^ 0xffffffff;
    uVar23 = (uint)*DAT_42000e44;
    do {
      uVar25 = uVar23;
      memw();
      uVar18 = uVar24 & *puVar14;
      do {
        uVar26 = (uVar25 & 0xffff) << 0x20 - (uVar21 * -8 + 0x20) | uVar18;
        wsr(uVar30,uVar26);
        uVar23 = *puVar14;
        if (uVar23 == in_SCOMPARE1) {
          *puVar14 = uVar18;
        }
        *(uint *)((int)unaff_retaddr + unaff_a10 + 8) = uVar18;
        puVar6 = DAT_42000e48;
        uVar18 = uVar23 & uVar24;
      } while ((uVar23 != uVar26) && (*(uint *)((int)unaff_retaddr + unaff_a10 + 8) != uVar18));
      uVar23 = uVar23 >> uVar21 * 8;
    } while ((uVar23 & 0xffff) != (uVar25 & 0xffff));
    uVar21 = (uint)DAT_42000e48 & 3;
    memw();
    uVar5 = *DAT_42000e48;
    uVar23 = (uint)DAT_42000e48 & 3;
    *(int *)((int)unaff_retaddr + unaff_a10 + 0xc) = (int)(short)uVar25;
    puVar14 = (uint *)((uint)puVar6 & 0xfffffffc);
    uVar24 = uVar16 << 0x20 - (uVar23 * -8 + 0x20) ^ 0xffffffff;
    uVar23 = (uint)uVar5;
    do {
      uVar25 = uVar23;
      memw();
      uVar18 = uVar24 & *puVar14;
      do {
        uVar26 = (uVar25 & 0xffff) << 0x20 - (uVar21 * -8 + 0x20) | uVar18;
        wsr(uVar30,uVar26);
        uVar23 = *puVar14;
        if (uVar23 == in_SCOMPARE1) {
          *puVar14 = uVar18;
        }
        *(uint *)((int)unaff_retaddr + unaff_a10 + 8) = uVar18;
        puVar6 = DAT_42000e88;
        uVar18 = uVar23 & uVar24;
      } while ((uVar23 != uVar26) && (*(uint *)((int)unaff_retaddr + unaff_a10 + 8) != uVar18));
      uVar23 = uVar23 >> uVar21 * 8;
    } while ((uVar23 & 0xffff) != (uVar25 & 0xffff));
    uVar24 = (uint)DAT_42000e88 & 3;
    memw();
    uVar5 = *DAT_42000e88;
    *(int *)((int)unaff_retaddr + unaff_a10 + 8) = (int)(short)uVar25;
    puVar14 = (uint *)((uint)puVar6 & 0xfffffffc);
    iVar29 = uVar24 * 8;
    uVar21 = uVar16 << 0x20 - (((uint)puVar6 & 3) * -8 + 0x20) ^ 0xffffffff;
    uVar23 = (uint)uVar5;
    do {
      uVar25 = uVar23;
      memw();
      uVar23 = uVar21 & *puVar14;
      do {
        uVar26 = (uVar25 & 0xffff) << 0x20 - (uVar24 * -8 + 0x20) | uVar23;
        wsr(uVar30,uVar26);
        uVar18 = *puVar14;
        if (uVar18 == in_SCOMPARE1) {
          *puVar14 = uVar23;
        }
        uVar16 = uVar18 & uVar21;
      } while ((uVar18 != uVar26) && (bVar1 = uVar23 != uVar16, uVar23 = uVar16, bVar1));
      uVar23 = uVar18 >> iVar29;
    } while ((uVar18 >> iVar29 & 0xffff) != (uVar25 & 0xffff));
    cVar3 = *(char *)(iVar12 + 0x9c);
    *(uint *)((int)unaff_retaddr + unaff_a10 + 0x10) = uVar25 & 0xff;
    if (cVar3 == '\0') goto LAB_42010429;
  }
  piVar7 = (int *)((int)unaff_retaddr + unaff_a10);
  uVar22 = uVar8;
LAB_42010429:
  if (((piVar7[3] == 0) || (uVar23 = (uint)*(byte *)(*piVar7 + 0xb4), uVar23 == 0)) ||
     (uVar21 = piVar7[1] + *(int *)(iVar12 + 0x1b0), uVar10 < uVar21 + uVar23)) {
    uVar23 = 0;
  }
  else {
    if ((uVar23 - 1 & 0xff) < 0x20) {
      uVar24 = piVar7[3];
      uVar25 = 0;
      do {
        iVar29 = 0x20 - (uVar21 & 7);
        if (uVar10 <= uVar21) break;
        bVar19 = param_2[uVar21 >> 3];
        bVar20 = (byte)(1 << 0x20 - iVar29);
        if (((-1 << 0x20 - (0x20 - (uVar23 & 0x1f)) & uVar24 ^ uVar24) & 1 << ((byte)uVar25 & 0x1f))
            == 0) {
          bVar20 = bVar20 & bVar19 ^ bVar19;
        }
        else {
          bVar20 = bVar20 | bVar19;
        }
        param_2[uVar21 >> 3] = bVar20;
        uVar25 = uVar25 + 1;
        uVar21 = uVar21 + 1;
      } while (uVar25 != uVar23);
    }
    uVar23 = uVar8;
  }
  if (((piVar7[2] != 0) && (uVar21 = (uint)*(byte *)(*piVar7 + 0xbc), uVar21 != 0)) &&
     (uVar24 = piVar7[1] + *(int *)(iVar12 + 0x1b8), uVar24 + uVar21 <= uVar10)) {
    if ((uVar21 - 1 & 0xff) < 0x20) {
      iVar29 = 0x20 - (uVar24 & 7);
      if (uVar24 < uVar10) {
        bVar2 = param_2[uVar24 >> 3];
        bVar19 = (byte)(1 << 0x20 - iVar29);
        if (((-1 << 0x20 - (0x20 - (uVar21 & 0x1f)) & piVar7[2] ^ piVar7[2]) & 1U) == 0) {
          bVar19 = bVar19 & bVar2 ^ bVar2;
        }
        else {
          bVar19 = bVar19 | bVar2;
        }
        (param_2 + (uVar24 >> 3))[0x10] = bVar19;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    uVar23 = uVar8;
  }
  if (((piVar7[4] != 0) && (uVar21 = (uint)*(byte *)(*piVar7 + 0xc4), uVar21 != 0)) &&
     (uVar24 = piVar7[1] + *(int *)(iVar12 + 0x1c0), uVar24 + uVar21 <= uVar10)) {
    if ((uVar21 - 1 & 0xff) < 0x20) {
      iVar9 = piVar7[4];
      uVar23 = 0;
      do {
        iVar29 = 0x20 - (uVar24 & 7);
        if (uVar10 <= uVar24) break;
        bVar19 = param_2[uVar24 >> 3];
        bVar20 = (byte)(1 << 0x20 - iVar29);
        if (((-1 << 0x20 - (0x20 - (uVar21 & 0x1f)) & (int)(char)iVar9 ^ (int)(char)iVar9) &
            1 << ((byte)uVar23 & 0x1f)) == 0) {
          bVar20 = bVar20 & bVar19 ^ bVar19;
        }
        else {
          bVar20 = bVar20 | bVar19;
        }
        param_2[uVar24 >> 3] = bVar20;
        uVar23 = uVar23 + 1;
        uVar24 = uVar24 + 1;
      } while (uVar21 != uVar23);
    }
    uVar23 = uVar8;
  }
  puVar14 = (uint *)(uint)(bVar2 >> iVar29);
  *(undefined4 *)(uVar8 + 0x300) = in_f4;
  licw(puVar14);
  *puVar14 = uVar10;
  memw();
  memw();
  memw();
  *DAT_42000e98 = (ushort)uVar22;
  memw();
  memw();
  memw();
  *DAT_42000e9c = (ushort)uVar22;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  if (*DAT_42000e00 <= *DAT_42000dfc) {
    memw();
    memw();
    memw();
    if (*DAT_42000e44 == 0) {
      memw();
      memw();
      memw();
      if (*DAT_42000e48 == 0) {
        memw();
        memw();
        memw();
        if (*DAT_42000e88 == 0) {
          memw();
          memw();
          memw();
          if (*DAT_42000e94 == 0) {
            memw();
            memw();
            memw();
            if (*DAT_42000e98 == 0) {
              memw();
              memw();
              memw();
              if (*DAT_42000e9c == 0) {
                memw();
                memw();
                *DAT_42000e04 = 0;
                memw();
                return uVar23;
              }
            }
          }
        }
      }
    }
  }
  memw();
  memw();
  *DAT_42000e04 = 1;
  memw();
  return uVar23;
}