// 42011ebc  Feature  FUN_42011ebc  size=1330
// strings: PARSE | Input | Feature | Feature (array)

undefined4
FUN_42011ebc(undefined1 *param_1,int param_2,int param_3,int *param_4,uint param_5,uint param_6,
            int param_7,int *param_8,int *param_9,int *param_10,undefined1 *param_11)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  
  if (param_5 == 10) {
    iVar6 = FUN_42011584(param_7,param_8,0x14,param_10);
    if (iVar6 == 0) {
      return 0;
    }
    piVar5 = (int *)(param_7 + *param_8 * 0x164);
    piVar5[4] = piVar5[4] + 1;
    if (*(byte *)(param_4 + 0x4b) == 0) {
      piVar5[1] = 0;
    }
    else {
      iVar6 = param_4[(*(byte *)(param_4 + 0x4b) - 1) * 5 + 1];
      piVar5[1] = iVar6;
      if (*piVar5 == 1) {
        if (iVar6 == 2) {
          *param_1 = 1;
          *(undefined1 *)((int)piVar5 + 0xb) = 1;
          *(undefined1 *)(piVar5 + 0x58) = 1;
          *(char *)(piVar5 + 2) = (char)param_10[2];
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          puVar12 = PTR_s_PARSE_42000efc;
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_4200104c,uVar3,PTR_s_PARSE_42000efc,piVar5[1],
                     (char)param_10[2]);
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,puVar12,PTR_DAT_42001050,uVar3,puVar12,
                     *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x1d5));
          if (param_2 == 0) {
            iVar6 = (*(code *)PTR_FUN_42000910)(1,0x1f0);
            if (iVar6 == 0) {
              uVar3 = (*(code *)PTR_FUN_4200005c)();
              (*(code *)PTR_FUN_42000118)(1,puVar12,PTR_DAT_42001054,uVar3,puVar12);
              return 0;
            }
            *(int *)(param_1 + 0x210) = iVar6;
          }
        }
        else if (iVar6 == 6) {
          param_1[1] = 1;
          *(undefined1 *)(piVar5 + 3) = 1;
          *(char *)(piVar5 + 2) = (char)param_10[2];
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          puVar12 = PTR_s_PARSE_42000efc;
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42001058,uVar3,PTR_s_PARSE_42000efc,piVar5[1],
                     (char)param_10[2]);
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,puVar12,PTR_DAT_4200105c,uVar3,puVar12,
                     *(undefined1 *)(*(int *)(param_1 + 0x214) + 0x62));
          if (*(int *)(param_1 + 0x214) == 0) {
            iVar6 = (*(code *)PTR_FUN_42000910)(1,0x46c);
            *(int *)(param_1 + 0x214) = iVar6;
            if (iVar6 == 0) {
              uVar3 = (*(code *)PTR_FUN_4200005c)();
              (*(code *)PTR_FUN_42000118)(1,puVar12,PTR_DAT_42001060,uVar3,puVar12);
              return 0;
            }
          }
        }
      }
    }
