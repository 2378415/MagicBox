// 4201eecc  FUN_4201eecc  FUN_4201eecc  size=1029

int FUN_4201eecc(undefined4 param_1,uint param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  uint uStack_28;
  
  uVar11 = DAT_42001bb8;
  puVar9 = &local_60;
  uVar6 = param_2 & 0x7fffffff;
  if (uVar6 <= DAT_42001b38) {
    *(undefined4 *)param_3 = param_1;
    *(uint *)((int)param_3 + 4) = param_2;
    *(undefined4 *)(param_3 + 1) = 0;
    *(undefined4 *)((int)param_3 + 0xc) = 0;
    return 0;
  }
  uStack_28 = param_2;
  if (uVar6 <= DAT_42001bb4) {
    if ((int)param_2 < 1) {
      uVar15 = (*DAT_42000e38)(param_1,param_2,DAT_42001bec,DAT_42001bb8);
      uVar13 = (undefined4)((ulonglong)uVar15 >> 0x20);
      uVar8 = (undefined4)uVar15;
      if (uVar6 == uVar11) {
        uVar14 = (*DAT_42000e38)(uVar8,uVar13,DAT_42001bd8,DAT_42001bdc);
        uVar8 = (undefined4)((ulonglong)uVar14 >> 0x20);
        uVar15 = (*DAT_42000e38)((int)uVar14,uVar8,DAT_42001be0,DAT_42001bcc);
        uVar14 = (*DAT_42000e2c)((int)uVar14,uVar8,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
        uVar8 = DAT_42001be0;
        uVar13 = DAT_42001bcc;
      }
      else {
        uVar15 = (*DAT_42000e38)(uVar8,uVar13,DAT_42001bf0,DAT_42001bdc);
        uVar14 = (*DAT_42000e2c)(uVar8,uVar13,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
        uVar8 = DAT_42001bf0;
        uVar13 = DAT_42001bdc;
      }
      uVar14 = (*DAT_42000e38)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar8,uVar13);
      *(int *)(param_3 + 1) = (int)uVar14;
      *param_3 = uVar15;
      *(int *)((int)param_3 + 0xc) = (int)((ulonglong)uVar14 >> 0x20);
      return -1;
    }
    uVar15 = (*DAT_42000e2c)();
    uVar13 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar8 = (undefined4)uVar15;
    if (uVar6 == uVar11) {
      uVar14 = (*DAT_42000e2c)(uVar8,uVar13,DAT_42001bd8,DAT_42001bdc);
      uVar8 = (undefined4)((ulonglong)uVar14 >> 0x20);
      uVar15 = (*DAT_42000e2c)((int)uVar14,uVar8,DAT_42001be0,DAT_42001bcc);
      uVar14 = (*DAT_42000e2c)((int)uVar14,uVar8,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
      uVar8 = DAT_42001be0;
      uVar13 = DAT_42001bcc;
    }
    else {
      uVar15 = (*DAT_42000e2c)(uVar8,uVar13,DAT_42001bf0,DAT_42001bdc);
      uVar14 = (*DAT_42000e2c)(uVar8,uVar13,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
      uVar8 = DAT_42001bf0;
      uVar13 = DAT_42001bdc;
    }
    uVar14 = (*DAT_42000e2c)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar8,uVar13);
    *(int *)(param_3 + 1) = (int)uVar14;
    *param_3 = uVar15;
    *(int *)((int)param_3 + 0xc) = (int)((ulonglong)uVar14 >> 0x20);
    return 1;
  }
  iVar10 = (int)uVar6 >> 0x14;
  if (DAT_42001bbc < uVar6) {
    if (DAT_42001b3c < uVar6) {
      uVar15 = (*DAT_42000e2c)(param_1,param_2,param_1,param_2);
      param_3[1] = uVar15;
      *param_3 = uVar15;
      return 0;
    }
    iVar12 = uVar6 + (iVar10 + -0x416) * -0x100000;
    (*DAT_42001b40)(param_1,iVar12);
    local_60 = (*DAT_42000e34)();
    uVar15 = (*DAT_42000e2c)(param_1,iVar12,(int)local_60,(int)((ulonglong)local_60 >> 0x20));
    uVar15 = (*DAT_42000e30)((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,DAT_42001bc8);
    (*DAT_42001b40)();
    uStack_58 = (*DAT_42000e34)();
    uVar15 = (*DAT_42000e2c)((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uStack_58,
                             (int)((ulonglong)uStack_58 >> 0x20));
    uStack_50 = (*DAT_42000e30)((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,DAT_42001bc8);
    iVar12 = 3;
    do {
      iVar7 = iVar12;
      puVar1 = (undefined4 *)((int)puVar9 + 0x10);
      puVar2 = (undefined4 *)((int)puVar9 + 0x14);
      puVar9 = (undefined8 *)((int)puVar9 + -8);
      iVar5 = (*DAT_42001bf4)(*puVar1,*puVar2,0,0);
      iVar12 = iVar7 + -1;
    } while (iVar5 == 0);
    iVar12 = FUN_4201f2d8(&local_60,param_3,iVar10 + -0x416,iVar7,2,PTR_DAT_42001bc4);
    uVar11 = DAT_420014c0;
    if (-1 < (int)uStack_28) {
      return iVar12;
    }
    uVar6 = *(uint *)((int)param_3 + 4) ^ DAT_420014c0;
    *(undefined4 *)param_3 = *(undefined4 *)param_3;
    *(uint *)((int)param_3 + 4) = uVar6;
    *(undefined4 *)(param_3 + 1) = *(undefined4 *)(param_3 + 1);
    *(uint *)((int)param_3 + 0xc) = *(uint *)((int)param_3 + 0xc) ^ uVar11;
    goto LAB_4201f2d1;
  }
  uVar15 = FUN_4202d980();
  uVar8 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar14 = (*DAT_42000e30)((int)uVar15,uVar8,DAT_42001be4,DAT_42001be8);
  (*DAT_42000e38)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x3fe00000);
  iVar12 = (*DAT_42001b40)();
  uStack_38 = (*DAT_42000e34)();
  uVar14 = (*DAT_42000e30)((int)uStack_38,(int)((ulonglong)uStack_38 >> 0x20),DAT_42001bec,
                           DAT_42001bb8);
  uVar15 = (*DAT_42000e2c)((int)uVar15,uVar8,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar13 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar8 = (undefined4)uVar15;
  uStack_40 = (*DAT_42000e30)((undefined4)uStack_38,uStack_38._4_4_,DAT_42001bf0,DAT_42001bdc);
  uVar14 = (*DAT_42000e2c)(uVar8,uVar13,(int)uStack_40,(int)((ulonglong)uStack_40 >> 0x20));
  uVar3 = CONCAT44(uStack_30._4_4_,(undefined4)uStack_30);
  if (((iVar12 < 0x20) && (*(uint *)(PTR_DAT_42001bc0 + (iVar12 + -1) * 4) != uVar6)) ||
     (uVar3 = CONCAT44(uStack_30._4_4_,(undefined4)uStack_30),
     (int)(iVar10 - ((uint)((ulonglong)uVar14 >> 0x34) & 0x7ff)) < 0x11)) {
LAB_4201f1ac:
    *param_3 = uVar14;
    uStack_30 = uVar15;
  }
  else {
    uVar15 = (*DAT_42000e30)((undefined4)uStack_38,uStack_38._4_4_,DAT_42001bd8,DAT_42001bdc);
    uStack_40 = uVar15;
    uStack_30 = (*DAT_42000e2c)(uVar8,uVar13,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
    uVar15 = (*DAT_42000e2c)(uVar8,uVar13,(int)uStack_30,(int)((ulonglong)uStack_30 >> 0x20));
    uVar15 = (*DAT_42000e2c)((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(undefined4)uStack_40,
                             uStack_40._4_4_);
    uVar14 = (*DAT_42000e30)((undefined4)uStack_38,uStack_38._4_4_,DAT_42001be0,DAT_42001bcc);
    uVar15 = (*DAT_42000e2c)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar15,
                             (int)((ulonglong)uVar15 >> 0x20));
    uStack_40 = uVar15;
    uVar14 = (*DAT_42000e2c)((undefined4)uStack_30,uStack_30._4_4_,(int)uVar15,
                             (int)((ulonglong)uVar15 >> 0x20));
    if (0x31 < (int)(iVar10 - ((uint)((ulonglong)uVar14 >> 0x34) & 0x7ff))) {
      uVar15 = (*DAT_42000e30)((undefined4)uStack_38,uStack_38._4_4_,0x2e000000,DAT_42001bcc);
      uStack_40 = uVar15;
      uVar15 = (*DAT_42000e2c)((undefined4)uStack_30,uStack_30._4_4_,(int)uVar15,
                               (int)((ulonglong)uVar15 >> 0x20));
      uVar8 = (undefined4)((ulonglong)uVar15 >> 0x20);
      uVar14 = (*DAT_42000e2c)((undefined4)uStack_30,uStack_30._4_4_,(int)uVar15,uVar8);
      uVar14 = (*DAT_42000e2c)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(undefined4)uStack_40,
                               uStack_40._4_4_);
      uStack_40 = uVar14;
      uVar14 = (*DAT_42000e30)((undefined4)uStack_38,uStack_38._4_4_,DAT_42001bd0,DAT_42001bd4);
      uVar14 = (*DAT_42000e2c)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(undefined4)uStack_40,
                               uStack_40._4_4_);
      uStack_40 = uVar14;
      uVar14 = (*DAT_42000e2c)((int)uVar15,uVar8,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      uVar3 = uStack_30;
      goto LAB_4201f1ac;
    }
    *param_3 = uVar14;
    uVar3 = uStack_30;
  }
  uVar4 = (ulonglong)uStack_30 >> 0x20;
  uVar8 = (undefined4)uStack_30;
  uStack_38 = uVar14;
  uStack_30 = uVar3;
  uVar15 = (*DAT_42000e2c)(uVar8,(int)uVar4,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar15 = (*DAT_42000e2c)((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(undefined4)uStack_40,
                           uStack_40._4_4_);
  param_3[1] = uVar15;
  if (-1 < (int)uStack_28) {
    return iVar12;
  }
  uStack_38._4_4_ = uStack_38._4_4_ ^ DAT_420014c0;
  uVar11 = (uint)((ulonglong)uVar15 >> 0x20) ^ DAT_420014c0;
  *(undefined4 *)param_3 = (undefined4)uStack_38;
  *(uint *)((int)param_3 + 4) = uStack_38._4_4_;
  *(int *)(param_3 + 1) = (int)uVar15;
  *(uint *)((int)param_3 + 0xc) = uVar11;
LAB_4201f2d1:
  return -iVar12;
}


