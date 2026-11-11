// 4201de98  FUN_4201de98  FUN_4201de98  size=889
// strings: hc)c

int FUN_4201de98(int *param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uStack_60;
  undefined1 auStack_58 [24];
  uint auStack_40 [4];
  int iStack_30;
  
  if (param_2 == 0) {
    return 0x102;
  }
  piVar7 = (int *)*param_1;
  param_1[7] = param_3;
  param_1[8] = param_4;
  if (piVar7 != (int *)0x0) {
    iVar11 = param_1[2];
    do {
      iVar10 = *piVar7;
      piVar9 = (int *)piVar7[1];
      if (iVar10 == 0) {
        *param_1 = (int)piVar9;
        piVar7 = piVar9;
      }
      else {
        piVar7 = (int *)*param_1;
        *(int **)(iVar10 + 4) = piVar9;
      }
      if (piVar9 == (int *)0x0) {
        param_1[1] = iVar10;
      }
      else {
        *piVar9 = iVar10;
      }
      iVar11 = iVar11 + -1;
    } while (piVar7 != (int *)0x0);
    param_1[2] = iVar11;
  }
  piVar7 = (int *)param_1[3];
  if (piVar7 != (int *)0x0) {
    iVar11 = param_1[5];
    do {
      iVar11 = iVar11 + -1;
      iVar10 = *piVar7;
      piVar9 = (int *)piVar7[1];
      if (iVar10 == 0) {
        param_1[3] = (int)piVar9;
        piVar7 = piVar9;
      }
      else {
        piVar7 = (int *)param_1[3];
        *(int **)(iVar10 + 4) = piVar9;
      }
      if (piVar9 == (int *)0x0) {
        param_1[4] = iVar10;
      }
      else {
        *piVar9 = iVar10;
      }
    } while (piVar7 != (int *)0x0);
    param_1[5] = iVar11;
  }
  iVar11 = -1;
  if (param_4 <= DAT_42001aac) {
    iVar11 = param_4 * 0x54 + 4;
  }
  iStack_30 = param_2;
  puVar2 = (uint *)(*(code *)PTR_FUN_4200056c)(iVar11);
  if (puVar2 == (uint *)0x0) {
    iVar11 = param_1[6];
    param_1[6] = 0;
    if (iVar11 == 0) {
      return 0x101;
    }
LAB_4201df55:
    for (iVar10 = *(int *)(iVar11 + -4) * 0x54 + iVar11; iVar10 != iVar11; iVar10 = iVar10 + -0x54)
    {
      FUN_4201cb60(iVar10 + -0x10);
    }
    (*(code *)PTR_FUN_42000570)((int *)(iVar11 + -4));
    puVar2 = (uint *)param_1[6];
    if (puVar2 == (uint *)0x0) {
      return 0x101;
    }
  }
  else {
    *puVar2 = param_4;
    iVar11 = param_4 - 1;
    puVar2 = puVar2 + 1;
    if (-1 < iVar11) {
      puVar4 = puVar2;
      do {
        iVar11 = iVar11 + -1;
        FUN_4201cccc(puVar4);
        puVar4 = puVar4 + 0x15;
      } while (iVar11 != -1);
      iVar11 = param_1[6];
      param_1[6] = (int)puVar2;
      if (iVar11 == 0) goto LAB_4201df8c;
      goto LAB_4201df55;
    }
    iVar11 = param_1[6];
    param_1[6] = (int)puVar2;
    if (iVar11 != 0) goto LAB_4201df55;
  }
  if (param_4 == 0) {
LAB_4201e050:
    if (param_1[2] == 0) {
      param_1[9] = 0;
      iVar11 = FUN_4201dd60(param_1);
      return iVar11;
    }
    iVar11 = FUN_4201dc44(param_1[1],&uStack_60);
    if (iVar11 != 0) {
      return iVar11;
    }
    piVar7 = (int *)param_1[1];
    param_1[9] = uStack_60 + 1;
    uVar5 = 0xffffffff;
    auStack_40[0] = 0;
    while (iVar11 = FUN_4201d244(piVar7,0xff,0xff,0,auStack_40,&uStack_60,0xff,0xff), iVar11 == 0) {
      uVar5 = (uStack_60 >> 0x10 & 0xff) + auStack_40[0];
      auStack_40[0] = uVar5;
    }
    piVar9 = (int *)*param_1;
    if (uVar5 == 0xffffffff) goto joined_r0x4201e129;
    piVar6 = piVar7;
    if (piVar7 != piVar9) {
      do {
        if (piVar9[3] != -8) {
          iVar11 = FUN_4201d70c(piVar9,uStack_60 & 0xff,uStack_60._1_1_,auStack_58,uStack_60._3_1_,
                                0xff);
          if (iVar11 == 0) {
            piVar6 = (int *)*param_1;
            bVar1 = piVar7 != piVar9;
            piVar9 = piVar6;
            if (bVar1) goto joined_r0x4201e129;
            goto LAB_4201e0ea;
          }
        }
        piVar9 = (int *)piVar9[1];
      } while (piVar7 != piVar9);
      piVar6 = (int *)*param_1;
LAB_4201e0ea:
      piVar9 = piVar6;
      if (uStack_60._1_1_ != 'H') goto joined_r0x4201e129;
      if (piVar7 != piVar6) {
        do {
          if (piVar6[3] != -8) {
            iVar11 = FUN_4201d70c(piVar6,uStack_60 & 0xff,0x41,auStack_58,uStack_60._3_1_,0xff);
            if (iVar11 == 0) break;
          }
          piVar6 = (int *)piVar6[1];
        } while (piVar7 != piVar6);
        piVar9 = (int *)*param_1;
        goto joined_r0x4201e129;
      }
    }
    do {
      if (piVar6[3] == -8) {
        piVar7 = (int *)param_1[1];
        if (piVar7[3] == -2) {
          iVar11 = FUN_4201dc84(piVar7);
          if (iVar11 != 0) {
            return iVar11;
          }
          iVar11 = *piVar7;
          piVar9 = (int *)piVar7[1];
          if (iVar11 == 0) {
            *param_1 = (int)piVar9;
          }
          else {
            *(int **)(iVar11 + 4) = piVar9;
          }
          if (piVar9 == (int *)0x0) {
            param_1[1] = iVar11;
          }
          else {
            *piVar9 = iVar11;
          }
          iVar11 = param_1[4];
          param_1[2] = param_1[2] + -1;
          if (iVar11 != 0) {
            *(int **)(iVar11 + 4) = piVar7;
          }
          *piVar7 = iVar11;
          piVar7[1] = 0;
          param_1[4] = (int)piVar7;
          if (param_1[3] == 0) {
            param_1[3] = (int)piVar7;
          }
          param_1[5] = param_1[5] + 1;
        }
        iVar11 = FUN_4201dd60(param_1);
        if ((iVar11 != 0) ||
           (((iVar11 = FUN_4201cdc0(piVar6,param_1[1]), iVar11 != 0 && (iVar11 != DAT_420011bc)) ||
            (iVar11 = FUN_4201dc84(piVar6), iVar11 != 0)))) {
          return iVar11;
        }
        iVar11 = *piVar6;
        piVar7 = (int *)piVar6[1];
        if (iVar11 == 0) {
          *param_1 = (int)piVar7;
        }
        else {
          *(int **)(iVar11 + 4) = piVar7;
        }
        if (piVar7 == (int *)0x0) {
          param_1[1] = iVar11;
        }
        else {
          *piVar7 = iVar11;
        }
        iVar11 = param_1[4];
        param_1[2] = param_1[2] + -1;
        if (iVar11 != 0) {
          *(int **)(iVar11 + 4) = piVar6;
        }
        *piVar6 = iVar11;
        piVar6[1] = 0;
        param_1[4] = (int)piVar6;
        if (param_1[3] == 0) {
          param_1[3] = (int)piVar6;
        }
        iVar11 = param_1[5] + 1;
        param_1[5] = iVar11;
        goto LAB_4201e1ec;
      }
      piVar9 = (int *)piVar6[1];
joined_r0x4201e129:
      piVar6 = piVar9;
    } while (piVar9 != (int *)0x0);
    iVar11 = param_1[5];
LAB_4201e1ec:
    if (iVar11 == 0) {
      return DAT_420011cc;
    }
    return 0;
  }
LAB_4201df8c:
  iVar10 = 0;
  iVar11 = param_3 + param_4;
  do {
    iVar3 = FUN_4201dafc((int)puVar2 + iVar10,iStack_30,param_3);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = FUN_4201dc44(param_1[6] + iVar10,auStack_40);
    uVar5 = auStack_40[0];
    if (iVar3 == 0) {
      piVar7 = (int *)*param_1;
      if (piVar7 == (int *)0x0) {
        iVar3 = param_1[1];
        piVar7 = (int *)(param_1[6] + iVar10);
        if (iVar3 == 0) {
          *piVar7 = 0;
          piVar7[1] = 0;
          param_1[1] = (int)piVar7;
        }
        else {
          *(int **)(iVar3 + 4) = piVar7;
          *piVar7 = iVar3;
          piVar7[1] = 0;
          param_1[1] = (int)piVar7;
        }
LAB_4201e016:
        *param_1 = (int)piVar7;
      }
      else {
        do {
          iVar3 = FUN_4201dc44(piVar7,&uStack_60);
          if ((iVar3 == 0) && (uVar5 < uStack_60)) {
            iVar3 = param_1[2];
            iVar12 = *piVar7;
            piVar9 = (int *)(param_1[6] + iVar10);
            if (iVar12 == 0) {
              puVar8 = (undefined4 *)*param_1;
              *piVar9 = 0;
              piVar9[1] = (int)puVar8;
              if (puVar8 != (undefined4 *)0x0) {
                *puVar8 = piVar9;
              }
              *param_1 = (int)piVar9;
              if (param_1[1] == 0) {
                param_1[1] = (int)piVar9;
              }
            }
            else {
              *(int **)(iVar12 + 4) = piVar9;
              *piVar7 = (int)piVar9;
              piVar9[1] = (int)piVar7;
              *piVar9 = iVar12;
            }
            param_1[2] = iVar3 + 1;
            goto LAB_4201e042;
          }
          piVar7 = (int *)piVar7[1];
        } while (piVar7 != (int *)0x0);
        iVar3 = param_1[1];
        iVar12 = *param_1;
        piVar7 = (int *)(param_1[6] + iVar10);
        if (iVar3 != 0) {
          *(int **)(iVar3 + 4) = piVar7;
        }
        *piVar7 = iVar3;
        piVar7[1] = 0;
        param_1[1] = (int)piVar7;
        if (iVar12 == 0) goto LAB_4201e016;
      }
      param_1[2] = param_1[2] + 1;
    }
    else {
      iVar3 = param_1[4];
      piVar7 = (int *)(param_1[6] + iVar10);
      if (iVar3 != 0) {
        *(int **)(iVar3 + 4) = piVar7;
      }
      *piVar7 = iVar3;
      piVar7[1] = 0;
      param_1[4] = (int)piVar7;
      if (param_1[3] == 0) {
        param_1[3] = (int)piVar7;
      }
      param_1[5] = param_1[5] + 1;
    }
LAB_4201e042:
    param_3 = param_3 + 1;
    iVar10 = iVar10 + 0x54;
    if (param_3 == iVar11) goto LAB_4201e050;
    puVar2 = (uint *)param_1[6];
  } while( true );
}


