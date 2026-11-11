// 420168fc  FUN_420168fc  FUN_420168fc  size=545

int FUN_420168fc(int *param_1,int param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 uStack_60;
  char cStack_5f;
  byte bStack_5e;
  undefined1 uStack_5d;
  undefined1 auStack_58 [24];
  int iStack_40;
  int aiStack_3c [3];
  int iStack_30;
  int *piStack_2c;
  
  if (param_2 == 0) {
    iVar7 = 0x102;
  }
  else {
    param_1[7] = param_3;
    param_1[8] = param_4;
    iStack_30 = param_2;
    FUN_420167c4(param_1);
    piStack_2c = param_1 + 3;
    FUN_420167c4(piStack_2c);
    if (DAT_420010f4 < param_4) {
      iVar7 = -1;
    }
    else {
      iVar7 = param_4 * 0x54 + 4;
    }
    puVar1 = (uint *)(*(code *)PTR_FUN_420006e0)(iVar7);
    if (puVar1 != (uint *)0x0) {
      *puVar1 = param_4;
      puVar1 = puVar1 + 1;
      puVar3 = puVar1;
      uVar5 = param_4;
      while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
        FUN_420156b8(puVar3);
        puVar3 = puVar3 + 0x15;
      }
    }
    iVar7 = param_1[6];
    param_1[6] = (int)puVar1;
    if (iVar7 != 0) {
      FUN_42014794(param_1 + 6);
    }
    if (param_1[6] == 0) {
      iVar7 = 0x101;
    }
    else {
      for (uVar5 = 0; uVar5 < param_4; uVar5 = uVar5 + 1) {
        iVar4 = uVar5 * 0x54;
        iVar7 = FUN_42016634(uVar5 * 0x54 + param_1[6],iStack_30,uVar5 + param_3);
        if (iVar7 != 0) {
          return iVar7;
        }
        iVar7 = FUN_42015770(param_1[6] + iVar4,aiStack_3c);
        if (iVar7 == 0) {
          iVar7 = FUN_420167ac(*param_1,0,aiStack_3c[0]);
          if (iVar7 == 0) {
            FUN_4202503c(param_1,param_1[6] + iVar4);
          }
          else {
            FUN_420168c8(param_1,iVar7,param_1[6] + iVar4);
          }
        }
        else {
          FUN_4202503c(piStack_2c,param_1[6] + iVar4);
        }
      }
      if (param_1[2] == 0) {
        param_1[9] = 0;
        iVar7 = FUN_420167dc(param_1);
      }
      else {
        iVar7 = FUN_42015770(param_1[1],aiStack_3c);
        if (iVar7 == 0) {
          param_1[9] = aiStack_3c[0] + 1;
          iVar4 = param_1[1];
          iStack_40 = 0;
          iVar6 = -1;
          while (iVar2 = FUN_42015dbc(iVar4,0xff,0xff,0,&iStack_40,&uStack_60,0xff,0xff), iVar2 == 0
                ) {
            iVar6 = (uint)bStack_5e + iStack_40;
            iStack_40 = iVar6;
          }
          if (iVar6 != -1) {
            iVar6 = *param_1;
            while ((iVar4 != iVar6 &&
                   ((*(int *)(iVar6 + 0xc) == -8 ||
                    (iVar2 = FUN_42016228(iVar6,uStack_60,cStack_5f,auStack_58,uStack_5d,0xff),
                    iVar2 != 0))))) {
              iVar6 = *(int *)(iVar6 + 4);
            }
            if ((iVar4 == iVar6) && (cStack_5f == 'H')) {
              iVar6 = *param_1;
              while ((iVar4 != iVar6 &&
                     ((*(int *)(iVar6 + 0xc) == -8 ||
                      (iVar2 = FUN_42016228(iVar6,uStack_60,0x41,auStack_58,uStack_5d,0xff),
                      iVar2 != 0))))) {
                iVar6 = *(int *)(iVar6 + 4);
              }
            }
          }
          for (iVar4 = *param_1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
            if (*(int *)(iVar4 + 0xc) == -8) {
              iVar6 = param_1[1];
              if (*(int *)(iVar6 + 0xc) == -2) {
                iVar2 = FUN_420157b4(iVar6);
                if (iVar2 != 0) {
                  return iVar2;
                }
                FUN_42025060(param_1,iVar6);
                FUN_4202503c(piStack_2c,iVar6);
              }
              iVar6 = FUN_420167dc(param_1);
              if (iVar6 != 0) {
                return iVar6;
              }
              iVar6 = FUN_42015920(iVar4,param_1[1]);
              if (iVar6 != 0 && iVar6 != DAT_42000cd4) {
                return iVar6;
              }
              iVar6 = FUN_420157b4(iVar4);
              if (iVar6 != 0) {
                return iVar6;
              }
              FUN_42025060(param_1,iVar4);
              FUN_4202503c(piStack_2c,iVar4);
              break;
            }
          }
          if (param_1[5] == 0) {
            iVar7 = DAT_42000ce0;
          }
        }
      }
    }
  }
  return iVar7;
}


