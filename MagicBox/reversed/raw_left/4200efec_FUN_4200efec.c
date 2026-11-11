// 4200efec  FUN_4200efec  FUN_4200efec  size=1643

/* WARNING: Control flow encountered bad instruction data */

void FUN_4200efec(int param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *unaff_retaddr;
  code *pcVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  uint uStack_88;
  uint uStack_80;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_68;
  int iStack_64;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  
  pcVar4 = (code *)&local_a0;
  iVar15 = param_1;
  if (param_1 < 1) {
    iVar15 = -param_1;
  }
  iVar16 = param_2;
  if (param_2 < 1) {
    iVar16 = -param_2;
  }
  local_a0._0_4_ = (uint)(iVar15 < iVar16) * iVar16 + (uint)(iVar15 >= iVar16) * iVar15 & 0xffff;
  if (((uint)local_a0 == 0) || (param_3 <= (uint)local_a0)) {
    local_a0._0_4_ = param_3;
  }
  uStack_88 = param_6;
  iStack_2c = param_1;
  iStack_28 = param_2;
  uStack_80 = (*(code *)PTR_FUN_42000e24)();
  uVar7 = DAT_42000de8;
  uStack_80 = uStack_80 + (uint)((ulonglong)uStack_80 * (ulonglong)DAT_42000de8 >> 0x22) * -6;
  uVar5 = (*(code *)PTR_FUN_42000e24)();
  uVar6 = (*(code *)PTR_FUN_42000e24)();
  iStack_64 = uVar6 + (uint)((ulonglong)uVar6 * (ulonglong)uVar7 >> 0x22) * -6;
  uVar7 = (*(code *)PTR_FUN_42000e24)();
  uVar1 = (ulonglong)DAT_42000dec;
  uStack_70 = (*(code *)PTR_FUN_42000e24)();
  if (param_4 == 0) {
    uVar6 = (*(code *)PTR_FUN_42000e24)();
    uVar8 = (*(code *)PTR_FUN_42000e24)();
    uStack_88 = (uint)((ulonglong)
                       ((uVar8 + (uint)((ulonglong)uVar8 * (ulonglong)DAT_42000df0 >> 0x25) * -0x33
                        + 0x19) * iStack_28) * (ulonglong)DAT_4200007c >> 0x25);
    param_5 = (uint)((ulonglong)
                     ((uVar6 + (uint)((ulonglong)uVar6 * (ulonglong)DAT_42000df0 >> 0x25) * -0x33 +
                      0x19) * iStack_2c) * (ulonglong)DAT_4200007c >> 0x25);
  }
  uStack_78 = (uint)local_a0;
  uVar6 = (*(code *)PTR_FUN_42000e24)();
  uVar19 = (*DAT_42000e28)(uVar6 % ((uVar5 & 3) * 2 + 1));
  uVar20 = (*DAT_42000e28)(uVar5 & 3);
  uVar19 = (*DAT_42000e2c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                           (int)((ulonglong)uVar20 >> 0x20));
  uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),DAT_42000e1c,DAT_42000e20);
  uVar20 = FUN_4201ea4c();
  uVar14 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar13 = (undefined4)uVar20;
  local_a0 = FUN_4201eac8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  uVar19 = (*DAT_42000e34)(iStack_2c);
  uStack_90 = (*DAT_42000e34)(iStack_28);
  uStack_98 = uVar19;
  uVar19 = (*DAT_42000e30)(uVar13,uVar14,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  uVar20 = (*DAT_42000e30)((uint)local_a0,local_a0._4_4_,(undefined4)uStack_90,uStack_90._4_4_);
  uStack_50 = (*DAT_42000e2c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                              (int)((ulonglong)uVar20 >> 0x20));
  uVar19 = (*DAT_42000e30)((uint)local_a0,local_a0._4_4_,(undefined4)uStack_98,uStack_98._4_4_);
  uVar20 = (*DAT_42000e30)(uVar13,uVar14,(undefined4)uStack_90,uStack_90._4_4_);
  uStack_48 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                              (int)((ulonglong)uVar20 >> 0x20));
  uVar19 = (*DAT_42000e34)(param_5);
  uVar20 = (*DAT_42000e34)(uStack_88);
  uStack_98 = uVar19;
  uStack_90 = uVar20;
  uVar19 = (*DAT_42000e30)(uVar13,uVar14,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  uVar20 = (*DAT_42000e30)((uint)local_a0,local_a0._4_4_,(undefined4)uStack_90,uStack_90._4_4_);
  uStack_60 = (*DAT_42000e2c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                              (int)((ulonglong)uVar20 >> 0x20));
  uVar19 = (*DAT_42000e30)((uint)local_a0,local_a0._4_4_,(undefined4)uStack_98,uStack_98._4_4_);
  uVar20 = (*DAT_42000e30)(uVar13,uVar14,(undefined4)uStack_90,uStack_90._4_4_);
  uStack_58 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                              (int)((ulonglong)uVar20 >> 0x20));
  uVar2 = (ulonglong)uStack_58 >> 0x20;
  uVar13 = (undefined4)uStack_58;
  uVar5 = (*(code *)PTR_FUN_42000e24)();
  local_a0._0_4_ = uStack_78;
  uVar19 = uStack_58;
  if (uVar5 + (uint)((ulonglong)uVar5 * (ulonglong)DAT_4200007c >> 0x25) * -100 <
      uVar7 + (uint)(uVar7 * uVar1 >> 0x23) * -0xb) {
    uVar19 = (*DAT_42000e28)(uStack_70 & 7);
    uVar19 = (*DAT_42000e3c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,DAT_42000e18);
    uVar19 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,DAT_42000e14);
    uVar14 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar20 = (*DAT_42000e30)((undefined4)uStack_60,uStack_60._4_4_,(int)uVar19,uVar14);
    uStack_60 = uVar20;
    uVar19 = (*DAT_42000e30)(uVar13,(int)uVar2,(int)uVar19,uVar14);
  }
  uVar7 = uStack_80;
  iStack_34 = (uStack_80 & 0xffff) * 2 + 1;
  uStack_58 = uVar19;
  uStack_40 = (*DAT_42000e34)((uint)local_a0);
  uStack_68 = (uint)local_a0;
  uStack_98._0_4_ = 0;
  iStack_38 = (uint)local_a0 - 1;
  uStack_78 = 0;
  local_a0._0_4_ = 0;
  uStack_90._0_4_ = 0;
  uStack_30 = uVar7 & 0xff;
  uStack_98._4_4_ = 0;
  uStack_74 = 0;
  local_a0._4_4_ = 0;
  uStack_90._4_4_ = 0;
  uVar7 = 0;
  do {
    uVar5 = uVar7;
    uVar7 = uVar5 + 1;
    uVar19 = (*DAT_42000e34)(uVar7);
    uVar19 = (*DAT_42000e3c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),
                             *(undefined4 *)((int)pcVar4 + 0x60),*(undefined4 *)((int)pcVar4 + 100))
    ;
    uVar14 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar13 = (undefined4)uVar19;
    uVar19 = (*DAT_42000e38)(uVar13,uVar14,uVar13,uVar14);
    uVar19 = (*DAT_42000e2c)(0,DAT_42000e10,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar20 = (*DAT_42000e30)(uVar13,uVar14,uVar13,uVar14);
    uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                             (int)((ulonglong)uVar20 >> 0x20));
    uVar10 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar13 = (undefined4)uVar19;
    uVar19 = (*DAT_42000e2c)(0,DAT_42000e14,uVar13,uVar10);
    uVar11 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar14 = (undefined4)uVar19;
    uVar19 = (*DAT_42000e30)(uVar14,uVar11,uVar14,uVar11);
    uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,0);
    *(undefined8 *)((int)pcVar4 + 0x18) = uVar19;
    uVar19 = (*DAT_42000e38)(uVar14,uVar11,uVar14,uVar11);
    uVar19 = (*DAT_42000e30)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar13,uVar10);
    uVar14 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar20 = (*DAT_42000e30)(uVar13,uVar10,uVar13,uVar10);
    iVar15 = *(int *)((int)pcVar4 + 0x10);
    *(int *)((int)pcVar4 + 0x30) = iVar15;
    *(undefined4 *)((int)pcVar4 + 0x34) = *(undefined4 *)((int)pcVar4 + 0x14);
    *(undefined8 *)((int)pcVar4 + 0x20) = uVar20;
    uVar20 = (*DAT_42000e30)((int)uVar19,uVar14,*(undefined4 *)((int)pcVar4 + 0x40),
                             *(undefined4 *)((int)pcVar4 + 0x44));
    uVar20 = (*DAT_42000e38)((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),
                             *(undefined4 *)((int)pcVar4 + 0x18),*(undefined4 *)((int)pcVar4 + 0x1c)
                            );
    uVar21 = (*DAT_42000e30)(*(undefined4 *)((int)pcVar4 + 0x50),*(undefined4 *)((int)pcVar4 + 0x54)
                             ,*(undefined4 *)((int)pcVar4 + 0x20),
                             *(undefined4 *)((int)pcVar4 + 0x24));
    uVar20 = (*DAT_42000e38)((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar21,
                             (int)((ulonglong)uVar21 >> 0x20));
    *(undefined8 *)((int)pcVar4 + 0x10) = uVar20;
    uVar19 = (*DAT_42000e30)((int)uVar19,uVar14,*(undefined4 *)((int)pcVar4 + 0x48),
                             *(undefined4 *)((int)pcVar4 + 0x4c));
    uVar13 = *(undefined4 *)((int)pcVar4 + 0x28);
    uVar19 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),
                             *(undefined4 *)((int)pcVar4 + 0x18),*(undefined4 *)((int)pcVar4 + 0x1c)
                            );
    uVar14 = *(undefined4 *)((int)pcVar4 + 0x2c);
    uVar20 = (*DAT_42000e30)(*(undefined4 *)((int)pcVar4 + 0x58),*(undefined4 *)((int)pcVar4 + 0x5c)
                             ,*(undefined4 *)((int)pcVar4 + 0x20),
                             *(undefined4 *)((int)pcVar4 + 0x24));
    uVar19 = (*DAT_42000e38)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                             (int)((ulonglong)uVar20 >> 0x20));
    *(undefined8 *)((int)pcVar4 + 0x28) = uVar19;
    uVar20 = (*DAT_42000e2c)(*(undefined4 *)((int)pcVar4 + 0x10),*(undefined4 *)((int)pcVar4 + 0x14)
                             ,*(undefined4 *)((int)pcVar4 + 0x30),
                             *(undefined4 *)((int)pcVar4 + 0x34));
    uVar20 = (*DAT_42000e38)(*(undefined4 *)pcVar4,*(undefined4 *)((int)pcVar4 + 4),(int)uVar20,
                             (int)((ulonglong)uVar20 >> 0x20));
    *(undefined8 *)pcVar4 = uVar20;
    uVar19 = (*DAT_42000e2c)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar13,uVar14);
    uVar19 = (*DAT_42000e38)(*(undefined4 *)((int)pcVar4 + 8),*(undefined4 *)((int)pcVar4 + 0xc),
                             (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    *(undefined8 *)((int)pcVar4 + 8) = uVar19;
    if ((int)uVar5 < *(int *)((int)pcVar4 + 0x68)) {
      uVar6 = (*(code *)PTR_FUN_42000e24)();
      uVar8 = (*(code *)PTR_FUN_42000e24)();
      uVar12 = *(uint *)((int)pcVar4 + 0x6c);
      uVar13 = *(undefined4 *)((int)pcVar4 + 0x70);
      uVar19 = (*DAT_42000e34)((int)(char)((char)(uVar6 % uVar12) - (char)uVar13));
      uVar19 = (*DAT_42000e38)(*(undefined4 *)pcVar4,*(undefined4 *)((int)pcVar4 + 4),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      *(undefined8 *)pcVar4 = uVar19;
      uVar19 = (*DAT_42000e34)((int)(char)((char)(uVar8 % uVar12) - (char)uVar13));
      uVar19 = (*DAT_42000e38)(*(undefined4 *)((int)pcVar4 + 8),*(undefined4 *)((int)pcVar4 + 0xc),
                               (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      *(undefined8 *)((int)pcVar4 + 8) = uVar19;
    }
    iVar16 = FUN_4201eb48(*(undefined4 *)pcVar4,*(undefined4 *)((int)pcVar4 + 4));
    uVar13 = *(undefined4 *)((int)pcVar4 + 8);
    uVar14 = *(undefined4 *)((int)pcVar4 + 0xc);
    iVar9 = FUN_4201eb48(uVar13,uVar14);
    uVar6 = (*(code *)PTR_FUN_42000e24)();
    uVar6 = uVar6 + (uint)((ulonglong)uVar6 * (ulonglong)DAT_4200007c >> 0x25) * -100;
    if (uVar6 < *(uint *)((int)pcVar4 + 0x3c)) {
      pcVar3 = (code *)((int)PTR_FUN_42000e24 * 4 + iVar15);
      pcVar4 = pcVar3 + uVar6;
      unaff_retaddr = pcVar3;
      uVar19 = (*DAT_42000e34)(uVar6);
      uVar19 = (*DAT_42000e2c)(*(undefined4 *)(pcVar3 + uVar6 + 8),
                               *(undefined4 *)(pcVar3 + uVar6 + 0xc),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      iVar16 = 0;
      *(int *)(pcVar3 + uVar6 + 8) = (int)uVar19;
      *(int *)(pcVar3 + uVar6 + 0xc) = (int)((ulonglong)uVar19 >> 0x20);
    }
    else {
      uVar19 = (*DAT_42000e34)(iVar16);
      uVar19 = (*DAT_42000e2c)(*(undefined4 *)pcVar4,*(undefined4 *)((int)pcVar4 + 4),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      *(undefined8 *)pcVar4 = uVar19;
      uVar19 = (*DAT_42000e34)(iVar9);
      uVar19 = (*DAT_42000e2c)(uVar13,uVar14,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      *(undefined8 *)((int)pcVar4 + 8) = uVar19;
    }
    piVar18 = DAT_42000df4 + (uVar5 & 0xffff);
    DAT_42000df8[uVar5 & 0xffff] = iVar9;
    uVar6 = *(uint *)(pcVar4 + 0x38);
    *piVar18 = iVar16;
  } while (uVar6 != uVar7);
  iVar16 = *DAT_42000df4;
  iVar9 = *(int *)(pcVar4 + 0x74) - iVar16;
  uVar7 = *(int *)(pcVar4 + 0x78) - *DAT_42000df8;
  iVar15 = iVar9;
  if (iVar9 < 1) {
    iVar15 = -iVar9;
  }
  if (iVar9 != 0) {
    iVar17 = -1;
    if (iVar9 != 0) {
      iVar17 = 1;
    }
    DAT_42000df4[uVar5] = DAT_42000df4[uVar5] + iVar17;
    if (iVar15 != 1) {
      if (iVar16 != 0) {
        uVar14 = **(undefined4 **)(unaff_retaddr + 4);
        uVar13 = (*(code *)PTR_FUN_42000b70)();
        (*(code *)PTR_FUN_42000e40)(uVar14,1,uVar13,0);
        return;
      }
      *(undefined4 *)(uVar5 + 0x28) = 1;
    }
  }
  uVar8 = uVar7;
  if ((int)uVar7 < 1) {
    uVar8 = -uVar7;
  }
  if (uVar7 != 0) {
    uVar12 = 0;
    iVar15 = -1;
    if (uVar7 != 0) {
      iVar15 = 1;
    }
    piVar18 = DAT_42000df8 + uVar5;
    do {
      uVar12 = uVar12 + 1;
      *piVar18 = *piVar18 + iVar15;
      if (uVar12 == uVar8) break;
      piVar18 = piVar18 + -1;
    } while (uVar12 != uVar6);
  }
  memw();
  (*unaff_retaddr)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


