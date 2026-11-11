// 42011938  FUN_42011938  FUN_42011938  size=860
// strings: PARSE

undefined4 FUN_42011938(uint *param_1,int param_2,uint param_3,uint param_4,char param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  short sVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined *puVar13;
  undefined2 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  piVar4 = DAT_42000fc4;
  pcVar3 = DAT_42000f90;
  if (param_3 == 6) {
    param_1[0xb] = param_4;
    uVar5 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fc0,uVar5,PTR_s_PARSE_42000efc,param_1[0xb]);
  }
  else {
    cVar8 = (char)param_4;
    if (param_3 < 7) {
      sVar9 = (short)param_4;
      if (param_3 == 3) {
        if (param_5 == '\x01') {
          param_4 = (int)cVar8;
        }
        else if (param_5 == '\x02') {
          param_4 = (int)sVar9;
        }
        param_1[8] = param_4;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fb4,uVar5,PTR_s_PARSE_42000efc,param_1[8]);
      }
      else if (param_3 < 4) {
        if (param_3 == 1) {
          if (param_5 == '\x01') {
            param_4 = (int)cVar8;
          }
          else if (param_5 == '\x02') {
            param_4 = (int)sVar9;
          }
          param_1[6] = param_4;
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fac,uVar5,PTR_s_PARSE_42000efc,param_1[6]);
        }
        else if (param_3 == 2) {
          if (param_5 == '\x01') {
            param_4 = (int)cVar8;
          }
          else if (param_5 == '\x02') {
            param_4 = (int)sVar9;
          }
          param_1[7] = param_4;
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fb0,uVar5,PTR_s_PARSE_42000efc,param_1[7]);
        }
        else {
          *param_1 = param_4 & 0xffff;
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fa0,uVar5,PTR_s_PARSE_42000efc,*param_1);
        }
      }
      else if (param_3 == 4) {
        if (param_5 == '\x01') {
          param_4 = (int)cVar8;
        }
        else if (param_5 == '\x02') {
          param_4 = (int)sVar9;
        }
        param_1[9] = param_4;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fb8,uVar5,PTR_s_PARSE_42000efc,param_1[9]);
      }
      else {
        if (param_5 == '\x01') {
          param_4 = (int)cVar8;
        }
        else if (param_5 == '\x02') {
          param_4 = (int)sVar9;
        }
        param_1[10] = param_4;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fbc,uVar5,PTR_s_PARSE_42000efc,param_1[10]);
      }
    }
    else {
      if (param_3 == 9) {
        *(char *)((int)param_1 + 10) = cVar8;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        puVar13 = PTR_DAT_42000fa8;
      }
      else if (param_3 < 10) {
        if (param_3 != 7) {
          *DAT_42000f90 = cVar8;
          FUN_420118d4(param_1,param_2,param_4 & 0xff);
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          puVar13 = PTR_s_PARSE_42000efc;
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000f94,uVar5,PTR_s_PARSE_42000efc,*pcVar3);
          cVar8 = *(char *)((int)param_1 + 0xb);
          *(undefined1 *)(param_2 + 0x20c) = 1;
          if ((cVar8 != '\0') && (*(int *)(param_2 + 0x210) != 0)) {
            *(char *)(*(int *)(param_2 + 0x210) + 0x1d5) = *pcVar3;
            uVar5 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)(3,puVar13,PTR_DAT_42000f98,uVar5,puVar13,*pcVar3);
          }
          if ((char)param_1[3] == '\0') {
            return 1;
          }
          if (*(int *)(param_2 + 0x214) == 0) {
            return 1;
          }
          *(char *)(*(int *)(param_2 + 0x214) + 0x62) = *pcVar3;
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)(3,puVar13,PTR_DAT_42000f9c,uVar5,puVar13,*pcVar3);
          return 1;
        }
        *(char *)((int)param_1 + 9) = cVar8;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        puVar13 = PTR_DAT_42000fa4;
      }
      else if (param_3 == 10) {
        iVar12 = *DAT_42000fc4;
        if (9 < iVar12) {
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (1,PTR_s_PARSE_42000efc,PTR_DAT_42000fd4,uVar5,PTR_s_PARSE_42000efc);
          return 1;
        }
        uVar2 = *(undefined2 *)((int)param_1 + 9);
        puVar11 = (uint *)(DAT_42000fc8 + iVar12 * 0x20);
        uVar7 = param_1[6];
        uVar10 = param_1[7];
        uVar18 = param_1[8];
        uVar16 = param_1[9];
        uVar15 = param_1[10];
        puVar14 = (undefined2 *)(DAT_42000fcc + iVar12 * 0x20);
        uVar6 = param_1[0xb];
        *puVar11 = *param_1;
        *puVar14 = uVar2;
        *piVar4 = iVar12 + 1;
        puVar11[2] = uVar7;
        puVar11[3] = uVar10;
        puVar11[4] = uVar18;
        puVar11[5] = uVar16;
        puVar11[6] = uVar15;
        puVar11[7] = uVar6;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        puVar13 = PTR_DAT_42000fd0;
      }
      else {
        if (param_3 != 0xb) {
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000fe0,uVar5,PTR_s_PARSE_42000efc,param_3,
                     param_4);
          return 1;
        }
        if (*DAT_42000fc4 < 1) {
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (1,PTR_s_PARSE_42000efc,PTR_DAT_42000fdc,uVar5,PTR_s_PARSE_42000efc);
          return 1;
        }
        iVar12 = *DAT_42000fc4 + -1;
        puVar11 = (uint *)(DAT_42000fc8 + iVar12 * 0x20);
        *DAT_42000fc4 = iVar12;
        uVar10 = *puVar11;
        uVar6 = puVar11[1];
        uVar1 = *(undefined1 *)((int)puVar11 + 5);
        uVar19 = puVar11[2];
        uVar17 = puVar11[3];
        uVar18 = puVar11[4];
        uVar16 = puVar11[5];
        uVar15 = puVar11[6];
        uVar7 = puVar11[7];
        *param_1 = 0;
        param_1[9] = uVar16;
        param_1[10] = uVar15;
        *param_1 = uVar10;
        *(char *)((int)param_1 + 9) = (char)uVar6;
        *(undefined1 *)((int)param_1 + 10) = uVar1;
        param_1[6] = uVar19;
        param_1[7] = uVar17;
        param_1[8] = uVar18;
        param_1[0xb] = uVar7;
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        puVar13 = PTR_DAT_42000fd8;
      }
      (*(code *)PTR_FUN_42000118)(3,PTR_s_PARSE_42000efc,puVar13,uVar5,PTR_s_PARSE_42000efc,param_4)
      ;
    }
  }
  return 1;
}