LAB_42012058:
    *(undefined1 *)(param_4 + 0x4b) = 0;
  }
  else {
    if (param_5 < 0xb) {
      if (param_5 == 8) {
        uVar11 = (uint)*(byte *)((int)param_10 + 10);
        piVar5 = (int *)((uint)*(byte *)(param_10 + 2) * 4 + DAT_42000f50);
        iVar6 = (int)(short)(ushort)*(byte *)((int)param_10 + 9) *
                (int)(short)(ushort)*(byte *)((int)param_10 + 10);
        *piVar5 = *piVar5 + iVar6;
        if ((param_6 & 1) != 0) {
          *param_9 = *param_9 + iVar6;
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          puVar12 = PTR_s_Input_42001070;
          goto LAB_42012372;
        }
        if (*(char *)((int)param_10 + 0xb) == '\0') {
          if (param_1[1] == '\0') {
            *param_9 = *param_9 + iVar6;
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (3,PTR_s_PARSE_42000efc,PTR_DAT_42001084,uVar3,PTR_s_PARSE_42000efc);
            return 1;
          }
          FUN_420115c8(param_1,param_3,param_10,param_9,param_6 & 0xff);
          return 1;
        }
        uVar7 = (uint)*(byte *)(param_4 + 0x4b);
        uVar4 = 0;
        if ((char)param_10[0x58] == '\0') {
LAB_42012169:
          if (uVar4 < uVar7) {
LAB_42012174:
            piVar5 = param_4 + uVar4 * 5;
            iVar6 = 0;
            do {
              iVar8 = *piVar5;
              if ((iVar8 == *param_10) &&
                 (uVar11 = (uint)*(byte *)((int)piVar5 + 0x11), uVar11 != 0)) {
                iVar9 = (uint)*(byte *)((int)param_10 + 10) - iVar6;
                if (iVar9 < 1) goto LAB_42012058;
                iVar9 = ((int)uVar11 < iVar9) * uVar11 + (uint)((int)uVar11 >= iVar9) * iVar9;
                if (iVar8 == 9) {
                  iVar8 = 0;
                  do {
                    iVar10 = iVar8 + piVar5[2];
                    iVar8 = iVar8 + 1;
                    FUN_42011d3c(param_2,param_9,*(undefined1 *)((int)param_10 + 9),iVar10);
                  } while (iVar8 != iVar9);
                }
                else if (iVar8 == 0xc) {
                  iVar8 = 0;
                  do {
                    iVar10 = iVar8 + piVar5[2];
                    iVar8 = iVar8 + 1;
                    FUN_42011e3c(param_2,param_9,*(undefined1 *)((int)param_10 + 9),iVar10);
                  } while (iVar8 != iVar9);
                }
                else {
                  if (iVar8 != 1) {
                    iVar8 = (int)(short)(ushort)*(byte *)((int)param_10 + 9) * (int)(short)iVar9;
                    iVar6 = iVar6 + iVar9;
                    *param_9 = *param_9 + iVar8;
                    uVar3 = (*(code *)PTR_FUN_4200005c)();
                    (*(code *)PTR_FUN_42000118)
                              (3,PTR_s_PARSE_42000efc,PTR_DAT_4200107c,uVar3,PTR_s_PARSE_42000efc,
                               *param_10,iVar9,iVar8);
                    goto LAB_4201226c;
                  }
                  iVar8 = 0;
                  do {
                    iVar10 = iVar8 + piVar5[2];
                    iVar8 = iVar8 + 1;
                    FUN_42011dac(param_2,param_9,*(undefined1 *)((int)param_10 + 9),iVar10);
                  } while (iVar8 != iVar9);
                }
                iVar6 = iVar6 + iVar8;
              }
LAB_4201226c:
              uVar4 = uVar4 + 1;
              piVar5 = piVar5 + 5;
            } while ((int)uVar4 < (int)(uint)*(byte *)(param_4 + 0x4b));
            uVar11 = (uint)*(byte *)((int)param_10 + 10) - iVar6;
          }
          else {
            uVar11 = (uint)*(byte *)((int)param_10 + 10);
          }
        }
        else if (uVar7 != 0) {
          uVar4 = param_6 & 1;
          if ((param_4[1] == 1) && (*param_4 == 1)) {
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (3,PTR_s_PARSE_42000efc,PTR_DAT_42001078,uVar3,PTR_s_PARSE_42000efc);
            uVar7 = (uint)*(byte *)(param_4 + 0x4b);
            uVar4 = 1;
            goto LAB_42012169;
          }
          goto LAB_42012174;
        }
        if (0 < (int)uVar11) {
          *param_9 = *param_9 + *(byte *)((int)param_10 + 9) * uVar11;
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42001080,uVar3,PTR_s_PARSE_42000efc,uVar11,
                     *(byte *)((int)param_10 + 9) * uVar11);
        }
        goto LAB_42012058;
      }
      if (param_5 == 9) {
        if ((param_6 & 1) != 0) {
          return 1;
        }
        if ((param_1[1] != '\0') && (*param_10 == 8)) {
          cVar1 = *(char *)((int)param_10 + 9);
          cVar2 = *(char *)((int)param_10 + 10);
          *(int *)(param_3 + 0x5c) = *param_9;
          *(char *)(param_3 + 0x60) = cVar1 * cVar2;
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42001088,uVar3,PTR_s_PARSE_42000efc,*param_9,
                     (int)(short)(ushort)*(byte *)((int)param_10 + 9) *
                     (int)(short)(ushort)*(byte *)((int)param_10 + 10));
        }
        *param_9 = *param_9 +
                   (int)(short)(ushort)*(byte *)((int)param_10 + 9) *
                   (int)(short)(ushort)*(byte *)((int)param_10 + 10);
        return 1;
      }
    }
    else {
      if (param_5 == 0xb) {
        iVar6 = (int)(short)(ushort)*(byte *)((int)param_10 + 9) *
                (int)(short)(ushort)*(byte *)((int)param_10 + 10) + *param_9;
        if ((param_6 & 1) != 0) {
          *param_9 = iVar6;
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          puVar12 = PTR_s_Feature_4200108c;
LAB_42012372:
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42001074,uVar3,PTR_s_PARSE_42000efc,puVar12);
          return 1;
        }
        if ((param_6 & 2) == 0) {
          uVar11 = 1;
          if (*param_10 != DAT_42001090) {
            uVar11 = param_6 >> 1 & 1;
          }
          if (uVar11 == 0) {
            *param_9 = iVar6;
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            puVar12 = PTR_s_Feature__array__42001094;
            goto LAB_42012372;
          }
        }
        *param_9 = iVar6;
        return 1;
      }
      if (param_5 == 0xc) {
        iVar6 = *param_8;
        cVar1 = *(char *)(param_7 + iVar6 * 0x164 + 0xb);
        if (iVar6 < 1) {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          puVar12 = PTR_s_PARSE_42000efc;
          (*(code *)PTR_FUN_42000118)
                    (2,PTR_s_PARSE_42000efc,PTR_DAT_42001064,uVar3,PTR_s_PARSE_42000efc);
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)(2,puVar12,PTR_DAT_42001068,uVar3,puVar12);
          return 0;
        }
        *param_8 = iVar6 + -1;
        if (((param_2 == 0) || (cVar1 == '\0')) && (param_1[1] == '\0')) {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_4200106c,uVar3,PTR_s_PARSE_42000efc,*param_10,
                     param_10[1]);
          return 1;
        }
        *param_11 = 1;
        return 1;
      }
    }
    if ((*(byte *)((int)param_10 + 9) == 0) || (*(byte *)((int)param_10 + 10) == 0)) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_PARSE_42000efc,PTR_DAT_4200109c,uVar3,PTR_s_PARSE_42000efc);
    }
    else {
      iVar6 = (int)(short)(ushort)*(byte *)((int)param_10 + 9) *
              (int)(short)(ushort)*(byte *)((int)param_10 + 10);
      *param_9 = *param_9 + iVar6;
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_PARSE_42000efc,PTR_DAT_42001098,uVar3,PTR_s_PARSE_42000efc,iVar6);
    }
  }
  return 1;
}


