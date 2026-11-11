uint __kernel_rem_pio2(int param_1,int *param_2,int param_3,int param_4,int *param_5,int param_6)

{
  bool bVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 local_290 [20];
  int aiStack_1f0 [40];
  undefined8 local_150 [19];
  uint auStack_b4 [21];
  int *piStack_60;
  int *piStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  int local_48;
  int iStack_44;
  undefined8 local_40;
  undefined8 *puStack_38;
  undefined8 *puStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  uint *puStack_24;
  
  puVar2 = local_290;
  iVar12 = *(int *)(PTR_DAT_42001bf8 + (int)param_5 * 4);
  iStack_28 = param_6;
  local_48 = iVar12;
  puVar13 = (undefined8 *)(param_4 + -1);
  puStack_38 = puVar13;
  iStack_2c = param_1;
  piStack_60 = param_2;
  iStack_30 = param_4;
  piStack_5c = param_5;
  local_40._0_4_ = (int *)0x0;
  if (-0x15 < param_3) {
    local_40._0_4_ =
         (int *)((int)((longlong)(param_3 + -3) * (longlong)DAT_42001bfc >> 0x22) -
                (param_3 + -3 >> 0x1f));
  }
  param_3 = ((int)(int *)local_40 + 1) * -0x18 + param_3;
  puVar14 = local_150;
  puStack_34 = puVar14;
  iVar3 = (int)(int *)local_40 - (int)puVar13;
  puVar5 = (undefined4 *)(iVar3 * 4 + param_6);
  for (iVar9 = 0; iVar9 <= iVar12 + (int)puVar13; iVar9 = iVar9 + 1) {
    uVar18 = 0;
    if (-1 < iVar9 + iVar3) {
      uVar18 = (*DAT_42000e34)(*puVar5);
    }
    *puVar14 = uVar18;
    puVar14 = puVar14 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar13 = puStack_34 + iStack_30;
  for (iVar12 = 0; iVar12 <= local_48; iVar12 = iVar12 + 1) {
    uVar18 = 0;
    uVar16 = 0;
    puVar14 = puVar13;
    while( true ) {
      if ((int)puStack_38 < (int)uVar16) break;
      puVar5 = (undefined4 *)((uVar16 & 0xffff) * 8 + iStack_2c);
      local_58._0_4_ = puVar14 + -1;
      local_50._0_4_ = puVar13;
      uVar19 = (*DAT_42000e30)(*puVar5,puVar5[1],*(undefined4 *)(puVar14 + -1),
                               *(undefined4 *)((int)puVar14 + -4));
      uVar18 = (*DAT_42000e38)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      uVar16 = uVar16 + 1;
      puVar13 = (undefined8 *)local_50;
      puVar14 = (undefined8 *)local_58;
    }
    *puVar2 = uVar18;
    puVar2 = puVar2 + 1;
    puVar13 = puVar13 + 1;
  }
  puStack_24 = auStack_b4 + local_48;
  iVar12 = local_48;
  do {
    puVar6 = auStack_b4 + 1;
    uVar18 = CONCAT44(*(undefined4 *)((int)local_290 + (iVar12 * 2 + 1) * 4),
                      *(undefined4 *)(local_290 + iVar12));
    iVar3 = iVar12;
    puVar10 = puVar6;
    while( true ) {
      uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
      if (iVar3 < 1) break;
      local_50 = uVar18;
      (*DAT_42000e30)((int)uVar18,uVar4,0,DAT_42001c04);
      (*DAT_42001b40)();
      uVar18 = (*DAT_42000e34)();
      local_58 = uVar18;
      uVar18 = (*DAT_42000e30)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_42001bc8);
      iVar3 = iVar3 + -1;
      (*DAT_42000e2c)((undefined8 *)local_50,local_50._4_4_,(int)uVar18,
                      (int)((ulonglong)uVar18 >> 0x20));
      uVar16 = (*DAT_42001b40)();
      *puVar10 = uVar16;
      puVar10 = puVar10 + 1;
      uVar18 = (*DAT_42000e38)((undefined8 *)local_58,local_58._4_4_,
                               *(undefined4 *)(local_290 + iVar3),
                               *(undefined4 *)((int)local_290 + (iVar3 * 2 + 1) * 4));
    }
    uVar18 = __ieee754_scalbn((int)uVar18,uVar4,param_3);
    uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
    (*DAT_42000e30)((int)uVar18,uVar4,0,0x3fc00000);
    uVar19 = __ieee754_floor();
    uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,0x40200000);
    uVar18 = (*DAT_42000e2c)((int)uVar18,uVar4,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    puVar2 = (undefined8 *)(*DAT_42001b40)();
    local_50._0_4_ = puVar2;
    uVar19 = (*DAT_42000e34)();
    uVar18 = (*DAT_42000e2c)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                             (int)((ulonglong)uVar19 >> 0x20));
    uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
    if (param_3 < 1) {
      if (param_3 == 0) {
        local_58._0_4_ = (undefined8 *)((int)auStack_b4[iVar12] >> 0x17);
        goto LAB_4201f520;
      }
      iVar3 = (*DAT_42001c08)((int)uVar18,uVar4,0,0x3fe00000);
      if (-1 < iVar3) {
        local_58._0_4_ = (undefined8 *)0x2;
        goto LAB_4201f552;
      }
      local_58._0_4_ = (undefined8 *)0x0;
    }
    else {
      uVar16 = auStack_b4[iVar12];
      iVar3 = (int)uVar16 >> (-(param_3 + -0x18) & 0x1fU);
      uVar16 = uVar16 - (iVar3 << 0x20 - (0x20 - (-(param_3 + -0x18) & 0x1fU)));
      auStack_b4[iVar12] = uVar16;
      local_58._0_4_ = (undefined8 *)((int)uVar16 >> (-(param_3 + -0x17) & 0x1fU));
      local_50._0_4_ = (undefined8 *)((int)(undefined8 *)local_50 + iVar3);
LAB_4201f520:
      if (0 < (int)(undefined8 *)local_58) {
LAB_4201f552:
        local_50._0_4_ = (undefined8 *)((int)(undefined8 *)local_50 + 1);
        bVar1 = false;
        for (iVar3 = 0; iVar3 < iVar12; iVar3 = iVar3 + 1) {
          uVar16 = *puVar6;
          if (bVar1) {
            uVar16 = 0xffffff - uVar16;
LAB_4201f57c:
            *puVar6 = uVar16;
            bVar1 = true;
          }
          else {
            bVar1 = false;
            if (uVar16 != 0) {
              uVar16 = 0x1000000 - uVar16;
              goto LAB_4201f57c;
            }
          }
          puVar6 = puVar6 + 1;
        }
        if (0 < param_3) {
          if (param_3 == 1) {
            puVar10 = auStack_b4 + iVar12;
            uVar16 = *puVar10 & 0x7fffff;
          }
          else {
            if (param_3 != 2) goto LAB_4201f5c0;
            puVar10 = auStack_b4 + iVar12;
            uVar16 = *puVar10 & 0x3fffff;
          }
          *puVar10 = uVar16;
        }
LAB_4201f5c0:
        if ((undefined8 *)local_58 == (undefined8 *)0x2) {
          uVar18 = (*DAT_42000e2c)(0,DAT_42000e14,(int)uVar18,uVar4);
          if (bVar1) {
            uVar19 = __ieee754_scalbn(0,DAT_42000e14,param_3);
            uVar18 = (*DAT_42000e2c)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                                     (int)((ulonglong)uVar19 >> 0x20));
          }
        }
      }
    }
    uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
    iVar3 = (*DAT_42001bf4)((int)uVar18,uVar4,0,0);
    if (iVar3 != 0) {
      local_40 = __ieee754_scalbn((int)uVar18,uVar4,-param_3);
      iVar3 = (*DAT_42001c08)((int)local_40,(int)((ulonglong)local_40 >> 0x20),0,DAT_42001bc8);
      if (iVar3 < 0) {
        uVar16 = (*DAT_42001b40)((int *)local_40,local_40._4_4_);
        auStack_b4[iVar12 + 1] = uVar16;
      }
      else {
        (*DAT_42000e30)((int *)local_40,local_40._4_4_,0,DAT_42001c04);
        uVar16 = (*DAT_42001b40)();
        uVar18 = (*DAT_42000e34)();
        uVar18 = (*DAT_42000e30)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_42001bc8);
        (*DAT_42000e2c)((int *)local_40,local_40._4_4_,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20))
        ;
        uVar17 = (*DAT_42001b40)();
        auStack_b4[iVar12 + 1] = uVar17;
        param_3 = param_3 + 0x18;
        auStack_b4[iVar12 + 2] = uVar16;
        iVar12 = iVar12 + 1;
      }
      goto LAB_4201f787;
    }
    uVar16 = 0;
    iVar3 = iVar12;
    while (local_48 <= iVar3 + -1) {
      uVar16 = uVar16 | auStack_b4[iVar3];
      iVar3 = iVar3 + -1;
    }
    iVar3 = iVar12;
    if (uVar16 != 0) {
      do {
        param_3 = param_3 + -0x18;
        iVar12 = iVar3 + -1;
        puVar10 = auStack_b4 + iVar3;
        iVar3 = iVar12;
      } while (*puVar10 == 0);
LAB_4201f787:
      uVar18 = __ieee754_scalbn(0,DAT_42000e14,param_3);
      iVar3 = iVar12;
      while( true ) {
        uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
        if (iVar3 < 0) break;
        uVar19 = (*DAT_42000e34)(auStack_b4[iVar3 + 1]);
        uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar4);
        *(int *)(local_290 + iVar3) = (int)uVar19;
        *(int *)((int)local_290 + (iVar3 * 2 + 1) * 4) = (int)((ulonglong)uVar19 >> 0x20);
        uVar18 = (*DAT_42000e30)((int)uVar18,uVar4,0,DAT_42001c04);
        iVar3 = iVar3 + -1;
      }
      uVar18 = local_40;
      for (iVar3 = iVar12; -1 < iVar3; iVar3 = iVar3 + -1) {
        puVar2 = local_290 + iVar3;
        uVar19 = 0;
        iVar9 = 0;
        iVar8 = iVar12 - iVar3;
        local_40._0_4_ = (int *)PTR_DAT_42001c00;
        while( true ) {
          local_40._4_4_ = (undefined4)((ulonglong)uVar18 >> 0x20);
          iVar7 = (int)((ulonglong)uVar19 >> 0x20);
          if ((local_48 < iVar9) || (iVar8 < iVar9)) break;
          puStack_38 = puVar2;
          uVar18 = (*DAT_42000e30)(*(int *)local_40,((int *)local_40)[1],*(undefined4 *)puVar2,
                                   *(undefined4 *)((int)puVar2 + 4));
          uVar19 = (*DAT_42000e38)((int)uVar19,iVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uVar18 = CONCAT44(local_40._4_4_,(int *)local_40);
          iVar9 = iVar9 + 1;
          local_40._0_4_ = (int *)local_40 + 2;
          puVar2 = puStack_38 + 1;
        }
        local_40 = uVar18;
        aiStack_1f0[iVar8 * 2] = (int)uVar19;
        aiStack_1f0[iVar8 * 2 + 1] = iVar7;
        uVar18 = local_40;
      }
      if ((int)piStack_5c < 3) {
        local_40 = uVar18;
        if ((int)piStack_5c < 1) {
          uVar18 = 0;
          if (piStack_5c == (int *)0x0) {
            while( true ) {
              uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
              if (iVar12 < 0) break;
              uVar18 = (*DAT_42000e38)((int)uVar18,uVar16,aiStack_1f0[iVar12 * 2],
                                       aiStack_1f0[iVar12 * 2 + 1]);
              iVar12 = iVar12 + -1;
            }
            if ((undefined8 *)local_58 != (undefined8 *)0x0) {
              uVar16 = uVar16 ^ DAT_420014c0;
            }
            *piStack_60 = (int)uVar18;
            piStack_60[1] = uVar16;
          }
        }
        else {
          uVar18 = 0;
          iVar3 = iVar12;
          while( true ) {
            uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
            iVar9 = (int)uVar18;
            if (iVar3 < 0) break;
            iVar8 = iVar3 * 2;
            iVar7 = iVar3 * 2;
            iVar3 = iVar3 + -1;
            uVar18 = (*DAT_42000e38)(iVar9,uVar16,aiStack_1f0[iVar8],aiStack_1f0[iVar7 + 1]);
          }
          uVar17 = uVar16;
          if ((undefined8 *)local_58 != (undefined8 *)0x0) {
            uVar17 = uVar16 ^ DAT_420014c0;
          }
          *piStack_60 = iVar9;
          piStack_60[1] = uVar17;
          uVar18 = (*DAT_42000e2c)(aiStack_1f0[0],aiStack_1f0[1],iVar9,uVar16);
          iVar3 = 1;
          piVar11 = aiStack_1f0;
          while( true ) {
            uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
            if (iVar12 < iVar3) break;
            uVar18 = (*DAT_42000e38)((int)uVar18,uVar16,piVar11[2],piVar11[3]);
            iVar3 = iVar3 + 1;
            piVar11 = piVar11 + 2;
          }
          if ((undefined8 *)local_58 != (undefined8 *)0x0) {
            uVar16 = uVar16 ^ DAT_420014c0;
          }
          piStack_60[2] = (int)uVar18;
          piStack_60[3] = uVar16;
        }
      }
      else if (piStack_5c == (int *)0x3) {
        piVar15 = aiStack_1f0 + iVar12 * 2;
        iVar3 = iVar12;
        piVar11 = piVar15;
        while( true ) {
          local_40._4_4_ = (undefined4)((ulonglong)uVar18 >> 0x20);
          if (iVar3 < 1) break;
          iVar9 = piVar11[-2];
          iVar8 = piVar11[-1];
          local_48 = *piVar11;
          iStack_44 = piVar11[1];
          piStack_5c = piVar11 + -2;
          local_40._0_4_ = piVar15;
          uVar18 = (*DAT_42000e38)(iVar9,iVar8,local_48,iStack_44);
          uVar19 = (*DAT_42000e2c)(iVar9,iVar8,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          iVar3 = iVar3 + -1;
          uVar19 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),local_48,iStack_44);
          piVar15 = (int *)local_40;
          piVar11 = piStack_5c;
          *(undefined8 *)(piStack_5c + 2) = uVar19;
          *(undefined8 *)piVar11 = uVar18;
          uVar18 = CONCAT44(local_40._4_4_,(int *)local_40);
        }
        local_40 = uVar18;
        for (iVar3 = iVar12; 1 < iVar3; iVar3 = iVar3 + -1) {
          local_48 = piVar15[-2];
          iStack_44 = piVar15[-1];
          iVar9 = *piVar15;
          iVar8 = piVar15[1];
          piStack_5c = piVar15 + -2;
          uVar18 = (*DAT_42000e38)(local_48,iStack_44,iVar9,iVar8);
          uVar19 = (*DAT_42000e2c)(local_48,iStack_44,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uVar19 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),iVar9,iVar8);
          piVar15 = piStack_5c;
          *(undefined8 *)(piStack_5c + 2) = uVar19;
          *(undefined8 *)piVar15 = uVar18;
        }
        uVar18 = 0;
        while( true ) {
          uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
          if (iVar12 < 2) break;
          iVar3 = iVar12 * 2;
          iVar9 = iVar12 * 2;
          iVar12 = iVar12 + -1;
          uVar18 = (*DAT_42000e38)((int)uVar18,uVar16,aiStack_1f0[iVar3],aiStack_1f0[iVar9 + 1]);
        }
        if ((undefined8 *)local_58 == (undefined8 *)0x0) {
          *piStack_60 = aiStack_1f0[0];
          piStack_60[1] = aiStack_1f0[1];
          piStack_60[2] = aiStack_1f0[2];
          piStack_60[3] = aiStack_1f0[3];
          *(undefined8 *)(piStack_60 + 4) = uVar18;
        }
        else {
          *piStack_60 = aiStack_1f0[0];
          uVar17 = DAT_420014c0;
          piStack_60[2] = aiStack_1f0[2];
          piStack_60[1] = aiStack_1f0[1] ^ uVar17;
          piStack_60[3] = aiStack_1f0[3] ^ uVar17;
          piStack_60[4] = (int)uVar18;
          piStack_60[5] = uVar16 ^ uVar17;
        }
      }
      return (uint)(undefined8 *)local_50 & 7;
    }
    iVar3 = 1;
    puVar10 = puStack_24;
    while (uVar16 = *puVar10, puVar10 = puVar10 + -1, uVar16 == 0) {
      iVar3 = iVar3 + 1;
    }
    iVar3 = iVar12 + iVar3;
    puVar2 = puStack_34 + iVar12 + iStack_30;
    while (iVar12 = iVar12 + 1, iVar12 <= iVar3) {
      uVar18 = (*DAT_42000e34)(*(undefined4 *)(((int)(int *)local_40 + iVar12) * 4 + iStack_28));
      *puVar2 = uVar18;
      puVar14 = (undefined8 *)0x0;
      uVar18 = 0;
      puVar13 = puVar2;
      while( true ) {
        uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
        if ((int)puStack_38 < (int)puVar14) break;
        puVar5 = (undefined4 *)(((uint)puVar14 & 0xffff) * 8 + iStack_2c);
        local_58._0_4_ = puVar13;
        local_50._0_4_ = puVar14;
        uVar19 = (*DAT_42000e30)(*puVar5,puVar5[1],*(undefined4 *)puVar13,
                                 *(undefined4 *)((int)puVar13 + 4));
        uVar18 = (*DAT_42000e38)((int)uVar18,uVar4,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        puVar14 = (undefined8 *)((int)(undefined8 *)local_50 + 1);
        puVar13 = (undefined8 *)local_58 + -1;
      }
      *(int *)(local_290 + iVar12) = (int)uVar18;
      *(undefined4 *)((int)local_290 + (iVar12 * 2 + 1) * 4) = uVar4;
      puVar2 = puVar2 + 1;
    }
    iVar12 = iVar3;
  } while( true );
}