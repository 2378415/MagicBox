// 420177e4  FUN_420177e4  FUN_420177e4  size=668

undefined4 FUN_420177e4(undefined4 *param_1,uint *param_2,undefined4 *param_3)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_3[2] != 0) {
    if ((((param_2[3] & 8) == 0) || (param_2[4] == 0)) &&
       (iVar7 = FUN_42017c98(param_1,param_2), iVar7 != 0)) {
      return 0xffffffff;
    }
    uVar5 = DAT_420011ac;
    piVar8 = (int *)*param_3;
    if ((param_2[3] & 2) == 0) {
      if ((param_2[3] & 1) == 0) {
        iVar7 = 0;
        uVar5 = 0;
        do {
          while (uVar5 == 0) {
            iVar7 = *piVar8;
            puVar1 = (uint *)(piVar8 + 1);
            piVar8 = piVar8 + 2;
            uVar5 = *puVar1;
          }
          uVar6 = param_2[3];
          uVar9 = *param_2;
          uVar11 = param_2[2];
          if ((uVar6 & 0x200) == 0) {
            if ((param_2[4] < uVar9) || (uVar5 < param_2[5])) {
              uVar6 = (uVar11 < uVar5) * uVar11 + (uVar11 >= uVar5) * uVar5;
              (*DAT_420011b4)(uVar9,iVar7,uVar6);
              uVar9 = param_2[2];
              param_2[2] = uVar9 - uVar6;
              *param_2 = *param_2 + uVar6;
              if ((uVar9 - uVar6 == 0) && (iVar3 = FUN_4201742c(param_1,param_2), iVar3 != 0))
              goto LAB_42017a80;
            }
            else {
              iVar3 = (uVar5 < 0x7fffffff) * uVar5 + (uint)(uVar5 >= 0x7fffffff) * 0x7fffffff;
              uVar6 = (*(code *)param_2[10])
                                (param_1,param_2[8],iVar7,iVar3 - iVar3 % (int)param_2[5]);
              if ((int)uVar6 < 1) goto LAB_42017a80;
            }
          }
          else {
            uVar12 = uVar5;
            if ((uVar11 <= uVar5) && (uVar12 = uVar11, (uVar6 & 0x480) != 0)) {
              iVar3 = uVar9 - param_2[4];
              uVar9 = (int)(param_2[5] * 3) / 2;
              uVar11 = iVar3 + 1 + uVar5;
              if (uVar9 < uVar11) {
                uVar9 = uVar11;
              }
              if ((uVar6 & 0x400) == 0) {
                uVar6 = (*(code *)PTR_FUN_420011b0)(param_1);
                if (uVar6 != 0) goto LAB_42017921;
                (*(code *)PTR_FUN_4200115c)(param_1,param_2[4]);
                *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xff7f;
              }
              else {
                uVar6 = (*(code *)PTR_FUN_4200119c)(param_1,uVar9);
                if (uVar6 != 0) {
                  (*DAT_420002fc)(uVar6,param_2[4],iVar3);
                  *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xfb7f | 0x80;
LAB_42017921:
                  param_2[4] = uVar6;
                  *param_2 = uVar6 + iVar3;
                  param_2[5] = uVar9;
                  param_2[2] = uVar9 - iVar3;
                  uVar12 = uVar5;
                  goto LAB_4201793b;
                }
              }
              *param_1 = 0xc;
              goto LAB_42017a80;
            }
LAB_4201793b:
            (*DAT_420011b4)(*param_2,iVar7);
            param_2[2] = param_2[2] - uVar12;
            *param_2 = *param_2 + uVar12;
            uVar6 = uVar5;
          }
          iVar3 = param_3[2];
          iVar7 = iVar7 + uVar6;
          param_3[2] = iVar3 - uVar6;
          uVar5 = uVar5 - uVar6;
        } while (iVar3 - uVar6 != 0);
      }
      else {
        uVar5 = 0;
        bVar2 = false;
        iVar7 = 0;
        uVar6 = 0;
        do {
          while (uVar6 == 0) {
            iVar7 = *piVar8;
            puVar1 = (uint *)(piVar8 + 1);
            bVar2 = false;
            piVar8 = piVar8 + 2;
            uVar6 = *puVar1;
          }
          if (!bVar2) {
            iVar3 = (*DAT_420011b8)(iVar7,10,uVar6);
            uVar5 = uVar6 + 1;
            if (iVar3 != 0) {
              uVar5 = (iVar3 + 1) - iVar7;
            }
          }
          uVar9 = *param_2;
          iVar3 = (uVar5 < uVar6) * uVar5 + (uVar5 >= uVar6) * uVar6;
          iVar10 = param_2[5] + param_2[2];
          if ((param_2[4] < uVar9) && (iVar10 < iVar3)) {
            (*DAT_420011b4)(uVar9,iVar7);
            *param_2 = *param_2 + iVar10;
            iVar4 = FUN_4201742c(param_1,param_2);
            iVar3 = iVar10;
            if (iVar4 != 0) goto LAB_42017a80;
          }
          else if (iVar3 < (int)param_2[5]) {
            (*DAT_420011b4)(uVar9,iVar7,iVar3);
            param_2[2] = param_2[2] - iVar3;
            *param_2 = *param_2 + iVar3;
          }
          else {
            iVar3 = (*(code *)param_2[10])(param_1,param_2[8],iVar7);
            if (iVar3 < 1) {
LAB_42017a80:
              *(ushort *)(param_2 + 3) = (ushort)param_2[3] | 0x40;
              return 0xffffffff;
            }
          }
          uVar5 = uVar5 - iVar3;
          bVar2 = true;
          if (uVar5 == 0) {
            iVar10 = FUN_4201742c(param_1,param_2);
            bVar2 = false;
            if (iVar10 != 0) goto LAB_42017a80;
          }
          iVar10 = param_3[2];
          iVar7 = iVar7 + iVar3;
          param_3[2] = iVar10 - iVar3;
          uVar6 = uVar6 - iVar3;
        } while (iVar10 - iVar3 != 0);
      }
    }
    else {
      iVar7 = 0;
      uVar6 = 0;
      do {
        while (uVar6 == 0) {
          iVar7 = *piVar8;
          puVar1 = (uint *)(piVar8 + 1);
          piVar8 = piVar8 + 2;
          uVar6 = *puVar1;
        }
        iVar3 = (*(code *)param_2[10])
                          (param_1,param_2[8],iVar7,
                           (uVar6 < uVar5) * uVar6 + (uVar6 >= uVar5) * uVar5);
        if (iVar3 < 1) goto LAB_42017a80;
        iVar10 = param_3[2];
        iVar7 = iVar7 + iVar3;
        param_3[2] = iVar10 - iVar3;
        uVar6 = uVar6 - iVar3;
      } while (iVar10 - iVar3 != 0);
    }
  }
  return 0;
}


