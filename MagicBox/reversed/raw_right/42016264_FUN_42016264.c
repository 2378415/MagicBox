// 42016264  FUN_42016264  FUN_42016264  size=953
// strings: `& 2

int FUN_42016264(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uStack_70;
  undefined1 uStack_50;
  char cStack_4f;
  byte bStack_4e;
  undefined1 auStack_48 [24];
  uint auStack_30 [12];
  
  uVar6 = *(int *)(param_1 + 0xc) + 8;
  if (((uVar6 < 7) && ((1 << ((byte)uVar6 & 0x1f) & 0x51U) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                        (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20,param_1 + 0x18),
     iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x40) = 0;
    for (uVar6 = 0; uVar6 < 0x7e; uVar6 = uVar6 + 1) {
      uVar8 = *(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18) >> (uVar6 & 0xf) * 2 & 3;
      if (uVar8 == 2) {
        if (*(int *)(param_1 + 0x3c) == -1) {
          *(uint *)(param_1 + 0x3c) = uVar6;
        }
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
      }
      else if (uVar8 == 0) {
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      }
    }
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 == -2) {
      for (uVar6 = 0; uVar6 < 0x7e; uVar6 = uVar6 + 1) {
        if ((~(*(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18) >> (uVar6 & 0xf) * 2) & 3) == 0) {
          *(uint *)(param_1 + 0x38) = uVar6;
          break;
        }
      }
      do {
        if (0x7d < *(uint *)(param_1 + 0x38)) goto LAB_420163a0;
        iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                          (*(int **)(param_1 + 0x50),
                           *(int *)(param_1 + 8) + *(uint *)(param_1 + 0x38) * 0x20 + 0x40,
                           &uStack_70,4);
        if (iVar1 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar1;
        }
        if (uStack_70 == 0xffffffff) goto LAB_420163a0;
        uVar6 = *(uint *)(param_1 + 0x38);
        if (0x7d < uVar6) {
          return -1;
        }
        uVar8 = *(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18);
        iVar1 = FUN_42015874(param_1,uVar6,0);
        if (iVar1 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar1;
        }
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
        if ((uVar8 >> (uVar6 & 0xf) * 2 & 3) == 2) {
          *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
        }
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      } while( true );
    }
    if (iVar1 == -4 || iVar1 == -8) {
      for (uVar6 = *(uint *)(param_1 + 0x3c); uVar6 < 0x7e; uVar6 = uVar6 + 1) {
        if ((*(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18) >> (uVar6 & 0xf) * 2 & 3) == 2) {
          iVar1 = FUN_42024fd8(param_1,uVar6,&uStack_70);
          if (iVar1 != 0) {
            *(undefined4 *)(param_1 + 0xc) = 0;
            return iVar1;
          }
          iVar1 = FUN_42016bd4(&uStack_70,uVar6 & 0xff);
          if (iVar1 == 0) {
            iVar1 = FUN_42015c90(param_1,uVar6);
            if (iVar1 != 0) {
              *(undefined4 *)(param_1 + 0xc) = 0;
              return iVar1;
            }
          }
          else {
            if (uStack_70._2_1_ == '\0') {
              return -1;
            }
            iVar1 = FUN_420155ec(param_1 + 0x44,&uStack_70,uVar6);
            if (iVar1 != 0) {
              *(undefined4 *)(param_1 + 0xc) = 0;
              return iVar1;
            }
            uVar5 = uStack_70 >> 0x10 & 0xff;
            uVar8 = uVar6;
            if ((uStack_70._1_1_ == 'A' || uStack_70._1_1_ == '!') || (uStack_70._1_1_ == 'B')) {
              do {
                uVar8 = uVar8 + 1;
                if (uVar6 + uVar5 <= uVar8) goto LAB_4201660e;
                if (0x7d < uVar8) {
                  return -1;
                }
              } while ((*(uint *)((uVar8 >> 4) * 4 + param_1 + 0x18) >> (uVar8 & 0xf) * 2 & 3) == 2)
              ;
              FUN_42015c90(param_1,uVar6);
            }
LAB_4201660e:
            uVar6 = (uVar6 + uVar5) - 1;
          }
        }
      }
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
LAB_420163a0:
  uVar6 = *(uint *)(param_1 + 0x38);
  if (0x7e < uVar6) {
    uVar6 = 0x7e;
  }
  uVar5 = 0;
  uVar8 = 0xffffffff;
  do {
    if (uVar6 <= uVar5) {
      if (uVar8 != 0xffffffff) {
        auStack_30[0] = 0;
        iVar1 = FUN_42015dbc(param_1,uStack_50,cStack_4f,auStack_48,auStack_30,&uStack_70,0xff,0xff)
        ;
        if (((iVar1 == 0) && (auStack_30[0] < uVar8)) && (iVar1 = FUN_42015c90(param_1), iVar1 != 0)
           ) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar1;
        }
      }
      return 0;
    }
    if (0x7d < uVar5) {
      return -1;
    }
    uVar8 = *(uint *)((uVar5 >> 4) * 4 + param_1 + 0x18) >> (uVar5 & 0xf) * 2 & 3;
    if (uVar8 == 0) {
      uVar4 = 1;
      uVar8 = 0xffffffff;
    }
    else if (uVar8 == 1) {
      iVar1 = FUN_42015c90(param_1,uVar5);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        return iVar1;
      }
      uVar4 = 1;
      uVar8 = 0xffffffff;
    }
    else {
      iVar1 = FUN_42024fd8(param_1,uVar5,&uStack_50);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        return iVar1;
      }
      iVar1 = FUN_42016bd4(&uStack_50,uVar5 & 0xff);
      uVar8 = uVar5;
      if (iVar1 == 0) {
        iVar1 = FUN_42015c90(param_1,uVar5);
        if (iVar1 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar1;
        }
        uVar4 = 1;
      }
      else {
        iVar2 = FUN_420155ec(param_1 + 0x44,&uStack_50,uVar5);
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar2;
        }
        uVar3 = FUN_42015508(param_1 + 0x44,0,&uStack_50);
        if ((cStack_4f == 'A' || cStack_4f == '!') || (cStack_4f == 'B')) {
          uVar4 = (uint)bStack_4e;
          for (uVar7 = uVar5; uVar7 < uVar5 + uVar4; uVar7 = uVar7 + 1) {
            if (0x7d < uVar7) {
              return -1;
            }
            if ((*(uint *)((uVar7 >> 4) * 4 + param_1 + 0x18) >> (uVar7 & 0xf) * 2 & 3) != 2) {
              uVar8 = 0xffffffff;
              goto LAB_420164a5;
            }
          }
          iVar1 = 0;
LAB_420164a5:
          if (iVar1 != 0) {
            FUN_42015c90(param_1,uVar5);
            goto LAB_420164d8;
          }
        }
        else {
          uVar4 = 1;
        }
        if (uVar3 < uVar5) {
          FUN_42015c90(param_1);
        }
      }
    }
LAB_420164d8:
    uVar5 = uVar5 + uVar4;
  } while( true );
}


