// 42012480  FUN_42012480  FUN_42012480  size=1134
// strings: PARSE | false | true

undefined4 FUN_42012480(char *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  undefined4 uStack_50;
  uint auStack_4c [3];
  undefined1 uStack_40;
  undefined1 auStack_3f [15];
  int iStack_30;
  char *pcStack_2c;
  int iStack_28;
  char *pcStack_24;
  
  (*DAT_42000094)(DAT_42000f50,0,0x400);
  iVar9 = *(int *)(param_1 + 0x210);
  *DAT_42000f90 = 0;
  if (iVar9 == 0) {
    iVar9 = (*(code *)PTR_FUN_42000910)(1,0x1f0);
    *(int *)(param_1 + 0x210) = iVar9;
    if (iVar9 == 0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_PARSE_42000efc,PTR_DAT_420010a8,uVar3,PTR_s_PARSE_42000efc);
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x214) == 0) {
    iVar9 = (*(code *)PTR_FUN_42000910)(1,0x46c);
    *(int *)(param_1 + 0x214) = iVar9;
    if (iVar9 == 0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_PARSE_42000efc,PTR_DAT_42001060,uVar3,PTR_s_PARSE_42000efc);
      (*(code *)PTR_FUN_42000570)(*(undefined4 *)(param_1 + 0x210));
      param_1[0x210] = '\0';
      param_1[0x211] = '\0';
      param_1[0x212] = '\0';
      param_1[0x213] = '\0';
      return 0;
    }
  }
  pcVar6 = param_1 + 0x600;
  param_1[0x635] = '\0';
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[0x20c] = '\0';
  auStack_3f[0] = 0;
  uStack_40 = 0;
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_420010ac,uVar3,PTR_s_PARSE_42000efc,param_1[3],
             param_1[4]);
  iStack_28 = FUN_42011534();
  if (iStack_28 == 0) {
LAB_420128c8:
    (*(code *)PTR_FUN_42000570)(iStack_28);
    if (*(int *)(param_1 + 0x210) != 0) {
      (*(code *)PTR_FUN_42000570)();
      param_1[0x210] = '\0';
      param_1[0x211] = '\0';
      param_1[0x212] = '\0';
      param_1[0x213] = '\0';
    }
    if (*(int *)(param_1 + 0x214) != 0) {
      (*(code *)PTR_FUN_42000570)();
      param_1[0x214] = '\0';
      param_1[0x215] = '\0';
      param_1[0x216] = '\0';
      param_1[0x217] = '\0';
    }
    return 0;
  }
  auStack_4c[2] = 0;
  *(undefined1 *)(iStack_28 + 0x15c) = 0;
  *(undefined1 *)(iStack_28 + 0x160) = 0;
  auStack_4c[1] = 0;
  auStack_4c[0] = 0;
  if (param_3 != 0) {
    auStack_4c[0] = 0;
    iStack_30 = iStack_28;
    pcStack_2c = param_1;
    pcStack_24 = pcVar6;
    do {
      bVar1 = *(byte *)(param_2 + auStack_4c[0]);
      auStack_4c[0] = auStack_4c[0] + 1;
      bVar5 = bVar1 >> 2 & 3;
      bVar2 = bVar1 >> 4;
      iVar9 = FUN_4202d4fc(param_2,param_3,auStack_4c,bVar1 & 3,&uStack_50);
      param_1 = pcStack_2c;
      if (iVar9 == 0) {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_420010b0,uVar3);
        goto LAB_420128c8;
      }
      uVar4 = (*(code *)PTR_FUN_4200005c)();
      uVar3 = uStack_50;
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_PARSE_42000efc,PTR_DAT_420010b4,uVar4,PTR_s_PARSE_42000efc,bVar5,bVar2,
                 uStack_50);
      iVar9 = iStack_30;
      if (bVar5 == 1) {
        if (bVar2 == 8) {
          auStack_4c[1] = 0;
        }
        FUN_42011938(iStack_30,pcStack_2c,bVar2,uVar3,bVar1 & 3);
      }
      else if (bVar5 == 2) {
        FUN_42011728(iStack_30 + 0x30,iStack_30,bVar2,uVar3);
      }
      else if ((bVar1 >> 2 & 3) == 0) {
        if (bVar2 == 8) {
          if ((*(char *)(iStack_30 + 0xb) != '\0') &&
             (*(char *)(*(int *)(pcStack_2c + 0x210) + 0x1d5) == '\0')) {
            *(undefined1 *)(*(int *)(pcStack_2c + 0x210) + 0x1d5) = *(undefined1 *)(iStack_30 + 8);
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (3,PTR_s_PARSE_42000efc,PTR_DAT_420010b8,uVar4,PTR_s_PARSE_42000efc,
                       *(undefined1 *)(iVar9 + 8));
          }
          iVar9 = iStack_30;
          iVar7 = *(int *)(pcStack_2c + 0x214);
          if ((*(char *)(iStack_30 + 0xc) != '\0') && (*(char *)(iVar7 + 0x62) == '\0')) {
            *(undefined1 *)(iVar7 + 0x62) = *(undefined1 *)(iStack_30 + 8);
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (3,PTR_s_PARSE_42000efc,PTR_DAT_420010bc,uVar4,PTR_s_PARSE_42000efc,
                       *(undefined1 *)(iVar9 + 8));
            goto LAB_42012659;
          }
        }
        else {
LAB_42012659:
          iVar7 = *(int *)(pcStack_2c + 0x214);
        }
        iVar9 = FUN_42011ebc(pcStack_2c,*(undefined4 *)(pcStack_2c + 0x210),iVar7,iStack_30 + 0x30,
                             bVar2,uVar3,iStack_28,auStack_4c + 2,auStack_4c + 1,iStack_30,
                             auStack_3f,&uStack_40);
        param_1 = pcStack_2c;
        if (iVar9 == 0) {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (1,PTR_s_PARSE_42000efc,PTR_DAT_420010c0,uVar3,PTR_s_PARSE_42000efc,
                     auStack_4c[0]);
          goto LAB_420128c8;
        }
        iStack_30 = iStack_28 + auStack_4c[2] * 0x164;
      }
      else {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(2,PTR_s_PARSE_42000efc,PTR_DAT_420010c4,uVar3);
      }
    } while (auStack_4c[0] < param_3);
    param_1 = pcStack_2c;
    pcVar6 = pcStack_24;
  }
  uVar8 = auStack_4c[0];
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_420010c8,uVar3,PTR_s_PARSE_42000efc,uVar8,param_3);
  if (*param_1 == '\0') {
    if (param_1[1] == '\0') {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_420010cc,uVar3);
      goto LAB_420128c8;
    }
    auStack_3f[0] = 1;
  }
  else {
    auStack_3f[0] = 1;
    memw();
    *DAT_42000dc0 = param_1;
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_420010d0,uVar3,PTR_s_PARSE_42000efc,param_1,param_1[3]
              );
    if (param_1[1] == '\0') goto LAB_420127c9;
  }
  memw();
  *DAT_42000dc4 = param_1;
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_420010d4,uVar3,PTR_s_PARSE_42000efc,param_1,param_1[3]);
LAB_420127c9:
  FUN_42012404(param_1);
  if (((*param_1 != '\0') || (param_1[1] != '\0')) && (pcVar6[0x35] != '\0')) {
    FUN_420112c4(param_1);
  }
  (*(code *)PTR_FUN_42000570)(iStack_28);
  pcVar6[0x35] = '\x01';
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_420010d8,uVar3,PTR_s_PARSE_42000efc,param_1[3]);
  if ((*param_1 != '\0') && (iVar9 = *(int *)(param_1 + 0x210), iVar9 != 0)) {
    iVar7 = *(int *)((uint)*(byte *)(iVar9 + 0x1d5) * 4 + DAT_42000f50);
    uVar8 = iVar7 + 7U >> 3;
    if (*(byte *)(iVar9 + 0x1d5) != 0) {
      uVar8 = uVar8 + 1;
    }
    *(char *)(iVar9 + 0x1d6) = (char)uVar8;
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    puVar10 = PTR_DAT_420010a0;
    if (*(char *)(*(int *)(param_1 + 0x210) + 0x1d5) == '\0') {
      puVar10 = PTR_s_false_420010a4;
    }
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_420010dc,uVar3,PTR_s_PARSE_42000efc,uVar8,iVar7,
               puVar10);
  }
  if ((param_1[1] != '\0') && (iVar9 = *(int *)(param_1 + 0x214), iVar9 != 0)) {
    iVar7 = *(int *)((uint)*(byte *)(iVar9 + 0x62) * 4 + DAT_42000f50);
    uVar8 = iVar7 + 7U >> 3;
    if (*(byte *)(iVar9 + 0x62) != 0) {
      uVar8 = uVar8 + 1;
    }
    *(char *)(iVar9 + 0x61) = (char)uVar8;
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    puVar10 = PTR_DAT_420010a0;
    if (*(char *)(*(int *)(param_1 + 0x214) + 0x62) == '\0') {
      puVar10 = PTR_s_false_420010a4;
    }
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_420010e0,uVar3,PTR_s_PARSE_42000efc,uVar8,iVar7,
               puVar10);
  }
  return 1;
}


