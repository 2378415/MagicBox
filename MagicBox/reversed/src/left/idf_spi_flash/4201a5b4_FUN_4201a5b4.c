undefined4
FUN_4201a5b4(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            char param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *extraout_a3;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  iVar8 = param_2[7];
  iVar7 = param_2[8];
  if (iVar8 == 0) {
    if (1 < iVar7) {
      return 0x102;
    }
    uVar12 = *param_1;
    uVar11 = DAT_42001940;
LAB_4201a5ee:
    uVar1 = *(undefined1 *)(param_2 + 2);
    uVar2 = *(undefined1 *)(param_2 + 1);
    iVar10 = param_2[10];
    uVar6 = param_2[0xb];
    *param_1 = 0;
    puVar9 = param_1 + 1;
    *(undefined1 *)((int)param_1 + 0xd) = uVar1;
    *(undefined1 *)((int)param_1 + 0xe) = uVar2;
    param_5 = *(char *)((int)param_2 + 0x26);
    *param_1 = uVar12;
    param_1[1] = uVar11;
    param_1[2] = iVar7;
    param_1[5] = iVar10;
    param_1[10] = uVar6;
    if (param_5 != '\0') {
      if (iVar7 == 0 && iVar8 == 0) {
        *(char *)(param_1 + 3) = (char)*param_2;
        memw();
        param_1[4] = param_2[3];
        goto LAB_4201a6d9;
      }
      goto LAB_4201a630;
    }
  }
  else {
    if (iVar8 == 1) {
      if (5 < iVar7) {
        return 0x102;
      }
      uVar12 = *param_1;
      uVar11 = DAT_42001944;
      goto LAB_4201a5ee;
    }
    if (2 < iVar7) {
      return 0x102;
    }
    if (iVar8 == 2) {
      uVar12 = *param_1;
      uVar11 = DAT_42001948;
      goto LAB_4201a5ee;
    }
LAB_4201a630:
    (*(code *)PTR_FUN_42000330)();
    puVar9 = extraout_a3;
  }
  iVar7 = param_2[5];
  uVar4 = FUN_4201a554(param_2,puVar9);
  iVar7 = (iVar7 + 1) * 0x50;
  if (-1000 < iVar7) {
    param_5 = (char)(((int)((longlong)iVar7 * (longlong)DAT_420002d0 >> 0x26) - (iVar7 >> 0x1f)) /
                    ((int)DAT_4200194c / (int)(DAT_4200194c / uVar4)));
  }
  *(char *)(param_1 + 3) = param_5;
  if (param_2[7] == 0) {
    bVar3 = FUN_4201a554(param_2);
    uVar4 = DAT_420014c0;
    if (bVar3 != 1) {
      uVar4 = bVar3 - 1;
      uVar4 = (int)uVar4 / 2 << 8 | (uVar4 & 0xff) << 0x10 | uVar4;
    }
  }
  else {
    uVar5 = FUN_4201a554(param_2);
    uVar4 = DAT_420014c0;
    if ((uVar5 & 0xff) != 1) {
      uVar4 = (uVar5 & 0xff) - 1;
      uVar4 = (((uVar5 & 0xff) >> 1) - 1 & 0xff) << 6 | (uVar4 & 0xff) << 0xc | uVar4;
    }
  }
  iVar10 = param_2[10];
  memw();
  param_1[4] = uVar4;
LAB_4201a6d9:
  if (*(char *)(param_2 + 9) != '\0') {
    param_1[6] = param_1[6] | 3;
    *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(param_2 + 0xd);
    *(undefined1 *)((int)param_1 + 0x2d) = *(undefined1 *)((int)param_2 + 0x35);
  }
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    param_1[6] = param_1[6] | 4;
  }
  if (iVar10 == 0x11) {
    param_1[9] = param_1[9] | 1;
  }
  return 0;
}